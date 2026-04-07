#include <iostream>
using namespace std;
//الفنكشن لا تحط فيه جمل قراءة وطباعة



float MySumFunction(int num1, int num2)
{
    return num1 + num2;
}
int main ()
{
    float num1,  num2;
      cout << "enter num1 : " << endl;
      cin >> num1;
       cout << "enter num2 : " << endl;
      cin >> num2;
      cout << "Sum : " << MySumFunction( num1,num2) << endl;

}