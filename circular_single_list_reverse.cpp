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
            return;
        }

        
        slist* temp;
        for(temp = head;temp->next!=head;temp=temp->next){}
        temp->next = newn;
        newn->next = head;
        head = newn;
        
    }

    void print()
    {
        slist* temp = head;
        while(true)
        {
            cout<<temp->data<<" ";
            temp = temp->next;

            if(temp==head)
            {
                break;
            }
        }
    }

    void rev()
    {
        slist* prev = NULL;
        slist* curr = head;
        slist* nxt = NULL;

        do
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        } while (curr!=head);

        curr->next = next;
        head = prev;
        
    }
};
 
int main()
{
    slist obj(0);
    
    obj.addhead(10);
    obj.addhead(11);
    obj.addhead(12);
    obj.addhead(13);
    obj.print();

    cout<<endl;
    obj.rev();
    obj.print();
 
 
}