//recursive code
#include <iostream>
using namespace std;

void reverse(int n)
{

   // base case
   if (n < 10) {
      cout<<n;
      return;
   }
    //general case
   else{
      cout<<n%10;
      reverse(n/10); //recursive function in function
   }
}

// Driver Program
int main()
{
   int n = 1234;
   reverse(n); //Calling recursive function
   cout << "\n";
   int x = 2345789;
   reverse(x);
   cout << "\n";
   int y = 3421;
   reverse(y);
   return 0;
}
