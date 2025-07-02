#ifndef SAB_IO_BASE_FILEREADER_HPP_
#define SAB_IO_BASE_FILEREADER_HPP_

#include "io/FileReader/BaseFileReaderTemplated.hpp"

namespace sab::ioos {
    class BaseFileReader : public BaseFileReaderTemplated<char> {
    public:
        BaseFileReader() : BaseFileReaderTemplated<char>() {};
        BaseFileReader(BaseFileReader&&) noexcept;
        
        virtual void open(const char*) override = 0;
        virtual void open(const std::string&) override = 0;
    };

}


















#endif //!SAB_IO_BASE_FILEREADER_HPP_