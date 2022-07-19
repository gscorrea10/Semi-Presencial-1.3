#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "market.h"

struct products *insertProducts(struct products *myProducts, int totalProducts, int k)
{
  int i;
  int departmentNumber;

  myProducts = realloc(myProducts, sizeof(struct products) * (k + totalProducts));
  for (i = totalProducts; i < totalProducts; i++)
  {
    setbuf(stdin, NULL);
    printf("Enter the product name: \n");
    scanf("%[^\n]s", myProducts[i].name);
    setbuf(stdin, NULL);
    printf("Enter the department: \n");
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

  return myProducts;
}

void findByName(struct products *myProducts, int totalProducts)
{
  int i;
  char lf[20]; // lf = looking for

  printf("\n Enter the name of the product u want to find: \n");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", lf);

  for (i = 0; i < totalProducts; i++)
  {
    if (strcmp(lf, myProducts[i].name) == 0)
    {
      printf("Name: %s \n", myProducts[i].name);
      printf("Department: %d \n", myProducts[i].department);
      printf("Amount: %d \n", myProducts[i].amount);
      printf("Price: %.2f \n \n \n", myProducts[i].price);
    }
  }
}

void findByDepartment(struct products *myProducts, int totalProducts)
{
  int i;
  int lf; // lf = looking for
  printf("\n Enter the number of department (between 1-5): \n");
  setbuf(stdin, NULL);
  scanf("%d", &lf);
  for (i = 0; i < totalProducts; i++)
  {
    if (myProducts[i].department == lf)
    {
      printf("Name: %s \n", myProducts[i].name);
      printf("Department: %d \n", myProducts[i].department);
      printf("Amount: %d \n", myProducts[i].amount);
      printf("Price: %.2f \n \n \n", myProducts[i].price);
    }
  }
}

void showOneProduct(struct products *myProducts, int totalProducts, int i)
{
  printf("\n Product: %d \n", i + 1);
  printf("\n Name: %s", myProducts[i].name);
  switch (myProducts[i].department)
  {
  case 1 /* constant-expression */:
    /* code */
    printf("\n Department is: Hortifruti");
    break;
  case 2:
    printf("\n Department is: Meat");
    break;
  case 3:
    printf("\n Department is: Grains");
    break;
  case 4:
    printf("\n Department is: Hygiene");
    break;
  case 5:
    printf("\n Department is: Drinks");
    break;
  }
  printf("\n The amount is: %d", myProducts[i].amount);
  printf("\n Price: R$ %.2f\n", myProducts[i].price);
}

void showAllProducts(struct products *myProducuts, int totalProducts)
{
  int i;
  for (i = 0; i < totalProducts; i++)
  {
    showOneProduct(myProducuts, totalProducts, i);
  }
}

float balance(struct products *myProducts, int totalProducts, float sum)
{
  sum += myProducts[totalProducts].amount * myProducts[totalProducts].price;
  if (totalProducts == 0)
  {
    return sum;
  }
  else
  {
    return balance(myProducts, totalProducts - 1, sum);
  }
}

struct products *sell(struct products *myProducts, int totalProducts)
{

  char product[20];

  printf("\n Type the name of product u want to sell: \n");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", product);

  int i;
  int j;

  for (i = 0; i < totalProducts; i++)
  {
    if (strcmp(product, myProducts[i].name) == 0)
    {
      myProducts[i].amount--;
      if (myProducts[i].amount == 0)
      {
        for (j = i; j < totalProducts; j++)
        {
          /* code */
          myProducts[j] = myProducts[j + 1];
        }
        i--;
        myProducts[totalProducts - 1].amount = 0;
        myProducts = realloc(myProducts, sizeof(struct products) * (totalProducts - 1));
      }
    }
    /* code */
  }
  return myProducts;
}