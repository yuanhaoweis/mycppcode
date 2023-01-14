#pragma once
#include <iostream>
template <typename T>
void Myprintf(T t1) {
	std::cout << t1;
}

template <typename T, typename ...Args>
void Myprintf(T t1, Args... arg) {
	//std::cout << "��" << sizeof...(arg) << "������:";
	Myprintf(t1);
	Myprintf(arg...);
}

template<typename ...Args>
void Myprintf(Args... args) {
	Myprintf(args);
	Myprintf(args...);
}

template<typename T>
void MyDeleGate(void fp(T t), T t) {
	fp(t);
}

template<typename... Args>
void MyDeleGate(void fp(Args... arg), Args... arg) {//��������,Ŀǰ��֧�ַ�������Ϊvoid��
	/*for (auto& a : {arg...}) {
	fp(a);
	}*/
	fp(arg...);
}

template<typename T, typename... Args>
T MyDeleGate(T fp(Args... arg), Args... arg) {
	return fp(arg...);
}

template <typename... T> void PrintFuns(T ...t) {
	((std::cout << t << " "), ...);//C++17�۵����ʽ
	endl(std::cout);
}

template<class... Ts>
class PayLoad :Ts...{
public:
	PayLoad(Ts...) {};
	using Ts::operator()...;
};

void LambdaStudy() {
	auto RecallLambda = [](int m) {//lambda���ʽʵ����һ����������
		for (int i = 0; i < m; i++) {
			std::cout << "i am lambda or just a nameless class without family variable \n";
		}};
	RecallLambda(5);

	auto M = []<typename T, typename ...Args>(T t, Args... args) {//lambda���ʽʵ����һ����������
		Myprintf(t);
		Myprintf(args...);
	};
	M("i ", "am ", "Variadic ", "package ", "template ", "lambda", "\n");
	int m = 10; int n = 20;
	auto N = [&n]/*��ͨ������ı��ⲿ������ֵ*/(int target) {
		n = target;
	};
	N(15);
	std::cout << n << std::endl;

	auto payLoad = PayLoad{ []() {MyDeleGate(Myprintf, 'h', 'e', 'l', 'l', 'o'); },
							[](int m) {MyDeleGate(Myprintf,' ',' '); },
							[](char n) {MyDeleGate(Myprintf,'W','o','r','l'); },
							[](float a) {MyDeleGate(Myprintf,'d','\n'); } };
	//[] <typename... Args>(void pf(Args... a),Args... args) { MyDeleGate(pf,args...); }
	payLoad(); payLoad(1); payLoad('c'); payLoad(1.2f);
}

void constexprStudy() {
	constexpr auto func = [](int n, int m) {
		int res = 1;
		for (int i = 0; i < m; i++) {
			res = res * n;
		}
		return res;
	};
	auto funcs = [](int n, int m) {
		int res = 1;
		for (int i = 0; i < m; i++) {
			res = res * n;
		}
		return res;
	};
	int m[func(3, 2)];
	std::vector<int>::iterator vi;
	//�Ƽ�ʹ��constexpr������ǰ���������ڼ�,��ǿ�����ݴ���,�����п��ܵ��±������޷�ʶ��ñ��ʽΪ����
	//int n[funcs(3, 2)];

}

//MyDeleGate(test);
	//std::cout << MySum(13.5, 1.2, 2.8, 3.75, 4.25, 5, 6.5, 7.5, 8.82, 9.18, 10.70);
	//MyDeleGate(f, 'n',48,50);