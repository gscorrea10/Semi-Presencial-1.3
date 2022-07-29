#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int value;
    TreeAVL *root;
    TreeAVL *k;
    int option;

    do
    {
        printf("\n \n Type the option u want, following the menu settings:\n 1- CreateAVL. \n 2- Insert. \n 3- Delete. \n 4- Print. \n 5- Height. \n 6- Free. \n 0-Leave\n");
        scanf("%i", &option);

        switch (option)
        {
        case 1:
        {
            root = emptyTree();
            printf("CreateAVL done!");
            break;
        }
        case 2:
        {
            printf("Type the value u want to insert: \n");
            scanf("%i", &value);
            k = search(root, value);
            if (root == NULL)
            {
                root = insert(root, value);
                printf("Entered value: \n");
            }
            else
            {
                printf("value already entered! \n");
            }

            break;
        }
        case 3:
        {
            printf("Type the value u want delete:");
            scanf("%i", &option);
            k = search(root, value);
            if (k == NULL)
            {
                printf("We dont find the value u want!!");
            }
            else
            {
                root = exclude(root, value);
                printf("value deleted!!!");
            }
            break;
        }
        case 4:
        {
            printf("type the order u want to show: \n 1- Pre order\n 2- In order\n 3- Pos Order\n");
            scanf("%i", &value);
            if (value == 1)
            {
                preOrder(root);
            }
            else if (value == 2)
            {
                inOrder(root);
            }
            else
            {
                posOrder(root);
            }
            break;
            ;
        }
        case 5:
        {
            value = height(root);
            printf("The height is %i", value);
            break;
        }

        case 6:
        {
            root = clear(root);
            printf("free done");
            break;
            ;
        }

        case 0:
        {
            printf("u left....");
            break;
        }
        default:
        {
            printf("wrong option");
            break;
        }
        }
    } while (option != 0);

    return (EXIT_SUCCESS);
}
