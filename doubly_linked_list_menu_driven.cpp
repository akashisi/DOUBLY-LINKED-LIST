#include<iostream>
#include<stdlib.h>
using namespace std;
int getcount();
void append();
void add_at_head();
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;

struct node *create()
{
    return((struct node *)malloc(sizeof(struct node)));
};

void add_random_position()
{
    struct node *temp,*newnode;
    int i=0,l=0,p;
    l=getcount();
    cout<<"\nTotal number of nodes are :: "<<l;
    cout<<endl<<"Enter the position to add data :: ";
    cin>>p;
    if(p<1 || p>(l+1))
        cout<<endl<<"Invalid position\n";
    else if(p==(l+1))
        append();
    else if(p==1)
        add_at_head();
    else
    {
        newnode=create();
        newnode->prev=NULL;
        newnode->next=NULL;
        cout<<endl<<"Enter the data to add at given position :: ";
        cin>>newnode->data;
        temp=head;
        for(i=1;i<p-1;i++)
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next->prev=newnode;
    }
}

void add_at_head()
{
    struct node *temp,*newnode;
    temp=head;
    newnode=create();
    cout<<endl<<"Enter the data to add at head :: ";
    cin>>newnode->data;
    if(temp==NULL)
    {
        temp=newnode;
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        newnode->next=temp;
        temp->prev=newnode;
        newnode->prev=NULL;
        head=newnode;
    }
}
void append()
{
    struct node *newnode,*temp;
    temp=head;
    newnode=create();
    cout<<endl<<"Enter the data to add at end :: ";
    cin>>newnode->data;
    if(temp==NULL)
    {
        temp=newnode;
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }

}

void delete_head()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        cout<<endl<<"DOUBLY LINKED LIST IS EMPTY \n";
    else
    {
        int l=getcount();
        if(l==1)
        {
            head=NULL;
            return;
        }
        head=temp->next;
        head->prev=NULL;
        free(temp);
    }

}
void delete_last()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
        cout<<endl<<"DOUBLY LINKED LIST IS EMPTY \n";
    else if(temp->next==NULL)
        delete_head();
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
    temp->next=NULL;
    }
}
void delete_random()
{
    int p,i=0,l;
    struct node *temp,*ptr;
    temp=head;
    l=getcount();
    cout<<"\nTotal number of nodes are :: "<<l;
    cout<<endl<<"Enter the position of node to be deleted :: ";
    cin>>p;
    if(p<1 || p>l)
        cout<<"\n Invalid position \n";
    else if(temp==NULL)
        cout<<endl<<"DOUBLY LINKED LIST IS EMPTY \n";
    else if(p==1)
        delete_head();
    else if(p==l)
        delete_last();
    else
    {
        for(i=1;i<p;i++)
            temp=temp->next;
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
}
int getcount()
{
    struct node *temp;
    int c=0;
    temp=head;
    if(head==NULL);


    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return(c);
}
void display()
{
    struct node *temp;
    temp=head;

    if(temp==NULL)
        cout<<"\nDOUBLY LINKED LIST IS EMPTY\n";
    else
    {
        cout<<endl<<"CONTENT OF DOUBLY LINKED LIST :: \n";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

int main()
{
    int ch,c;
    while(1)
    {
        cout<<"\n1. ADD DATA AT END\n2. ADD AT ANY POSITION\n";
        cout<<"3. ADD AT HEAD\n4. DELETE HEAD NODE\n5. DELETE LAST NODE\n";
        cout<<"6. DELETE ANY RANDOM NODE\n";
        cout<<"7. TOTAL NUMBER OF NODES IN LIST\n8. DISPLAY\n9. EXIT\n";
        cout<<"Enter your choice :: ";
        cin>>ch;
        switch(ch)
        {
            case 1: append();
                    break;
            case 2: add_random_position();
                    break;
            case 3: add_at_head();
                    break;
            case 4: delete_head();
                    break;
            case 5: delete_last();
                    break;
            case 6: delete_random();
                    break;
            case 7: c=getcount();
                    cout<<"\nTotal Number of Nodes :: "<<c;
                    break;
            case 8: display();
                    break;
            case 9: exit(1);
            default:exit(1);
        }
    }
}
