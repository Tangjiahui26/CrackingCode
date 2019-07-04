#include <iostream>
#include <string>

using namespace std;

string getPath(int origin_x, int origin_y, int x, int y, bool* off_limits){
    if (origin_x < 0 || x <= origin_x || origin_y < 0 || y <= origin_y
        || off_limits[origin_y * y + origin_x]) {
        return "";
    }

    if (origin_x == x - 1 && origin_y == y - 1){
        return "E";
    }

    string path = getPath(origin_x + 1, origin_y, x, y, off_limits);
    if (!path.empty()){
        return "R" + path;
    }

    path = getPath(origin_x, origin_y + 1, x, y, off_limits);
    if (!path.empty()){
        return "D" + path;
    }

    off_limits[origin_y * y + origin_x] = true;
    return "";
}

int main()
{
    const int x = 5;
    const int y = 5;
    bool off_limits[x * y] = {0};
    off_limits[2 * y + 2] = true;
    off_limits[2 * y + 3] = true;
    off_limits[2 * y + 4] = true;

    cout << "Path: " << getPath(0, 0, x, y, off_limits) << endl;
    return 0;
}
