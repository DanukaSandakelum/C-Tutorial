#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void create_list(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->link = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while(current->link != NULL) {
            current = current->link;
        }
        current->link = new_node;
    }
}
void print(struct node *head)
{
    struct node *current = head;
    while (current != NULL){
        printf("%d....",current->data);
        current = current->link;
    }
    printf("NULL \n");
}
void search_value(struct node *head, int value)
{

    struct node *current= head;
    int posision = 1;
    int found =0;
    while (current != NULL)
    {
        if (current->data == value) {
            printf("Value %d found at position %d\n", value, posision);
            found = 1;
            //break;
        }
        current = current->link;
        posision++;
    }
    if (!found) {
        printf("Value %d not found in the list\n", value);
    }
}
void free_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->link;
        free(temp);
    }
}
int main ()
{
    struct node *head = NULL;
    create_list(&head, 10);
    create_list(&head, 45);
    create_list(&head, 75);
    create_list(&head, 74);
    create_list(&head, 7);
    create_list(&head, 175);

    // Print the list
    printf("Linked list: ");
    print(head);



    int s_value;
    printf("Enter value to search: ");
    scanf("%d..", &s_value);
    search_value(head, s_value);


    free_list(head);
    return 0;
}


