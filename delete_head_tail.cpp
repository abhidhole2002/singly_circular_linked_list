#include<iostream>
using namespace std;

class slist
{
    int data;
    slist* next;

public:
    slist(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    void addhead(int x, slist* &head)
    {
        slist* newn = new slist(x);
        newn->next = NULL;

        if (head == NULL)
        {
            head = newn;
            newn->next = head;
            return;
        }

        slist* temp;
        for (temp = head; temp->next != head; temp = temp->next) {}
        temp->next = newn;
        newn->next = head;
        head = newn;
    }

    void print(slist* head)
    {
        slist* temp = head;
        for (; ; temp = temp->next)
        {
            cout << temp->data << " ";
            if (temp->next == head)
            {
                break;
            }
        }
    }

    void delete_head(slist* &head)
    {
        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            slist* prev = head;
            slist* temp;

            for (temp = head; temp->next != head; temp = temp->next) {}
            head = head->next;
            temp->next = head;
            delete prev;
            prev = NULL;
        }
    }

    void delete_tail(slist* head)
    {
        if(head->next==head)
        {
            delete head;
            head = NULL;
        }

        else
        {
            slist* temp;
            for(temp = head;temp->next->next!=head;temp = temp->next)
            {}
            slist* delnode = temp->next;
            temp->next = head;
            delete delnode;
            delnode = NULL;

        }
    }

    int gethead(slist* head)
    {
        return head->data;
    }

    int gettail(slist* head)
    {
        slist* temp = head;
        for(temp = head;temp->next!=head;temp=temp->next){}
        return temp->data;
    }

    int getdata()
    {
        return data;
    }
};

int main()
{
    slist obj(0);

    slist* head = NULL;
    obj.addhead(1,head);
    obj.addhead(2,head);
    obj.addhead(3,head);
    obj.addhead(4,head);

    cout<<"ORIGINAL LIST ==>> ";
    obj.print(head);
    cout << endl;

    cout<<"AFTER DELETING HEAD ==>> ";
    obj.delete_head(head);
    obj.print(head);

    cout<<endl<<"AFTER DELETING TAIL ==> ";
    obj.delete_tail(head);
    obj.print(head);

    cout<<endl<<"HEAD = "<<obj.gethead(head);
    cout<<endl<<"TAIL = "<<obj.gettail(head);

    return 0;
}


