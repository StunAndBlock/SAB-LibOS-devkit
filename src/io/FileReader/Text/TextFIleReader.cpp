#include "io/FileReader/Text/TextFileReader.hpp"

namespace sab::ioos {
    TextFileReader::TextFileReader(TextFileReader&& source) noexcept
        : BaseFileReader(std::move(source)){

        }
    void  TextFileReader::open(const char* fileName){
        file_.open(fileName);
        if (file_.is_open()){
            status_ = Status::OK;
        } else {
            status_ = Status::OPEN_ERROR;
        }
    }
    void  TextFileReader::open(const std::string& fileName){
        open(fileName.c_str());
    }
}