#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include "Song.hpp"

using namespace std;

void display_menu();
void display_playlist(const list<Song> &playlist, const Song &s);
void display_current_song(const Song &s);
list<Song> reading_from_file(const string &filename);
void writing_to_file(const  list<Song> &playlist, const string &filename);

int main() {
    string filename{"Song_Playlist_1.txt"};
    
    list<Song> playlist = reading_from_file(filename);
    list<Song>::iterator current_song = playlist.begin();
    
    char input[1];
    do{
        display_menu();
        cin >> input[0];
        input[0] = toupper(input[0]);
        if(input[0] == 'F') {
            current_song = playlist.begin();
            cout << "\nPlaying first song of playlist";
            display_current_song(*current_song);
        }
        else if(input[0] == 'N') {
            cout << "\nPlaying next song" << endl;
            current_song++;
            if(current_song == playlist.end()) {
                cout << "wrapping to start of playlist";
                current_song = playlist.begin();
            }
            display_current_song(*current_song);
        }
        else if(input[0] == 'P') {
            cout << "\nPlaying previous song" << endl;
            if(*current_song == playlist.front()) {
                cout << "wrapping to end of playlist";
                current_song = playlist.end();
            }
            current_song--;
            display_current_song(*current_song);
        }
        else if(input[0] == 'A') {
            string name{}, artist{};
            int rating{0};
            cout << "\nAdding and playing new song" << endl;
            cin.clear();
            cin.ignore();
            cout << "Enter song name : ";
            getline(cin, name);
            cout << "Enter song artist : ";
            getline(cin, artist);
            while(true){
                string str_rating{};
                cout << "Enter your rating (1-5) : ";
                getline(cin, str_rating);
                stringstream ss{str_rating};
                if(ss >> rating) {
                    if(1 <= rating && rating <= 5)
                        break;
                    else
                        cout << "\nEnter a valid integer between 1 and 5" << endl;
                }
                else
                    cout << "\nEnter a valid integer between 1 and 5" << endl;
            }
            playlist.insert(current_song, Song{name, artist, rating});
            current_song--;
            display_current_song(*current_song);
        }
        else if(input[0] == 'D') {
            char confirmation[1];
            do{
                cout << "\nAre you sure, you want to delete the current song (Y/N) : ";
                cin >> confirmation[0];
                confirmation[0] = toupper(confirmation[0]);
                if(confirmation[0] == 'Y') {
                    current_song = playlist.erase(current_song);
                    cout << "\nCurrent song deleted" << endl;
                    if(current_song == playlist.end())
                        current_song = playlist.begin();
                    display_current_song(*current_song);
                }
                else if(confirmation[0] == 'N')
                    display_current_song(*current_song);
                else 
                    cout << "\nInvalid option! Please try again" << endl;
            }while(confirmation[0] != 'N' && confirmation[0] != 'Y');
        }
        else if(input[0] == 'L') {
            if(playlist.empty())
                cout << "\nPlaylist is empty" << endl;
            else
                display_playlist(playlist, *current_song);
        }
        else if(input[0] == 'Q'){
            cout << "\nThank You!!\n" << endl;
            writing_to_file(playlist, filename);
        }
        else {
            cout << "\nInvalid option! Please try again" << endl;
        }
    }while(input[0] != 'Q');
    
    return 0;
}

void display_menu() {
    cout << "\n\nF - Play First Song" << endl;
    cout << "N - Play Next Song" << endl;
    cout << "P - Play Previous Song" << endl;
    cout << "A - Add and Play a new song at current location" << endl;
    cout << "D - Delete Current Song" << endl;
    cout << "L - List the Current Playlist" << endl;
    cout << "Q - To Quit" << endl;
    cout << "========================================" << endl;
    cout << "Select an appropriate option : ";
}

void display_playlist(const list<Song> &playlist, const Song &s){
    cout << "\n";
    for(const auto songs : playlist)
        cout << songs << endl;
    display_current_song(s);
}

void display_current_song(const Song &s) {
    cout << "\nNow Playing: \n" << s << endl;
}

list<Song> reading_from_file(const string &filename) {
    ifstream in_file{filename};
    if(!in_file) {
        cerr << "\nFile Opening Error!\n" << endl;
        exit(1);
    }
    list<Song> playlist{};
    string line{};
    while(getline(in_file, line)) {
        stringstream ss {line};
        vector <string> vec{};
        string obj{};
        while(getline(ss, obj, ';')) {
            vec.push_back(obj);
        }
        int rating {};
        stringstream iss{vec.at(2)};
        iss >> rating;
        playlist.emplace_back(vec.at(0), vec.at(1), rating);
    }
    in_file.close();
    return move(playlist);
}

void writing_to_file(const  list<Song> &playlist, const string &filename) {
    ofstream out_file{filename};
    if(!out_file) {
        cerr << "\nFile Opening Error!\n" << endl;
        exit(1);
    }
    for(const auto songs : playlist) {
        out_file << songs.get_name() << ";" << songs.get_artist() << ";" << songs.get_rating() << endl;
    }
    out_file.close();
}