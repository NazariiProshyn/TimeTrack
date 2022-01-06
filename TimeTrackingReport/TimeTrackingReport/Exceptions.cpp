#include "Exceptions.h"

std::string Exceptions::getErrorMsg()
{
    if (errWithFile)
    {
        return errWithFileMsg + path;
    }
    return path + errWithValueMsg + errValue;
}
