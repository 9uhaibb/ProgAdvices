#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <vector>
#include "clsDate.h"

using namespace std;

class clsQueueLine
{
private:
	struct stTicket
	{
		string Prefix;
		string CurrentDateTime = clsDate::GetSystemDateTimeString();
		short WaitingClients;
		short ServeTimeInMinutes = 0;
	};

	queue <stTicket> _Queue;

	string _Prefix;
	int _PrCounter = 0; //

	short _ServeTimePerClient;
	int _NumberOfClients = 0;//
	int _TotalTickets = 0;
	int _ServedClients = 0;//

	void _PrintSingleTicket(stTicket Ticket)
	{
		cout << endl << setw(22) << left << " " << "------------------------------------------\n";
		cout << setw(31) << left << " " << Ticket.Prefix << endl;
		cout << setw(31) << left << " " << Ticket.CurrentDateTime << endl; 
		cout << setw(31) << left << " " << "Waiting Clients = " << Ticket.WaitingClients << endl;
		cout << setw(31) << left << " " << "Serve Time in " << Ticket.ServeTimeInMinutes << " Minutes.";
		cout << endl << setw(22) << left << " " << "------------------------------------------\n\n";

	}

public:
	
	clsQueueLine(string Prefix, short ServeTimePerClient)
	{
		_Prefix = Prefix;
		_TotalTickets = 0; //
		_ServeTimePerClient = ServeTimePerClient;
	}
	
	void IssueTicket()
	{
		stTicket Ticket;
		_NumberOfClients++;
		_PrCounter++;

		//  áÇ ÊÛíøÑ _Prefix ÃÈÏðÇ!
		// ÇÓÊÎÏãåÇ ÝÞØ áÅäÔÇÁ ÞíãÉ ÌÏíÏÉ:
		string PrefixValue = _Prefix + to_string(_PrCounter);

		Ticket.Prefix = PrefixValue;
		Ticket.CurrentDateTime = clsDate::GetSystemDateTimeString();
		Ticket.ServeTimeInMinutes = (_NumberOfClients * _ServeTimePerClient) 
			- _ServeTimePerClient;
		Ticket.WaitingClients = _NumberOfClients - 1;

		_Queue.push(Ticket);
		_TotalTickets++;
	}

	void PrintInfo()
	{
		cout << endl << endl << setw(32) << left << " " <<  "____________________\n";
		cout << setw(30) << left << " " << "       Queue Info";
		cout << endl <<  setw(32) << left << " " << "____________________\n\n";
		
		cout << setw(32) << left << " " << "Prefix = " << _Prefix << endl;
		cout << setw(32) << left << " " << "Total Tickets   = " << _TotalTickets << endl;
		cout << setw(32) << left << " " << "Served Clients  = " << _ServedClients << endl;
		cout << setw(32) << left << " " << "Waiting Clients = " << _Queue.size() << endl;
	}

	void PrintTicketsLineLTR()
	{
		vector <stTicket> vTickets;
		queue <stTicket> Temp = _Queue;
		
		// copying them to a vector then print them from the end

		while (!Temp.empty())
		{
			vTickets.push_back(Temp.front());
			Temp.pop();
		}
		
		cout << endl << endl << setw(20) << left << " " << "Tickets:  ";

		for (int i = vTickets.size() - 1; i >= 0; i--)
		{
			cout << vTickets[i].Prefix << " --> ";
		}

	}

	void PrintTicketsLineRTL()
	{
		queue <stTicket> Temp = _Queue;

		cout << endl << endl << setw(20) << left << " " << "Tickets:  ";
		while (!Temp.empty())
		{
			cout << Temp.front().Prefix << " --> ";
			Temp.pop();
		}
	}

	void PrintAllTickets()
	{
		if (_Queue.empty())
		{
			cout << endl << setw(30) << left << " " << "No Tickets.\n";
			return;
		}

		queue <stTicket> Temp = _Queue;

		cout << endl << endl <<setw(35) << left << " " << "----Tickets----\n";

		while (!Temp.empty())
		{
			stTicket T = Temp.front();

			_PrintSingleTicket(T);

			Temp.pop();
		}
	}

	void ServeNextClient()
	{
		_TotalTickets--;
		_ServedClients++;
		_Queue.pop();
	}
};

