#ifndef SAB_IO_FILEREADER_TEXT_TEXTREADER_HPP
#define SAB_IO_FILEREADER_TEXT_TEXTREADER_HPP

#include "io/FileReader/BaseFileReader.hpp"

namespace sab::ioos {
    class TextFileReader : public BaseFileReader {
        private:

        public:
            TextFileReader() : BaseFileReader() {};
            TextFileReader(TextFileReader&&) noexcept;
            void open(const char*) override;
            void open(const std::string&) override;
    };
}


















#endif //!SAB_IO_FILEREADER_TEXT_TEXTREADER_HPP