#include <iostream>
using namespace std;

void reverse(int n)
{
    int rev=0;
    //base case
    while(n>0){

    //general case
    int rem=n%10;
    rev = rev*10 + rem;
    n /= 10;
   }
   cout<<rev<<endl;
}

bool running=true;

void run(int x){
    if (x==1){
        running=true;
    } else{
        running=false;
    }
}

// Driver
int main()
{
   while(running==true){
    int n;
    cout << "enter number :";
    cin >> n;
    reverse(n); 


    cout<<"would you like to continue?"<<endl;
    cout<<"press 1 for yes, press 2 for no";
    int answer;
    cin>>answer;

    run(answer);
    }
}
