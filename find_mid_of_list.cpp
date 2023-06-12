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
        for(;;)  // we can use  "while(true)" in place of for(;;)
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
        slist* temp ;

        for(temp=head;;temp = temp->next) // we can use  "while(true)" in place of for(;;)
        {
            cnt++;
            if(temp->next==head)
            {
                break;
            }
        }

        return cnt;
    }

    slist* mid_class()
    {
        slist* slow = head;
        slist* fast = head;

        while(fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    int mid_int()
    {
        slist* slow = head;
        slist* fast = head;

        while(fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        /* 
            if list = 1 2 3 4 (even list)---> then print middle 3
            if list 1 2 10 4 5 (odd  list)---> then print middle 10
        */

       if(count()%2==0)
       {
        slow = slow->next;
       }

        return slow->data;
    }

    int getdata()
    {
        return data;
    }

    void reverse()
    {
        slist* prev =NULL;
        slist* curr = head;
        slist* nxt = NULL;

        
        do 
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        while(curr!=head);

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
    //obj.addhead(14);

    cout<<"ORIGINAL list ==>> ";
    obj.print();
    cout<<endl;

    cout<<"TOTAL NODES IN LIST = "<<obj.count()<<endl;
    cout<<"MIDDLE OF LIST = "<<obj.mid_class()->getdata()<<endl;
    cout<<"MIDDLE OF LIST = "<<obj.mid_int()<<endl;

    cout<<"AFTER REVERSED ==> ";
    obj.reverse();
    obj.print();
   
}