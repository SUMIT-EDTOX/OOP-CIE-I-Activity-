#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SmartDevice {
private:
    string deviceId;
    string location;
    string deviceType;
    bool status;

public:
    SmartDevice(string id, string loc, string type, bool state = false)
        : deviceId(id), location(loc), deviceType(type), status(state) {}

    void toggleStatus() {
        status = !status;
    }

    void display() const {
        cout << "Device ID: " << deviceId
             << " | Type: " << deviceType
             << " | Location: " << location
             << " | Status: " << (status ? "ON" : "OFF") << endl;
    }
};

int main() {
    vector<SmartDevice> home = {
        SmartDevice("D101", "Living Room", "Light", true),
        SmartDevice("D102", "Bedroom", "Thermostat", false),
        SmartDevice("D103", "Main Entrance", "Door Lock", true),
        SmartDevice("D104", "Front Yard", "Security Camera", true)
    };

    cout << "== Smart Home Device Manager Dashboard ==" << endl;
    for (const auto& dev : home) {
        dev.display();
    }

    cout << "\n--- Toggling Bedroom Thermostat ---" << endl;
    home[1].toggleStatus();
    home[1].display();

    return 0;
}
