#include "CustomException.h"

utils::CustomException::CustomException(const char* errorMessage) : errorMessage_(errorMessage)
{
}

utils::CustomException::CustomException(std::string errorMessage = "Unknown error") : errorMessage_(std::move(errorMessage))
{
}

const char* utils::CustomException::what() const
{
	return errorMessage_.c_str();
}

