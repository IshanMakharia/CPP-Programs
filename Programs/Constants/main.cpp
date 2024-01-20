#include <iostream>

using namespace std;

int main()
{
    cout << "Estimate for carpet cleaning service" << endl;
    
    int number_of_srooms{0};
    cout << "Number of small rooms: ";
    cin >> number_of_srooms;
    
    int number_of_lrooms{0};
    cout << "Number of large rooms: ";
    cin >> number_of_lrooms;
    
    const double price_per_sroom{25};
    const double price_per_lroom{35};
    cout << "Price per small rooms: $" << price_per_sroom << endl;
    cout << "Price per large rooms: $" << price_per_lroom << endl;
    
    double cost{price_per_sroom*number_of_srooms + price_per_lroom*number_of_lrooms};
    cout << "Cost: $" << cost << endl;
    
    double tax{(cost*6)/100};
    cout << "Tax: $" << tax << endl;
    
    cout << "=====================================" << endl;
    
    double total{cost + tax};
    cout << "Total estimate: $" << total << endl;
    
    cout << "This estimate is valid for 30 days" << endl;
    
    return 0;
    
}