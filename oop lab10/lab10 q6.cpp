#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
class InventoryItem{
public:
    int itemID;
    char itemName[20];
    InventoryItem() {
        itemID = 0;
        itemName[0] = '\0'; 
    }

    InventoryItem(int i, const char* n) {
        itemID = i;
        strncpy(itemName, n, sizeof(itemName) - 1);
        itemName[sizeof(itemName) - 1] = '\0';  
    }

    void display() {
        cout<<"Item ID: "<<itemID << endl;
        cout<<"Item Name: "<<itemName<<endl;
    }
};

int main() {
    InventoryItem soap(11, "Lux");

    ofstream file1("items.dat", ios::binary);
    file1.write((char*)&soap, sizeof(soap));
    file1.close();

    InventoryItem s2;
    ifstream file2("items.dat", ios::binary);
    file2.read((char*)&s2, sizeof(s2));
    file2.close();

    s2.display();
    return 0;
}

