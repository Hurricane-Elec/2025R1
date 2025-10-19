/**
 * @file    malloc.c
 * @author  Deadline039
 * @brief   Redefine C Malloc library. Malloc in SRAM4. 
 * @version 1.0
 * @date    2025-04-17
 */

#include "tlsf.h"

#include <stdint.h>
#include <string.h>

#define MEMORY_POOL SRAM4_MEM

extern uint8_t MEMORY_POOL[];

#include "tlsf.h"
#include <string.h>

#if defined(__clang__)
/* ARM Compiler 6 */
__asm(".global __use_no_heap_region\n\t");
#elif defined(__CC_ARM)
/* ARM Compiler 5 */
#pragma import(__use_no_heap_region)
#endif /* ARM Compiler */

/**
 * @brief Allocates space for an object whose size is specified by 'size' and whose
 *        value is indeterminate.
 * 
 * @param size The size to allocate.
 * @return Either a null pointer or a pointer to the allocated space.
 */
_ARMABI void *malloc(size_t size) {
    return tlsf_malloc(MEMORY_POOL, size);
}

/**
 * @brief causes the space pointed to by ptr to be deallocated (i.e., made
 *        available for further allocation). If ptr is a null pointer, no action
 *        occurs. Otherwise, if ptr does not match a pointer earlier returned by
 *        calloc, malloc or realloc or if the space has been deallocated by a call
 *        to free or realloc, the behaviour is undefined. 
 * 
 * @param p The pointer to free.
 */
_ARMABI void free(void *p) {
    if (p) {
        tlsf_free(MEMORY_POOL, p);
    }
}

/**
 * @brief changes the size of the object pointed to by ptr to the size specified by
 *        size. The contents of the object shall be unchanged up to the lesser of
 *        the new and old sizes. If the new size is larger, the value of the newly
 *        allocated portion of the object is indeterminate. If ptr is a null
 *        pointer, the realloc function behaves like a call to malloc for the
 *        specified size. Otherwise, if ptr does not match a pointer earlier
 *        returned by calloc, malloc or realloc, or if the space has been
 *        deallocated by a call to free or realloc, the behaviour is undefined.
 *        If the space cannot be allocated, the object pointed to by ptr is
 *        unchanged. If size is zero and ptr is not a null pointer, the object it
 *        points to is freed.
 * 
 * @param p The pointer to free. 
 * @param want The new size to allocate.
 * @return either a null pointer or a pointer to the possibly moved
 *         allocated space.
 */
_ARMABI void *realloc(void *p, size_t want) {
    return tlsf_realloc(MEMORY_POOL, p, want);
}

/**
 * @brief allocates space for an array of nmemb objects, each of whose size is
 *        'size'. The space is initialised to all bits zero.
 * 
 * @param nmemb The single member size. 
 * @param size The number of member to allocate.
 * @return either a null pointer or a pointer to the allocated space.
 */
_ARMABI void *calloc(size_t nmemb, size_t size) {
    void *p = tlsf_malloc(MEMORY_POOL, nmemb * size);
    if (p) {
        memset(p, 0, nmemb * size);
    }
    return p;
}
