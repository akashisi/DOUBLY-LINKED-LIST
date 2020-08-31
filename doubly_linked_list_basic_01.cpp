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
    int x=9,i=0;
    for(i=0;i<6;i++)
    {
        p=create();
        p->data=x;
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
        x=x+10;
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

    append();
    display();

    return(0);
}

