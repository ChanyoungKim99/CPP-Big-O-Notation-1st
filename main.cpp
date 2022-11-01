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

// Sum�� Time - Complexity : 4 * n ^ 2
// ( if�� f + 23~25���� ) * for�� �ݺ�Ƚ�� ^ 2

// Sum�� Space - Complexity : n + 5
// int numbers[] n�� + int count, Comparison f, int i, int j, int temp 5��

// Big O Notation���� �����ٸ�,
// �ð��� ������ �󸶳� �þ����, �� �־��� �Է� n�� focus�Ǳ� ������,
// Time - Complexity��
// if�� ������ 4��, f ���� ����� focus ���� �ʴ´�. (�þ�� �ʱ⶧��!)
// ���������, n ^ 2 ���� �ȴ�.

// Space - Complexity��
// ������ int numbers[]�� n���� focus�ϱ� ������,
// ���������, n���� �ȴ�.

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