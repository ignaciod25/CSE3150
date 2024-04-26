#include "Vehicle.h"

Vehicle::Vehicle() {}

Vehicle::~Vehicle() {}

Gasoline::Gasoline() {}

double Gasoline::calculateCostOfTrip(double miles) {
    if(mpg == 0) return 0; 
    return (miles / mpg * costPerGallon);
}

void Gasoline::setMpg(double m) { mpg = m; }

double Gasoline::getMpg() { return mpg; }

void Gasoline::setCostPerGallon(double c) { costPerGallon = c; }

double Gasoline::getCostPerGallon() { return costPerGallon; }

double Gasoline::getMpg() const { return mpg; } 

double Gasoline::getCostPerGallon() const { return costPerGallon; } 

Gasoline::~Gasoline() {}

Electric::Electric() {}

double Electric::calculateCostOfTrip(double miles) {
    if(mpge == 0) return 0; 
    return (miles / mpge * costPerkWh);
}

void Electric::setMpge(double m) { mpge = m; }

double Electric::getMpge() { return mpge; }

void Electric::setCostPerkWh(double c) { costPerkWh = c; }

double Electric::getCostPerkWh() { return costPerkWh; }

double Electric::getMpge() const { return mpge; } 

double Electric::getCostPerkWh() const { return costPerkWh; } 

Electric::~Electric() {}

Hybrid::Hybrid() {}

double Hybrid::calculateCostOfTrip(double miles) {

    if(getMpg() == 0 || getMpge() == 0) return 0; 
    return (Electric::calculateCostOfTrip(miles / 2) + Gasoline::calculateCostOfTrip(miles / 2));
}

Hybrid::~Hybrid() {}
