#ifndef SAB_STATUS_MIXIN_HPP_
#define SAB_STATUS_MIXIN_HPP_

namespace sab {
    template <typename Derived>
    class StatusMixin {
        protected:
            using StatusEnum = typename Derived::Status;
            StatusEnum status_;
        public:
            virtual ~StatusMixin() = 0;  
            StatusEnum getStatus() const;
    };

    template <typename Derived>
    StatusMixin<Derived>::~StatusMixin() = default;

    template <typename Derived>
    typename StatusMixin<Derived>::StatusEnum 
    StatusMixin<Derived>::getStatus() const {
        return status_;
    }

};

#endif //!SAB_STATUS_MIXIN_HPP_