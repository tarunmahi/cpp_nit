#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int dat) : data(dat), next(nullptr){}; 
};
class LList{
    
    public:
    Node* head=nullptr;

    void insertatbig(int data){
        Node* node = new Node(data);
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
        Node*temp=head;
        if(!head){
            node->next=head;
            head=node;
            return;
        }
        while(temp->next){
            temp=temp->next;
        }
        temp->next=node;
        node->next=nullptr;
    }
    void insertatpos(int val,int pos){
        Node*tmp=head;
        Node* prev;
        Node*nxt;
        Node* node = new Node(val);
        if(pos<0 || pos>counnt()){
            throw invalid_argument("givenis a negative integer ");
        }
        int count=0;
        if (pos==0){
            node->next=head;
            head=node;
            return;
        }
        while(tmp){
            if(count==pos-1){
              nxt=tmp->next;
              tmp->next=node;
              node->next=nxt;
            }
            tmp=tmp->next;
            count++;
        }
    }
  
    void print(){
      Node* temp=head;
      while(temp){
        cout<<temp->data<<"-->";
        temp=temp->next;
      } 
    }
    ~LList(){
        cout<<"the entire values are deallocated";
    }
  int counnt(){
        int count=0;
        Node*temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }
   void deletfromb(){
    Node*temp=head;
    if(!head){
        return;
    }
    if(!head->next){
        head=nullptr;
        return;
    }
    head=head->next;
    delete temp;
   }
   void deleteffrome(){
    Node* temp=head;
    if(!head){
      return;
    }
    if(!head->next){
        head=nullptr;
        return;
    }
    while(temp->next->next){
        temp=temp->next;
    }

    delete(temp->next);
    temp->next=nullptr;
   }
   void deletefrompos(int pos){
   if (!head){
    return;
   }
   if(pos<0 || pos>counnt()){
    throw invalid_argument("given range is not correct");
   }
   if(pos==0){
    Node*temp=head;
    head=head->next;
    delete temp;
    return;
   }
   if(!head->next){
    head=head->next;
    return;
   }
   int count=0;
   Node*temp=head;
   Node*nxt;
   while(temp){
    if(count==pos-1){
        nxt=temp->next;
        temp->next=nxt->next;
        delete nxt;
    }
    temp=temp->next;
    count++;
   }
}
void reversee(){
    Node *curr=head,*prev=nullptr,*nxt=nullptr;
    while(curr){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;  //change the head value later to start the print iteration
}
int middle(){
    if(!head){
        return -1;
    }
    if(!head->next){
        return head->data;
    }
    Node* slow=head,*fast=head;
    while (fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
    
}
bool detectcycle(){
    Node *slow=head,*fast=head;
    if(!head){
        return false;
    }
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
        }return false;
    }
   void removecycle(){
    Node* slow=head,*fast=head;
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
    void remdup(){
        Node*temp=head,*prev;
        unordered_set<int> vec;
        while(temp){
        if(vec.find(temp->data)!=vec.end()){
            prev->next=temp->next;
            delete temp;
            temp=prev->next;
        }
        else{
            vec.insert(temp->data);
            prev=temp;
            temp=temp->next;
        }}


    }
    bool isplaindrome(){
        Node*slow=head,*fast=head,*curr,*prev=nullptr,*nxt;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        curr=slow;
        while(curr){
          nxt=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nxt;
        }
        Node*fhalf =head;
        Node*shalf=prev;
        while(shalf){
            if(fhalf->data!=shalf->data)return false;
            fhalf=fhalf->next;
            shalf=shalf->next;
            cout<<"hello";
        }
        return true;

    }

};
int main(){
LList* val = new LList;
val->insertatbig(1);
val->insertatbig(8);
val->insertatend(90);
val->insertatbig(67);
val->insertatend(50);
val->insertatpos(56,2);
val->insertatpos(2,1);
//val->print();
val->insertatend(1);
val->deletfromb();
val->deletefrompos(1);
val->insertatend(87);
//val->deleteffrome();
// cout<<endl;
// val->print();
// cout<<endl;
// cout<<val->middle();
// cout<<endl;
// //cout<<val->detectcycle();
// //val->reversee();
// val->print();
//has to do remove a cyle from linked list
val->print();
cout<<endl;
val->remdup();
val->print();
cout<<endl;
cout<<(val->isplaindrome()?"True":"false");
delete val;

};