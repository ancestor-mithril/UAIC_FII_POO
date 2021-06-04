#pragma once
#include <exception>
#include <string>

namespace utils {
	class CustomException final : public std::exception {
		std::string _errorMessage;
	public:
		explicit CustomException(const char* errorMessage);
		explicit CustomException(std::string errorMessage);
		CustomException(const CustomException& other) = default;
		CustomException(CustomException&& other) = default;
		CustomException& operator=(const CustomException& other) = default;
		CustomException& operator=(CustomException&& other) = default;
		~CustomException() noexcept override = default;
		const char* what() const override;
	};
}
