#include<iostream>
#include "SLL.cpp"
using namespace std;

Node*getnthElement(Node*head,int k){
    while(k--){
        head=head->next;
    }
    return head;
}

bool hasKElements(Node*head,int k){
    k--;
    while(k--){
        if(head==NULL) return false;
        head=head->next;
    }
    return true;
}

Node*ReverseBlockOfKnodes(Node*head,int k){
    if(k==0 || k==1) return head;
    Node*cur=head;
    if(hasKElements(cur,k)){
        Node*newHead=getnthElement(cur,k-1);
        Node*prevNode=ReverseBlockOfKnodes(newHead->next,k);
        Node*nextNode=cur->next;
        for(int i=0;i<k;i++){
            cur->next=prevNode;
            prevNode=cur;
            cur=nextNode;
            if(nextNode!=NULL) nextNode=nextNode->next;
        }
        return newHead;
    }else{
        return head;
    }
}

int main(){
    for(int k=2;k<=4;k++){
        SinglyLinkedList SLL;
        for(int i = 1; i <= 10; i++){
            SLL.insertAtEnd(i);
        }
        SLL.head=ReverseBlockOfKnodes(SLL.head,k);
        SLL.print();
    }
    return 0;
}