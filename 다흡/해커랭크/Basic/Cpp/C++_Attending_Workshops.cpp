#include <iostream>
#include <algorithm>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int startTime;
    int duration;
    int endTime;

    bool operator<(const Workshop& w)
    {
        return endTime < w.endTime;
    }
};

struct Available_Workshops
{
    Workshop* workshops;
    int num;

    Available_Workshops(int n)
    {
        num = n;
        workshops = new Workshop[num];
    }

    ~Available_Workshops()
    {
        if (workshops != nullptr)
            delete workshops;
        workshops = nullptr;
    }
};


Available_Workshops* initialize(int* start_time, int* duration, int n)
{
    Available_Workshops* result = nullptr;
    result = new Available_Workshops(n);

    for (int i = 0; i < n; ++i)
    {
        result->workshops[i].startTime = start_time[i];
        result->workshops[i].duration = duration[i];
        result->workshops[i].endTime = start_time[i] + duration[i];
    }

    sort(result->workshops, result->workshops + n);

    return result;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    // Greedy 알고리즘 
    // endTime 기준 정렬
    // 가장 먼저 종료되는 워크샵부터 시작, 선택된 워크샵의 종료시간 이후 시작하는 다음 워크샵 선택
    int result = 0;

    int workTime = 0;
    for (int i = 0; i < ptr->num; ++i)
    {
        if (workTime <= ptr->workshops[i].startTime)
        {
            workTime = ptr->workshops[i].endTime;
            result++;
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
