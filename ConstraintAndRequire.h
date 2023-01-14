#pragma once
#include<memory>
template<class T>
concept IsInteger = std::is_same_v<T, int>;//要求模板类型为int

template <class Father, class Child>
concept IsChild = std::is_base_of<Father, Child>::value;//要求传入两个类间有继承关系

//概念的作用是规范模板实例化类型,以免编译器生成我们不想生成的模板

class Father {

};
class Child :public virtual Father {

};

template<class U>
void RequireTest() requires IsInteger<U>{

}

template<class U,class T,class F>
void RequireTest2() requires IsInteger<U> and IsChild<T,F>{
	//通过概念约束模板的实例化范围
	//极大的加强代码稳定性
	//合取要求同时满足全部概念约束的条件 
	// 语法:requires 概念1&&概念2&&... 或 requires 概念1 and 概念2 and ... 
	//析取要求同时满足一个概念或多个概念约束的条件
	// 语法:requires 概念1||概念2||... 或 requires 概念1 or 概念2 or ... 
	//不可分割一般用于规范模板实例化类型(即按指定类型实例化)
	//语法: 模板(要求类型) 如 requires (MyType M) void Func<T>(M m)
}
template<class T>
void DeathTemplate() requires false{
	//当require 后接入的多个析取或合取或不可分割的概念(我称之为概念集),
	// 概念集的值为false时该模板不可实例化.
	//如同该案例
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