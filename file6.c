#include <stdio.h>
#include <stdlib.h>
/*---------------------------Создание типа данных списка----------------------------------*/
typedef struct list {
    int value;
    struct list *next;
}list;

/*--------------------------Функция создания списка---------------------------------------*/
list *create(int value){
    list *n = malloc(sizeof(list));
    n->next = NULL;
    n->value = value;
    return n;
}

/*--------------------------Уничтожение списка---------------------------------------------*/
list *destroy(list *head){
    while(head != NULL){
	list * n = head -> next;
	free(n);
	head = n;
    }
    return 0;
}
/*--------------------------Первый элемент списка-------------------------------------------*/
list *first (list *head){
    return head;
}
/*--------------------------Последний элемент списка----------------------------------------*/
list *last(list *head){
    if (head == 0){
	return 0;
    }
    while (head -> next){
	head = head -> next;
    }
    return head;
}
/*--------------------------Следующий элемент списка----------------------------------------*/
list *next (list *head){
    return head -> next;
}

/*-------------------------Функция PUSH - вставка элемента в начало списка-----------------*/
void push(list **head, int data){
    list *tmp = (list*) malloc(sizeof(list));
    tmp -> value = data;
    tmp -> next = (*head);
    (*head) = tmp;
}
/*------------------------Функция POP - удаление первого элемента списка-----------------*/
int pop(list **head){
    list* prev = NULL;
    int val;
    if (head == NULL){
	exit (-1);
    }
    prev = (*head);
    val = prev -> value;
    (*head) = (*head) -> next;
    free(prev);
    return (val);
}
/*---------------------Функция, которая выводит элементы списка на экран ------------------*/
void printList(const list *head){
    while (head){
	printf("%d ", head ->value);
	head = head->next;
    }
    printf ("\n");
}

/*-------------------Функция "Вставка n после p"------------------------------------------*/
void insertAfter(list * head, list* p, list* n){
    n -> next = p -> next;
    p -> next = n;
}

/*-------------------Вставка n до p-------------------------------------------------------*/
void insertBefore(list *head, list *p, list *n){
    insertAfter(head, p, n);
    int tmp = p->value;
    p->value = n ->value;
    n->value = tmp;
}


/*----------------Функция поиска по списку------------------------------------------------*/
list *search(list *head, int value){
    do{
	if (head -> value == value){
	    return (head);
	}
	else{
	    head = head -> next;
	}
    } while (head -> next);
    return 0;
}

/*-----------------Функция удаления элемента------------------------------------------------*/
list *remvoe(list *head, list *n){
    list *r = n->next;
    int data = r->value;
    r->value = n->value;
    n->value = data;
    n->value = r->value;
    r->value = 0;
    return r;
}


int main(){


}






