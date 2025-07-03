#ifndef SAB_IO_BASE_FILEREADER_TEMPLATED_HPP_
#define SAB_IO_BASE_FILEREADER_TEMPLATED_HPP_

#include "io/IOCommon.hpp"

namespace sab::ioos {
    namespace Status {
        enum class BaseFileReaderTemplated {
            OK,
            CLOSE_ERROR_FILE_NOT_OPENED,
            OPEN_ERROR,
        };
    }
    template<typename CharT>
    class BaseFileReaderTemplated : public sab::StatusMixin<Status::BaseFileReaderTemplated> {
        protected:
            std::basic_ifstream<CharT> file_;  
            using Status = Status::BaseFileReaderTemplated;
        public:
            virtual ~BaseFileReaderTemplated() = default;
            BaseFileReaderTemplated() = default;
            BaseFileReaderTemplated(const BaseFileReaderTemplated&) = delete;
            BaseFileReaderTemplated& operator=(const BaseFileReaderTemplated&) = delete;

            BaseFileReaderTemplated(BaseFileReaderTemplated<CharT>&&) noexcept;
            BaseFileReaderTemplated& operator=(BaseFileReaderTemplated<CharT>&&) noexcept;

            virtual void open(const CharT*) = 0;
            virtual void open(const std::basic_string<CharT>&) = 0;

            void close();
    }; 

    template<typename CharT>
    BaseFileReaderTemplated<CharT>::BaseFileReaderTemplated(
        BaseFileReaderTemplated<CharT>&& source) noexcept
        : file_(std::move(source.file_)) {
        this->status_ = source.status_;
    }
    template<typename CharT>
    BaseFileReaderTemplated<CharT>& BaseFileReaderTemplated<CharT>::operator=(
        BaseFileReaderTemplated<CharT>&& rhs) noexcept {
        if (this != &rhs) {
            file_ = std::move(rhs.file_);
            this->status_ = rhs.status_;
        }
        return *this;
    }

    template<typename CharT>
    void BaseFileReaderTemplated<CharT>::close(){
        if (file_.is_open()){
            file_.close();
            this->status_ = Status::OK;
        } else {
            this->status_ = Status::CLOSE_ERROR_FILE_NOT_OPENED;
        }
    }


};
#endif //!SAB_IO_BASE_FILEREADER_TEMPLATED_HPP_