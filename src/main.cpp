#include "io/FileReader/Text/TextFileReader.hpp"


#include <iostream>

int main(){
    sab::ioos::TextFileReader tfr;
    tfr.open("testfile");
    if (tfr.getStatus() == sab::ioos::Status::BaseFileReaderTemplated::OK) {
        std::cout << "yay";
    } else if (tfr.getStatus() == sab::ioos::Status::BaseFileReaderTemplated::OPEN_ERROR){
        std::cout << "yay but open error";
    }
    return 0;
}