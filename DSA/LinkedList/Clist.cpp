#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int data):data(data),next(nullptr){};
};
class CList{
    public:
    Node*head=nullptr;
    Node*tail=nullptr;  //for accessing the last element in the linked list 
    void insertatbig(int val){
        Node*node=new Node(val);
        if(!head){
            head=node;
            tail=node;
            tail->next=head;
            return;
        }
        node->next=head;
        head=node;
        tail->next=head;
    }
    void insertatend(int val){
        Node*node=new Node(val);
        if(!head){
            insertatbig(val);
            return;
        }
        tail->next=node;
        tail=node;
        tail->next=head;
    }
    void print(){
        Node*temp=head;
        do{
            cout<<temp->data<<" -->";
            temp=temp->next;
        }
        while(temp!=head);
    }
    void deletefrombig(){
        Node*temp=head;
        head=head->next;
        tail->next=head;
        delete temp;
    }
    void deletefromend(){

    }

};
int main(){
CList *list=new CList;
list->insertatbig(24);
list->insertatbig(67);
list->insertatend(45);
// list->deletefrombig();
list->print();
}