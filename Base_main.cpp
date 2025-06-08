#include "Base_of_N_conver.h"

int main() {
    while (true) {
        int choice;
        cout << "\nChoose the base:\n";
        cout << "1. BIN\n2. OCT\n3. DEC\n4. HEX\n";
        cout << "Press any key to exit...\n";
        cout << ">> ";
        try{
        cin >> choice;

        if (choice < 1 || choice > 4) {
            cout << "\nBye!\n";
            break;
        }

        
            Base b(choice);
            cout << "\n===###$$$%^^^===\n";
            b.display();
        } catch (const exception& e) {
            cout << "Expection: " << e.what() << endl;
        }
    }

    return 0;
}
