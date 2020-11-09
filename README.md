# 💽 Audio Player "Le Audio Playero"

## Description
Text editor made with Qt GUI

## How to use

### Must Have (dependencies)
- CMake 3.18.2 or above - https://cmake.org/download
- Qt 5.15 or above - https://www.qt.io/download

### Building
##### First step
If you do not have ```CMAKE_PREFIX_PATH``` you can fix it in 2 ways:
- go into ```utag/CMakeLists.txt``` and add ```set(CMAKE_PREFIX_PATH "/your/path/to/qt")```
- or you can just write in terminal ```export CMAKE_PREFIX_PATH=/your/path/to/qt```

##### Second step
    ./build.sh

### Run
    ./uamp 

## App features
- support these audio formats:mp3 ,mp4 ,wav
- support such standard options:
	• play - to start playing the song
	• paus e- to temporarily interrupt the song
	• stop - to completely interrupt the song
	• fast forward - to play the song forward for 10 seconds
	• rewind - to play the song back for 10 seconds
	• next - to play the next song in the Queue
	• previous - to play the previous song in the Queue
- control sound volume
- control bass volume (bass booster)
- autoplay the next song in the Queue
- create/read/update and delete personal playlists
- import/export playlists in at least one standard playlist format e.g.m3u
- add and remove songs from the Queue
- loop (repeat) a single song or Queue
- shuffle songs listed in the Queue
- sort songs listed in the Queue by title, genre, etc.
- edit songs album art using pictures on the computer
- save its state. The program restores all data after an app restart. 
- support displaying/editing of the audio tags listed below for all supported audio formats:
	• Artist
	• Title
	• Album
	• Genre
	• Audio file path
