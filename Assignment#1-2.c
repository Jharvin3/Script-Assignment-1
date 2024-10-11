#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int num;
struct node* next;
} node;

int whatDoesItDo(node *head){
    node *current = head;
    while(current != NULL){//Transversing through the list while printing out the number
        printf("%d->", current->num); 
        current = current->next;
    }

    //Another way of sloving this problem(for practice later)
    /*if(head == NULL){
        return 0;
    }
    node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return 1;
        }
    }*/

    return 0;
}

//Node Creation Function
node *create_node(int num){
    node *new_node = (node*)malloc(sizeof(node)); //Dynamically allocating memory for new node
    new_node->num = num;
    new_node->next = NULL;
    return new_node;
}

//Insert Node Function
void insert_node(node **head, int num){
    node *new_node = create_node(num);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    node *current = *head;
    while(current->next != NULL){ //while the next node after current is not NULL then we transverse through the list
        current = current->next;
    }
    current->next = new_node;
} 

int main(){
    node *list_1 = NULL; //Empty list
    node *list_2 = create_node(3); //One node list
    node *list_3 = NULL;
    for(int i = 0; i <= 1; ++i){
        insert_node(&list_3, i + 6);//Two node list
        }
    node *list_4 = NULL;
    for(int i = 0; i < 3; ++i){
        insert_node(&list_4, i * 3); //Odd number of nodes
    }
    node *list_5 = NULL;
    for(int i = 0; i < 4; ++i){
        insert_node(&list_5, i + 3); //Even number of nodes
    }

    //Showing each edge cases
    printf("List 1: ");
    whatDoesItDo(list_1); //Empty
    printf("\nList 2: ");
    whatDoesItDo(list_2); //One NOde
    printf("\nList 3: ");
    whatDoesItDo(list_3); //Two Nodes
    printf("\nList 4: ");
    whatDoesItDo(list_4); //Odd Nodes
    printf("\nList 5: ");
    whatDoesItDo(list_5); //Even Nodes
    printf("\n");

    //Freeing dynamically allocated memory
    free(list_1);
    free(list_2);
    free(list_3);
    free(list_4);
    free(list_5);

    return 0;
}