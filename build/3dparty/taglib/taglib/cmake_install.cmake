# Install script for directory: /Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/ndykyy/.brew")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/ndykyy/.brew/lib/libtag.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/ndykyy/.brew/lib" TYPE STATIC_LIBRARY FILES "/Users/ndykyy/Desktop/uamp/build/3dparty/taglib/taglib/libtag.a")
  if(EXISTS "$ENV{DESTDIR}/Users/ndykyy/.brew/lib/libtag.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/ndykyy/.brew/lib/libtag.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}/Users/ndykyy/.brew/lib/libtag.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/ndykyy/.brew/include/taglib/tag.h;/Users/ndykyy/.brew/include/taglib/fileref.h;/Users/ndykyy/.brew/include/taglib/audioproperties.h;/Users/ndykyy/.brew/include/taglib/taglib_export.h;/Users/ndykyy/.brew/include/taglib/taglib_config.h;/Users/ndykyy/.brew/include/taglib/taglib.h;/Users/ndykyy/.brew/include/taglib/tstring.h;/Users/ndykyy/.brew/include/taglib/tlist.h;/Users/ndykyy/.brew/include/taglib/tlist.tcc;/Users/ndykyy/.brew/include/taglib/tstringlist.h;/Users/ndykyy/.brew/include/taglib/tbytevector.h;/Users/ndykyy/.brew/include/taglib/tbytevectorlist.h;/Users/ndykyy/.brew/include/taglib/tbytevectorstream.h;/Users/ndykyy/.brew/include/taglib/tiostream.h;/Users/ndykyy/.brew/include/taglib/tfile.h;/Users/ndykyy/.brew/include/taglib/tfilestream.h;/Users/ndykyy/.brew/include/taglib/tmap.h;/Users/ndykyy/.brew/include/taglib/tmap.tcc;/Users/ndykyy/.brew/include/taglib/tpropertymap.h;/Users/ndykyy/.brew/include/taglib/trefcounter.h;/Users/ndykyy/.brew/include/taglib/tdebuglistener.h;/Users/ndykyy/.brew/include/taglib/mpegfile.h;/Users/ndykyy/.brew/include/taglib/mpegproperties.h;/Users/ndykyy/.brew/include/taglib/mpegheader.h;/Users/ndykyy/.brew/include/taglib/xingheader.h;/Users/ndykyy/.brew/include/taglib/id3v1tag.h;/Users/ndykyy/.brew/include/taglib/id3v1genres.h;/Users/ndykyy/.brew/include/taglib/id3v2.h;/Users/ndykyy/.brew/include/taglib/id3v2extendedheader.h;/Users/ndykyy/.brew/include/taglib/id3v2frame.h;/Users/ndykyy/.brew/include/taglib/id3v2header.h;/Users/ndykyy/.brew/include/taglib/id3v2synchdata.h;/Users/ndykyy/.brew/include/taglib/id3v2footer.h;/Users/ndykyy/.brew/include/taglib/id3v2framefactory.h;/Users/ndykyy/.brew/include/taglib/id3v2tag.h;/Users/ndykyy/.brew/include/taglib/attachedpictureframe.h;/Users/ndykyy/.brew/include/taglib/commentsframe.h;/Users/ndykyy/.brew/include/taglib/eventtimingcodesframe.h;/Users/ndykyy/.brew/include/taglib/generalencapsulatedobjectframe.h;/Users/ndykyy/.brew/include/taglib/ownershipframe.h;/Users/ndykyy/.brew/include/taglib/popularimeterframe.h;/Users/ndykyy/.brew/include/taglib/privateframe.h;/Users/ndykyy/.brew/include/taglib/relativevolumeframe.h;/Users/ndykyy/.brew/include/taglib/synchronizedlyricsframe.h;/Users/ndykyy/.brew/include/taglib/textidentificationframe.h;/Users/ndykyy/.brew/include/taglib/uniquefileidentifierframe.h;/Users/ndykyy/.brew/include/taglib/unknownframe.h;/Users/ndykyy/.brew/include/taglib/unsynchronizedlyricsframe.h;/Users/ndykyy/.brew/include/taglib/urllinkframe.h;/Users/ndykyy/.brew/include/taglib/chapterframe.h;/Users/ndykyy/.brew/include/taglib/tableofcontentsframe.h;/Users/ndykyy/.brew/include/taglib/podcastframe.h;/Users/ndykyy/.brew/include/taglib/oggfile.h;/Users/ndykyy/.brew/include/taglib/oggpage.h;/Users/ndykyy/.brew/include/taglib/oggpageheader.h;/Users/ndykyy/.brew/include/taglib/xiphcomment.h;/Users/ndykyy/.brew/include/taglib/vorbisfile.h;/Users/ndykyy/.brew/include/taglib/vorbisproperties.h;/Users/ndykyy/.brew/include/taglib/oggflacfile.h;/Users/ndykyy/.brew/include/taglib/speexfile.h;/Users/ndykyy/.brew/include/taglib/speexproperties.h;/Users/ndykyy/.brew/include/taglib/opusfile.h;/Users/ndykyy/.brew/include/taglib/opusproperties.h;/Users/ndykyy/.brew/include/taglib/flacfile.h;/Users/ndykyy/.brew/include/taglib/flacpicture.h;/Users/ndykyy/.brew/include/taglib/flacproperties.h;/Users/ndykyy/.brew/include/taglib/flacmetadatablock.h;/Users/ndykyy/.brew/include/taglib/apefile.h;/Users/ndykyy/.brew/include/taglib/apeproperties.h;/Users/ndykyy/.brew/include/taglib/apetag.h;/Users/ndykyy/.brew/include/taglib/apefooter.h;/Users/ndykyy/.brew/include/taglib/apeitem.h;/Users/ndykyy/.brew/include/taglib/mpcfile.h;/Users/ndykyy/.brew/include/taglib/mpcproperties.h;/Users/ndykyy/.brew/include/taglib/wavpackfile.h;/Users/ndykyy/.brew/include/taglib/wavpackproperties.h;/Users/ndykyy/.brew/include/taglib/trueaudiofile.h;/Users/ndykyy/.brew/include/taglib/trueaudioproperties.h;/Users/ndykyy/.brew/include/taglib/rifffile.h;/Users/ndykyy/.brew/include/taglib/aifffile.h;/Users/ndykyy/.brew/include/taglib/aiffproperties.h;/Users/ndykyy/.brew/include/taglib/wavfile.h;/Users/ndykyy/.brew/include/taglib/wavproperties.h;/Users/ndykyy/.brew/include/taglib/infotag.h;/Users/ndykyy/.brew/include/taglib/asffile.h;/Users/ndykyy/.brew/include/taglib/asfproperties.h;/Users/ndykyy/.brew/include/taglib/asftag.h;/Users/ndykyy/.brew/include/taglib/asfattribute.h;/Users/ndykyy/.brew/include/taglib/asfpicture.h;/Users/ndykyy/.brew/include/taglib/mp4file.h;/Users/ndykyy/.brew/include/taglib/mp4atom.h;/Users/ndykyy/.brew/include/taglib/mp4tag.h;/Users/ndykyy/.brew/include/taglib/mp4item.h;/Users/ndykyy/.brew/include/taglib/mp4properties.h;/Users/ndykyy/.brew/include/taglib/mp4coverart.h;/Users/ndykyy/.brew/include/taglib/modfilebase.h;/Users/ndykyy/.brew/include/taglib/modfile.h;/Users/ndykyy/.brew/include/taglib/modtag.h;/Users/ndykyy/.brew/include/taglib/modproperties.h;/Users/ndykyy/.brew/include/taglib/itfile.h;/Users/ndykyy/.brew/include/taglib/itproperties.h;/Users/ndykyy/.brew/include/taglib/s3mfile.h;/Users/ndykyy/.brew/include/taglib/s3mproperties.h;/Users/ndykyy/.brew/include/taglib/xmfile.h;/Users/ndykyy/.brew/include/taglib/xmproperties.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/ndykyy/.brew/include/taglib" TYPE FILE FILES
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/tag.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/fileref.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/audioproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/taglib_export.h"
    "/Users/ndykyy/Desktop/uamp/build/3dparty/taglib/taglib/../taglib_config.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/taglib.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tstring.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tlist.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tlist.tcc"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tstringlist.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tbytevector.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tbytevectorlist.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tbytevectorstream.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tiostream.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tfilestream.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tmap.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tmap.tcc"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tpropertymap.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/trefcounter.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/toolkit/tdebuglistener.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/mpegfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/mpegproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/mpegheader.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/xingheader.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v1/id3v1tag.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v1/id3v1genres.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2extendedheader.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2frame.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2header.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2synchdata.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2footer.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2framefactory.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2tag.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/commentsframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/eventtimingcodesframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/ownershipframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/privateframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/synchronizedlyricsframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/unknownframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/urllinkframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/chapterframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/tableofcontentsframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/podcastframe.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/oggfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/oggpage.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/oggpageheader.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/xiphcomment.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/vorbis/vorbisfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/vorbis/vorbisproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/flac/oggflacfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/speex/speexfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/speex/speexproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/opus/opusfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ogg/opus/opusproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/flac/flacfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/flac/flacpicture.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/flac/flacproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/flac/flacmetadatablock.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ape/apefile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ape/apeproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ape/apetag.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ape/apefooter.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/ape/apeitem.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpc/mpcfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mpc/mpcproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/wavpack/wavpackfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/wavpack/wavpackproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/trueaudio/trueaudiofile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/trueaudio/trueaudioproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/riff/rifffile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/riff/aiff/aifffile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/riff/aiff/aiffproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/riff/wav/wavfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/riff/wav/wavproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/riff/wav/infotag.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/asf/asffile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/asf/asfproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/asf/asftag.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/asf/asfattribute.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/asf/asfpicture.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mp4/mp4file.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mp4/mp4atom.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mp4/mp4tag.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mp4/mp4item.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mp4/mp4properties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mp4/mp4coverart.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mod/modfilebase.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mod/modfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mod/modtag.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/mod/modproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/it/itfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/it/itproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/s3m/s3mfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/s3m/s3mproperties.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/xm/xmfile.h"
    "/Users/ndykyy/Desktop/uamp/3dparty/taglib/taglib/xm/xmproperties.h"
    )
endif()

