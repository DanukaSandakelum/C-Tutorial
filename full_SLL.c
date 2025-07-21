#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void create_list(struct node **head , int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf ("Memory allocation failed\n");
        return;
    }
    new_node->data=data;
    new_node->link=NULL;
    if(*head ==NULL){
        *head = new_node;
    }else{
        struct node *current = *head;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = new_node;
    }
}
void print(struct node *head)
{
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}
void search_value(struct node *head, int value)
{
    struct node *current = head;
    int position = 0;
    int found = 0;
    while (current != NULL)
    {
        if (current->data == value)
        {
            printf("value %d is founded at position %d\n", value, position);
            found = 1;
        }
        {
            current = current->link;
            position++;
        }
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
void delete_node(struct node **head, int value)
{
    struct node *temp = *head;
    struct node *priv = NULL;

    if (temp == NULL) return;

    if(temp ->data ==  value){
        *head = temp->link;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != value) {
        priv = temp;
        temp = temp->link;
    }
   priv->link = temp->link;
    free(temp); 
    printf("Node with value %d deleted successfully.\n", value);
}


void selection_sort(struct  node **head)
{
    struct node *i, *j, *min;
    int temp;
    for (i= *head;i !=NULL && i->link !=NULL;i=i->link){
        min =i;
        for(j=i->link; j != NULL; j=j->link)
        {
            if(j->data<min->data){
                min =j;
            }
        }
        if(min != i)
        {
            temp = i->data;
            i->data =min->data;
            min->data =temp;
        }


    } 
}

int main() {
    struct node *head = NULL;
    int choice;
    int value;

    do {
        printf("\n===== Linked List Menu =====\n");
        printf("1. Insert values into the list\n");
        printf("2. Search a value\n");
        printf("3. Delete a node\n");
        printf("4. Sort the list\n");
        printf("5. Print the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter values to insert (-1 to stop):\n");
                while (1) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (value == -1)
                        break;
                    create_list(&head, value);
                }
                print(head);
                break;

            case 2:
                if (head == NULL) {
                    printf("List is empty. Nothing to search.\n");
                } else {
                    printf("Enter value to search: ");
                    scanf("%d", &value);
                    search_value(head, value);
                }
                break;

            case 3:
                if (head == NULL) {
                    printf("List is empty. Nothing to delete.\n");
                } else {
                    printf("Enter value to delete: ");
                    scanf("%d", &value);
                    delete_node(&head, value);
                }
                print(head);
                break;

            case 4:
                if (head == NULL) {
                    printf("List is empty. Nothing to sort.\n");
                } else {
                    selection_sort(&head);
                    printf("List has been sorted.\n");
                }
                print(head);
                break;

            case 5:
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("The list is:\n");
                    print(head);
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);
    free_list(head);

    return 0;
}