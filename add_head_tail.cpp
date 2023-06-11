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
      slist* newnode = new slist(x);
      newnode->next = NULL; 

      if(head == NULL) {
        head = newnode;
        newnode->next = head;
        return ;
      } 
        slist* temp;
        for(temp = head;temp->next != head;temp = temp->next)
        {}
        temp->next = newnode;
        newnode->next = head;
        head = newnode;

    }

    void addtail(int x)
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
            for(temp = head;temp->next!=head;temp=temp->next)
            {}
            temp->next = newn;
            newn->next = head;
    }

    void print()
    {
        slist* temp = head;
        while (true)
        {
            cout << temp->data << " ";
            temp = temp->next;

            if (temp == head)
            {
                break;
            }
        }
    }

    slist* gethead()
    {
        return head;
    }

    slist* gettail()
    {
        slist* temp;
        for(temp= head;temp->next!=head;temp=temp->next)
        {}
        return temp;
    }

    int getdata()
    {
        return data;
    }
};
 
int main()
{
    slist obj(0);
    obj.addhead(10);
    obj.addhead(11);
    obj.addhead(12);
    obj.addtail(10);
    obj.addtail(11);
    obj.addtail(100);
    obj.print();
    cout<<endl;

    cout<<"head = "<< obj.gethead()->getdata()<<endl;
    cout<<"tail = "<<obj.gettail()->getdata()<<endl;
 
}