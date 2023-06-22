#include <iostream>

using namespace std;

/*
	static cast
	const cast
	reinterpret cast ���� ����ȯ
	dynamic cast --> ������ �ٿ�ĳ���ÿ� ���, ��Ÿ�ӿ� �˻��ϱ� ������ ��Ÿ�� ����� ����

	cf) Up casting : �θ� Ŭ���� �����ͷ� �ڽ� Ŭ���� ��ü�� ����Ŵ --> �θ� Ŭ������ ����� ��� ����
	Down casting : �ڽ� Ŭ���� �����ͷ� �θ� Ŭ���� �����Ͱ� ����Ű�� ��ü�� ����Ŵ --> �ڽ� Ŭ������ ��� ��� ����
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

void DoSomething(Base* b) // static_cast�� ���輺 �����ֱ�� �Լ�
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
	// static_cast�� �����ϴ�.
	Derived1* baseToD1 = dynamic_cast<Derived1*>(base);
	// dynamic�� �� �� ����

	DoSomething(&d1);
	cout << d1.j << endl; // --> static_cast�� ��� Derived2 �� k�� �ٲٷ� �ߴµ� Derived1�� j���� �ٲ�����
	// dynamic_cast�� ��� d1�� Base ���� �ƴ϶� ��ȯ�� �����ֹǷ� ��Ÿ�� ������ ��

	return 0;
}