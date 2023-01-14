#pragma once
#include<iostream>
template <typename T>
class MyArrayIterator;

template <typename T>
class Myarray{
private:
	int _maxsize;
	
	int _size = 0;

	T* List;

	void Extend() {
		T * temp = this->List;
		this->_maxsize = this->_maxsize * 2;
		this->List = new T[this->_maxsize];
		for (int i = 0; i < this->_size; i++) {
			this->List[i] = temp[i];
		}
		delete []temp;
	}
public:


	Myarray(const int size = 8) :_maxsize(size) {
		this->List = new T[this->_maxsize];
	};

	~Myarray() {
		delete []this->List;
	}

	void Add(T x) {
		if (this->_size >= this->_maxsize) {
			this->Extend();
		}
		this->List[this->_size++] = x;
		
	}

	void insert(T x,int location) {
		if (this->_size==this->_maxsize-1) {
			this->Extend();
			
		}

		if (location>=this->_size) {
			this->List[this->_size++] = x;
			
		}
		else if(location <= 0) {
			for (int i = this->_size-1; i > 0;i--) {
				this->List[i + 1] = this->List[i];
			}
			List[0] = x;
			
		}
		else {
			for (int i = this->_size-1; i >= location; i--) {
				this->List[i+1] = this->List[i];
			}
			this->List[location] = x;
		}
	}

	void Delete(int target) {
		if (target<0 or target>this->_size) {
			return;
		}
		for (int i = target; i < this->_size;i++) {
			List[i] = List[i + 1];
		}
		this->_size--;
	}

	bool isEmpty()const {
		return this->_size == 0;
	}

	int size()const {
		return this->_size;
	}

	void clear(int size = 8) {
		delete this->List;
		this->List = new T[size];
		this->_maxsize = size;
		this->_size = 0;
	}

	T operator[](int n) {
		if (n >= this->_size) {
			static_assert("Error");
		}
		return this->List[n];
	}

	Myarray<T>& operator=(Myarray<T>& other) {
		this->clear();
		for (int i = 0; i < other._size; i++) {
			this->Add(other[i]);
		}
		return *this;
	}

	MyArrayIterator<T> start() const{
		return MyArrayIterator<T>{this->List, 0};
	}

	MyArrayIterator<T> end() const{
		return MyArrayIterator<T>{this->List + this->_size,this->_size};
	}
};


template <typename T>
class MyArrayIterator {
	T* _object;
	int _number;
public:
	MyArrayIterator() :_object(nullptr), _number(0) {};
	MyArrayIterator(T* t, int num) :_object(t), _number(num) {
		
		//std::cout <<"input value:"<< *this->_object << std::endl;
	}
	int operator-(MyArrayIterator m) {
		
		return this->_number - m._number;
	}
	void SetObject(const T* obj) {
		this->_object = obj;
	}
	void SetNum(int n) {
		this->_number = n;
	}
	const T Object() {
		return *this->_object;
	}
	int Number() {
		return this->_number;
	}
	MyArrayIterator<T> operator++() {
		return *(this + 1);
	}
	MyArrayIterator<T> operator--() {
		return *(this - 1);
	}
	MyArrayIterator<T> operator+(int n) {
		return *(this + n);
	}
	MyArrayIterator<T> operator-(int n) {
		return *(this - n);
	}
};