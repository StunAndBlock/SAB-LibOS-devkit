#ifndef SAB_IO_BASEFILE_HPP_
#define SAB_IO_BASEFILE_HPP_
#include "IO/Common.hpp"

namespace sab::ioos {
    
    template<typename CharT = char>
    class BaseFile : public sab::status::Statusable {
        protected:
            std::basic_ifstream<CharT> file_;  
        public:
            enum class Status {
                OK,
                CLOSE_ERROR
            };
            virtual ~BaseFile() = default;
            BaseFile() = default;
            BaseFile(const BaseFile&) = delete;
            BaseFile& operator=(const BaseFile&) = delete;

            BaseFile(BaseFile<CharT>&&) noexcept;
            BaseFile& operator=(BaseFile<CharT>&&) noexcept;
            virtual void open(const std::filesystem::path&) = 0;
            void close();
    }; 

    template<typename CharT>
    BaseFile<CharT>::BaseFile(
        BaseFile<CharT>&& source) noexcept
        : file_(std::move(source.file_)) {
        //this->status_ = source.status_;
    }
    template<typename CharT>
    BaseFile<CharT>& BaseFile<CharT>::operator=(
        BaseFile<CharT>&& rhs) noexcept {
        if (this != &rhs) {
            file_ = std::move(rhs.file_);
            //this->status_ = rhs.status_;
        }
        return *this;
    }

    template<typename CharT>
    void BaseFile<CharT>::close(){
        if (this->file_.is_open()){
            this->file_.close();
            this->setStatus(Status::OK);
        } else {
            this->setStatus(Status::CLOSE_ERROR);
        }
    }
};

#endif //!SAB_IO_BASEFILE_HPP_