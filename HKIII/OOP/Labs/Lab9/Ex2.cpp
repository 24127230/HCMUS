#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum class Genre { Vietnamese, Western, Korean };
class Song {
protected: 
    string title;
    string lyrics;  
    string artistName;  
    Genre musicGenre;
    int yearOfRelease;
    int numberOfPlays;
public:
    Song(string t, string l, string a, Genre g, int y, int p);
    virtual ~Song() = 0;
    virtual void display() = 0;
    virtual void play() = 0;
    virtual Song* clone() const = 0;
    virtual bool isCopyrighted() const;
};
class RegularSong : public Song {
public:
    RegularSong(string t, string l, string a, Genre g, int y, int p);
    ~RegularSong() override;
    void display() override;
    void play() override;
    RegularSong* clone() const override;
};
class CopyrightedSong : public Song {
private: 
    double copyrightValue;
public:
    CopyrightedSong(string t, string l, string a, Genre g, int y, int p, double val);
    ~CopyrightedSong() override;
    void display() override;
    void play() override;
    CopyrightedSong* clone() const override;
    bool isCopyrighted() const override;
};
class Playlist {
private:
    vector<Song*> songs;
public:
    Playlist();
    ~Playlist();
    void addSong(Song* Song);
    void removeSong(int index);
    void displayPlaylist();
};
class UserAccount {
protected:
    string username;
    string password;
    double balance;
public:
    UserAccount(string u, string p, double b);
    virtual ~UserAccount() = 0;
    virtual void displayInforUser() = 0;
    virtual void listen(Song*) = 0;
};
class RegularAccount : public UserAccount {
public: 
    RegularAccount(string u, string p, double b);
    ~RegularAccount() override;
    void displayInforUser() override;
    void listen(Song*) override;
};
class VIPAccount : public UserAccount {
private:
    int subscriptionMonths;
    double monthlyFee;
public: 
    VIPAccount(string u, string p, double b, int m, double f);
    ~VIPAccount();
    void displayInforUser() override;
    void listen(Song*) override; 
    Song* suggestTopByGenre();
    void renewSubscription();
};
class MusicSystem {
private: 
    vector<Song*> AvailableSongs;
    Playlist myPlayList;
    vector<UserAccount*> UserAccounts;
public:
    MusicSystem();
    ~MusicSystem();
    void loginUser();
    void registerUser();
    void inputSong();
    void outputSong();
    void displayTop5Plays();
};
Song::Song(string t, string l, string a, Genre g, int y, int p)
    : title(t), lyrics(l), artistName(a), musicGenre(g), yearOfRelease(y), numberOfPlays(p) {}
Song::~Song() {}
bool Song::isCopyrighted() {
    return 0;
}
RegularSong::RegularSong(string t, string l, string a, Genre g, int y, int p)
    : Song(t, l, a, g, y, p){}
RegularSong::~RegularSong() {}
void RegularSong::display() {
    cout << "Non-copyrighted song: " << title << endl
         << "Artist: " << artistName << " - " << yearOfRelease << endl
         << "Music genre: " << musicGenre << endl 
         << "Number of plays: " << numberOfPlays;
}
void RegularSong::play() {
    ++numberOfPlays;
    cout << "Playing regular song: " << title << " - " << artistName << endl
         << numberOfPlays << endl
         << "--Lyric--" << endl << lyrics << endl;
}
RegularSong* RegularSong::clone() const {
    return new RegularAccount(*this);
}
CopyrightedSong::CopyrightedSong(string t, string l, string a, Genre g, int y, int p, double val)
    : Song(t, l, a, g, y, p), copyrightValue(val) {}
CopyrightedSong::~CopyrightedSong() {}
void CopyrightedSong::display() {

}
void CopyrightedSong::play() ;
CopyrightedSong* CopyrightedSong::clone() const ;

int main() {

}