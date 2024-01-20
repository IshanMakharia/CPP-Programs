#ifndef MOVIES_H
#define MOVIES_H

#include<string>
#include<vector>
#include "Movie.h"

using namespace std;

class Movies {
private:
    vector <Movie> movies;
public:
    Movies();
    bool add_movie(string name, string rating, int watched);
    bool increment_watched(string name);
    void display() const;
    ~Movies();
};

#endif // MOVIES_H
