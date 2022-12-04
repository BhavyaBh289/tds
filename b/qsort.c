#include<stdio.h>
#include<malloc.h>
struct node {
    int data;
    struct node * next;
};
int main(){
    struct node * head = NULL;
    int n,temp;
    do{
    printf("1 to add value 2 to show value 3to remove a value 4 to exit");
    scanf("%d",&n);
    switch(n){
        case 1:
            printf("value to be added");
            scanf("%d",&temp);
            head = addnode(head,temp);
    }
    }while(n !=4)
}
