#include<iostream>
#include "Movies.h"

Movies::Movies() {
}


bool Movies::add_movie(string name, string rating, int watched) {
    for(const auto &values: movies) {
        if(values.get_name() == name)
            return false;
    }
    Movie add{name, rating, watched};
    movies.push_back(add);
    return 1;
}

bool Movies::increment_watched(string name) {
    for(auto &values: movies) {
        if(values.get_name() == name) {
            values.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (movies.size() == 0)
        cout << "List is empty" << endl;
    else {
        cout << "==================================================" << endl;
        for(const auto &values: movies)
            values.display();
        cout << "==================================================" << endl;
    }
}

Movies::~Movies() {
}
