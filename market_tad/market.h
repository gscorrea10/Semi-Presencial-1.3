enum department{Hortifruti=1,Meat=2,Grains=3,Hygiene=4,Drinks=5};

struct products {
  char name[15];
  enum department department;
  int amount;
  float price;
};

struct products * insertProducts(struct products *myProducts, int totalProducts, int k);
void showOneProduct(struct products *myProducts, int totalProducts, int i);
void showAllProducts(struct products *myProducts, int totalProducts);
void findByName(struct products *myProducts, int totalProducts);
void findByDepartment(struct products *myProducts, int totalProducts);
float balance (struct products *myProducts, int totalProducts, float sum);
struct products * sell(struct products *myProducts, int totalProducts);