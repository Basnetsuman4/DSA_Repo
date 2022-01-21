#include<iostream>
using namespace std;
#define MAXSIZE 10


class stack
{
    private:
        int top;
        int array[MAXSIZE];

    public:

        stack()
        {
            top = -1;
            for(int i = 0; i<MAXSIZE ;i++)
            {
                array[i]=0;
            }
        }

        bool isempty()
        {
            if(top<= -1)
            {
                cout<<" STACK UNDERFLOW!!!"<<endl;
                return 1;
            }
            else
            {
                return 0;
            }
        }


        bool isfull()
        {
            if(top== MAXSIZE -1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }


        void PUSH(int val)
        {
            if(isfull())
            {
                cout<<"STACK OVERFLOW"<<endl;

            }
            else
            {   
                top++;
                array[top]=val ;
                
            }
        }

        int POP()
        {
            if(isempty())
            {
                cout<<"STACK UNDERFLOW!!!"<<endl;
                return 0;
            }
            else 
            {
                cout<<"The item that poped is : "<<array[top]<<endl;
            
                top--;
                
            }
            return 0;
        }

        void traverse()
        {
            cout<<"The elements in the stack are : "<<endl;
            for(int i = top; i>=0; i--)
            {
                cout<<array[i]<<"\n\t"<<endl;
            }
        }



};

int main()
{ 
    int choice,ins;
    stack s1;
    cout<<"------STACK OPERATION------"<<endl;
    cout<<"1. PUSH"<<endl;
    cout<<"2. POP"<<endl;
    cout<<"3. TRAVERSE"<<endl;
    cout<<"4. EXIT"<<endl;

    do{
    cout<<"Enter the operation to be performed "<<endl;
    cin>>choice;
    switch (choice)
    {
    case  1: 
            cout<<"Enter the element to be inserted : "<<endl;
            cin>>ins;
            s1.PUSH(ins);
            break;

    case 2:
            s1.POP();
            break;

    case 3:
            
            s1.traverse();
            break;

    default:
            cout<<"INVALID CHOICE!!!!"<<endl;
        break;
    }

    }
    while(choice!=4);
    return 0;
}
