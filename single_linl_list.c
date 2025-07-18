#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
  void create_list(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));  
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->link = NULL;
    if(*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while(current->link != NULL) {
            current = current->link;
        }
        current->link = new_node;
    }
}


int main()
{
    struct node *head = NULL;
    create_list(&head, 10);
    create_list(&head, 45);
    create_list(&head, 75);
    create_list(&head, 74);
    create_list(&head, 7);
    create_list(&head, 175);

    struct node *current = head;
    while(current != NULL)
    {
        printf("%d ..", current->data);
        current = current->link;
    }
    printf("NULL\n");

    
    current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->link;
        free(temp);
    }


    
    return 0;
    
}