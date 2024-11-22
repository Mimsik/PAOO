cmake_minimum_required(VERSION 3.10)

# Numele proiectului
project(TvShowsPlatform)

# Specificăm standardul C++
set(CMAKE_CXX_STANDARD 17)

# Fișierele sursă
set(SOURCES
    src/main.cpp
    src/TvShow.cpp
    src/LimitedSeries.cpp  # Asigură-te că este inclus
)

# Adaugăm executabilul
add_executable(TvShowsPlatform ${SOURCES})

# Include directoarele header
target_include_directories(TvShowsPlatform PRIVATE include)
