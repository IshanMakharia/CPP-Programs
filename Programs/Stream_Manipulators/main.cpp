#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct City {
    string name;
    long population;
    double cost;
};

struct Country {
    string name;
    vector <City> cities;
};

struct Tours {
    string title;
    vector <Country> countries;
};

int main() {
    Tours  tours { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    {"Bogota", 8778000, 400.98}, 
                    {"Cali", 2401000, 424.12}, 
                    {"Medellin", 2464000, 350.98}, 
                    {"Cartagena", 972000, 345.34}
                }
            }, 
            {
                "Brazil", {
                    {"Rio De Janiero", 13500000, 567.45}, 
                    {"Sao Paulo", 11310000, 975.45}, 
                    {"Salvador", 18234000, 855.99}
                }
            }, 
            {
                "Chile", {
                    {"Valdivia", 260000, 569.12},
                    {"Santiago", 7040000, 520.00}
                }
            }, 
            {
                "Argentina", {
                    {"Buenos Aires", 3010000, 723.77}
                }
            }
        }
    };
    
    const int total_width {60};
    const int field_width_1{15};
    const int field_width_2 {15};
    const int field_width_3 {15};
    const int field_width_4 {15};
    
    cout << "\n\n\n" << setw( (total_width-tours.title.length()) / 2 ) << "" << tours.title << endl << endl;
    cout << setw(field_width_1) << left << "COUNTRIES"
            << setw(field_width_2) << "CITIES"
            << setw(field_width_3) << right << "POPULATION"
            << setw(field_width_4) << "PRICE" << endl;
    cout << setw(total_width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setprecision(2) << fixed << showpoint;
    
    for(auto country: tours.countries) {
        for (size_t i = 0; i < country.cities.size(); i++) {
            cout << setw(field_width_1) << left << ( (i==0) ? country.name : "")
                    << setw(field_width_2) << country.cities.at(i).name
                    << setw(field_width_3) << right << country.cities.at(i).population
                    << setw(field_width_4) << country.cities.at(i).cost << endl;
        }
    }
    cout << "\n" << endl;
    return 0;
}