#include "IO/File/Reader/Text/WTextFileReader.hpp"

namespace sab::ioos {
    WTextFileReader::WTextFileReader(WTextFileReader&& mSrc) noexcept 
        : BaseTextFileReader(std::move(mSrc)){
        
    };
}