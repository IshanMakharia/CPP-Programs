#ifndef MOVIE_H
#define MOVIE_H

#include<string>

using namespace std;

class Movie {
private:
    string name;
    string rating;
    int watched;
public:
    Movie(string name, string rating, int watched);
    Movie(const Movie &source);
    string get_name() const {return name;}
    void set_name(string name) {this->name = name;}
    string get_rating() const {return rating;}
    void set_rating(string rating) {this->rating = rating;}
    int get_watched() const {return watched;}
    void set_watched(int watched) {this->watched = watched;}
    void increment_watched() {++watched;}
    void display() const;
};

#endif // MOVIE_H
