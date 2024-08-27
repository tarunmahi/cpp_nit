#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node (int val) : data(val),next(nullptr){};
};

class LList{
    public:
    Node*head=nullptr;
    void insertatbig(int val){
          Node * node=new Node(val);
        if(!head){
            node->next=head;
            head=node;
            return;
        }
      
        node->next=head;
        head=node;
    }
    void insertatend(int val){
        Node* node= new Node(val);
        if(!head){
            insertatbig(val);
            return;
        }
        Node*temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=node;
    }
    void insertatpos(int val,int pos){
        Node*node=new Node(val);
        Node*temp=head;
        int  count=1;
        if(pos==0){
            node->next=head;
            head=node;
            return;
        }
        if(pos==1){
            Node*te=head;
            node->next=te->next;
            te->next=node;
            return;
        }
        Node*te;
        while(temp){
            if(count==pos-1){
                te=temp->next;
                node->next=te;
                temp->next=node;
            }
            count++;
            temp=temp->next;
        }
    }
    void print(){
        Node*temp=head;
        while(temp){
            cout<<temp->data<<" --> ";
            temp=temp->next;
            
        }
    }
    int length(){
        Node*temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void delfrobig(){
        if(!head){
            return;
        }
        if(!head->next){
            Node*tmp=head;
            head=nullptr;
            delete tmp;
        }
        Node*tmp=head;
        head=tmp->next;
        delete tmp;
    }
    void delfromend(){
        if(!head || !head->next){
            delfrobig();
            return;
        }
        Node*temp=head;
        while(temp->next->next){
            temp=temp->next;
        }
        Node*val=temp->next;
        temp->next=nullptr;
        delete val;
        
    }
    void delatpos(int pos){
        if(pos<0 || pos>length()){
            throw invalid_argument("irregular value given");
        }
        if(pos==0){
            Node*tmp=head;
            head=head->next;
            delete tmp;
            return;
        }
        if(pos==1){
            Node*tmp=head;
            Node*te=tmp->next;
            Node*val=te->next;
            tmp->next=val;
            delete te;
            return;
        }
        Node * tmp=head;
        Node*curr,*nxt;
        int count=0;
        while(tmp){
            if (count==pos-1){
              curr=tmp->next;
              nxt=curr->next;
              tmp->next=nxt;
              delete curr;
            }
            count++;
            tmp=tmp->next;
        }
    }
    void revers(){
        Node*tmp=head,*prev=nullptr,*nxt=nullptr;
        while(tmp){
            nxt=tmp->next;
            tmp->next=prev;
            prev=tmp;
            tmp=nxt;
        }
        head=prev;   //arrange the prev value to the head since the head points the entire list not the other way around
    }
    void findmiddle(){
        Node*slow=head;
        Node*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<endl;
        cout<<"the middle value is "<<slow->data;
    }
    void detectcycle(){
        Node*slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"has cycle";
            }
        }
        cout<<"doesnt have a cycle";
    }
     void removecycle(){
        Node*slow=head,*fast=head;
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=nullptr;

     }
    void removedup(){
        unordered_set<int> vec;
        Node*prev,*curr=head;
        while(curr){
           if(vec.find(curr->data)!=vec.end()){
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
           }
           else{
            vec.insert(curr->data);
            prev=curr;
            curr=curr->next;
           }
        }cout<<endl;
    }
   bool ispalindrome(){
    Node*slow=head,*fast=head,*prev,*temp;
    while(fast &&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    prev=slow;
    slow=slow->next;
    prev->next=nullptr;
    while(slow){
        temp=slow->next;
        slow->next=prev;
        prev=slow;
        slow=temp;
    }
    fast=head;
    slow=prev;
    while(slow){
        if(fast->data!=slow->data)return false;
        slow=slow->next;
        fast=fast->next;
    }
    return true;

   }
};

int main(){
     LList *list = new LList;
    //  list->insertatbig(1);
    //  list->insertatbig(56);
    //  list->insertatbig(100);
    //  list->insertatend(44);
    //  list->insertatpos(23,1);
    //  list->insertatpos(11,0);
    //  list->insertatpos(55,5);
    //  list->insertatend(55);
    //  list->print();
    //  cout<<endl;
    // //  list->delfrobig();
    // //  list->delfromend();
    //  //list->delatpos(6);
    //  list->revers();
    //  list->print();
    //  list->findmiddle();
    //  list->detectcycle();
    //  list->removedup();
    //  list->print();
    list->insertatbig(1);
    // list->insertatbig(34);
    // list->insertatbig(9);
    // list->insertatbig(9);
    // list->insertatbig(34);
    list->insertatbig(1);
     cout<<(list->ispalindrome()?"yeah palindrome":"Nope its not it...");

}