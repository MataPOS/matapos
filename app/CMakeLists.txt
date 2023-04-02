add_executable(matapos src/main.cpp)

target_link_libraries(matapos barcodereader window camera database)
