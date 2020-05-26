#ifndef ENGINEUTIL_H
#define ENGINEUTIL_H

#include <chrono>

class EngineUtil {
    public:
        static inline long getTime(){
            return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        }
};


#endif
