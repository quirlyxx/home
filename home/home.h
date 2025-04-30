#pragma once
#include <iostream>

class Person {
private:
    char* name;
    int age;

public:
    Person();
    Person(const char* name, int age);
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    void output() const;
};

class Apartment {
private:
    Person* people;
    int personCount;

public:
    Apartment();
    Apartment(int count);
    Apartment(const Apartment& other);
    Apartment& operator=(const Apartment& other);
    ~Apartment();

    void output() const;
};

class House {
private:
    Apartment* apartments;
    int apartmentCount;

public:
    House();
    House(int count);
    House(const House& other);
    House& operator=(const House& other);
    ~House();

    void output() const;
};
