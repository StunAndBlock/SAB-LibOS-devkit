#ifndef SAB_IO_BASETEXTFILEREADER_HPP_
#define SAB_IO_BASETEXTFILEREADER_HPP_

#include "IO/File/Reader/BaseFileReader.hpp"

namespace sab::ioos {
    namespace Status {
        enum class BaseTextFileReader {
            OK,
            CLOSE_ERROR,
            OPEN_ERROR,
            FILE_EOF,
            NEW
        };
    }
    template<typename CharT>
    class BaseTextFileReader : public BaseFileReader<CharT>, public sab::StatusMixin<Status::BaseTextFileReader> {
        private:
        using Status = Status::BaseTextFileReader;
        public:
            BaseTextFileReader() = default;
            BaseTextFileReader(BaseTextFileReader<CharT>&& mSrc) : BaseFileReader<CharT>(std::move(mSrc)) {};


            void open(const std::filesystem::path&) override;
            void close() override;
            void read(CharT*, uint64_t) override;
            void readLine(std::basic_string<CharT>&, CharT) override;
            void readLine(std::basic_string<CharT>&) override;
    };

    template<typename CharT>
    void BaseTextFileReader<CharT>::open(const std::filesystem::path& filePath){
        this->file_.open(filePath, std::ios::in);
        if (this->file_.is_open()){
            this->status_ = Status::OK;
        } else {
            this->status_ = Status::OPEN_ERROR;
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
    template<typename CharT>
    void BaseTextFileReader<CharT>::close(){
        if (this->file_.is_open()){
            this->file_.close();
            this->status_ = Status::OK;
        } else {
            this->status_ = Status::CLOSE_ERROR;
        }
    }
    // template<typename CharT>
    // BaseFileReader<CharT>::BaseFileReader(BaseFileReader<CharT>&& other) noexcept
    //     : BaseFile(std::move(source.file_)) {
    //         this->status_ = source.status_;
    //     }

}


















#endif //!SAB_IO_BASETEXTFILEREADER_HPP_