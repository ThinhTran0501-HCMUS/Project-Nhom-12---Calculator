#include <iostream>
#include <iomanip>
#include "Calculator_mode.h"

using namespace std;
void introduction();
int getChoice(int max_choice);

int main(){
    introduction();
    int choice_1 = getChoice(7);
    return 0;
}

void introduction(){
            const int width = 50;
    string title = "SUPER POWER CALCULATOR";

    cout << string(width, '*') << '\n';         // bien tren
    cout << "*" << setw(width - 1) << "*" << '\n';  // khoang trang
    // cout << "*";

    // trung tam data
    int padding = (width - 2 - title.length()) / 2;
    cout <<"*"<< string(padding, ' ') << title;
    cout << string(width - 2 - padding - title.length(), ' ') << "*\n";

    cout << "*" << setw(width - 1) << "*" << '\n';  // khoang trang
    cout << string(width, '*') << '\n';         // bien duoi
    cout << '\n';

    // Cac lua chon
    cout << "Please select a mode:\n\n";

    cout << "  1. Basic Operations\n";
    cout << "  2. Combination\n";
    cout << "  3. Unit Converter\n\n";

    cout << "  4. Polynomial Simplification\n";
    cout << "  5. Base-N Converter\n";
    cout << "  6. Matrix Calculator\n\n";

    cout << "  7. Equation Solver\n";
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