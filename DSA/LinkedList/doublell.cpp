#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*prev;
    Node*next;
    Node(int dat ) :data(dat),prev(nullptr),next(nullptr){}; 
};
class Dlist{
    public:
    Node* head=nullptr;
    void insertatbig(int val){
        Node*node=new Node(val);
        if(!head){
            node->next=head;
            head=node;
            return;
        }
        node->next=head;
        head->prev=node;
        node->prev=nullptr;
        head=node;
    }
    void insertatend(int val){
        Node*temp=head;
        if(!head){
            insertatbig(val);
            return;
        }
        while(temp->next){
            temp=temp->next;
        }
        Node*node=new Node(val);
        node->prev=temp;
        temp->next=node;
    }
    void insertatpos(int pos,int val){
        if(pos<0 || pos>length()){
            throw invalid_argument("not in a possible range");
        }
        Node*temp=head;
        int count=0;
        Node*pre,*nxt;
        Node*node=new Node(val);
        if (pos==0){
            head->prev=temp;
            node->next=head;
            head=node;
            return;
        }
        if(pos==1){
            Node*tmp=temp->next;
            node->next=tmp;
            tmp->prev=node;
            node->prev=head;
            head->next=node;
            return;
        }
        while(temp){
            if(count==pos-1){
            Node*tmp=temp->next;
              node->prev=temp;
              node->next=tmp;
              tmp->prev=node;
              temp->next=node;
            }
            count++;
            temp=temp->next;
        }
    }
    void print(){
        Node*temp=head;
        while(temp){
            cout<<temp->data<<" -->";
            temp=temp->next;
        }
    }
    void deletfrobig(){
        Node*tmp=head;
        tmp->next->prev=head;
        head=head->next;
        delete tmp;
        cout<<endl;
    }
    void deletfromend(){
        if(!head||!head->next)deletfrobig();
        Node*temp=head;
        while(temp->next->next){
            temp=temp->next;
        }
        Node*tmp=temp->next;
        temp->next=nullptr;
        delete tmp;
    }
    int length(){
        int count=0;
        Node*temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void deleteatpos(int pos){
        Node*temp=head;
      if (pos<0 || pos>length())throw invalid_argument("values not in possible range");
      if(pos==0){
        deletfrobig();
        return;
        }
      if(pos==1){
        Node*tmp=temp->next;
        temp->next=tmp->next;
        tmp->next->prev=temp;
        delete tmp;
        return;
      }
      int count=0;
      while(temp){
        if(count==pos-1){
            Node*tmp=temp->next;
            temp->next=tmp->next;
            tmp->next->prev=temp;
            delete tmp;
        }
        count++;
        temp=temp->next;
      }
      cout<<endl;
      
    }
    void reverse(){
        Node*temp=head;
        while(temp->next)temp=temp->next;
        while(temp){
            cout<<temp->data<<" --> ";
            temp=temp->prev;
        }

    }
};
int main(){
    Dlist *dlist = new Dlist;
    dlist->insertatbig(23);
    dlist->insertatbig(70);
    dlist->insertatend(1);
    dlist->insertatbig(56);
    dlist->insertatpos(3,2);
    dlist->print();
    // dlist->deletfrobig();
    // dlist->deletfromend();
    // dlist->deleteatpos(3);
    cout<<endl;
    dlist->reverse();
    cout<<endl;
    dlist->print();
}