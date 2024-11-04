#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Product {
  private:
    string name;
    int quantity, price;
  public:
    Product(string n, int q, int p) {
      name = n;
      quantity = q;
      price = p;
    }

    void setName(string n) {
      name = n;
    }

    void setQuantity(int q) {
      quantity = q;
    }

    void setPrice(int p) {
      price = p;
    }

    string getName() {
      return name;
    }

    int getQuantity() {
      return quantity;
    }

    int getPrice() {
      return price;
    }
};

int main() {
  string customer_name, product_name;
  int product_quantity, product_price, choice, product_total;
  int total_price = 0;

  cout << "Customer Name: ";
  getline(cin, customer_name);

  vector<Product> shopping_cart;
  
  while (true) {
    cout << "***Cashier Menu***" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. View Shopping Cart" << endl;
    cout << "3. Save and Leave" << endl;
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
      case 1:
        cout << "Product Name: ";
        getline(cin, product_name);
        cout << "Product Quantity: ";
        cin >> product_quantity;
        cin.ignore();
        cout << "Product Price (Rupiah/Rp): ";
        cin >> product_price;

        shopping_cart.push_back(Product(product_name, product_quantity, product_price));
        
        break;
      case 2:
        cout << "--" << customer_name << "'s Shopping Cart--" << endl;

        for (int i = 0; i < shopping_cart.size(); i++) {
          product_total = shopping_cart[i].getQuantity() * shopping_cart[i].getPrice();
          cout << shopping_cart[i].getName() << " x" << shopping_cart[i].getQuantity() << " @ Rp" << shopping_cart[i].getPrice() << " = Rp" << product_total << endl;
          total_price += product_total;
        }

        cout << "Total Price: Rp" << total_price << endl;

        break;
      case 3:
        cout << "Saving and Leaving..." << endl;
        
        //filestream here
        
        return 0;
      default:
        cout << "Invalid choice. Please try again." << endl;

        break;
    }
  }
  
  return 0;
}