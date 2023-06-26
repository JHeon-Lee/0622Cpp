#include <iostream>

using namespace std;

/*
	���̾Ƹ�� ��� ����

		A
	   / \
	  B   C
	   \ /
	    D

	�� ��� ���迡���� ��ȣ�� ����
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
		//, Copier(power3) �Ұ���
		, PoweredDevice(power3)
		// �ݵ�� ������ ���� ȣ���������
	{

	}
};

int main()
{
	// Copier copier{ 1,2,3,4}; --> PoweredDevice3, PoweredDevice4�� �ֻ��� Ŭ������ �ΰ� �������
	Copier copier{ 1,2,3,4,5 }; // --> PoweredDevice5 �ϳ� �������

	// copier.i; --> ��ȣ�� �߻�

	cout << &copier.Scanner::PoweredDevice::i << endl;
	cout << &copier.Printer::PoweredDevice::i << endl;
	// ��, �Ʒ� �ּҰ� �ٸ� ������ Ȯ�� ����. --> �ذ��ϱ� ���� ������ ��Ų��.
	// ��� ���� �����ڿ� virtual �ֱ�

	return 0;
}