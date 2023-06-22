#include <iostream>

using namespace std;

// 템플릿 : 함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료 형으로 사용할 수 있도록 하게 만들어 놓은 틀.

int GetMax(int x, int y) { return (x > y) ? x : y; }
short GetMax(short x, short y) { return (x > y) ? x : y; }
float GetMax(float x, float y) { return (x > y) ? x : y; }
double GetMax(double x, double y) { return (x > y) ? x : y; }
// 일일히 만들기 번거로움 그래서...

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

	cout << GetMax<int>(1, 4.1f) << endl; // 들어가는 자료형이 다르다면 명시해야함
	cout << GetMax(1.0, 4.1) << endl; // 들어가는 자료형이 똑같다면 명시 안해줘도 됨
	cout << GetMax(1.0f, 4.1f) << endl;

	cout << GetMax(Won(6), Won(2)) << endl;

	return 0;
}