#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <iconv.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>         
#include <openssl/md5.h>
#include <fcntl.h>

#define yellow "\033[33m"
#define none "\033[0m"

char *table[192]={
	"Blues","Classic Rock","Country","Dance","Disco","Funk","Grunge","Hip-Hop","Jazz","Metal","New Age","Oldies","Other",
	"Pop","R&B","Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack",
	"Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz+Funk","Fusion","Trance","Classical","Instrumental","Acid","House",
	"Game","Sound Clip","Gospel","Noise","Alternative Rock","Bass","Soul","Punk","Space","Meditative","Instrumental Pop",
    "Instrumental Rock","Ethnic","Gothic","Darkwave","Techno-Industrial","Electronic","Pop-Folk","Eurodance","Dream","Southern Rock",
	"Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop/Funk","Jungle","Native US","Cabaret","New Wave","Psychadelic","Rave",
	"Showtunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz","Polka","Retro","Musical","Rock & Roll","Hard Rock","Folk",
	"Folk-Rock","National Folk","Swing","Fast Fusion","Bebob","Latin","Revival","Celtic","Bluegrass","Avantgarde","Gothic Rock",
    "Progressive Rock","Psychedelic Rock","Symphonic Rock","Slow Rock","Big Band","Chorus","Easy Listening","Acoustic","Humour",
	"Speech","Chanson","Opera","Chamber Music","Sonata","Symphony","Booty Bass","Primus","Porn Groove","Satire","Slow Jam","Club",
	"Tango","Samba","Folklore","Ballad","Power Ballad","Rhytmic Soul","Freestyle","Duet","Punk Rock","Drum Solo","Acapella","Euro-House",
	"Dance Hall","Goa","Drum & Bass","Club-House","Hardcore","Terror","Indie","BritPop","Negerpunk","Polsk Punk","Beat","Christian Gangsta",
	"Heavy Metal","Black Metal","Crossover","Contemporary C","Christian Rock","Merengue","Salsa","Thrash Metal","Anime","JPop","SynthPop",
    "Abstract","Art Rock","Baroque","Bhangra","Big beat","Breakbeat","Chillout","Downtempo","Dub","EBM","Eclectic","Electro","Electroclash",
	"Emo","Experimental","Garage","Global","IDM","Illbient","Industro-Goth","Jam Band","Krautrock","Leftfield","Lounge","Math Rock","New Romantic",
    "Nu-Breakz","Post-Punk","Post-Rock","Psytrance","Shoegaze","Space Rock","Trop Rock","World Music","Neoclassical","Audiobook",
	"Audio Theatre","Neue Deutsche Welle","Podcast","Indie-Rock","G-Funk","Dubstep","Garage Rock","Psybient",
};

void help();
void list();
void delete();

typedef struct _data{
    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[28];
    uint8_t is_track;
    uint8_t track;
    uint8_t genre;
}data;