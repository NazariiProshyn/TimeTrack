#include "Exceptions.h"

std::string Exceptions::GetErrorMsg()
{
    if (errWithFile)
    {
        return errWithFileMsg + path;
    }
    return path + errWithValueMsg + errValue;
}
