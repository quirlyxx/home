#include "home.h"

int main() {
    int numApartments;
    std::cout << "Enter number of apartments: ";
    std::cin >> numApartments;

    House myHouse(numApartments);
    myHouse.output();
}
