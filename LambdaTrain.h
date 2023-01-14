#pragma once
#include <iostream>
template <typename T>
void Myprintf(T t1) {
	std::cout << t1;
}

template <typename T, typename ...Args>
void Myprintf(T t1, Args... arg) {
	//std::cout << "第" << sizeof...(arg) << "个参数:";
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
void MyDeleGate(void fp(Args... arg), Args... arg) {//函数代理,目前仅支持返回类型为void型
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
	((std::cout << t << " "), ...);//C++17折叠表达式
	endl(std::cout);
}

template<class... Ts>
class PayLoad :Ts...{
public:
	PayLoad(Ts...) {};
	using Ts::operator()...;
};

void LambdaStudy() {
	auto RecallLambda = [](int m) {//lambda表达式实质是一个匿名空类
		for (int i = 0; i < m; i++) {
			std::cout << "i am lambda or just a nameless class without family variable \n";
		}};
	RecallLambda(5);

	auto M = []<typename T, typename ...Args>(T t, Args... args) {//lambda表达式实质是一个匿名空类
		Myprintf(t);
		Myprintf(args...);
	};
	M("i ", "am ", "Variadic ", "package ", "template ", "lambda", "\n");
	int m = 10; int n = 20;
	auto N = [&n]/*可通过捕获改变外部变量的值*/(int target) {
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
	//推荐使用constexpr将计算前推至编译期间,增强代码容错性,否则有可能导致编译器无法识别该表达式为常数
	//int n[funcs(3, 2)];

}

//MyDeleGate(test);
	//std::cout << MySum(13.5, 1.2, 2.8, 3.75, 4.25, 5, 6.5, 7.5, 8.82, 9.18, 10.70);
	//MyDeleGate(f, 'n',48,50);