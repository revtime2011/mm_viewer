cmake_minimum_required(VERSION 2.6)

project(mm_viewer)

aux_source_directory(../src/mygui_test1 SRC)

include_directories(../usr/include ../usr/include/OGRE ../usr/include/mygui 
	../usr/include/boost ../usr/include/OGRE/Threading
	../usr/include/OIS )

link_directories(../usr/libs/mygui ../usr/libs/OGRE/debug)

add_executable(../bin32d/mm_viewer ${SRC})

target_link_libraries(../bin32d/mm_viewer MyGUIEngine_d.lib MyGUI.OgrePlatform_d.lib OgreMain_d.lib OIS_d.lib)

