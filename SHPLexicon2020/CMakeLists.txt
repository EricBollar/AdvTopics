cmake_minimum_required(VERSION 3.14)
project(SHPLexicon)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(LexiconTest lexiconmain.cpp shplexicon.cpp shplexicon.h)

add_executable(Boggle bogglemain.cpp shplexicon.cpp shplexicon.h)

add_executable(SpellCheck spellcheckmain.cpp shplexicon.cpp shplexicon.h)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SpellCheck ${SFML_LIBRARIES})
endif()

