#include<iostream>
using namespace std;

class slist
{
    slist* head;
    slist* next;
    int data;

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
        newn->next = head;
        temp->next = newn;
        head = newn;
    }

    void print()
    {
        slist* temp = head;
        for(;;)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
            if(temp==head)
            {
                break;
            }
        }
    }

    int count()
    {
        int cnt = 0;
        slist* temp = head ;

        for(;;)
        {
            cnt++;
            temp=temp->next;
            if(temp==head)
            {
                break;
            }
        }

        return cnt;
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

    cout<<"TOTAL NODES IN LIST = "<<obj.count();
}