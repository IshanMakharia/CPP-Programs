#include <iostream>
#include <string>
//#include <cctype>
#include "Movie.h"
#include "Movies.h"

using namespace std;

void add_movie(Movies &list, string name, string rating, int watched) {
    for(size_t i = 0; i < name.length(); i++) {
        name[i] = toupper(name[i]);
    }
    for(size_t i = 0; i < rating.length(); i++) {
        rating[i] = toupper(rating[i]);
    }
    if (list.add_movie(name, rating, watched)) 
        cout << name << " - Added successfully!" << endl;
    else 
        cout << name << " - Already there!" << endl;
}

void increment_watched(Movies &list, string name) {
    for(size_t i = 0; i < name.length(); i++)
        name[i] = toupper(name[i]);
    if (list.increment_watched(name))
        cout << name << " - Watch incremented" << endl;
    else
        cout << name << " - Movie is not added"<< endl;
}

int main()
{
    char input;
//    string movie_list_name{};
//    cout << "Enter a name to create a movie list: ";
//    cin >> movie_list_name;
    Movies movie_list_name;
    do{
        cout << "\nSelect an appropriate option:" << endl;
        cout << "A - add movie" << endl;
        cout << "I - increment watched" << endl;
        cout << "D - display movies" << endl;
        cout << "E - exit" << endl;
        cin >> input;
        if (input == 'A' || input == 'a') {
            string movie_name;
            string rating;
            int watched;
            cin.ignore();
            //cin.clear();
            //cin.sync();
            cout << "Enter name of movie: \n";
            getline (cin, movie_name);
            cout << "Enter the " << movie_name << " ratings: ";
            getline(cin, rating);
            cout << "How many times you have watched the " << movie_name << ": ";
            cin >> watched;
            add_movie(movie_list_name, movie_name, rating, watched);
        }
        else if (input == 'I' || input =='i') {
            string name;
            cout << "Enter a existing movie name to increase watch count: ";
            cin.ignore();
            getline(cin, name);
            increment_watched(movie_list_name, name);
        }
        else if (input == 'D' || input == 'd') {
            movie_list_name.display();
        }
        else if (input == 'E' || input == 'e') {
            cout << "Thank you!" << endl;
        }
        else {
            cout << "Invalid option! Please try again." << endl;
        }
        
    }while(input != 'E' && input != 'e');


//    favourites.display();
//    add_movie(favourites, "Money heist" , "*****" , 1);
//    add_movie(favourites, "Into the flight" , "****" , 1);
//    favourites.display();
//    increment_watched(favourites, "Money heist");
//    favourites.display();


    return 0;
}