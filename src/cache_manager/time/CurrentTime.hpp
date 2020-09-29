#pragma once

#include <string>
#include <ctime>
#include <stdint.h>

/**
 * @brief this class is for calculating the corent time.
 */
namespace cache{
namespace timeCounter{
    static constexpr std::uint32_t TIME_STRING_LENGTH = 14;
    /**
     * @brief Gets the Time.
     * 
     * @return std::string rturn string that
     * stands for the time & date.
     */
    std::string getTime();
}
}