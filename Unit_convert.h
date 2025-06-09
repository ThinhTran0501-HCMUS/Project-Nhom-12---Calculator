#ifndef UNIT_CONVERT_H
#define UNIT_CONVERT_H

#include "Calculator_mode.h"
#include <iostream>
#include <string>
using namespace std;

class Unit_convert : public Calculator_mode {
private:
    string firstUnit;
    string secondUnit;
    double conversionFactor;
    double conversionOffset = 0;
    int choice;

    // internal logic
    static double convert(const string&, const string&, double, double, double);
    static double convertByOffset(const string&, const string&, double, double, double);

    // category menus
    void temperature_menu();
    void length_menu();
    void area_menu();
    void mass_menu();
    void velocity_menu();
    void pressure_menu();
    void energy_menu();
    void power_menu();

public:
    Unit_convert();
    virtual ~Unit_convert() = default;

    virtual void welcome() override;
    virtual void print_name() override;
    virtual void parse_operation(const string& str) override;
    virtual void set_choice(int choice) override;
    virtual int get_choice() override;
};

#endif