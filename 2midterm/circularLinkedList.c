#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * addToEmpty (struct Node * last, int data){
    if (last != NULL)
        return last;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    last = newNode;
    last->next - last;
    return last;
}

struct Node *addFront(struct Node * last, int data){
    if(last == NULL) return addToEmpty(last, data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next=newNode;
    return last;
}

struct Node *addEnd(struct Node *last, int data) {
    if (last == NULL) return addToEmpty(last, data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    // last = newNode;
    // return last;
    return newNode;
}

struct Node * addAfter(struct Node* last, int data, int item){
    if(last == NULL) return addToEmpty(last, data);
    struct Node * newNode, *p;
    p = last->next;
    do{
        if(p->data == item){
            struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;
            if(p == last) last = newNode;
            return last;
        }
    }while(p!=last->next);
return last;
}

void deleteNode(struct Node** last, int key){
    if (*last==NULL) return;
    if ((*last)->data==key && (*last)->next == *last){
            free(*last);
            *last = NULL;
            return;
    }

    struct Node *temp = *last, *d;

    if((*last)->data==key){
        while(temp->next!=*last)temp=temp->next;
        temp->next=(*last)->next;
        free(*last);
        *last=temp;
    }
    while(temp->next!=*last && temp->next->data!=key) temp=temp->next;
    if(temp->next->data==key){
        d = temp->next;
        temp ->next=d->next;
        free(d);
    }
}
struct Node * createNode (int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
}

// Function to print the list
void printList(struct Node * first)
{
    struct Node * temp = first->next;
    struct Node * last = first;
    printf("Forward List: ");
    printf("%d", last->data);
    while (temp != last) {
        printf("%d ", temp->data);
        temp = temp->next;

    }
}


int main(){
    struct Node * first = createNode(1);
    struct Node * second = createNode(2);
    struct Node * third = createNode(3);

    first->next = second;
    second->next = third;
    third->next = first;
    
    printList(first);

}