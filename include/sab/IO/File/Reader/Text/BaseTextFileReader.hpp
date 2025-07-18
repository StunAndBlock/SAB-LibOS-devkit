#ifndef SAB_IO_BASETEXTFILEREADER_HPP_
#define SAB_IO_BASETEXTFILEREADER_HPP_

#include "IO/File/Reader/BaseFileReader.hpp"

namespace sab::ioos {
    template<typename CharT = char>
    class BaseTextFileReader : public BaseFileReader<CharT> {
        private:
        public:
            enum class Status {    
                OK,
                CLOSE_ERROR,
                OPEN_ERROR,
                FILE_EOF
            };
            BaseTextFileReader() = default;
            BaseTextFileReader(BaseTextFileReader<CharT>&& mSrc) : BaseFileReader<CharT>(std::move(mSrc)) {};


            void open(const std::filesystem::path&) override;
            void read(CharT*, uint64_t) override;
            void readLine(std::basic_string<CharT>&, CharT) override;
            void readLine(std::basic_string<CharT>&) override;
    };

    template<typename CharT>
    void BaseTextFileReader<CharT>::open(const std::filesystem::path& filePath){
        this->file_.open(filePath, std::ios::in);
        if (this->file_.is_open()){
            this->setStatus(Status::OK);
        } else {
            this->setStatus(Status::OPEN_ERROR);
        }
    }

    template<typename CharT>
    void BaseTextFileReader<CharT>::read(CharT* buffer, uint64_t size){
        this->file_.read(buffer,size);
    }
    template<typename CharT>
    void BaseTextFileReader<CharT>::readLine(std::basic_string<CharT>& str, CharT delim){
        std::getline(this->file_, str, delim);
    }
    template<typename CharT>
    void BaseTextFileReader<CharT>::readLine(std::basic_string<CharT>& str){
        std::getline(this->file_, str);
    }

}


#endif //!SAB_IO_BASETEXTFILEREADER_HPP_