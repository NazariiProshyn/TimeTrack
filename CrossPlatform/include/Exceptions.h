#pragma once

/**
 * @file      Exceptions.h
 *
 * @brief     Simple structure exception
 *
 * @author    Proshyn Nazarii
 * Contact:   nazariyproshyn@gmail.com
 *
 */

#include <iostream>
#include <string>
#include <iostream>
#include <stdexcept>
class Exceptions final
:public std::exception
{
public:
    Exceptions(const std::string& msg) :std::exception()
    {
        path = msg;
    };
    Exceptions(const std::string& msg,const std::string& value) :std::exception()
    {
        path = msg;
        errValue = value;
        errWithFile = false;
    };

    /**
     * @brief	Returns information about
     *          error.
     *
     * @return  Information about error.
    */
    std::string GetErrorMsg();
private:
    bool errWithFile = true;

    std::string errValue = "";
    std::string path     = "";

    const std::string errWithFileMsg  = "Unable to open or find file: ";
    const std::string errWithValueMsg = " does not have a column or have invalid data: ";
};
