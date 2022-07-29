struct tree
{
    struct tree *left;
    struct tree *right;
    int key;
    int height;
};
typedef struct tree TreeAVL;

TreeAVL *emptyTree();
TreeAVL *exclude(TreeAVL *root, int value);
TreeAVL *insert(TreeAVL *root, int value);
TreeAVL *clear(TreeAVL *root);
TreeAVL *search(TreeAVL *root, int value);
void preOrder(TreeAVL *root);
void inOrder(TreeAVL *root);
void posOrder(TreeAVL *root);
int height(TreeAVL *root);
int max(int a, int b);
