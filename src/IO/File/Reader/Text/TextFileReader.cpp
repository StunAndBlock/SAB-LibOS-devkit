#include "IO/File/Reader/Text/TextFileReader.hpp"

namespace sab::ioos {
    TextFileReader::TextFileReader(TextFileReader&& mSrc) noexcept 
        : BaseTextFileReader(std::move(mSrc)){
        
    };
}