add_library(barcodereader src/barcodereader.cpp include/barcodereader.h include/barcodereadercallback.h)

target_include_directories(barcodereader PUBLIC include/)

target_link_libraries(barcodereader camera Threads::Threads PkgConfig::ZBar ${OpenCV_LIBS})

add_subdirectory(test)
