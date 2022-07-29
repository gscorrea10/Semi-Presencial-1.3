#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int height(TreeAVL *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return root->height;
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

TreeAVL *insert(TreeAVL *root, int value)
{
    if (root == NULL)
    {
        root = (TreeAVL *)malloc(sizeof(TreeAVL));
        root->key = value;
        root->right = NULL;
        root->left = NULL;
        root->height = 0;
        return root;
    }
    else
    {
        if (value < root->key)
        {
            root->left = insert(root->left, value);
            /*if(height(root->left) - height(root->right) == 2){
                if(height(root->left->left) - height(root->left->right) ==1){
                    root = */
        }
        else
        {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

TreeAVL *exclude(TreeAVL *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (value < root->key)
        {
            root->left = exclude(root->left, value);
        }
        else
        {
            if (value > root->key)
            {
                root->right = exclude(root->right, value);
            }
            else
            {
                if (root->left == NULL && root->right == NULL)
                {
                    free(root);
                    return NULL;
                }
                else
                {
                    if (root->right == NULL)
                    {
                        TreeAVL *aux = root;
                        root = root->right;
                        free(aux);
                    }
                    else
                    {
                        if (root->left == NULL)
                        {

                            TreeAVL *x = root->left;
                            while (x->right != NULL)
                            {
                                x = x->right;
                            }
                            root->key = x->key;
                            x->key = value;
                            root->left = exclude(root->left, value);
                        }
                    }
                }
            }
        }
    }
    return root;
}

TreeAVL *emptyTree()
{
    return NULL;
}

TreeAVL *clear(TreeAVL *root)
{
    if (root == NULL)
    {
        clear(root->right);
        clear(root->left);
        clear(root);
    }
    return NULL;
}

TreeAVL *search(TreeAVL *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->key > value)
    {
        return search(root->left, value);
    }
    else if (root->key < value)
    {
        return search(root->right, value);
    }
    else
    {
        return root;
    }
}

void preOrder(TreeAVL *root)
{

    if (root == NULL)
    {
        printf("<>");
    }
    else if (root != NULL)
    {
        printf("<%i ", root->key);
        preOrder(root->left);
        preOrder(root->right);
        printf(">");
    }
}

void inOrder(TreeAVL *root)
{
    if (root == NULL)
    {
        printf("<>");
    }
    else if (root != NULL)
    {
        inOrder(root->left);
        printf("<%i", root->key);
        inOrder(root->right);
        printf(">");
    }
}

void posOrder(TreeAVL *root)
{
    if (root == NULL)
    {
        printf("<>");
    }
    else if (root != NULL)
    {
        posOrder(root->left);
        printf(">");
        posOrder(root->right);
        printf("<%i", root->key);
    }
}
