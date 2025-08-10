#include "GameManager.h"
#include "PrintUtil.h"

using namespace Managers;
using namespace Utils;

GameManager::GameManager(int r, int c) : row(r), col(c), snake(r / 2, c / 2)
{
}

GameManager::~GameManager()
{
}

void GameManager::Start()
{
    NextTarget();
    Update();
}
void GameManager::Update()
{
    while (true)
    {
        PrintUtil::ClearScreen();
        UpdateMap();
        std::cout << "按 'q' 退出游戏" << std::endl;

        char key = _getch();
        switch (key)
        {
        case 'w':
            snake.Move(-1, 0);
            break;
        case 's':
            snake.Move(1, 0);
            break;
        case 'a':
            snake.Move(0, -1);
            break;
        case 'd':
            snake.Move(0, 1);
            break;
        case 'q':
            break;
        default:
            break;
        }
        if (target == snake.GetHead())
        {
            NextTarget();
            snake.AddSegment(snake.GetTail()); // 增加蛇身
        }
    }
}

void GameManager::UpdateMap()
{
    // 绘制上边界
    for (size_t i = 0; i < col + 2; i++)
    {
        std::cout << "▣ ";
    }
    std::cout << std::endl;
    // 绘制左右边界以及中间部分
    for (int i = 0; i < row; i++)
    {
        std::cout << "▣ ";
        for (int j = 0; j < col; j++)
        {
            // 检查目标位置
            if (target.first == i && target.second == j)
            {
                PrintUtil::ColorText("◈", 2);
            }
            // 检查蛇身是否在当前位置
            else if (std::find(snake.snakeBody.begin(), snake.snakeBody.end(), std::make_pair(i, j)) != snake.snakeBody.end())
            {
                PrintUtil::ColorText("◉", 1); // 绘制蛇身
            }
            else
            {
                std::cout << ' '; // 绘制空格
            }
            std::cout << ' ';
        }

        std::cout << "▣" << std::endl;
    }
    // 绘制下边界
    for (size_t i = 0; i < col + 2; i++)
    {
        std::cout << "▣ ";
    }
    std::cout << std::endl;
}

void GameManager::NextTarget()
{
    target.first = rand() % row;
    target.second = rand() % col;
}

bool GameManager::CheckCollision()
{
    // 检查蛇头是否碰到边界
    auto head = snake.GetHead();
    if (head.first < 0 || head.first >= row || head.second < 0 || head.second >= col)
    {
        return true; // 碰撞
    }

    // 检查蛇头是否碰到自己
    return snake.CheckCollision();
}