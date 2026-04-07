// My Solution
#include <iostream>
#include "clsQueueLine.h"

using namespace std;

int main()
{

	clsQueueLine PayBillsQueue("A0", 10);
	clsQueueLine SubscriptionsQueue("B0", 5);

	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket(); // 5 Tickets

	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket(); // 3 Tickets

	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();

	PayBillsQueue.PrintAllTickets();

	cout << "\nPay Bills after serving one client\n";
	PayBillsQueue.ServeNextClient();
	PayBillsQueue.PrintInfo();

	cout << "\nSubscriptions Queue after serving one client\n";
	PayBillsQueue.ServeNextClient();
	SubscriptionsQueue.PrintInfo();

}

