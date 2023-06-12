#ifndef LIST_HPP
#define LIST_HPP

#include <iosfwd>

namespace list {

struct Node {
    char data;
    Node* next;
};

// returns a linked list from a c-string s
Node* from_string(const char* s);

// deletes all nodes of linked list
void free(Node* head);

// prints linked list to ostream out
void print(std::ostream& out, Node* head);

// returns an exact duplicate of linked list starting at head
Node* copy(Node* head);

// similar to strcmp but for lists
int compare(Node* lhs, Node* rhs);

// similar to strncmp but for lists
int compare(Node* lhs, Node* rhs, int n);

// counts number of nodes in linked list
int length(Node* head);

// returns reversed copy of linked list
Node* reverse(Node* head);

// returns new list containing all nodes of lhs followed by all nodes of rhs
Node* append(Node* lhs, Node* rhs);

// returns index of node in list starting at head
int index(Node* head, Node* node);

// similar to strchr but for a linked list
Node* find_char(Node* head, char c);

// similar to strstr but for two linked lists
Node* find_list(Node* haystack, Node* needle);

// get the nth node of linked list
Node* nth(Node* head, int n);

// get the last node of linked list
Node* last(Node* head);

};  // namespace list

#endif
