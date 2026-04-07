#include <iostream>
using namespace std;
int main()
{
    int week = 1, days_n_week = 7 ;

        for (int i = 1; i <= 4; ++i)
        {
            cout << "   Week : " << week << "\n"<< endl;
            week++; 
            
            for (int d = 1; d <= 7; d++)
                if (d == 1)
                    cout << "       Satarday" << endl;
                else if (d == 2)
                    cout << "       Sunday" << endl;
                else if (d == 3)
                    cout << "       Monday" << endl;
                else if (d == 4)
                    cout << "       Tuesday" << endl;
                else if (d == 5)
                    cout << "       Thirsday" << endl;
                else if (d == 6)
                    cout << "       Wednsday" << endl;
                else
                    cout << "       Friday" << endl;
        }
    
}