#include<iostream>
#include "Movie.h"

Movie::Movie(string name, string rating, int watched)
    :name{name}, rating{rating}, watched{watched} {

}

Movie::Movie(const Movie &source)
    :Movie{source.name, source.rating, source.watched} {

}

void Movie::display() const {
    std::cout << name << " , " << rating << " , " << watched << std::endl;
}