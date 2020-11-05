# 🗒 Text Editor "Ventana de muerte"

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
    ./utext 

## App features
- open directories and single files;
- list opened directory files and subdirectories in the tree area;
- open files from the Tree area for reading/editing in the text area;
- save files after editing;
- copy/cut/paste options in the Toolbar;
- find and replace options in the Toolbar;
- undo and redo options in the Toolbar;
- keyboard shortcuts for all options from Toolbar. Key combinations must be user- friendly;
- keyboard and mouse management of carriage position;
- ability to select a piece of text with the keyboard as well as the mouse :

    - the selected text is highlighted;
    
    - copy/cut/paste options are applied only for the selected piece of text;
    
    - the selected portion of text is taken for search when find/replace option is applied.
    
- horizontal and vertical scroll if the Text area is smaller than the content available;
- syntax highlighting for source code;
- line wrapping. Fit long lines into display area without horizontal scrolling.
