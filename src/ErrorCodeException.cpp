#include "ErrorCodeException.hpp"

//Implementing methods
	ErrorCodeException::ErrorCodeException(const ErrorCode er) : _errorCode(er){}

  bool ErrorCodeException::isSuccess() const{
    return error_isSuccess(_errorCode); 
  }

  void ErrorCodeException::printErrorMessage() const{
		cout<<error_getErrorMessage(_errorCode)<<endl; 
	}

  void ErrorCodeException::throwErrorIfNeeded(ErrorCode er){
    //checking success
    ErrorCodeException exeption = ErrorCodeException(er);
    if(!exeption.isSuccess()) {
      throw exeption;
    }
  }
