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

        if(head == NULL)
        {
            head = newn;
            newn->next = head;
            return;
        }

        slist* temp;
        for(temp=head;temp->next!=head;temp=temp->next){}

        newn->next = head;
        temp->next = newn;
        head = newn;

    }

    void print()
    {
        slist* temp = head;
        while(true)
        {
            cout<<temp->data<<" ";
            temp=temp->next;

            if(temp==head)
            {
                break;
            }
        }
    }

    void add_at_any(int pos,int x)
    {
        slist* newn = new slist(x);
        newn->next = NULL;

        if(pos==1)
        {
            addhead(x);
            return;
        }

        else
        {
            slist* temp = head;
            for(int i=1;i<pos-1;i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;
        }
    }

    slist* gethead()
    {
        return head;
    }

    slist* gettail()
    {
        slist* temp;
        for(temp=head;temp->next!=head;temp=temp->next)
        {}

        return temp;
    }

    int getdata()
    {
        return data;
    }

       void rev()
       {
    
        slist* prev = nullptr;
        slist* curr = head;
        slist* nextNode = nullptr;

        do {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        } while (curr != head);

        // Adjust the head pointer
        curr->next = prev;
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
    obj.add_at_any(5,100);
    obj.print();

    cout<<endl;

    cout<<"HEAD = "<<obj.gethead()->getdata()<<endl;
    cout<<"TAIL = "<<obj.gettail()->getdata()<<endl;
}