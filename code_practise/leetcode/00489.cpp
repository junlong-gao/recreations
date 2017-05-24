/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    int d {0}, x{0}, y{0};
    // initially robot will be facing "up": up is actually going down: increase x, not decrease x
    vector<pair<int, int>> dir {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    unordered_map<int, unordered_map<int, bool>> visited;
    
public:
    void cleanRoom(Robot& robot) {
        visited[x][y] = true;
        robot.clean();
        
        int curx = x; int cury = y;
        for (int i = 0; i < 4; ++i) {
            int nx = curx + dir[d%4].first;
            int ny = cury + dir[d%4].second;
            if (!visited[nx][ny] && robot.move()) {
                x = nx; y = ny;
                cleanRoom(robot);
                
                robot.turnRight(); robot.turnRight();
                assert(robot.move());
                robot.turnRight(); robot.turnRight();
            }
            robot.turnRight();
            d++;
        }
    }
};
