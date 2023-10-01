#pragma once

#include <iostream>
#include <string>
#include <filesystem>


// bit field
#define BIT_LOC(x) (1 << x)

#define STRINGIZE(x) #x

inline const std::string getFileName(const char* path)
{
	return std::filesystem::path(path).filename().string();
}

#define __FILENAME__ getFileName(__FILE__).c_str()

#if defined(DEBUG) || defined(SEA_TRIALS)
	#define V_ASSERT(value, message)		\
		if (!(value))						\
		{									\
			std::cerr << '[' << __FILENAME__\
			<< "::" << __LINE__ << "] "		\
			<< message << std::endl;		\
			DebugBreak();					\
		}									\
		
#else
	define V_ASSERT(value, message) ((void)0)
#endif