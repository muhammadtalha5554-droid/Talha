#include <iostream>
#include <string>

using namespace std;

// Base Class TrafficSignal (Abstract Class)
class TrafficSignal {
private:
    string signalID;
    string location;

protected:
    int greenDuration;
    int redDuration;

public:
    // Constructor
    TrafficSignal(string id, string loc, int green, int red)
        : signalID(id), location(loc), greenDuration(green), redDuration(red) {}

    // Pure virtual function
    virtual void displayStatus() = 0;

    // Getter functions
    string getSignalID() const { return signalID; }
    string getLocation() const { return location; }
    int getGreenDuration() const { return greenDuration; }
    int getRedDuration() const { return redDuration; }

    // Virtual destructor
    virtual ~TrafficSignal() {}
};

// Derived Class VehicleSensorSignal
class VehicleSensorSignal : public TrafficSignal {
private:
    int vehicleCount;

public:
    // Constructor
    VehicleSensorSignal(string id, string loc, int green, int red, int count)
        : TrafficSignal(id, loc, green, red), vehicleCount(count) {}

    // Override displayStatus()
    void displayStatus() {
        cout << "Vehicle Sensor Signal Information" << endl;
        cout << "Signal ID: " << getSignalID() << endl;
        cout << "Location: " << getLocation() << endl;
        cout << "Green Duration: " << greenDuration << endl;
        cout << "Red Duration: " << redDuration << endl;
        cout << "Vehicle Count: " << vehicleCount << endl;
    }

    // Calculate efficiency
    float calculateEfficiency() {
        return (float)greenDuration / (greenDuration + redDuration) * 100;
    }
};

// Derived Class PedestrianSensorSignal
class PedestrianSensorSignal : public TrafficSignal {
private:
    int pedestrianCount;
    bool emergencyMode;

public:
    // Constructor
    PedestrianSensorSignal(string id, string loc, int green, int red,
                           int count, bool emergency)
        : TrafficSignal(id, loc, green, red),
          pedestrianCount(count),
          emergencyMode(emergency) {}

    // Override displayStatus()
    void displayStatus() {
        cout << "Pedestrian Sensor Signal Information" << endl;
        cout << "Signal ID: " << getSignalID() << endl;
        cout << "Location: " << getLocation() << endl;
        cout << "Green Duration: " << greenDuration << endl;
        cout << "Red Duration: " << redDuration << endl;
        cout << "Pedestrian Count: " << pedestrianCount << endl;
        cout << "Emergency Mode: "
             << (emergencyMode ? "True" : "False") << endl;
    }

    // Access protected member greenDuration
    int getPedestrianGreenDuration() {
        return greenDuration;
    }
};

int main() {
    // Create VehicleSensorSignal object
    VehicleSensorSignal vehicleSignal(
        "V347", "Main Street", 60, 40, 25);

    // Create PedestrianSensorSignal object
    PedestrianSensorSignal pedestrianSignal(
        "P347", "Central Park", 50, 60, 30, true);

    // Display Vehicle Signal Information
    vehicleSignal.displayStatus();
    cout << endl;

    // Display Pedestrian Signal Information
    pedestrianSignal.displayStatus();
    cout << endl;

    // Display Efficiency
    cout << "Signal Efficiency: "
         << vehicleSignal.calculateEfficiency()
         << "%" << endl;

    // Display Green Duration
    cout << "Green Duration of Pedestrian Signal: "
         << pedestrianSignal.getPedestrianGreenDuration()
         << endl;

    return 0;
}
