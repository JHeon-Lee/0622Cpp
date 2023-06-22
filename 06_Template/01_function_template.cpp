#include <iostream>

using namespace std;

// ���ø� : �Լ��� Ŭ������ ���������� �ٽ� �ۼ����� �ʾƵ�, ���� �ڷ� ������ ����� �� �ֵ��� �ϰ� ����� ���� Ʋ.

int GetMax(int x, int y) { return (x > y) ? x : y; }
short GetMax(short x, short y) { return (x > y) ? x : y; }
float GetMax(float x, float y) { return (x > y) ? x : y; }
double GetMax(double x, double y) { return (x > y) ? x : y; }
// ������ ����� ���ŷο� �׷���...

template <typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

class Won
{
public:
	Won(int value = 0) : value(value){}

	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

private:
	int value = 0;
};

int main()
{
	Won a, b;

	cout << GetMax<int>(1, 4.1f) << endl; // ���� �ڷ����� �ٸ��ٸ� ����ؾ���
	cout << GetMax(1.0, 4.1) << endl; // ���� �ڷ����� �Ȱ��ٸ� ��� �����൵ ��
	cout << GetMax(1.0f, 4.1f) << endl;

	cout << GetMax(Won(6), Won(2)) << endl;

	return 0;
}