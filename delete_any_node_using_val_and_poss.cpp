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
        for(temp = head;temp->next!=head;temp = temp->next){}
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

    void delete_head()
    {
        if(head->next==head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            slist* temp = head;
            slist* prev = head;

            for(;temp->next!=head;temp = temp->next){}

            head = head->next;
            temp->next = head;
            delete prev;
            prev = NULL;
        }
    }

    void delete_val(int num)
    {
    
        if (head->data == num)
        {
            delete_head();
            return;
        }

        slist* temp;
        for(temp = head;temp->next != head;temp = temp->next)
        {
            if (temp->next->data == num)
            {
                slist* node = temp->next;
                temp->next = node->next;
                delete node;
                node = NULL;
                return;
            }  
        }
    }

    void delet_pos(int pos)
    {
        if(pos==1)
        {
            delete_head();
        }
        else
        {
            slist* prev = NULL;
            slist* curr = head;
            for(int i =1;i<pos;i++)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            delete curr;
            curr = NULL;
        }
    }

    int gethead()
    {
        return head->data;
    }

    int gettail()
    {
        slist* tail;
        for(tail = head;tail->next!=head;tail=tail->next){}
        return tail->data;
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
    //obj.delete_val(10);
    obj.delet_pos(2);
    obj.print();
    
    cout<<endl<<"HEAD = "<<obj.gethead();
    cout<<endl<<"TAIL = "<<obj.gettail()<<endl;    
}