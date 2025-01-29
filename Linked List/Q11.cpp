#include<iostream>
#include "SLL.cpp"
#include<stack>
using namespace std;

Node*ReverseBlockOfKnodes(Node*head,int k){
    int k_dup=k;
    Node*cur=head;
    stack<Node*> recur;
    // Loop for k times
    // Check if the list has enough items to reverse the segment
    // If it doesn't then return the original head since the segment didn't change
    // Else keep pushing everything onto a stack so we can reverse later.
    while(k_dup--){
        if(cur==nullptr) return head;
        recur.push(cur);
        cur=cur->next;
    }
    // Pre-store the new head so we can return it at the end.
    auto new_head=recur.top();

    // For all non-ending nodes, reverse the pointer to the one below it in the stack i.e behind in the list
    while(recur.size()!=1){
        auto forward=recur.top();
        recur.pop();
        auto back=recur.top();
        forward->next=back;
    }

    // For the ending node, recursive k-reverse the next segment and concate it.
    recur.top()->next=ReverseBlockOfKnodes(cur,k);
    // Return the new head of the reversed segment.
    return new_head;
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