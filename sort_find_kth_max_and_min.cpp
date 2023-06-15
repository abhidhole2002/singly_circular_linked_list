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

    void sort_and_kth_max_min(int k)
    {
        slist* temp;
        slist* curr = NULL;
        int count = 0;
        int max = 0;

        for(temp = head;(temp!=head || count<k);temp = temp->next)
        {
            for(curr = temp->next;curr!=head;curr = curr->next)
            {
                if(temp->data < curr ->data)
                {
                    int tempdata = temp->data;
                    temp->data = curr->data;
                    curr->data = tempdata;
                }
            }

            count++;
            if(count == k)
            {
                max = temp->data;
                break;
            }
        }

        cout<<k<<" th "<<"MAX = "<<max<<endl;
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
    obj.addhead(100);
    obj.addhead(1);
    obj.addhead(13);
    obj.print();
    cout<<endl;
    obj.sort_and_kth_max_min(4);
    obj.print();
 
 
}