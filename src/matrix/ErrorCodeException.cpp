#include "ErrorCodeException.hpp"

using namespace matrix;

//Implementing methods
	ErrorCodeException::ErrorCodeException(const ErrorCode er) : m_errorCode(er){}

  bool ErrorCodeException::isSuccess() const{
    return error_isSuccess(m_errorCode); 
  }

  void ErrorCodeException::printErrorMessage() const{
    //prints the error messege
		cerr << error_getErrorMessage(m_errorCode) << endl; 
	}

  void ErrorCodeException::throwErrorIfNeeded(ErrorCode er){
    //checking success
    ErrorCodeException exeption = ErrorCodeException(er);
    if (!exeption.isSuccess()) {
      throw exeption;
    }
  }
