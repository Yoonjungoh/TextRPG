#pragma once

#include <cstdlib>
#include <ctime>

// Util �Լ����� ���� ����Ǵ� �ڵ� �������ִ� inline�� ������
namespace RandomUtil    // ��ü ���� ���ص� �Ǵ� Ŭ������ �ƴ϶� namespace ��������
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

