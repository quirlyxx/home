#define _CRT_SECURE_NO_WARNINGS
#include "home.h"

Person::Person() : name(nullptr), age(0) {}

Person::Person(const char* name, int age) : age(age) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Person::Person(const Person& other) : age(other.age) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        delete[] name;
        age = other.age;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    return *this;
}

Person::~Person() {
    delete[] name;
}

void Person::output() const {
    std::cout << "Name: " << (name ? name : "no name") << ", Age: " << age << "\n";
}

Apartment::Apartment() : people(nullptr), personCount(0) {}

Apartment::Apartment(int count) : personCount(count) {
    people = new Person[personCount];
    for (int i = 0; i < personCount; ++i) {
        char buffer[50];
        std::cout << "Enter name for person " << i + 1 << ": ";
        std::cin.ignore();
        std::cin.getline(buffer, 25);
        int age;
        std::cout << "Enter age: ";
        std::cin >> age;
        people[i] = Person(buffer, age);
    }
}

Apartment::Apartment(const Apartment& other) : personCount(other.personCount) {
    people = new Person[personCount];
    for (int i = 0; i < personCount; ++i)
        people[i] = other.people[i];
}

Apartment& Apartment::operator=(const Apartment& other) {
    if (this != &other) {
        delete[] people;
        personCount = other.personCount;
        people = new Person[personCount];
        for (int i = 0; i < personCount; ++i)
            people[i] = other.people[i];
    }
    return *this;
}

Apartment::~Apartment() {
    delete[] people;
}

void Apartment::output() const {
    std::cout << "Apartment with " << personCount << " person(s):\n";
    for (int i = 0; i < personCount; ++i) {
        people[i].output();
    }
    std::cout << "\n";
}

House::House() : apartments(nullptr), apartmentCount(0) {}

House::House(int count) : apartmentCount(count) {
    apartments = new Apartment[apartmentCount];
    for (int i = 0; i < apartmentCount; ++i) {
        int numPeople;
        std::cout << "\nApartment " << i + 1 << ":\n";
        std::cout << "Enter number of people: ";
        std::cin >> numPeople;
        apartments[i] = Apartment(numPeople);
    }
}

House::House(const House& other) : apartmentCount(other.apartmentCount) {
    apartments = new Apartment[apartmentCount];
    for (int i = 0; i < apartmentCount; ++i)
        apartments[i] = other.apartments[i];
}

House& House::operator=(const House& other) {
    if (this != &other) {
        delete[] apartments;
        apartmentCount = other.apartmentCount;
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; ++i)
            apartments[i] = other.apartments[i];
    }
    return *this;
}

House::~House() {
    delete[] apartments;
}

void House::output() const {
    std::cout << "\nHouse withö " << apartmentCount << " apartments:\n";
    for (int i = 0; i < apartmentCount; ++i) {
        std::cout << "Apartment " << i + 1 << ":\n";
        apartments[i].output();
    }
}
