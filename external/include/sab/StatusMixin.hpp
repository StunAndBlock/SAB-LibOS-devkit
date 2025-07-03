#ifndef SAB_STATUS_MIXIN_HPP_
#define SAB_STATUS_MIXIN_HPP_

namespace sab {
    template <typename StatusEnum>
    class StatusMixin {
        protected:
            StatusEnum status_;
        public:
            StatusMixin() = default;
            virtual ~StatusMixin() = 0;  
            StatusEnum getStatus() const;
    };

    template <typename StatusEnum>
    StatusMixin<StatusEnum>::~StatusMixin() = default;

    template <typename StatusEnum>
    StatusEnum StatusMixin<StatusEnum>::getStatus() const {
        return status_;
    }

};

#endif //!SAB_STATUS_MIXIN_HPP_