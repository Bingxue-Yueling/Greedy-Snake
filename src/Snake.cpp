#include "Snake.h"

Snake::Snake(int startX, int startY)
{
    snakeBody.push_back({startX, startY});
}

Snake::~Snake()
{
}

bool Snake::CheckCollision()
{
    auto head = snakeBody.front();
    for (size_t i = 1; i < snakeBody.size(); ++i)
    {
        // 检查蛇头是否碰到自己
        if (head == snakeBody[i] && i == 1)
        {
            return true; // 碰撞
        }
    }
    return false; // 未碰撞
}

void Snake::Move()
{
    Move(dir[0], dir[1]);
}

void Snake::Move(int dx, int dy)
{
    // 计算新头部位置
    int newHeadX = snakeBody.front().first + dx;
    int newHeadY = snakeBody.front().second + dy;

    // 移动身体
    for (int i = snakeBody.size() - 1; i > 0; --i)
    {
        snakeBody[i] = snakeBody[i - 1];
    }

    // 更新头部位置
    snakeBody[0] = {newHeadX, newHeadY};
}