/**
 * @file cstddef.h
 * @brief C++ Standard Library: cstddef header
 * @version 0.1
 * @date 2021-01-09
 * 
*/

#ifndef _CSTDDEF_H
#define _CSTDDEF_H

#include <stddef.h>

#ifdef __cplusplus
    namespace xstl
    {
        typedef decltype(__nullptr) nullptr_t;
    }

    using ::xstl::nullptr_t;
#endif


#endif /* _CSTDDEF_H */