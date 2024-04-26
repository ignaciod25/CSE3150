#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
public:
    Vehicle();
    virtual double calculateCostOfTrip(double miles) = 0;
    virtual ~Vehicle();
};

class Gasoline : public virtual Vehicle {
public:
    Gasoline();
    double calculateCostOfTrip(double miles) override;
    void setMpg(double m);
    double getMpg();
    void setCostPerGallon(double c);
    double getCostPerGallon();
    double getMpg() const; 
    double getCostPerGallon() const; 
    virtual ~Gasoline();
private:
    double mpg;
    double costPerGallon;
};

class Electric : public virtual Vehicle {
public:
    Electric();
    double calculateCostOfTrip(double miles) override;
    void setMpge(double m);
    double getMpge();
    void setCostPerkWh(double c);
    double getCostPerkWh();
    double getMpge() const; 
    double getCostPerkWh() const; 
    virtual ~Electric();
private:
    double mpge;
    double costPerkWh;
};

class Hybrid : public Electric, public Gasoline {
public:
    Hybrid();
    double calculateCostOfTrip(double miles) override;
    virtual ~Hybrid();
};

#endif
