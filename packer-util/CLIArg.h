//
// Created by ernes on 7/3/2023.
//

#ifndef PACKER_UTIL_CLIARG_H
#define PACKER_UTIL_CLIARG_H

#include <algorithm>
#include <string>

namespace packer {
    /**
* @brief Helper class to assist in dealing with CLI arguments
*/
    class CLIArg {
    public:
        CLIArg();

        /**
        * @brief Gets the position of a specific argument in argv
         * @param argument Argument to look for
         * @param argv Argv from the main function
         * @return The index in argv of the argument
        */
        int GetIndexOfArgument(char *argv[], std::string argument);

        /**
        * @brief Checks if an argument exists in argv
         * @param argument Argument to look for
         * @param argv Argv from the main function
         * @return If an argument exists in argv
        */
        bool ArgumentExists(char *argv[], std::string argument);
    };
}

#endif //PACKER_UTIL_CLIARG_H
