#include "Song.hpp"
#include <iomanip>

Song::Song(string name, string artist, int rating)
        :name{name}, artist{artist}, rating{rating} {
            
}

ostream &operator<<(ostream &os, const Song &s) {
    os << setw(20) << left << s.name
         << setw(30) << s.artist
         << setw(2) << s.rating;
    return os;
}

bool Song::operator<(const Song &rhs) const {
    return this->name < rhs.name;
}

bool Song::operator==(const Song &rhs) const {
    return this->name == rhs.name;
}

Song::~Song() {
    
}

