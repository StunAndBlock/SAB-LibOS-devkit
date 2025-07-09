#ifndef SAB_IO_WTEXTFILEREADER_HPP
#define SAB_IO_WTEXTFILEREADER_HPP

#include "IO/File/Reader/Text/BaseTextFileReader.hpp"

namespace sab::ioos {
    class WTextFileReader : public BaseTextFileReader<wchar_t> {
        public:
            WTextFileReader() = default;
            WTextFileReader(WTextFileReader&&) noexcept;
    };
}
















#endif //!SAB_IO_WTEXTFILRREADER_HPP