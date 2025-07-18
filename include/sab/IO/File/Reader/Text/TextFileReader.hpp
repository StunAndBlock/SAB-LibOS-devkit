#ifndef SAB_IO_TEXTFILEREADER_HPP
#define SAB_IO_TEXTFILEREADER_HPP

#include "IO/File/Reader/Text/BaseTextFileReader.hpp"

namespace sab::ioos {

    class TextFileReader : public BaseTextFileReader<char> {
        public:
            enum class Status {
                OK,
                CLOSE_ERROR,
                OPEN_ERROR,
                FILE_EOF
            };
            TextFileReader() = default;
            TextFileReader(TextFileReader&&) noexcept;
    };
}

#endif //!SAB_IO_WTEXTFILRREADER_HPP