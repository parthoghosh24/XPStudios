#pragma once

#include <iostream>

#define LOG(X) std::cout << x
#define LOG_LN(X) LOG(X) << std::endl
#define ERR(X) std::cerr << X
#define ERR_LN(X) ERR(X) << std::endl
