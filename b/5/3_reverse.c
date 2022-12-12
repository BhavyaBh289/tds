#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

static void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct Node* head = NULL;
    int n = 0,data ;
    while (n !=4){
	printf("1 to add \n 2 to reverse \n 3 to print\n 4 to exit");
	scanf("%d",&n);
	switch(n){
        case 1:
            printf("enter data : ");
            scanf("%d",&data);
            push(&head, data);
            break;
        case 2:
            reverse(&head);
            break;
        case 3:
            printf("\n");
            printList(head);
            break;
        case 4:
            printf("exiting");
        }
	}
}
