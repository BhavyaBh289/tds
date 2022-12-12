#include <stdio.h>
#include <malloc.h>
 struct node{
    int data;
    struct node * next;

};
struct node * create(int n){
    struct node * head = (struct node *) malloc(sizeof(struct node));
    head->data = n;
    head->next = NULL;
    return head;
}
void insert_last(int n,struct node * head){
    struct node *next = (struct node *) malloc(sizeof(struct node));
    next->data = n;
    next->next = NULL;
    struct node *test = head;
    while (test->next != NULL){
        test = test->next;
    }
    test->next = next;
    test = next;
}
void display(struct node * head){
    struct node *temp;
    temp = head;
    if (temp != NULL){
        while(temp != NULL){
            printf("data is : %d\n",temp->data);
            temp = temp->next;
        }
    }
}
struct node * split(struct node * head){
    int l = 1;
    struct node *test = head;
    while (test->next != NULL){
        test = test->next;
        l++;
    }
    printf("%d",l);
    if (l==1){
        return head;
    }else if (l ==2){
        test = head->next;
        head->next = NULL;
        return test;
    }else{
    int q = l/2 +l%2;
    for (int i=0)
    }
}
int main() {
  struct node * head = create(10);
  insert_last(15,head);
  insert_last(15,head);
  insert_last(15,head);
  insert_last(15,head);
  display(head);
  struct node * test = split(head);
  return 0 ;
}
