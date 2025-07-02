#include "io/FileReader/BaseFileReader.hpp"

namespace sab::ioos {
    BaseFileReader::BaseFileReader(BaseFileReader&& source) noexcept
        : BaseFileReaderTemplated<char>(std::move(source)) {
    }
}