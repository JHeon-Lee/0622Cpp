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

// 클래스 템플릿의 경우 구현부도 헤더에 두거나 cpp에 정의해두고 main에서 헤더, cpp 모두 include 해야한다
// 아니면 inl 파일을 사용해서 나눠줄 수 있다.