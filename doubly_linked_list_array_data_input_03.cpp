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

void append(int a[],int n)
{
    struct node *p;
    for(int i=0;i<n;i++)
    {
        p=create();
        p->data=a[i];
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
    int a[]={9,0,4,5,6,7,0,0,6,4},n;
    n=sizeof(a)/sizeof(a[0]);
    append(a,n);
    display();

    return(0);
}


