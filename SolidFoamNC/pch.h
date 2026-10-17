#ifndef PCH_H
#define PCH_H

#include "framework.h"

// 2. Спасение от конфликта "byte" (GDI+ vs C++17/Qt)
#pragma warning(push)
#pragma warning(disable: 4458)
#include <gdiplus.h>
#pragma warning(pop)

#endif //PCH_H