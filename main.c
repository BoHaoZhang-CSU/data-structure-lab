#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* creatNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;

}

void insertTail(struct Node** head, int value){
    struct Node* newNode = creatNode(value);
    if(*head == NULL){
        *head = newNode;
    }else{
        struct Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

void insertBefore(struct Node** head, int target, int value){
    struct Node* newNode = creatNode(value);
    //空链表
    if(*head == NULL) return;
    //头结点
    if((*head)->data == target){
        newNode->next = *head;  
        *head = newNode;
        return;
    }else{
        struct Node* temp = *head;
        while(temp->next != NULL && temp->next->data != target){
            temp = temp->next;
        }
        if(temp->next == NULL) return;
        newNode->next = temp->next;
        temp->next = newNode;

    }

    

}

void deleteValue(struct Node** head, int value){
    if(*head == NULL) return;
    if((*head)->data == value){
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    while(temp->next && temp->next->data != value){
        temp = temp->next;
    } 
    if(temp->next == NULL) return;
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

}
//打印链表
void printList(struct Node* head){
    if(head == NULL){
        printf("链表为空！");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d,", temp->data);
        temp = temp->next;
    }
   printf("\n");
}
//计算两个链表集合的并集
struct Node* unionSet(struct Node* list1, struct Node* list2){
    struct Node* result = NULL;
    struct Node* temp = list1;
    while(temp){
        insertTail(&result, temp->data);
        temp = temp->next;
    }
    temp = list2;
    while(temp){
        struct Node* check = result;
        int found = 0;
        while(check){
            if(check->data == temp->data){
                found = 1;
                break;
            }
            check = check->next;

        }
        if(!found){
            insertTail(&result,temp->data);
        }
        temp = temp->next;
    }
    return result;

}


void print_ergou(){
    printf("二狗");
}
    

int main() {
    print_ergou();
    struct Node* list1 = NULL;  
    struct Node* list2 = NULL;
    insertTail(&list1, 3);
    insertTail(&list1, 9);
    insertTail(&list1, 5);
    insertTail(&list1, 6);
    insertTail(&list1, 11);
    insertTail(&list1, 8);
    printf("list1:\n");
    printList(list1);
    printf("在5之前插入4和7\n");
    insertBefore(&list1, 5, 4);
    insertBefore(&list1, 5, 7);
    printf("list1:\n");
    printList(list1);
    printf("删除元素11\n");
    deleteValue(&list1, 11);
    printf("list1:\n");
    printList(list1);
    insertTail(&list2, 1);
    insertTail(&list2, 12);
    insertTail(&list2, 8);
    insertTail(&list2, 6);
    insertTail(&list2, 4);
    insertTail(&list2, 9);
    printf("list2:\n");
    printList(list2);
    printf("list1和list2的并集:\n");
    struct Node* result = unionSet(list1, list2);
    printList(result);

    return 0;
}