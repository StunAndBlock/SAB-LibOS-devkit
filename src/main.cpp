#include "IO/File/Reader/Text/TextFileReader.hpp"


#include <iostream>

int main(){
    sab::ioos::TextFileReader tfr;
    tfr.open("testfile");
    if (tfr.getStatus<sab::ioos::TextFileReader::Status>() == sab::ioos::TextFileReader::Status::OK) {
        std::cout << "yay";
    } else if (tfr.getStatus<sab::ioos::TextFileReader::Status>() == sab::ioos::TextFileReader::Status::OPEN_ERROR){
        std::cout << "yay but open error";
    }

    sab::ioos::TextFileReader nn = std::move(tfr);
    std::string str;
    nn.readLine(str); 
    std::cout <<str;
    return 0;
}