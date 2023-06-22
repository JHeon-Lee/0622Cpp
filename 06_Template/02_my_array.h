#pragma once

template<class T>

class my_array
{
public:
	my_array(int length)
		: length(length)
	{
		arr = new T[length];
	}

	~my_array()
	{
		delete[] arr;
	}

	void Print();

private:
	T* arr = nullptr;
	int length = 0;
};

// Ŭ���� ���ø��� ��� �����ε� ����� �ΰų� cpp�� �����صΰ� main���� ���, cpp ��� include �ؾ��Ѵ�
// �ƴϸ� inl ������ ����ؼ� ������ �� �ִ�.