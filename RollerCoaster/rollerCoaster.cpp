#include <iostream>

using namespace std;

int *getElem(int **queue, int &index0, const int &N)
{
    if (index0 == N) index0 = 0;
    else if (index0 > N) index0 = index0 - N;

    return *(queue + index0);
}

const int &newRide(int **queue, const int &L, const int &N, int &index0)
{
    if (getElem(queue, index0, N)[1] > 0)
    {
        int grMoney(getElem(queue, index0, N)[1]);
        index0 = getElem(queue, index0, N)[2];
        return grMoney;
    }

    int nextIndex(index0);
    int currGroup(0);
    for (size_t i(0); i < N; ++i)
    {
        int nextInQ = getElem(queue, nextIndex, N)[0];
        if (currGroup + nextInQ > L) break;
        else
        {
            currGroup += nextInQ;
            ++nextIndex;
        }
    }

    getElem(queue, index0, N)[1] = currGroup;
    getElem(queue, index0, N)[2] = nextIndex;
    index0 = nextIndex;

    return currGroup;
}

int main()
{
    int L;
    int C;
    int N;
    cin >> L >> C >> N;
    cin.ignore();

    unsigned long money(0);

    int index0(0);
    int **queue = new int *[N];
    for (int i(0); i < N; ++i)
    {
        int Pi;
        cin >> Pi;
        cin.ignore();
        *(queue + i) = new int[2];
        queue[i][0] = Pi;
        queue[i][1] = 0;
        queue[i][2] = 0;
    }


    for (size_t i(0); i < C; ++i)
    {
        money += newRide(queue, L, N, index0);
    }

    cout << money << endl;

    for (size_t i(0); i < N; ++i)
        delete[] queue[i];

    delete[] queue;

    return 0;
}
