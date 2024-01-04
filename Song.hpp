#pragma once

#include <string>

class Song {
private:
    std::string name_;
    std::string artist_;
    std::string album_;
    unsigned int duration_;
    bool explicit_lyrics_;

public:
    Song(std::string, std::string, std::string, unsigned int, bool);
    std::string name();
    std::string artist();
    std::string album();
    unsigned int minutes();
    unsigned int seconds();
    bool explicit_lyrics();
};
 Song::Song(std::string newname,std::string newartist, std::string newalbum, unsigned int newduration, bool newexplicit_lyrics){ // initializing all values in list
                                                                                                                      // as if a song has not been chosen yet
  name_ = newname;
  artist_ = newartist;
  album_ = newalbum;
  duration_ = newduration;
  explicit_lyrics_ = newexplicit_lyrics;
}
std::string Song::name(){ // returns name of song.

  return name_;
}
std::string Song::artist(){ // returns song artist.
  return artist_;
}
std::string Song::album(){ // returns the album title.
  return album_;
}
unsigned int Song::minutes(){ // returns the number of minutes in the song.
duration_ = duration_/60;
return duration_;
}
unsigned int Song::seconds(){ // returns the remaining seconds after minutes have been calculated.
  duration_ = duration_%60;
  return duration_;
}
bool Song::explicit_lyrics(){ //retruns whether or not the song has explicit lyrics.
  return explicit_lyrics_;
}
