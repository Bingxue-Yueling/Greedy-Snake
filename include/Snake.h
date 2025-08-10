#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <utility>

class Snake
{
private:
    /* data */
public:
    std::vector<std::pair<int, int>> snakeBody;
    Snake(int startX, int startY);
    ~Snake();

    std::pair<int, int> GetHead() const
    {
        return snakeBody.front();
    }

    std::pair<int, int> GetTail() const
    {
        return snakeBody.back();
    }

    std::pair<int, int> GetSegment(int index) const
    {
        if (index < 0 || index >= snakeBody.size())
        {
            throw std::out_of_range("Index out of range");
        }
        return snakeBody[index];
    }

    size_t GetLength() const
    {
        return snakeBody.size();
    }

    // 检查蛇头是否碰到自己
    bool CheckCollision();
    void AddSegment(int x, int y)
    {
        AddSegment({x, y});
    }
    void AddSegment(const std::pair<int, int> &segment)
    {
        snakeBody.push_back(segment);
    }
    void Move(int dx, int dy);
};
