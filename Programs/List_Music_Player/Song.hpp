#ifndef SONG_HPP
#define SONG_HPP
#include <iostream>
#include <string>

using namespace std;

class Song {
    friend ostream &operator<<(ostream &os, const Song &s);
    string name;
    string artist;
    int rating;
public:
    Song() = default;
    Song(string name, string artist, int rating);
    string get_name() const {return name;}
    string get_artist() const {return artist;}
    int get_rating() const {return rating;}
    bool operator<(const Song &rhs) const;
    bool operator==(const Song &rhs) const;
    ~Song();

};

#endif // SONG_HPP
