#pragma once
#include<memory>
template<class T>
concept IsInteger = std::is_same_v<T, int>;//Ҫ��ģ������Ϊint

template <class Father, class Child>
concept IsChild = std::is_base_of<Father, Child>::value;//Ҫ������������м̳й�ϵ

//����������ǹ淶ģ��ʵ��������,����������������ǲ������ɵ�ģ��

class Father {

};
class Child :public virtual Father {

};

template<class U>
void RequireTest() requires IsInteger<U>{

}

template<class U,class T,class F>
void RequireTest2() requires IsInteger<U> and IsChild<T,F>{
	//ͨ������Լ��ģ���ʵ������Χ
	//����ļ�ǿ�����ȶ���
	//��ȡҪ��ͬʱ����ȫ������Լ�������� 
	// �﷨:requires ����1&&����2&&... �� requires ����1 and ����2 and ... 
	//��ȡҪ��ͬʱ����һ�������������Լ��������
	// �﷨:requires ����1||����2||... �� requires ����1 or ����2 or ... 
	//���ɷָ�һ�����ڹ淶ģ��ʵ��������(����ָ������ʵ����)
	//�﷨: ģ��(Ҫ������) �� requires (MyType M) void Func<T>(M m)
}
template<class T>
void DeathTemplate() requires false{
	//��require �����Ķ����ȡ���ȡ�򲻿ɷָ�ĸ���(�ҳ�֮Ϊ���),
	// �����ֵΪfalseʱ��ģ�岻��ʵ����.
	//��ͬ�ð���
}
/*template<typename T>
class Object {
public:
	virtual bool isObject() = 0;
};
template <typename T>
class IObject:public Object<T> {
public:
	bool isObject() override {
		return true;
	}
};*/