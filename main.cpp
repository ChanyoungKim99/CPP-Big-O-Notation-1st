#include <iostream>

using Comparison = bool(*) (int, int);

bool Ascending(int x, int y)
{
	return x > y;
}

bool Descending(int x, int y)
{
	return x < y;
}

void Sort(int numbers[], int count, Comparison f)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

// Sum의 Time - Complexity : 4 * n ^ 2
// ( if의 f + 23~25번줄 ) * for문 반복횟수 ^ 2

// Sum의 Space - Complexity : n + 5
// int numbers[] n개 + int count, Comparison f, int i, int j, int temp 5개

// Big O Notation으로 따진다면,
// 시간과 공간이 얼마나 늘어나느냐, 즉 주어진 입력 n에 focus되기 때문에,
// Time - Complexity는
// if를 포함한 4줄, f 같은 대상은 focus 하지 않는다. (늘어나지 않기때문!)
// 결론적으로, n ^ 2 개가 된다.

// Space - Complexity는
// 오로지 int numbers[]의 n개만 focus하기 때문에,
// 결론적으로, n개가 된다.

int main()
{
	const int NUM_ARRAY{ 10 };

	int scores[NUM_ARRAY]{ 20, 10, 40, 15, 30, 70, 60, 90, 80, 50 };

	Sort(scores, NUM_ARRAY, Ascending);
	
	for (int i = 0; i < NUM_ARRAY; i++)
	{
		std::cout << scores[i] << std::endl;
	}
}