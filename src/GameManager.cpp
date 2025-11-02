#include "GameManager.h"
#include "PrintUtil.h"

#include "LogUtil.h"

using namespace Managers;
using namespace Utils;

GameManager::GameManager(int r, int c) : row(r), col(c),
                                         snake(r / 2, c / 2),
                                         gameOver(false),
                                         autoMove(true),
                                         autoMoveInterval(std::chrono::milliseconds(1000))
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
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
    gameOver.store(true); // 设置游戏结束标志
}

void GameManager::GameUpdate()
{
    while (true)
    {
        if (gameOver.load())
        {
            // // 清空输入缓冲区中的所有残留按键
            // while (_kbhit())
            // {
            //     _getch();
            // }
            PrintUtil::ColorText("Game Over!", 4);
            _getch(); // 等待用户按键
            PrintUtil::ClearScreen();
            break;
        }
        if (_kbhit())
        {
            char key = _getch();
            // std::lock_guard<std::mutex> lock(mutex_); // 保证线程安全

            switch (key)
            {
            case 'w':
                if (snake.snakeBody.size() > 1)
                {
                    int x = snake.snakeBody[0].first - snake.snakeBody[1].first;
                    int y = snake.snakeBody[0].second - snake.snakeBody[1].second;
                    if (x == 1 && y == 0)
                    {
                        break; // 防止直接反向移动
                    }
                }

                snake.dir[0] = -1;
                snake.dir[1] = 0;
                break;
            case 's':
                if (snake.snakeBody.size() > 1)
                {
                    int x = snake.snakeBody[0].first - snake.snakeBody[1].first;
                    int y = snake.snakeBody[0].second - snake.snakeBody[1].second;
                    if (x == -1 && y == 0)
                    {
                        break; // 防止直接反向移动
                    }
                }
                snake.dir[0] = 1;
                snake.dir[1] = 0;
                break;
            case 'a':
                if (snake.snakeBody.size() > 1)
                {
                    int x = snake.snakeBody[0].first - snake.snakeBody[1].first;
                    int y = snake.snakeBody[0].second - snake.snakeBody[1].second;
                    if (x == 0 && y == 1)
                    {
                        break; // 防止直接反向移动
                    }
                }

                snake.dir[0] = 0;
                snake.dir[1] = -1;
                break;
            case 'd':
                if (snake.snakeBody.size() > 1)
                {
                    int x = snake.snakeBody[0].first - snake.snakeBody[1].first;
                    int y = snake.snakeBody[0].second - snake.snakeBody[1].second;
                    if (x == 0 && y == -1)
                    {
                        break; // 防止直接反向移动
                    }
                }
                snake.dir[0] = 0;
                snake.dir[1] = 1;
                break;
            case 'q':
                return; // 退出游戏
            default:
                break;
            }
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
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
            // 检查蛇头是否在当前位置
            else if (snake.GetHead() == std::make_pair(i, j))
            {
                PrintUtil::ColorText("◉", 1); // 绘制蛇头
            }

            // 检查蛇身是否在当前位置
            else if (std::find(snake.snakeBody.begin() + 1, snake.snakeBody.end(), std::make_pair(i, j)) != snake.snakeBody.end())
            {
                PrintUtil::ColorText("◯", 1); // 绘制蛇身
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
    // // 确保目标不出现在蛇身上
    do
    {
        target.first = rand() % row;
        target.second = rand() % col;
    } while (std::find(snake.snakeBody.begin(), snake.snakeBody.end(), target) != snake.snakeBody.end());
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
            snake.Move();
            if (target == snake.GetHead())
            {
                NextTarget();
                snake.AddSegment(snake.GetTail()); // 增加蛇身
            }
            if (CheckCollision())
            {
                GameOver();
                break;
            }
            UpdateMap();
            std::this_thread::sleep_for(autoMoveInterval);
        }
    }
    catch (...)
    {
        std::cout << "An unknown exception occurred in the auto move thread." << std::endl;
        gameOver.store(true); // 确保在未知异常情况下也能结束游戏
    }
}

// 安全停止函数
void GameManager::StopAutoMove()
{
    std::lock_guard<std::mutex> lock(mutex_);
    autoMove = false;
    // autoMoveThread.reset();
}

GameManager::~GameManager()
{
}