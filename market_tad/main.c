/* 
-> List 1.3
-> 13/07/2022
-> Gabriel Silveira Corrêa

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "market.h"

int main(void)
{
  int totalProducts;
  int i;
  struct products *myProducts = NULL;
  int departmentNumber;

  printf("How many products do you want to register?: \n");
  setbuf(stdin, NULL);
  scanf("%d", &totalProducts);
  myProducts = (struct products *)malloc(totalProducts * sizeof(struct products));

  for (i = 0; i < totalProducts; i++)
  {
    setbuf(stdin, NULL);
    printf("Enter the product name: \n");
    scanf("%[^\n]s", myProducts[i].name);
    setbuf(stdin, NULL);
    printf("Enter the department: (Hortifruti=1,Meat=2,Grains=3,Hygiene=4,Drinks=5) \n");
    setbuf(stdin, NULL);
    scanf("%d", &departmentNumber);
    myProducts[i].department = departmentNumber;
    setbuf(stdin, NULL);
    printf("Enter the amount: \n");
    scanf("%d", &myProducts[i].amount);
    setbuf(stdin, NULL);
    printf("Enter the price: \n");
    scanf("%f", &myProducts[i].price);
  }

  int option = -1;
  while (option = !0)
  {
    printf("\nMenu: \nChoose an option below:\n \
        \n#1 -> Insert Product: \
        \n#2 -> Find one Product: \
        \n#3 -> Find by name of Product: \
        \n#4 -> Find by Department: \
        \n#5 -> Show all Products: \
        \n#6 -> Balance: \
        \n#7 -> Sell one Product: \
        \n#0 -> Leave the program: \n");
    fflush(stdin);
    printf("\n");
    printf("\n");
    printf("Chose one option:\n\n");
    scanf("%d", &option);
    fflush(stdin);
    printf("\n");
    printf("\n");
    switch (option)
    {
    case 0:
      printf("\nLeaving...");
      return 0;

    case 1:
      printf("Inserting a product:\n");
      int k = 0;
      printf("Enter the number of products u want register:\n");
      setbuf(stdin, NULL);
      scanf("%d", &k);
      myProducts = insertProducts(myProducts, totalProducts, k);
      totalProducts += k;
      break;

    case 2:
      printf("Find one product: \n");
      printf("Enter what product u want find:(1 - %d) \n ", totalProducts);
      setbuf(stdin, NULL);
      scanf("%d", &i);
      i = i - 1;
      showOneProduct(myProducts, totalProducts, i);
      break;

    case 3:
      printf("\n Find by Name: \n");
      findByName(myProducts, totalProducts);
      break;

    case 4:
      printf("\n Find by Department: \n");
      findByDepartment(myProducts, totalProducts);
      break;

    case 5:
      printf("\n Show all Products: \n");
      showAllProducts(myProducts, totalProducts);
      break;

    case 6:
      printf("\n Balance is R$ %.2f \n", balance(myProducts, totalProducts, 0));
      break;

    case 7:
      printf("\n Sell product: \n");
      sell(myProducts, totalProducts);
      if (myProducts[totalProducts - 1].amount == 0)
      { 
        totalProducts--;
      }
      printf("\n U sold a unit \n");
      break;
    }
  }
  return 0;
}
