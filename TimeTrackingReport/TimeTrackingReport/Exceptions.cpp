/**
 * @file      Exceptions.cpp
 *
 * @brief     Simple realization of
 *            structure exception
 *
 *
 */

#include "Exceptions.h"

std::string Exceptions::GetErrorMsg()
{
    if (errWithFile)
    {
        return errWithFileMsg + path;
    }
    return path + errWithValueMsg + errValue;
}
