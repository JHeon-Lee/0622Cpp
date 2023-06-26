#include <iostream>

using namespace std;

/*
	다이아몬드 상속 문제

		A
	   / \
	  B   C
	   \ /
	    D

	의 상속 관계에서의 모호성 문제
*/

class PoweredDevice
{
public:
	PoweredDevice(int power) { cout << "PoweredDevice" << power << endl; }

	int i;
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power)
	{
		cout << "Scanner : " << scanner << endl;
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		:PoweredDevice(power)
	{
		cout << "Printer : " << printer << endl;
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power1, int power2, int power3)
		: Scanner(scanner, power1)
		, Printer(printer, power2)
		//, Copier(power3) 불가능
		, PoweredDevice(power3)
		// 반드시 생성자 직접 호출해줘야함
	{

	}
};

int main()
{
	// Copier copier{ 1,2,3,4}; --> PoweredDevice3, PoweredDevice4로 최상위 클래스가 두개 만들어짐
	Copier copier{ 1,2,3,4,5 }; // --> PoweredDevice5 하나 만들어짐

	// copier.i; --> 모호성 발생

	cout << &copier.Scanner::PoweredDevice::i << endl;
	cout << &copier.Printer::PoweredDevice::i << endl;
	// 위, 아래 주소가 다른 것으로 확인 가능. --> 해결하기 위해 가상상속 시킨다.
	// 상속 접근 지정자에 virtual 넣기

	return 0;
}