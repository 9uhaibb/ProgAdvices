#include <iostream>
using namespace std;


enum enCity {irbid , amman , jericho, alquds , sahab};
enum enCountry {palestine , jordan};
enum enGender {M , F};
enum enMarry_type {married , notMarried};

int main ()
{
 enCity Mycity;
 Mycity = enCity::alquds;
 cout << Mycity << endl;

}


