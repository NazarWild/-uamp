# Install script for directory: /Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/okolevatov/.brew")
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
   "/Users/okolevatov/.brew/lib/libtag.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/okolevatov/.brew/lib" TYPE STATIC_LIBRARY FILES "/Users/okolevatov/okolevatov/uamp/build/3dparty/taglib/taglib/libtag.a")
  if(EXISTS "$ENV{DESTDIR}/Users/okolevatov/.brew/lib/libtag.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/okolevatov/.brew/lib/libtag.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}/Users/okolevatov/.brew/lib/libtag.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/okolevatov/.brew/include/taglib/tag.h;/Users/okolevatov/.brew/include/taglib/fileref.h;/Users/okolevatov/.brew/include/taglib/audioproperties.h;/Users/okolevatov/.brew/include/taglib/taglib_export.h;/Users/okolevatov/.brew/include/taglib/taglib_config.h;/Users/okolevatov/.brew/include/taglib/taglib.h;/Users/okolevatov/.brew/include/taglib/tstring.h;/Users/okolevatov/.brew/include/taglib/tlist.h;/Users/okolevatov/.brew/include/taglib/tlist.tcc;/Users/okolevatov/.brew/include/taglib/tstringlist.h;/Users/okolevatov/.brew/include/taglib/tbytevector.h;/Users/okolevatov/.brew/include/taglib/tbytevectorlist.h;/Users/okolevatov/.brew/include/taglib/tbytevectorstream.h;/Users/okolevatov/.brew/include/taglib/tiostream.h;/Users/okolevatov/.brew/include/taglib/tfile.h;/Users/okolevatov/.brew/include/taglib/tfilestream.h;/Users/okolevatov/.brew/include/taglib/tmap.h;/Users/okolevatov/.brew/include/taglib/tmap.tcc;/Users/okolevatov/.brew/include/taglib/tpropertymap.h;/Users/okolevatov/.brew/include/taglib/trefcounter.h;/Users/okolevatov/.brew/include/taglib/tdebuglistener.h;/Users/okolevatov/.brew/include/taglib/mpegfile.h;/Users/okolevatov/.brew/include/taglib/mpegproperties.h;/Users/okolevatov/.brew/include/taglib/mpegheader.h;/Users/okolevatov/.brew/include/taglib/xingheader.h;/Users/okolevatov/.brew/include/taglib/id3v1tag.h;/Users/okolevatov/.brew/include/taglib/id3v1genres.h;/Users/okolevatov/.brew/include/taglib/id3v2.h;/Users/okolevatov/.brew/include/taglib/id3v2extendedheader.h;/Users/okolevatov/.brew/include/taglib/id3v2frame.h;/Users/okolevatov/.brew/include/taglib/id3v2header.h;/Users/okolevatov/.brew/include/taglib/id3v2synchdata.h;/Users/okolevatov/.brew/include/taglib/id3v2footer.h;/Users/okolevatov/.brew/include/taglib/id3v2framefactory.h;/Users/okolevatov/.brew/include/taglib/id3v2tag.h;/Users/okolevatov/.brew/include/taglib/attachedpictureframe.h;/Users/okolevatov/.brew/include/taglib/commentsframe.h;/Users/okolevatov/.brew/include/taglib/eventtimingcodesframe.h;/Users/okolevatov/.brew/include/taglib/generalencapsulatedobjectframe.h;/Users/okolevatov/.brew/include/taglib/ownershipframe.h;/Users/okolevatov/.brew/include/taglib/popularimeterframe.h;/Users/okolevatov/.brew/include/taglib/privateframe.h;/Users/okolevatov/.brew/include/taglib/relativevolumeframe.h;/Users/okolevatov/.brew/include/taglib/synchronizedlyricsframe.h;/Users/okolevatov/.brew/include/taglib/textidentificationframe.h;/Users/okolevatov/.brew/include/taglib/uniquefileidentifierframe.h;/Users/okolevatov/.brew/include/taglib/unknownframe.h;/Users/okolevatov/.brew/include/taglib/unsynchronizedlyricsframe.h;/Users/okolevatov/.brew/include/taglib/urllinkframe.h;/Users/okolevatov/.brew/include/taglib/chapterframe.h;/Users/okolevatov/.brew/include/taglib/tableofcontentsframe.h;/Users/okolevatov/.brew/include/taglib/podcastframe.h;/Users/okolevatov/.brew/include/taglib/oggfile.h;/Users/okolevatov/.brew/include/taglib/oggpage.h;/Users/okolevatov/.brew/include/taglib/oggpageheader.h;/Users/okolevatov/.brew/include/taglib/xiphcomment.h;/Users/okolevatov/.brew/include/taglib/vorbisfile.h;/Users/okolevatov/.brew/include/taglib/vorbisproperties.h;/Users/okolevatov/.brew/include/taglib/oggflacfile.h;/Users/okolevatov/.brew/include/taglib/speexfile.h;/Users/okolevatov/.brew/include/taglib/speexproperties.h;/Users/okolevatov/.brew/include/taglib/opusfile.h;/Users/okolevatov/.brew/include/taglib/opusproperties.h;/Users/okolevatov/.brew/include/taglib/flacfile.h;/Users/okolevatov/.brew/include/taglib/flacpicture.h;/Users/okolevatov/.brew/include/taglib/flacproperties.h;/Users/okolevatov/.brew/include/taglib/flacmetadatablock.h;/Users/okolevatov/.brew/include/taglib/apefile.h;/Users/okolevatov/.brew/include/taglib/apeproperties.h;/Users/okolevatov/.brew/include/taglib/apetag.h;/Users/okolevatov/.brew/include/taglib/apefooter.h;/Users/okolevatov/.brew/include/taglib/apeitem.h;/Users/okolevatov/.brew/include/taglib/mpcfile.h;/Users/okolevatov/.brew/include/taglib/mpcproperties.h;/Users/okolevatov/.brew/include/taglib/wavpackfile.h;/Users/okolevatov/.brew/include/taglib/wavpackproperties.h;/Users/okolevatov/.brew/include/taglib/trueaudiofile.h;/Users/okolevatov/.brew/include/taglib/trueaudioproperties.h;/Users/okolevatov/.brew/include/taglib/rifffile.h;/Users/okolevatov/.brew/include/taglib/aifffile.h;/Users/okolevatov/.brew/include/taglib/aiffproperties.h;/Users/okolevatov/.brew/include/taglib/wavfile.h;/Users/okolevatov/.brew/include/taglib/wavproperties.h;/Users/okolevatov/.brew/include/taglib/infotag.h;/Users/okolevatov/.brew/include/taglib/asffile.h;/Users/okolevatov/.brew/include/taglib/asfproperties.h;/Users/okolevatov/.brew/include/taglib/asftag.h;/Users/okolevatov/.brew/include/taglib/asfattribute.h;/Users/okolevatov/.brew/include/taglib/asfpicture.h;/Users/okolevatov/.brew/include/taglib/mp4file.h;/Users/okolevatov/.brew/include/taglib/mp4atom.h;/Users/okolevatov/.brew/include/taglib/mp4tag.h;/Users/okolevatov/.brew/include/taglib/mp4item.h;/Users/okolevatov/.brew/include/taglib/mp4properties.h;/Users/okolevatov/.brew/include/taglib/mp4coverart.h;/Users/okolevatov/.brew/include/taglib/modfilebase.h;/Users/okolevatov/.brew/include/taglib/modfile.h;/Users/okolevatov/.brew/include/taglib/modtag.h;/Users/okolevatov/.brew/include/taglib/modproperties.h;/Users/okolevatov/.brew/include/taglib/itfile.h;/Users/okolevatov/.brew/include/taglib/itproperties.h;/Users/okolevatov/.brew/include/taglib/s3mfile.h;/Users/okolevatov/.brew/include/taglib/s3mproperties.h;/Users/okolevatov/.brew/include/taglib/xmfile.h;/Users/okolevatov/.brew/include/taglib/xmproperties.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/okolevatov/.brew/include/taglib" TYPE FILE FILES
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/tag.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/fileref.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/audioproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/taglib_export.h"
    "/Users/okolevatov/okolevatov/uamp/build/3dparty/taglib/taglib/../taglib_config.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/taglib.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tstring.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tlist.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tlist.tcc"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tstringlist.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tbytevector.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tbytevectorlist.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tbytevectorstream.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tiostream.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tfilestream.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tmap.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tmap.tcc"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tpropertymap.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/trefcounter.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/toolkit/tdebuglistener.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/mpegfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/mpegproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/mpegheader.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/xingheader.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v1/id3v1tag.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v1/id3v1genres.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2extendedheader.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2frame.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2header.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2synchdata.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2footer.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2framefactory.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/id3v2tag.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/commentsframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/eventtimingcodesframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/ownershipframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/privateframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/synchronizedlyricsframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/unknownframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/urllinkframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/chapterframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/tableofcontentsframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpeg/id3v2/frames/podcastframe.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/oggfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/oggpage.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/oggpageheader.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/xiphcomment.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/vorbis/vorbisfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/vorbis/vorbisproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/flac/oggflacfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/speex/speexfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/speex/speexproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/opus/opusfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ogg/opus/opusproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/flac/flacfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/flac/flacpicture.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/flac/flacproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/flac/flacmetadatablock.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ape/apefile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ape/apeproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ape/apetag.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ape/apefooter.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/ape/apeitem.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpc/mpcfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mpc/mpcproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/wavpack/wavpackfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/wavpack/wavpackproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/trueaudio/trueaudiofile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/trueaudio/trueaudioproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/riff/rifffile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/riff/aiff/aifffile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/riff/aiff/aiffproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/riff/wav/wavfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/riff/wav/wavproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/riff/wav/infotag.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/asf/asffile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/asf/asfproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/asf/asftag.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/asf/asfattribute.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/asf/asfpicture.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mp4/mp4file.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mp4/mp4atom.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mp4/mp4tag.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mp4/mp4item.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mp4/mp4properties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mp4/mp4coverart.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mod/modfilebase.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mod/modfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mod/modtag.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/mod/modproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/it/itfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/it/itproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/s3m/s3mfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/s3m/s3mproperties.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/xm/xmfile.h"
    "/Users/okolevatov/okolevatov/uamp/3dparty/taglib/taglib/xm/xmproperties.h"
    )
endif()

