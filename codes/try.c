// a tree of arrays

typedef struct node // it doesnt store the key, or the name. the arrays point to the 'letter' or index
{
    struct node *children[26];
    char *number;
} node;
