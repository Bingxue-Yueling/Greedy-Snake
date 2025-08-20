#include "GameManager.h"
#include "PrintUtil.h"
#include "LogUtil.h"

using namespace Managers;
using namespace Utils;

GameManager::GameManager(int r, int c) : row(r), col(c),
                                         snake(r / 2, c / 2),
                                         autoMove(true),
                                         autoMoveInterval(std::chrono::milliseconds(1000))
{
}

void GameManager::GameStart()
{
    NextTarget();
    StartAutoMove();
    GameUpdate();
}

void GameManager::GameOver()
{
    StopAutoMove();
    gameOver = true; // 设置游戏结束标志
    PrintUtil::ColorText("Game Over!", 4);
    // _getch();
    PrintUtil::ClearScreen();
}

void GameManager::GameUpdate()
{
    while (!gameOver)
    {
        if (_kbhit())
        {

            char key = _getch();

            switch (key)
            {
            case 'w':
                snake.dir[0] = -1;
                snake.dir[1] = 0;
                break;
            case 's':
                snake.dir[0] = 1;
                snake.dir[1] = 0;
                break;
            case 'a':
                snake.dir[0] = 0;
                snake.dir[1] = -1;
                break;
            case 'd':
                snake.dir[0] = 0;
                snake.dir[1] = 1;
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

void GameManager::StartAutoMove()
{
    if (!autoMoveThread)
    {
        autoMoveThread = std::make_unique<std::thread>(&GameManager::UpdateAutoMove, this);
        autoMoveThread->detach(); // 分离线程
    }
}

void GameManager::UpdateAutoMove()
{
    try
    {
        while (true)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (!autoMove)
            {
                break;
            }
            PrintUtil::ClearScreen();
            UpdateMap();
            snake.Move();
            if (CheckCollision())
            {
                GameOver();
            }
            std::this_thread::sleep_for(autoMoveInterval);
        }
    }
    catch (const std::exception &e)
    {
        gameOver = true; // 确保在异常情况下也能结束游戏
    }
    catch (...)
    {
        gameOver = true; // 确保在未知异常情况下也能结束游戏
    }
}

// 安全停止函数
void GameManager::StopAutoMove()
{
    std::lock_guard<std::mutex> lock(mutex_);
    autoMove = false;
    autoMoveThread.reset();
}

GameManager::~GameManager()
{
    // StopAutoMove(); // 确保在析构时停止自动移动线程
}