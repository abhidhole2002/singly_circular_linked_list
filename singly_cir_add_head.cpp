#include<iostream>
using namespace std;

class slist
{
    int data;
    slist* head;
    slist* next;

    public:
    slist(int data)
    {
        this->data = data;
        this->head = NULL;
        this->next = NULL;
    }

    void addhead(int x)
    {
        slist* newn = new slist(x);
        newn->next = NULL;

        if(head==NULL)
        {
            head = newn;
            newn->next = head;
        }

        else
        {
            slist* temp;
            for(temp = head;temp->next!=head;temp=temp->next){}
            temp->next = newn;
            newn->next = head;
            head = newn;

        }
    }

    void print()
    {
        for(slist* temp = head;temp!=NULL;temp=temp->next)
        {
            cout<<temp->data<<" ";
            if(temp->next== head)
            {
                break;
            }
        }   
    }

};
 
int main()
{
    slist obj(0);
    obj.addhead(10);
    obj.addhead(20);
    obj.addhead(30);
    obj.addhead(40);
    obj.print();

 
 
}