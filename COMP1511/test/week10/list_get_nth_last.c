#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int get_nth_last(int n, struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s n list-elements\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 2, &argv[2]);

    int result = get_nth_last(n, head);
    printf("%d\n", result);

    return 0;
}


// Return the n-th element of linked list.
// n == 0 returns first element, n == 1, second element, ....
int get_nth_last(int n, struct node *head) {
    //how to find nth elements from the null
    int size = 0;
    struct node *current = head;
    while(current != NULL){
        size++;
        current = current -> next;
    }


    // i'm not sure of this 
    int nth = 0;
    current = head;
    while (nth < size - n)
    {
        nth++;
        current = current ->next;
    }
    return current->data;
    
    // PUT YOUR CODE HERE (change the next line!)

}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}