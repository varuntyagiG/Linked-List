#include<iostream>
#include<vector>
using namespace std;

class Node{
       public:
       int data;
       Node* next;

       Node(int data){
              this->data = data;
              this->next = NULL;
       }

       ~Node(){
              cout << "Deleted " << this->data << endl;
       }
};

int linkedListLength(Node* Head){
       Node* temp = Head;
       int l = 0;
       while(temp != nullptr){
              temp = temp->next;
              l += 1;
       }
       return l;
}

void insertAtTail(Node* &Head,Node* &Tail,int data){
       Node* newNode = new Node(data);

       Tail->next = newNode;

       Tail = newNode;
}

void insertAtHead(Node* &Head,Node* &Tail,int data){
       if(Head == NULL){
              Node* newNode = new Node(data);
              Head = newNode;
              Tail = newNode;
       }else{
              Node* temp = new Node(data);

              temp->next = Head;

              Head = temp;
       }
}

void print(Node* Head){
       Node* temp = Head;
       while(temp != NULL){
              cout << temp->data << " ";
              temp = temp->next;
       }
       cout << endl;
}

void insertAtPostition(Node* &Head,Node* Tail,int pos,int data){
       if(pos == 0){
              insertAtHead(Head,Tail,data);
              return;
       }

       int len = linkedListLength(Head);
       if(pos >= len){
              insertAtTail(Head,Tail,data);
              return;
       }

       int i = 1;
       // 1-step
       Node* prev = Head;
       while(i < pos){
              prev = prev->next;
              i += 1;
       }
       Node* curr = prev->next;

       // step 2
       Node* newNode = new Node(data);

       // step 3
       newNode->next = curr;
       prev->next = newNode;
}

void deleteNode(Node* &Head,Node* &Tail,int pos){
       if(pos == 1){
              Node* temp = Head;
              Head = Head->next;
              temp->next = nullptr;
              delete temp;
              return;
       }

       int len = linkedListLength(Head);

       if(pos == len){
              Node* prev = Head;
              int i = 1;
              while(i < (pos - 1)){
                     prev = prev->next;
                     i++;
              }
              Node* temp = Tail;
              Tail = prev;
              prev->next = nullptr;
              delete temp;
              return;
       }

       // at any position
       int j = 1;
       Node* previos = Head;
       while(j < (pos - 1)){
              previos = previos->next;
              j++;
       }
       
       Node* currNext = previos->next->next;

       Node* temmp = previos->next;

       previos->next = currNext;

       temmp->next = nullptr;

       delete temmp;

}

int main(){
       Node* Head = NULL;
       Node* Tail = NULL;

       // insert at Head
       insertAtHead(Head,Tail,50);
       insertAtHead(Head,Tail,40);
       insertAtHead(Head,Tail,30);
       insertAtHead(Head,Tail,20);
       insertAtHead(Head,Tail,10);

       // insert at Head
       insertAtTail(Head,Tail,60);
       insertAtTail(Head,Tail,70);
       insertAtTail(Head,Tail,80);
       insertAtTail(Head,Tail,90);
       insertAtTail(Head,Tail,100);
       print(Head);     
       cout << endl;

       // insert At any Position
       // insertAtPostition(Head,Tail,50,999);

       deleteNode(Head,Tail,2);


       print(Head);       
       return 0;
}