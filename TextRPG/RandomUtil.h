#pragma once

#include <cstdlib>
#include <ctime>

// Util 함수들은 자주 수행되니 코드 복붙해주는 inline이 유리함
namespace RandomUtil    // 객체 생성 안해도 되니 클래스가 아니라 namespace 선언해줌
{
    inline void InitRandom()
    {
        static bool initialized = false;
        if (initialized == false)
        {
            srand((time(nullptr)));
            initialized = true;
        }
    }

    inline bool IsSuccess(int probability)
    {
        InitRandom();
        return (rand() % 100) < probability; 
    }
}

