#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Calculator_mode.h"
using namespace std;
int getChoice(int max_choice);

int main(){
    Calculator_mode calc;
    Calculator_mode* calcPtr = &calc;
    calcPtr->welcome();
    calcPtr->set_choice(getChoice(8));
    return 0;
}

int getChoice(int max_choice){
    string input;
    int choice;
    cout << "\nPlease enter your choice (1 to "<<max_choice<<"): ";
try {
        cin >> input;

        for (char c : input) {
            if (!isdigit(c)) { // neu co dau khac so nguyen
                throw invalid_argument("\nInvalid input! Enter a WHOLE NUMBER between 1 and " + to_string(max_choice) + ".");
            }
        }

        // Chuyen doi thanh so nguyen
        choice = stoi(input);

        // gia tri hop le
        if (choice < 1 || choice > max_choice) {
            throw out_of_range("\nOut of range! Select a number between 1 and " + to_string(max_choice) + ".");
        }

        return choice; // choice hop le

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bo qua input khong hop le
        return getChoice(max_choice); // thu lai
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
        return getChoice(max_choice); // thu lai
    }
}