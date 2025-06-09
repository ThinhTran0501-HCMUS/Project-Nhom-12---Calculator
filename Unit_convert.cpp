#include "Unit_convert.h"
#include <limits>
#include <cmath>

Unit_convert::Unit_convert() : firstUnit("empty"), secondUnit("empty"), conversionFactor(1), conversionOffset(0), choice(0) {}

void Unit_convert::welcome() {
    cout << "\nUNIT CONVERTER\n";
    cout << "Select the type of unit to convert:\n";
    cout << "  1. Temperature\n";
    cout << "  2. Length\n";
    cout << "  3. Area\n";
    cout << "  4. Mass\n";
    cout << "  5. Velocity\n";
    cout << "  6. Pressure\n";
    cout << "  7. Energy\n";
    cout << "  8. Power\n";
    cout << "  9. Return to Main Menu\n";
}

void Unit_convert::print_name() {
    cout << "\nMode: Unit Converter\n";
}

void Unit_convert::set_choice(int c) {
    choice = c;
}

int Unit_convert::get_choice() {
    return choice;
}

void Unit_convert::parse_operation(const string&) {
    while (true) {
        welcome();
        cout << "\nEnter choice: ";
        int cat;
        cin >> cat;
        set_choice(cat);

        switch (cat) {
            case 1: temperature_menu(); break;
            case 2: length_menu(); break;
            case 3: area_menu(); break;
            case 4: mass_menu(); break;
            case 5: velocity_menu(); break;
            case 6: pressure_menu(); break;
            case 7: energy_menu(); break;
            case 8: power_menu(); break;
            case 9:
                cout << "Returning to main menu...\n";
                return;
            default:
                cout << "Invalid selection!\n";
                break;
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
}

double Unit_convert::convert(const string& first, const string& second, double val, double factor, double offset) {
    double result = val * factor + offset;
    cout << val << " " << first << " = " << result << " " << second << "\n";
    return result;
}

double Unit_convert::convertByOffset(const string& first, const string& second, double val, double factor, double offset) {
    double result = (val + offset) * factor;
    cout << val << " " << first << " = " << result << " " << second << "\n";
    return result;
}

// Temperature
void Unit_convert::temperature_menu() {
    int choice;
    double input;
    cout << "1. C to F\n2. F to C\n3. C to K\n4. K to C\n5. K to F\n6. F to K\n> ";
    cin >> choice;
    cout << "Enter value: "; cin >> input;
    switch (choice) {
        case 1: convert("C", "F", input, 1.8, 32); break;
        case 2: convertByOffset("F", "C", input, 5.0/9.0, -32); break;
        case 3: convert("C", "K", input, 1, 273.15); break;
        case 4: convert("K", "C", input, 1, -273.15); break;
        case 5: convert("K", "F", input, 1.8, -459.67); break;
        case 6: convertByOffset("F", "K", input, 5.0/9.0, -32); break;
        default: cout << "Invalid.\n";
    }
}

// Length
void Unit_convert::length_menu() {
    int choice; double v;
    cout << "1. m to ft\n2. ft to m\n3. m to yd\n4. yd to m\n5. km to mi\n6. mi to km\n7. cm to banana\n> ";
    cin >> choice;
    cout << "Enter value: "; cin >> v;
    switch (choice) {
        case 1: convert("m", "ft", v, 3.28084, 0); break;
        case 2: convert("ft", "m", v, 0.3048, 0); break;
        case 3: convert("m", "yd", v, 1.09361, 0); break;
        case 4: convert("yd", "m", v, 0.9144, 0); break;
        case 5: convert("km", "mi", v, 0.621371, 0); break;
        case 6: convert("mi", "km", v, 1.60934, 0); break;
        case 7: convert("cm", "banana(s)", v, 1.0/18.55236432, 0); break;
        default: cout << "Invalid.\n";
    }
}

// Area
void Unit_convert::area_menu() {
    int choice; double v;
    cout << "1. m² to ft²\n2. ft² to m²\n3. m² to yd²\n4. yd² to m²\n5. km² to mi²\n6. mi² to km²\n7. km² to ha\n8. km² to football field\n> ";
    cin >> choice; cout << "Enter value: "; cin >> v;
    switch (choice) {
        case 1: convert("m²", "ft²", v, 10.7639, 0); break;
        case 2: convert("ft²", "m²", v, 0.092903, 0); break;
        case 3: convert("m²", "yd²", v, 1.19599, 0); break;
        case 4: convert("yd²", "m²", v, 0.83613, 0); break;
        case 5: convert("km²", "mi²", v, 0.386102, 0); break;
        case 6: convert("mi²", "km²", v, 2.58999, 0); break;
        case 7: convert("km²", "ha", v, 100, 0); break;
        case 8: convert("km²", "football fields", v, 140, 0); break;
        default: cout << "Invalid.\n";
    }
}

// Mass
void Unit_convert::mass_menu() {
    int choice; double v;
    cout << "1. kg to lb\n2. lb to kg\n3. g to oz\n4. oz to g\n> ";
    cin >> choice; cout << "Enter value: "; cin >> v;
    switch (choice) {
        case 1: convert("kg", "lb", v, 2.20462, 0); break;
        case 2: convert("lb", "kg", v, 1.0/2.20462, 0); break;
        case 3: convert("g", "oz", v, 0.035274, 0); break;
        case 4: convert("oz", "g", v, 1.0/0.035274, 0); break;
        default: cout << "Invalid.\n";
    }
}

// Velocity
void Unit_convert::velocity_menu() {
    int c; double v;
    cout << "1. m/s to ft/s\n2. ft/s to m/s\n3. km/h to m/s\n4. m/s to km/h\n5. knot to km/h\n6. km/h to knot\n> ";
    cin >> c; cout << "Value: "; cin >> v;
    switch (c) {
        case 1: convert("m/s", "ft/s", v, 3.28084, 0); break;
        case 2: convert("ft/s", "m/s", v, 1.0/3.28084, 0); break;
        case 3: convert("km/h", "m/s", v, 5.0/18, 0); break;
        case 4: convert("m/s", "km/h", v, 3.6, 0); break;
        case 5: convert("knot", "km/h", v, 1.852, 0); break;
        case 6: convert("km/h", "knot", v, 1.0/1.852, 0); break;
        default: cout << "Invalid.\n";
    }
}

// Pressure
void Unit_convert::pressure_menu() {
    int c; double v;
    cout << "1. atm to Pa\n2. Pa to atm\n3. kgf/cm² to Pa\n4. Pa to kgf/cm²\n> ";
    cin >> c; cout << "Value: "; cin >> v;
    switch (c) {
        case 1: convert("atm", "Pa", v, 101325, 0); break;
        case 2: convert("Pa", "atm", v, 1.0/101325, 0); break;
        case 3: convert("kgf/cm²", "Pa", v, 98066.5, 0); break;
        case 4: convert("Pa", "kgf/cm²", v, 1.0/98066.5, 0); break;
        default: cout << "Invalid.\n";
    }
}

// Energy
void Unit_convert::energy_menu() {
    int c; double v;
    cout << "1. J to Cal\n2. Cal to J\n3. J to Wh\n4. Wh to J\n> ";
    cin >> c; cout << "Value: "; cin >> v;
    switch (c) {
        case 1: convert("J", "Cal", v, 0.239006, 0); break;
        case 2: convert("Cal", "J", v, 1.0/0.239006, 0); break;
        case 3: convert("J", "Wh", v, 1.0/3600, 0); break;
        case 4: convert("Wh", "J", v, 3600, 0); break;
        default: cout << "Invalid.\n";
    }
}

//Power
void Unit_convert::power_menu() {
    int c; double v;
    cout << "1. HP to kW\n2. kW to HP\n> ";
    cin >> c; cout << "Value: "; cin >> v;
    switch (c) {
        case 1: convert("HP", "kW", v, 0.7457, 0); break;
        case 2: convert("kW", "HP", v, 1.0/0.7457, 0); break;
        default: cout << "Invalid.\n";
    }
}