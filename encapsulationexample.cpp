#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    int age;
    string address;

public:
    // Constructor to set initial data
    Person(const std::string& initialName, int initialAge, const std::string& initialAddress)
        : name(initialName), age(initialAge), address(initialAddress) {}

    // Setter methods to update data
    void setName(const std::string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    void setAddress(const string& newAddress) {
        address = newAddress;
    }

    // Getter methods to access data
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getAddress() const {
        return address;
    }
};

int main() {
    string initialName, initialAddress;
    int initialAge;

    // Input initial data from the user
    cout << "Enter initial name: ";
    getline(cin, initialName);

    cout << "Enter initial age: ";
    cin >> initialAge;
    cin.ignore(); // Ignore the newline character from the previous input

    cout << "Enter initial address: ";
    getline(cin, initialAddress);

    // Create a person object with initial data
    Person person(initialName, initialAge, initialAddress);

    // Input new data from the user to update the person's data
    string newName, newAddress;
    int newAge;

    cout << "\nEnter new name: ";
    getline(cin, newName);

    cout << "Enter new age: ";
    cin >> newAge;
    cin.ignore(); // Ignore the newline character from the previous input

    cout << "Enter new address: ";
    getline(cin, newAddress);

    // Update person's data using setter methods
    person.setName(newName);
    person.setAge(newAge);
    person.setAddress(newAddress);

    // Display person's data using getter methods
    cout << "\nUpdated Person Data:\n";
    cout << "Name: " << person.getName() <<endl;
    cout << "Age: " << person.getAge() <<endl;
    cout << "Address: " << person.getAddress() <<endl;

    return 0;
}