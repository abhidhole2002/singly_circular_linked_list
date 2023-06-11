#include<iostream>
using namespace std;

class slist
{
    //int data;
    //slist* head;
    //slist* next;

    public:
    int data;
    slist* head;
    slist* next;
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

        if(head ==  NULL)
        {
            head = newn;
            newn->next = head;
            return;
        }

        slist* temp;
        for(temp=head;temp->next!=head;temp=temp->next){}
        temp->next = newn;
        newn->next = head;
        head = newn;
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
        slist* tail;
        for(tail = head;tail->next!=head;tail=tail->next){}
        return tail;
    }

    int getdata()
    {
        return data;
    }

    void print()
    {
        slist* temp = head;
        while(true)
        {
            cout<<temp->data<<" ";
            temp = temp->next;

            if(temp == head)
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
    obj.addhead(11);
    obj.addhead(12);
    obj.addhead(13);
    obj.add_at_any(5,100);
    obj.print();

    //cout<<endl<<"HEAD = "<<obj.gethead()->getdata()<<endl;
    //cout<<"TAIL = "<<obj.gettail()->getdata()<<endl;
    cout<<endl<<"HEAD = "<<obj.gethead().data<<endl;
    cout<<"TAIL = "<<obj.gettail()->data<<endl;

}