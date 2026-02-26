#pragma once 
#include <string>
#include <stdexcept>

namespace dtcpp {

    namespace errors {

        enum class ErrorCode {

            InvalidCivilDate = 0, 
            InvalidCivilHour = 1, 
            InvalidDateStringFormat = 2, 
            UnknownDayCountConvention = 3, 
            InvalidStartEndDate = 4, 
            UnknownBusinessDayConvention = 5, 
            UnknownHolidayCalendar = 6
        };

        inline std::string getCodeAsString(ErrorCode code) {
            switch (code) {
                case ErrorCode::InvalidCivilDate: return "InvalidCivilDate";
                case ErrorCode::InvalidCivilHour: return "InvalidCivilHour";
                case ErrorCode::InvalidDateStringFormat: return "InvalidDateStringFormat";
                case ErrorCode::UnknownDayCountConvention: return "UnknownDayCountConvention";
                case ErrorCode::InvalidStartEndDate: return "InvalidStartEndDate";
                case ErrorCode::UnknownBusinessDayConvention: return "UnknownBusinessDayConvention";
                case ErrorCode::UnknownHolidayCalendar: return "UnknownHolidayCalendar";
                default: return "UnknownErrorCode";
            }
        }

        inline std::string getCodeMessage(ErrorCode code) {
            switch (code) {
                case ErrorCode::InvalidCivilDate: return "The year, month or day given to construct a civil date is invalid.";
                case ErrorCode::InvalidCivilHour: return "The hour, minute or second given to construct a civil hour is invalid.";
                case ErrorCode::InvalidDateStringFormat: return "The date string format is invalid.";
                case ErrorCode::UnknownDayCountConvention: return "No method is defined to compute the year faction based on given day count convention.";
                case ErrorCode::InvalidStartEndDate: return "Start date cannot be set after the end date.";
                case ErrorCode::UnknownBusinessDayConvention: return "No method is defined to compute the business day adjustement for the convention given.";
                case ErrorCode::UnknownHolidayCalendar: return "No method is defined to check if a day is business for the calendar given.";
                default: return "Unknown error occurred.";
            }
        }

        class Error : public std::runtime_error {

            public: 
                explicit Error(ErrorCode code): std::runtime_error(generateErrorMessage(code)), code_(code) {}
                explicit Error(ErrorCode code, std::string detail): std::runtime_error(generateErrorMessage(code, detail)), code_(code) {}
                ~Error() = default; 

                ErrorCode getCode() const noexcept {return code_;}
            private:
                ErrorCode code_;
                static std::string generateErrorMessage(ErrorCode code) { return getCodeAsString(code) + "::" + std::to_string(static_cast<int>(code)) + " : " + getCodeMessage(code); }
                static std::string generateErrorMessage(ErrorCode code, std::string detail) {return generateErrorMessage(code) + "[ Details : " + detail + " ]";}
        
        };




    }

    
    
};