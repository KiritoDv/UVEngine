#ifndef DATA_NINPUT
#define DATA_NINPUT

#include "nmouse.h"
#include "nscroll.h"
#include "nkeyboard.h"

struct NInput{
    Mouse mouse;
    Scroll scroll;
    Keyboard keyboard;
};

#endif
