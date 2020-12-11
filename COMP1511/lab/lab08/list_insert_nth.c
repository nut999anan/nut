#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *insert_nth(int n, int value, struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int value;
    scanf("%d", &value);
    // create linked list from command line arguments
    struct node *head = NULL;
    if (argc > 1) {
        // list has elements
        head = strings_to_list(argc - 1, &argv[1]);
    }

    struct node *new_head = insert_nth(n, value, head);
    print_list(new_head);

    return 0;
}


// Insert a new node containing value at position n of the linked list.
// if n == 0, node is inserted at start of list
// if n >= length of list, node is appended at end of list
// The head of the new list is returned.
struct node *insert_nth(int n, int value, struct node *head) {
    //if n == 0 chang insert at start 
    if(n==0){
        struct node *insert = malloc(sizeof(struct node));
        insert->data = value;
        insert->next = head;//copy head value
        head = insert;//head point to insert
        return head;
    }
    //else loop till n and insert at nth position
    else
    {
        //loop till n to find head at nth position 
        // n == 1 head = head -> next;
        struct node *current = head;//dummy head for looping
        int i = 0;
        while (i < n-1)
        {
            printf("current point to %d\n",current->data);
            current = current->next;
            i++;
        }
        struct node *insert = malloc(sizeof(struct node));
        insert->data = value;

        //loop till head point to nth position
        //point insert next to what that node point
        //change next of that node to insert

        insert->next = current->next;
        current->next = insert;
        
        return head;
      
        
    }
    


}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}