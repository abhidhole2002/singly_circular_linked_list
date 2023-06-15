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
        for(temp = head;temp->next!=head;temp = temp->next){}
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
            temp = temp->next;

            if(temp == head)
            {
                break;
            }
        }
    }

    void gethead()
    {
        cout<<"HEAD = "<<head->data<<endl;
    }

    void gettail()
    {
        slist* tail;
        for(tail = head;tail->next!=head;tail = tail->next)
        {}
        cout<<"TAIL = "<<tail->data<<endl;
    }

    int search(int x)
    {
        slist* temp;
        int c = 0;

        for(temp = head;(temp!=head || c==0);temp = temp->next)
        {
            if(temp->data == x)
            {
                return 1;
            }
            c++;
        }

        return -1;

    }

  

    slist* odd_even(slist* odd,slist* even)
    {
        int c = 0;
        for(slist* temp = head;(temp!=head || c == 0);temp = temp->next)
        {
            if(temp->data%2==0)
            {
                even->addhead(temp->data);
            }
            else
            {
                odd->addhead(temp->data);
            }

            c++;
        }

    }
};
 
int main()
{
    slist obj(0);

    obj.addhead(10);
    obj.addhead(100);
    obj.addhead(1);
    obj.addhead(9);
    obj.addhead(13);
    obj.print();
    cout<<endl;
    obj.gethead();
    obj.gettail();
    cout<<obj.search(13);

    cout<<endl;

    slist odd(0);
    slist even(0);

    obj.odd_even(&odd,&even);

    odd.print();
    cout<<endl;
    even.print();
    cout<<endl;
    obj.print();

}