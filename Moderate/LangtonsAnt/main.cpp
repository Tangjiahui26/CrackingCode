#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// since this question is easier to implement in JAVA(Pixel), here we changed the requirement a bit
// the code is trying to figure out how many sqaures are black after a certain number of moves of the ant
// from @euler.stephan-brumme/349

int getBlackNumbers(int K){
    const bool White = false;
    const bool Black = true;
    const unsigned int Size = 128;

    //1D vector for 2D grid pos: y * Size + x
    vector<bool> grid(Size * Size, White);

    unsigned int x = Size / 2;
    unsigned int y = Size / 2;

    // four directions
    const short DeltaX[] = {0, +1, 0, -1};
    const short DeltaY[] = {+1, 0, -1, 0};

    short direction = 0;
    // see wikipedia about Langto's Ant, after about 10000 steps, the ant starts a cycle
    const auto Cycle = 104;
    const auto Reminder = K % Cycle;

    auto count = 0;
    auto last = count;

    // keep tracking the last delta
    vector<int> lastDelta = {0};
    // assume a "steady state" if the most recent 10 cycles have the same deltas
    const unsigned int StopIfSameDelta = 10;

    auto steps = 0;
    while(steps < K){
        if (steps % Cycle == Reminder){
            auto diff = int(count - last);
            lastDelta.push_back(diff);
            last = count;

            if (lastDelta.size() >= StopIfSameDelta){
                bool same = true;
                for (auto scan = lastDelta.rbegin(); scan != lastDelta.rbegin() + StopIfSameDelta; scan++){
                    if (*scan != diff){
                        same = false;
                        break;
                    }
                }
                if (same){
                    auto remainingCycles = (K - steps) /Cycle;
                    count += remainingCycles * diff;
                    break;
                }
            }
        }

        auto pos = y * Size + x;
        if (grid[pos] == White){
            grid[pos] = Black;
            count++;

            direction = (direction + 1) % 4;
        } else {
            grid[pos] = White;
            count--;

            direction = (direction + 4 - 1) % 4;
        }

        x += DeltaX[direction];
        y += DeltaY[direction];
        steps++;
    }
    cout << count << endl;
    return 0;
}

int main()
{
    getBlackNumbers(1000);
    return 0;
}
