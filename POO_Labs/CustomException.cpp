#include "CustomException.h"

utils::CustomException::CustomException(const char* errorMessage) : _errorMessage(errorMessage)
{
}

utils::CustomException::CustomException(std::string errorMessage = "Unknown error") : _errorMessage(std::move(errorMessage))
{
}

const char* utils::CustomException::what() const
{
	return _errorMessage.c_str();
}

