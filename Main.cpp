#include "ThreadFile.h"
#include "Demo.h"
#include "DATA.h"
#include "Data_Struct.h"
#include <stdc++.h>
#include "ConstraintAndRequire.h"
#include "LambdaTrain.h"
#include "Myarray.h"
#include "factorical.h"
void func(void *a) {
	int arr[2];
	arr[1] = 10;
	//arr[0] = (int)a;
	//arr[0](0);
}

void test() {
	Myspace::HashMap<int, char> hashmap;
	Myspace::HashMap<int, Myspace::HashMap<int, char>> hashmaps;
	Myspace::HashMap<int, void*> maps;
	hashmap.setkey(0);
	hashmap.setvalue('s');
	hashmaps.setvalue(hashmap);
	maps.setkey(0);
	//maps.setvalue(print);
	std::cout << maps.getvalue() << '\n';
	func(maps.getvalue());
	std::cout << hashmaps.getvalue().getkey() << "\n";
	std::cout << hashmaps.getvalue().getvalue();
}

void test2() {
	Base base = Base(10);
	Extends<std::string> extends{ "haha",7 };
	int nums[] = { 51,1,2,3,4,5,6,7,8,9 };
	add(base);
	BaseList<int> baseList = { nums,11 };
	char ptr[] = "hello world";
	ExtendsList<char, std::string> extendsList{ ptr,"haha",12 };
	ExtendsList<char, std::string> ss = extendsList + extendsList;
	std::cout << ss.GetValue() << "\n";
	ExtendsList<char, std::string>* fp = &ss;
	std::cout << extendsList.getBase() << "\n";
	std::cout << extends.GetValue() << "\n";
	for (int i = 0; i < 10; i++) {
		std::cout << baseList.GetList()[i] << "\n";
	}
	base.show();
	extends.show();
	baseList.show();
	extendsList.show();
	
}

template <typename ...Args>
void f(Args... arg) {
	for (const auto& i : { arg... }) {
		std::cout << i<<"";
	}
}

template <typename T>
T MySum(T t) {
	return t;
}

template <typename T,typename... Args>
T MySum(T t,Args... args) {
	return t + MySum(args...);
}



void Func(int t) {
#if 0
	int nums1[] = { 0,1,2,3,4 };
	int nums2[] = { 5,6,7,8,9 };
	BaseList<int> ex{ nums1,5 };
	BaseList<int> fex{ nums2,5 };
	BaseList<int> dex = ex + fex;
	std::cout << dex[6] << "\n";
	Myprintf(12, 15, 0, 18, 22);
	std::list<int> ls;
	ls.emplace_front(10);
	ls.emplace_front(11);
	ls.emplace_front(12);
	for (int f : ls) {
		std::cout << f << "\n";
	}
	struct std {

	};//存在与已存在命名空间冲突的名称时,可添加前缀::进行全局命名查找
	Myspace::ValueCon<int> valueCon;//对于特定命名空间中的配置
	//要么using namespace xx
	//要么使用时 ->xx::yy
	valueCon.setValue(10);
	Myspace::Container<int, Myspace::ValueCon> con;
	con.setValue(valueCon);
	::std::cout << con.getValue().getValue() << "\n";
#endif 
	std::cout << t << std::endl;
}

template<typename T>
struct A {
	int n;
	void Afunc() { }
};

template<class T> struct B:A<T>
{
	void Bfunc() { this->Afunc(); }
	//{ Afunc(); }
	//无法调用,因为未加this时其为非待决名,将在实例化前进行函数声明的查询,其指向父类的同名函数
	//而父类在实例化前为空，无法进行绑定,导致编译出错.
	//为待决名后该函数声明将在实例化后进行查找,并进行绑定.
};

void func() {
	static int s_num = 0;
	int num = 0;
	std::cout << "该函数调用次数，静态形式:" << ++s_num<<"\n";
	std::cout << "该函数调用次数,动态形式:" << ++num<<"\n";
	std::cout << "特定函数调用次数" << ++functwice<<"\n";
}

void func2() {
	std::cout << "特定函数调用次数" << ++functwice << "\n";
}

void funcfortest() {
	int nums1[] = { 0,1,2,3,4 };
	int nums2[] = { 5,6,7,8,9 };
	BaseList<int> aex{ nums1,5 };
	BaseList<int> bex{ nums2,5 };
	BaseList<int> cex = aex + bex;
	BaseList<int> dex(cex);
	BaseList<int>* fex = &dex;
	printf("Aex address:%d,Bex address:%d,Cex address %d,Dex address %d and value is %d,Fex address %d\n",
		&aex, &bex, &cex, &dex, dex[7], fex);

	std::cout << "&dex 类型:" << typeid(&dex).name() << "\n,fex类型:" << typeid(fex).name() << "\n&fex类型:"
		<< typeid(&fex).name() << "\n";
	Base b{ 10 };
	Base bd = Base(b);
	Base bf{ b };
	std::cout << "bf地址:" << &bf << ",bd地址:" << &bd << "\n" << "b地址:" << &b << "\n";
	try {
		std::string("abc").substr(15);
		
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}

	Base bc{ 15 };
	Base ab(std::move(b));  //右值是指表达式结束后就不存在的变量
							//左值是指表达式结束后依旧能存在的变量，
							//可通过std::move()将右值移动至左值表达式，减少拷贝变量的内存开销
	//std::move的实现是采用static_cast，实质是一种强制类型转换.
	int p = bc.getBase();
	int ptr = ab.getBase();
	std::cout << &p << "  " << &ptr << "\n";
	//std::cout<<std::endl;
}





