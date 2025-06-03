#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include "Calculator_mode.h"
#include "Equation_solve.h"
using namespace std;

int getChoice(int max_choice);
void construct();
void waitingfor();

int main() {
    Calculator_mode calc;
    Equation_solve equa;
    Calculator_mode* calcPtr = &calc;

    // Main loop
    while (true) {
        calcPtr = &calc;
        calcPtr->welcome();
        calcPtr->set_choice(getChoice(8));

        int choice = calcPtr->get_choice();

        if (choice == 8) {
            cout << "Exiting the calculator.\n";
            waitingfor();
            cout<<"Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1:
            case 3:
            case 4:
            case 5:
            case 6:
                construct(); // placeholder for other modes
                break;

            case 2: { // Equation Solver
 
                while (true) {
                    calcPtr=&equa; 
                    calcPtr->welcome();
                    calcPtr->set_choice(getChoice(7));
                    int subchoice = calcPtr->get_choice();

                    if (subchoice == 7) {
                        cout << "Returning to main menu...\n\n";
                        waitingfor();
                        break;
                    }

                    // For now, just print that it's under construction
                    construct();
                }
                break;
            }

            case 7:
                construct(); // e.g., Matrix mode
                break;

            default:
                cout << "Unknown option.\n";
                break;
        }
    }

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

void construct(){
    cout << "Sorry, this feature is under development." << endl;
    waitingfor();
}

void waitingfor(){
    for (int i = 3; i >= 1; --i) {
        cout << "\rPlease wait for " << i << " second" << (i > 1 ? "s" : "") << "    " << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }

    // Erase the line after countdown
    cout << "\r" << string(40, ' ') << "\r" << flush;
}