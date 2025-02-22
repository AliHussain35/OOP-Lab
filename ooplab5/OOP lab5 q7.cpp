#include <iostream>
#include <string>
using namespace std;
class Product {
public:
    int productId;
    string name;
    float price;
    Product(int id, string n, float p) {
        productId = id;
        name = n;
        price = p;
    }
};
class Store {
private:
    string name;
    Product** products;
    int productcount;
    int initial;

public:
    Store(string n) {
        name = n;
        productcount = 0;
        initial = 20;
        products = new Product*[initial];
    }
    void addProduct(int id, string n, float p) {
        if(productcount == initial){
            cout<< "Store is full, cannot add more products"<<endl;
            return;
        }
        products[productcount++] = new Product(id, n, p);
    }
    void search() {
        string pname;
        int flag = 0;
        cout << "Enter Product name to find: ";
        cin.ignore();
        getline(cin, pname); 
        for(int i = 0; i < productcount; i++){
            if(products[i]->name == pname){  
                flag = 1;
                cout<<"Product ID = "<<products[i]->productId<<endl;
                cout<<"Product Price = "<<products[i]->price<<endl;
                break;
            }
        }
        if (flag == 0) {
            cout<<"No product found"<<endl;
        }
    }
    void displayCheapest() {
        if(productcount == 0) {
            cout<<"No products available"<<endl;
            return;
        }
        Product** sortedproducts = new Product*[productcount];
        for (int i = 0; i < productcount; i++) {
            sortedproducts[i] = products[i];
        }
        for (int i = 0; i < productcount - 1; i++) {  
            bool swapped = false;
            for (int j = 0; j < productcount - i - 1; j++) {  
                if (sortedproducts[j]->price > sortedproducts[j + 1]->price) {
                    swap(sortedproducts[j], sortedproducts[j + 1]);  
                    swapped = true;
                }
            }
            if (!swapped) break;  
        }
        cout<<"Products sorted by price"<<endl;
        for (int i = 0; i < productcount; i++) {
            cout<<"Product ID: "<<sortedproducts[i]->productId<<endl;
            cout<<"Name: "<<sortedproducts[i]->name<<endl; 
            cout<<"Price: "<<sortedproducts[i]->price<< endl;
        }
        delete[] sortedproducts;  
    }

    ~Store() {
        for (int i = 0; i < productcount; i++) {
            delete products[i];  
        }
        delete[] products;  
    }
};
int main() {
    Store myStore("Outfitterrs");
    myStore.addProduct(101,"Glasses", 700.0);
    myStore.addProduct(102,"Shirt", 400.0);
    myStore.addProduct(103,"Pants", 300.0);
    myStore.search();
    cout<<"Displaying cheapest products"<<endl;
    myStore.displayCheapest();
    return 0;
}

