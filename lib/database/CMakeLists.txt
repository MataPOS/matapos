add_library(database src/database.cpp include/database.h)

target_include_directories(database PUBLIC include/)

target_link_libraries(database Threads::Threads Qt5::Sql entity)

add_subdirectory(test)


