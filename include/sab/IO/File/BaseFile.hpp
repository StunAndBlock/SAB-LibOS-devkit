#ifndef SAB_IO_BASEFILE_HPP_
#define SAB_IO_BASEFILE_HPP_
#include "IO/Common.hpp"

namespace sab::ioos {
    template<typename CharT>
    class BaseFile{
        protected:
            std::basic_ifstream<CharT> file_;  
        public:
            virtual ~BaseFile() = default;
            BaseFile() = default;
            BaseFile(const BaseFile&) = delete;
            BaseFile& operator=(const BaseFile&) = delete;

            BaseFile(BaseFile<CharT>&&) noexcept;
            BaseFile& operator=(BaseFile<CharT>&&) noexcept;
            virtual void open(const std::filesystem::path&) = 0;
            virtual void close() = 0;
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






};
#endif //!SAB_IO_BASEFILE_HPP_