template<typename T1,typename T2>
bool myis_same_v() {//std::is_same_v的简单实现
	return false;
}
template<typename T1>
bool myis_same_v() {
	return true;
}

struct Location {
	int x;
	int y;
};

void printfLoca(Location&& l) {//右值引用
	std::cout << "x is " << l.x << ",y is " << l.y << "\n";
}

template<typename T>
void RefrenceMoveTest(T&& t) {//采用右值引用传递,既可以传递左值,又可以传递右值(即表达式结束后就消失的常量)
	//std::cout << typeid("2019").name << std::endl;
	std::cout << t << std::endl;
}
	//RefrenceMoveTest(2019);

	//运行顺序:
	//1.函数要求Location类型,编译器尝试将括号内内容转换成Location类型,编译器判断能够转换成功
	//2.通过列表初始化该Location对象,并通过对象成员指针进行数据访问
	//3.对象初始化成功,该函数通过右值引用获取对象所有权，并打印数据
	

	
/// <summary>
/// 左值与右值
/// 左值是指表达式结束后依然在栈内存中持续存在的值(其内存不会被分配)
/// 右值是指表达式结束后依然在栈内存中不再存在的值(其内存会在表达式结束后被分配)
/// </summary>
/// <typeparam name="...T"></typeparam>
/// <param name="...t"></param>



void rvalue_test(int && p) {
	std::cout << p<<"\n";
	//正常情况下该函数结束后传入右值引用,如果该右值通过右值引用的方式与左值绑定其将被转化成一个左值,
	//否则该函数结束后系统释放该右值的内存,右值引用丢失(即右值是右值,右值引用是左值)
	//引用
}

void IntarrayTest() {
	int num[5];
	num[0] = 7;
	int a = 0;
	std::cout << "num[0]'s value:" << num[0] << "	num[0]'s address:" << &num[0] << "\n";
	std::cout << "num[1]'s address:" << &num[1] << "	num[0]'s size:" << sizeof(num[0]) << "\n";
	//std::cout << "int's byte" << sizeof(int) << "\n";
	//std::cout << "and try to get another value:" << (&num[0] + sizeof(int)/4) << "\n and a's value:"<<&a;
	//std::cout << "	a's operator:" << (&a) + sizeof(int) << "\n";
	*(&num[0] + sizeof(int) / 4) = 4;
	std::cout << num[1] << "\n";
}
void Doublearray() {
	double num[5];
	num[0] = 1.2;
	*(&num[0] + 1) = 2.5;
	double *n = &num[0];
	std::cout << *n<<"\n";
	
}
void MyArrayTest() {
	int Array[] = { 2,5,8,17,23,44,58,79,11,5,12,18,19 };
	Myarray<int>ma;
	std::cout << ma.isEmpty() << "\n";
	for (int i = 0; i < 13; i++) {
		ma.Add(Array[i]);
	}
	ma.Delete(3);
	std::cout << ma.size() << "\n";
	Myarray<int> f;//Myarray<int> f=ma 不是等于运算符而是复制初始化
	f = ma;
	std::cout << f[0] << "\n";
	//std::cout << ma[15];
	//std::cout << ma.isEmpty() << "\n";


	//std::cout << *ma[7] << std::endl;
}

void fuckcompiler() {
	MyDeleGate(fuckcompiler);
}

int main() {
	fuckcompiler();
	//std::cout << sizeof(Myarray<int>)<<"\n";
	//Myfactorical(1, 5);
	RequireTest<int>();//符合约束要求
	//RequireTest<float>();//不符合约束要求
	RequireTest2<int, Father, Child>();
	int *ptr;
	std::cout << &ptr;
	int p = 7;
	int j = 8;
	const int& ps = 15;//等同于 int ps = 15；
	int& pp = p;
	std::cout << &pp << std::endl;
	std::cout << &p << std::endl;
	int * const m = &p;//m = *&p
	int* s = &p;
	std::cout << typeid(m).name() << "\n";
	std::cout << typeid(&p).name() << std::endl;
	std::cout << m << std::endl;
	
	MyDeleGate(Myprintf,
		'h', 'e', 'l', 'l', 'o', ' ', ' ',
		'w', 'o', 'r', 'l', 'd', '!', '!', '!', '\n');
	//RequireTest2<int, float, std::string>();//不满足第二个约束要求
	//rvalue_test(10);
	//DeathTemplate<char>(); //基本等同于死函数
	//大佬请问一下断言和异常的使用场景

	//std::cout<<
#if 0 //预编译指令在编译前执行
	
	for (int i = 0; i < 5;i++) {
		func();
		func2();
	}
	B <int>b;
	b.Bfunc();
	b.n = 10;
	B<int> bb(b);
	std::cout << "address: " << &b << "。\nb's Value->" << b.n << "\n";
	std::cout << "address: " << &bb << "。\nbb's Value->" << bb.n << "\n";
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	std::cout << dex.getBase() << "\n";
	dex.setBase(15);
	std::cout << cex.getBase() << "\n";
#endif 

	
	
} 
//LambdaStudy();
	//XList<1, 2, 3, 5, 6,7, 8> x;
	//x.PrintData();
	//printfLoca({ .x = 1,.y = 2 });
	//PrintFuns(1, 2, 3, 4, 5, 6, 7, 8, 9);
	//Doublearray();