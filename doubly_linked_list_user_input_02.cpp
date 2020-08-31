#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL,*last=NULL;

struct node *create()
{
    return((struct node *)malloc(sizeof(struct node)));
};

void append()
{
    struct node *p;
    p=create();
    cout<<endl<<"Enter data to append in list :: ";
    cin>>p->data;
    p->next=NULL;
    p->prev=NULL;
    if(head==NULL)
    {
        head=last=p;
    }
    else
    {
        last->next=p;
        p->prev=last;
        last=p;
    }
}

void display()
{
    struct node *temp;
    temp=head;
    cout<<endl<<"CONTENT OF DOUBLY LINKED LIST :: \n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main()
{
    int ch;
    while(1)
    {
        cout<<endl<<"1. ADD DATA TO END OF LIST ::\n2. DISPLAY\n3. EXIT";
        cout<<endl<<"Enter your choice :: ";
        cin>>ch;
        switch(ch)
        {
            case 1: append();
                    break;
            case 2: display();
                    break;
            case 3: exit(1);
            default:exit(1);
        }
    }
    return(0);
}


