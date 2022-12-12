#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node * next;
};
struct node * addnode(struct node *head, int data){

}
int main(){
    struct node * head;
    int n, temp;
    while(true){
        printf("1. Add \n 2. Display \n 3. Delete \n 4.Exit");
        scanf("%d", &n);
        switch(n){
            case 1:
            printf("Enter value to be added: ");
            scanf("%d", &temp);
            head = addnode(head, temp);
            

        }
    }
}