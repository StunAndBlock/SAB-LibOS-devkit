#ifndef SAB_IO_BASE_FILEREADER_HPP_
#define SAB_IO_BASE_FILEREADER_HPP_

#include "IO/File/BaseFile.hpp"

namespace sab::ioos {

    template<typename CharT = char>
    class BaseFileReader : public BaseFile<CharT> {

        public:
            BaseFileReader() = default;
            BaseFileReader(BaseFileReader<CharT>&& mSrc) noexcept : BaseFile<CharT>(std::move(mSrc)){};


            virtual void open(const std::filesystem::path&) override = 0;
            virtual void read(CharT*, uint64_t) = 0;
            virtual void readLine(std::basic_string<CharT>&, CharT) = 0;
            virtual void readLine(std::basic_string<CharT>&) = 0;
    };

}

#endif //!SAB_IO_BASE_FILEREADER_HPP_