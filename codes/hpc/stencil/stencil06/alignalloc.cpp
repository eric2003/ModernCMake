#include "alignalloc.h"
// https://stackoverflow.com/questions/12942548/making-stdvector-allocate-aligned-memory
namespace detail {
    void* allocate_aligned_memory(size_t align, size_t size) {
        //return std::aligned_alloc(align, size);
		return std::malloc(size);
    }
    void deallocate_aligned_memory(void* ptr) noexcept {
        //std::free(ptr);
		std::free(ptr);
    }
}
