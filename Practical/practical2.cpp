// jug water problem 
#include<iostream>
using namespace std;

int main(){

    int x=0,y=0;
    cout<< "Initial State of gallons : (x,y) : "<<x<<" "<<y<<endl;
    cout<<"`~~~~~~~Lets play's the game~~~~"<<endl;
    int ch;
    do
    {
        cout<< "Rules "<<endl;
        cout<<"(X,Y | X<4 ) choose 1"<<endl;
        cout<<"(X,Y | Y<3 ) choose 2"<<endl;
        cout<<"(X,Y | X>0 ) choose 3"<<endl;
        cout<<"(X,Y | Y>0 ) choose 4"<<endl;
        cout<<"(X,Y | X+Y>=4 && Y>0 ) choose 5"<<endl;
        cout<<"(X,Y | X+Y>=3 && X>0 ) choose 6"<<endl;
        cout<<"(X,Y | X+Y<=4 && Y>0 ) choose 7"<<endl;
        cout<<"(X,Y | X+Y<=3 && X>0 ) choose 8"<<endl;
        cout<<"(X,Y | X<4 ) choose 9"<<endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            x = 4;
            break;
        case 2: y=3; break;
        case 3: x=0; break;
        case 4: y=0; break;
        case 5: y = y - (4-x); x=4; break;
        case 6: x = x - (3-y); y=3; break;
        case 7: x = x+y; y=0; break;
        case 8: x=0; y=x+y; break;
        case 9: x=y; y=0; break;
        default: cout<<"invalid input"<<endl;
            break;
        }

        cout<< "Current State : (x,y) -> "<< "("<<x<< ")"<<"("<<y<<")"<<endl;


    } while (x != 2 || y != 0);


    cout<< "Current State : (x,y) -> "<< "("<<x<< ")"<<"("<<y<<")"<<endl;
}