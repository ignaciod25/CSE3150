#include <iostream>

#include "Vehicle.h"

int main() {
    char choice;
    
    std::cout << "Choose the type of vehicle:\n";
    std::cout << "G - Gasoline\n";
    std::cout << "E - Electric\n";
    std::cout << "H - Hybrid\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    switch(choice) {
        case 'G': {
            Gasoline gasoline;
            double costPerGallon, mpg;
            std::cout << "Enter cost per gallon for Gasoline vehicle: ";
            std::cin >> costPerGallon;
            gasoline.setCostPerGallon(costPerGallon);
            std::cout << "Enter miles per gallon for Gasoline vehicle: ";
            std::cin >> mpg;
            gasoline.setMpg(mpg);
            std::cout << "Enter the trip distance in miles: ";
            double trip_distance;
            std::cin >> trip_distance;
            std::cout << "Cost of trip in Gasoline: $" << gasoline.calculateCostOfTrip(trip_distance) << std::endl;
            break;
        }
        case 'E': {
            Electric electric;
            double costPerkWh, mpge;
            std::cout << "Enter cost per kWh for Electric vehicle: ";
            std::cin >> costPerkWh;
            electric.setCostPerkWh(costPerkWh);
            std::cout << "Enter miles per gallon equivalent for Electric vehicle: ";
            std::cin >> mpge;
            electric.setMpge(mpge);
            std::cout << "Enter the trip distance in miles: ";
            double trip_distance;
            std::cin >> trip_distance;
            std::cout << "Cost of trip in Electric: $" << electric.calculateCostOfTrip(trip_distance) << std::endl;
            break;
        }
        case 'H': {
            Hybrid hybrid;
            double costPerGallon, mpg, costPerkWh, mpge;
            std::cout << "Enter cost per gallon for Hybrid vehicle: ";
            std::cin >> costPerGallon;
            hybrid.setCostPerGallon(costPerGallon);
            std::cout << "Enter miles per gallon for Hybrid vehicle: ";
            std::cin >> mpg;
            hybrid.setMpg(mpg);
            std::cout << "Enter cost per kWh for Hybrid vehicle: ";
            std::cin >> costPerkWh;
            hybrid.setCostPerkWh(costPerkWh);
            std::cout << "Enter miles per gallon equivalent for Hybrid vehicle: ";
            std::cin >> mpge;
            hybrid.setMpge(mpge);
            std::cout << "Enter the trip distance in miles: ";
            double trip_distance;
            std::cin >> trip_distance;
            std::cout << "Cost of trip in Hybrid: $" << hybrid.calculateCostOfTrip(trip_distance) << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }

    return 0;
}

// g++ -o main main.cpp Vehicle.cpp 
