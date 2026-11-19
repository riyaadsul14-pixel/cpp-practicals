
#include <iostream>
using namespace std;

class ApplicationSettings {
private:
    static ApplicationSettings* instance;

    int volume;

    // Private constructor
    ApplicationSettings() {
        volume = 50;
        cout << "Settings object created." << endl;
    }

public:
    // Function to get the single instance
    static ApplicationSettings* getInstance() {
        if (instance == nullptr) {
            instance = new ApplicationSettings();
        }
        return instance;
    }

    void setVolume(int v) {
        volume = v;
    }

    void displaySettings() {
        cout << "Volume: " << volume << endl;
    }
};

// Initialize static instance
ApplicationSettings* ApplicationSettings::instance = nullptr;

int main() {
    cout << "First call:" << endl;

    ApplicationSettings* settings1 =
        ApplicationSettings::getInstance();

    settings1->setVolume(80);
    settings1->displaySettings();

    cout << "\nSecond call:" << endl;

    ApplicationSettings* settings2 =
        ApplicationSettings::getInstance();

    settings2->displaySettings();

    if (settings1 == settings2) {
        cout << "\nBoth pointers refer to the same object."
             << endl;
    }

    return 0;
}
