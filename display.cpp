
#include <cstdlib>
#include <iostream>
// #include <stdio.h>
using namespace std;
void createnode(struct node *head);
void displaylist(struct node *head );
int node_count(struct node *head );
int sum_node(struct node *head );
void search_list(struct node *head);
void sort_list(struct node *head);
void merge(struct node *head1, struct node *head2);
void dispdouble(struct node *head);
void createDouble(struct node * head);
void createLoop(struct node *head ) ;
struct node  {
    int data ; 
    struct node *next ; 

};

int main(){
 struct node *head1 , *head2;
 head1 = (struct node *)malloc(sizeof(struct node));

}
 // creating a linked list 
void createnode(struct node *head){
    struct node *newnode , *traverse  ; 
    head = (struct node *)malloc(sizeof(struct node) );

    int data ,count ; 
    cout<<"enter number of node ";
    cin>>count;
    cout<<"enter data of node 1 ";
    cin>>data;
    head->data = data ;
    head->next = NULL;
    traverse = head; 
    
    int i ; 
    for(i =2;i<=count;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        cout<<"enter data for node "<<i;
        cin>>data;
        newnode->data = data;
        newnode->next = NULL;
        traverse->next = newnode;
        traverse =  traverse->next ;

    }
    
}
// creating a display linked list
void displaylist(struct node *head ){
    struct node *traverse;
    traverse = head ; 
    while(traverse!= NULL){
        cout<<traverse->data<<endl;
        traverse = traverse->next ;
    }                                               
}

int node_count(struct node *head){
int count = 0 ; 
while(head!=NULL){                          
    count++;
    head = head->next ; 

}
return count ; 
}
//  summing the elments of linked list 
int sum_node(struct node *head ){

    int sum = 0 ; 
    struct node *traverse ;
    traverse = head ;  
    while(traverse != NULL){
     sum  = sum + traverse->data ;
     traverse = traverse->next   ; 
     
    }
    return sum ; 
}
//  searching the elements in linked list
void search_list(struct node *head){
    struct node *traverse  , *p1 ; 
    int x , i ; 
    cout<<"Enter number to search for ";
    cin>>x ; 

    if(head== NULL ){
        cout<<"memory not allocated "<<endl;
        return;
    }
    traverse = head ; 
 int y = node_count(head);
 for(i= 1;i<= y ; i++){
    if(traverse->data==x){
        cout<<"element found at node"<< i;
    }
    traverse = traverse->next;
  }

}
//  sorting the elements in increasing linked list
void sort_list(struct node *head){
    struct node *current , *index  ;
    int temp;

    current = head ;    
    index =  NULL;

    if(head==NULL){
        cout<<"NULL"<<endl;
        return;
    }           

    while(current!=NULL){
        index = current->next;

        while(index!=NULL){
            if(current->data > index->data){
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index =index->next;
        }
        current = current->next;

    }
}

//  merging the linked list 
void merge(struct node *head1, struct node *head2) {
    sort_list(head1);
    sort_list(head2);

    struct node *tmp, *last;
    struct node *merged_head = NULL; // Initialize the merged list head to NULL

    if (head1->data < head2->data) {
        last = tmp = head1;
        head1 = head1->next;
        last->next = NULL;
    } else {
        last = tmp = head2;
        head2 = head2->next;
        last->next = NULL;
    }

    merged_head = tmp; // Set the merged list head to the correct node

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            last->next = head1;
            last = head1;
            head1 = head1->next;
            last->next = NULL;
        } else {
            last->next = head2;
            last = head2;
            head2 = head2->next;
            last->next = NULL;
        }
    }

    // Handle the case where there are remaining nodes in either head1 or head2
    if (head1 != NULL) {
        last->next = head1;
    } else {
        last->next = head2;
    }

    // Return the merged list head (if needed)
    // return merged_head; (if required in your use case)
}

// program to create double ll 
void createDouble(struct node * head){
    struct node *tr;
    tr = head ; 
    while(tr->next !=NULL){
        tr = tr->next ; 

    }
    tr->next = head ; 

}
// program to display double linked list    // 
void dispdouble(struct node *head){
   struct node *traverse ; 
   traverse = head;
   do{
    cout<<traverse->data;
    traverse = traverse->next;
   }while(traverse != head );
   cout<<head->data<<"\n";
}

void createLoop(struct node *head ) {
    struct node *traverse , *store_node ; 
     int pos ,  count = 1 ,x ; 
     x= node_count(head);
    cout<<"enter the position";
    cin>>pos;
    if(pos > x ){
        return ; 

    } 
    traverse = head ; 
    while(count< pos){
       traverse =  traverse->next ;
       count++ ; 

    }
    store_node = traverse ; 
    while(traverse->next!=NULL){
        traverse = traverse->next;

    }
    traverse->next = store_node  ;

}




