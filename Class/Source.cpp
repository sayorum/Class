#include <iostream>
#include <string>
#include <vector>
#include <locale.h>

using namespace std;

class Person {
public:
    Person(const string& name, int age)
        : name_(name), age_(age)
    {}

    void sayHi() const {
        cout << "Привет, меня зовут " << name_ << " и мне " << age_ << " лет." << endl;
    }

private:
    string name_;
    int age_;
};

class Employer : public Person {
public:
    Employer(const string& name, int age)
        : Person(name, age)
    {}

    void sayHi() const {
        cout << "Привет, я работодатель." << endl;
    }
};

class Supplier : public Person {
public:
    Supplier(const string& name, int age)
        : Person(name, age)
    {}

    void sayHi() const {
        cout << "Привет, я поставщик." << endl;
    }
};

class Client : public Person {
public:
    Client(const string& name, int age)
        : Person(name, age)
    {}

    void sayHi() const {
        cout << "Привет, я клиент." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Person*> people;

    people.push_back(new Employer("Иван", 30));
    people.push_back(new Supplier("Анна", 25));
    people.push_back(new Client("Михаил", 40));

    for (auto person : people) {
        person->sayHi();
        delete person;
    }

    return 0;
}
