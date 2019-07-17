#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <memory>
#include <array>
#include <set>
#include <string>

using namespace std;

// @github oskargustafsson

struct Box {
    int x, y, z;
    bool operator==(const Box& rhs) {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }
};

int getStackHeight(list<Box> & boxes){
    int acc_y = 0;
    for (Box& box : boxes){
        acc_y += box.y;
    }
    return acc_y;
}

list<Box> getTallestStack(const list<Box>& boxes, const Box* prev_box){
    list<Box> ret;
    int max_height = 0;
    for (const Box& box : boxes){
        if (!prev_box || box.x > prev_box->x && box.y > prev_box->y && box.z > prev_box->z) {
            list<Box> boxes_copy(boxes);
            boxes_copy.remove(box);
            list<Box> a_stack = getTallestStack(boxes_copy, &box);
            int a_stack_height = box.y + getStackHeight(a_stack);
            if (a_stack_height >= max_height) {
                a_stack.push_front(box);
                ret = a_stack;
                max_height = a_stack_height;
            }
        }
    }
    return ret;
}

int main()
{
    list<Box> boxes {{1,2,3}, {3,2,1}, {4,4,4}, {4,5,6}, {5,4,3}, {3,3,2}, {1,1,1}, {2,2,1}};

    for (const Box& box : getTallestStack(boxes, nullptr)){
        cout << "(" << box.x << " " << box.y << " " << box.z << ")" << endl;
    }
    return 0;
}
