#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include "Calculator_mode.h"
    #include "Basic_calculator.h"
    #include "Combination.h"
    #include "Unit_convert.h"
    #include "Base_of_N_convert.h"
    #include "Polynomial_cal.h"
    #include "Matrix.h"
    #include "Equation_solve.h"
        #include "Two_vars.h"
            #include "Three_vars.h"
        #include "Quadratic_equa.h"
            #include "Quadratic_ine.h"
        #include "Cubic_equa.h"
using namespace std;

int getChoice(int max_choice);
void construct();
void waitingfor(int seconds = 3);

int main() {
    Calculator_mode calc;
        Basic_calculator basiccal;
        Combination combi;
        Unit_convert unitcon;
        Polynomial poly;
        Base baseN;
        Matrix matrix;
        Equation_solve equa;
            Two_vars sys2var;
                Three_vars sys3var;
            Quadratic_equa deg2equa;
                Quadratic_ine deg2ine;
            Cubic_equa deg3equa;
    Calculator_mode* calcPtr = &calc;

    // Main loop
    while (true) {
        calcPtr = &calc;
        calcPtr->welcome();
        calcPtr->set_choice(getChoice(8));

        int choice = calcPtr->get_choice();

        if (choice == 8) {
            cout << "Exiting the calculator.\n";
            waitingfor(3);
            cout<<"Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1: {
                calcPtr = &basiccal;
                calcPtr->welcome();
                string user_input;
                while (true) {
                    cout << "\nEnter operation (or type 'exit' to return): ";
                    cin >> user_input;

                    if (user_input == "exit") {
                        cout << "Returning to main menu...\n\n";
                        waitingfor(3);
                        break;
                    }

                    calcPtr->parse_operation(user_input);
                    cout << endl;
                    waitingfor();
                    calcPtr->welcome();
                }

                break;
            }

            case 2: {
                calcPtr = &combi;
                calcPtr->welcome();
                string user_input;
                while (true) {
                    cout << "\nEnter operation (or type 'exit' to return): ";
                    cin >> user_input;

                    if (user_input == "exit") {
                        cout << "Returning to main menu...\n\n";
                        waitingfor();
                        break;
                    }

                    calcPtr->parse_operation(user_input);
                    waitingfor();
                    cout << endl;
                    calcPtr->welcome();
                }

                break;
            }
            case 3: {
                calcPtr = &unitcon;
                calcPtr->parse_operation("");
                if (calcPtr->get_choice() == 9) {
                    waitingfor();
                }
                break;
            }

            case 4: {
                calcPtr = &poly;
                calcPtr->parse_operation("");
                if (calcPtr->get_choice() == 5) {
                    waitingfor();
                }
                break;
            }

            case 5: {
                calcPtr = &baseN;
                calcPtr->parse_operation("");
                if (calcPtr->get_choice() == 5) {
                    waitingfor();
                }
                break;
            }
            case 6: {
                calcPtr = &matrix;
                calcPtr->parse_operation("");
                if (calcPtr->get_choice()==7){
                    waitingfor();
                };
                break;
            }

            case 7: { // Equation Solver
                while (true){
                    calcPtr = &equa; 
                    calcPtr->welcome();
                    calcPtr->set_choice(getChoice(6));
                    int subchoice = calcPtr->get_choice();

                    if (subchoice == 6) {
                        cout << "Returning to main menu...\n\n";
                        waitingfor(3);
                        break;
                    }

                    switch (subchoice){
                        case 1: {
                            calcPtr = &deg2equa; // Use polymorphism to delegate
                            calcPtr->welcome();
                            calcPtr->parse_operation("");
                            waitingfor(6);
                            break;
                        }
                        case 2: {
                            calcPtr = &deg3equa; // Use polymorphism to delegate
                            calcPtr->welcome();
                            calcPtr->parse_operation("");
                            waitingfor(6);
                            break;                            
                        }
                        case 3:{
                            calcPtr = &deg2ine; // Use polymorphism to delegate
                            calcPtr->welcome();
                            calcPtr->parse_operation("");
                            waitingfor(6);
                            break;                           
                        }
                        case 4: {
                            calcPtr = &sys2var; // Use polymorphism to delegate
                            calcPtr->welcome();
                            calcPtr->parse_operation("");
                            waitingfor(6);
                            break;
                        }
                        case 5: {
                            calcPtr = &sys3var; // Use polymorphism to delegate
                            calcPtr->welcome();
                            calcPtr->parse_operation("");
                            waitingfor(6);
                            break;                            
                        }
                        default:
                            construct();
                        break;
                    }
                }
                break;
            }
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
    waitingfor(3);
}

void waitingfor(int seconds) {
    for (int i = seconds; i >= 1; --i) {
        cout << "\rPlease wait for " << i << " second" << (i > 1 ? "s" : "") << "    " << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }

    // Erase the line after countdown
    cout << "\r" << string(40, ' ') << "\r" << flush;
}