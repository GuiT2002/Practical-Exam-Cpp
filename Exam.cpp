#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printMenu(){
    cout << "UFSC VEHICLE MANAGER SYSTEM (UVMS)" << endl;
cout << "-----------------------------------" << endl;
cout << "1. Insert a new vehicle" << endl;
cout << "2. Insert a route to a vehicle be executed" << endl;
cout << "3. Show reports (summary)" << endl;
cout << "4. Show history by vehicle"<< endl;
cout << "0. Quit" << endl;
};

void printOption1(){
    cout << "Choose the vehicle to be added: 1-Car, 2-Bus, 3-LightTruck, 4-HeavyTruck:" << endl;
}

class Vehicle{
protected:
    vector<pair<string, float>> m_route;
    string m_plate;
    string m_description;

public: 
    Vehicle();
    Vehicle(string plate, string description): m_plate(plate), m_description(description){};
    
    virtual string getPlate(){
        return m_plate;
    }; 

    virtual void setRoute(string city, float distance){
        
        pair<string, float> routePair;
        routePair.first = city;
        routePair.second = distance;

        m_route.push_back(routePair);

    };

    virtual void ShowMe(){
        cout << "I'm a vehicle class" << endl;
    }

    virtual void getCity(){
        for (size_t a=0; a<m_route.size();a++){
            cout << m_route.at(a).first;
        };
    };
    
    void getDistance(){
        float distSum = 0;
        for (size_t k=0; k<m_route.size();k++){
            distSum += m_route.at(k).second;
        };

        cout << distSum << endl;

    };

};

class Car : public Vehicle{
private: 
    int m_gasCons = 12;
public:
    Car(){};
    Car(string plate, string description): Vehicle(plate, description){};

    void ShowMe(){
        float routeSum = 0;

        for (size_t i=0; i<m_route.size(); i++){
            routeSum += m_route.at(i).second;
        }
    
        cout << "Vehicle: " << m_plate << " - " << "Distance: " << routeSum << " - " << "Gas consumed: " << routeSum/m_gasCons << " liters" << endl;

    }

};

class Bus : public Vehicle{
private:
    int m_gasCons = 7;

public:
    Bus(){};
    Bus(string plate, string description): Vehicle(plate, description){};

    void ShowMe(){
        float routeSum = 0;

        for (size_t i=0; i<m_route.size(); i++){
            routeSum += m_route.at(i).second;
        }
    
        cout << "Vehicle: " << m_plate << " - " << "Distance: " << routeSum << " - " << "Gas consumed: " << routeSum/m_gasCons << " liters" << endl;

    }
};

class LightTruck : public Vehicle{
private:
    int m_gasCons = 4;

public:
    LightTruck(){};
    LightTruck(string plate, string description): Vehicle(plate, description){};

    void ShowMe(){
        float routeSum = 0;

        for (size_t i=0; i<m_route.size(); i++){
            routeSum += m_route.at(i).second;
        }
    
        cout << "Vehicle: " << m_plate << " - " << "Distance: " << routeSum << " - " << "Gas consumed: " << routeSum/m_gasCons << " liters" << endl;

    }
};

class HeavyTruck : public Vehicle{
private:
    int m_gasCons = 2;

public:
    HeavyTruck(){};
    HeavyTruck(string plate, string description): Vehicle(plate, description){};

    void ShowMe(){
        float routeSum = 0;

        for (size_t i=0; i<m_route.size(); i++){
            routeSum += m_route.at(i).second;
        }
    
        cout << "Vehicle: " << m_plate << " - " << "Distance: " << routeSum << " - " << "Gas consumed: " << routeSum/m_gasCons << " liters" << endl;

    }
};


int main(){

    int i = 10;
    int option;
    vector<Vehicle> listofVehicles;
    int vehicle_id;
    string vehicle_plate;
    string vehicle_description;
    string city_name;
    float city_distance;

    while(i != 0){
        printMenu();
        cin >> option;

        if (option == 1){
            cout << "Set the vehicle's plate: " << endl;
            cin >> vehicle_plate;

            printOption1();
            cin >> vehicle_id;

            cout << "Set the vehicle's description: " << endl;
            cin >> vehicle_description; 

            if(vehicle_id == 1){
                listofVehicles.push_back(Car(vehicle_plate, vehicle_description));
            };

            if (vehicle_id == 2){
                listofVehicles.push_back(Bus(vehicle_plate, vehicle_description));
            };

            if (vehicle_id == 3){
                listofVehicles.push_back(LightTruck(vehicle_plate, vehicle_description));
            };

            if (vehicle_id == 4){
                listofVehicles.push_back(HeavyTruck(vehicle_plate, vehicle_description));
            };
        }

        if (option == 2){
            cout << "Set the vehicle's plate: " << endl;
            cin >> vehicle_plate;

            for (size_t j=0; j<listofVehicles.size(); j++){
                if (vehicle_plate == listofVehicles.at(j).getPlate()){
                    cout << "Set the city's name: " << endl;
                    cin >> city_name;
                    cout << "Set the distance from that city (in km): " << endl;
                    cin >> city_distance;

                    listofVehicles.at(j).setRoute(city_name, city_distance);
                }
            }

        }

        if (option == 3){
            Vehicle *p;

            for(size_t u=0; u<listofVehicles.size(); u++){
                p = &listofVehicles.at(u);
                p -> ShowMe();
            }

        }

        if (option == 4){
            cout << "Set the vehicle's plate: " << endl;
            cin >> vehicle_plate;

            for (size_t q=0; q<listofVehicles.size(); q++){
                if (vehicle_plate == listofVehicles.at(q).getPlate()){
                    listofVehicles.at(q).getCity();
                    cout << "Total distance: " << endl;
                    listofVehicles.at(q).getDistance();
                }
            }
        }

        if (option == 0){
            break;
        }
    }
};



