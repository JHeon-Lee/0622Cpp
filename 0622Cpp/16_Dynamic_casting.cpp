#include <iostream>

using namespace std;

/*
	static cast
	const cast
	reinterpret cast 강제 형변환
	dynamic cast --> 안전한 다운캐스팅에 사용, 런타임에 검사하기 때문에 런타임 비용이 높음

	cf) Up casting : 부모 클래스 포인터로 자식 클래스 객체를 가리킴 --> 부모 클래스의 멤버만 사용 가능
	Down casting : 자식 클래스 포인터로 부모 클래스 포인터가 가리키는 객체를 가리킴 --> 자식 클래스의 멤버 사용 가능
*/

class Base
{
public:
	virtual void Print() { cout << "Base " << endl; }

	int i = 0;
};

class Derived1 : public Base
{
public:
	virtual void Print() override { cout << "Derived1" << endl; }

	int j = 1;
};

class Derived2 : public Base
{
public:
	virtual void Print() override { cout << "Derived2" << endl; }

	int k = 2;
};

void DoSomething(Base* b) // static_cast의 위험성 보여주기용 함수
{
	// Derived2* baseToD2 = static_cast<Derived2*>(b);
	Derived2* baseToD2 = dynamic_cast<Derived2*>(b);
	baseToD2->k = 33;
}

int main()
{
	Derived1 d1;
	Base* base = &d1; // Up casting

	// Derived1* baseToD1 = static_cast<Derived1*>(base); --> Down casting
	// static_cast는 위험하다.
	Derived1* baseToD1 = dynamic_cast<Derived1*>(base);
	// dynamic이 좀 더 안정

	DoSomething(&d1);
	cout << d1.j << endl; // --> static_cast의 경우 Derived2 의 k를 바꾸려 했는데 Derived1의 j값이 바뀌어버림
	// dynamic_cast의 경우 d1이 Base 형이 아니라서 변환을 막아주므로 런타임 에러가 남

	return 0;
}