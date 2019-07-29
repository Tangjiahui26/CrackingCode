#include <iostream>

using namespace std;

// aligned_malloc() and aligned_free() without testing

void* aligned_malloc(size_t required_bytes, size_t alignment){
    void* p1; // initial block - the beginning of the full memory block
    void* p2; // aligned block inside initial block
    int offset = alignment - 1 + sizeof(void*); // sizeof(void*) to store the address where the memory begins
    if ((p1 = (void*)malloc(required_bytes + offset)) == NULL){
        return NULL;
    }
    p2 = (void*)(((size_t)(p1) + offset) & ~(alignment - 1)); // make it divisible
    ((void**)p2)[-1] = p1; // void** - an array of void*'s
    return p2;
}

void aligned_free(void *p2){
    void *p1 = ((void**)p2)[-1];
    free(p1);
}

// 2D alloc - allocates a two-dimisional array (without testing)

int ** my2DAlloc(int rows, int cols){
    int ** rowptr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++){
        rowptr[i] = (int*)malloc(cols * sizeof(int));
    }
}

void my2DDeallc(int ** rowptr, int rows){
    for (int i = 0; i < rows; i++){
        free(rowptr[i]);
    }
    free(rowptr);
}
