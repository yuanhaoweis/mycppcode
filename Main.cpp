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

	};//�������Ѵ��������ռ��ͻ������ʱ,�����ǰ׺::����ȫ����������
	Myspace::ValueCon<int> valueCon;//�����ض������ռ��е�����
	//Ҫôusing namespace xx
	//Ҫôʹ��ʱ ->xx::yy
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
	//�޷�����,��Ϊδ��thisʱ��Ϊ�Ǵ�����,����ʵ����ǰ���к��������Ĳ�ѯ,��ָ�����ͬ������
	//��������ʵ����ǰΪ�գ��޷����а�,���±������.
	//Ϊ��������ú�����������ʵ��������в���,�����а�.
};

void func() {
	static int s_num = 0;
	int num = 0;
	std::cout << "�ú������ô�������̬��ʽ:" << ++s_num<<"\n";
	std::cout << "�ú������ô���,��̬��ʽ:" << ++num<<"\n";
	std::cout << "�ض��������ô���" << ++functwice<<"\n";
}

void func2() {
	std::cout << "�ض��������ô���" << ++functwice << "\n";
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

	std::cout << "&dex ����:" << typeid(&dex).name() << "\n,fex����:" << typeid(fex).name() << "\n&fex����:"
		<< typeid(&fex).name() << "\n";
	Base b{ 10 };
	Base bd = Base(b);
	Base bf{ b };
	std::cout << "bf��ַ:" << &bf << ",bd��ַ:" << &bd << "\n" << "b��ַ:" << &b << "\n";
	try {
		std::string("abc").substr(15);
		
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}

	Base bc{ 15 };
	Base ab(std::move(b));  //��ֵ��ָ���ʽ������Ͳ����ڵı���
							//��ֵ��ָ���ʽ�����������ܴ��ڵı�����
							//��ͨ��std::move()����ֵ�ƶ�����ֵ���ʽ�����ٿ����������ڴ濪��
	//std::move��ʵ���ǲ���static_cast��ʵ����һ��ǿ������ת��.
	int p = bc.getBase();
	int ptr = ab.getBase();
	std::cout << &p << "  " << &ptr << "\n";
	//std::cout<<std::endl;
}





template<typename T1,typename T2>
bool myis_same_v() {//std::is_same_v�ļ�ʵ��
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

void printfLoca(Location&& l) {//��ֵ����
	std::cout << "x is " << l.x << ",y is " << l.y << "\n";
}

template<typename T>
void RefrenceMoveTest(T&& t) {//������ֵ���ô���,�ȿ��Դ�����ֵ,�ֿ��Դ�����ֵ(�����ʽ���������ʧ�ĳ���)
	//std::cout << typeid("2019").name << std::endl;
	std::cout << t << std::endl;
}
	//RefrenceMoveTest(2019);

	//����˳��:
	//1.����Ҫ��Location����,���������Խ�����������ת����Location����,�������ж��ܹ�ת���ɹ�
	//2.ͨ���б��ʼ����Location����,��ͨ�������Աָ��������ݷ���
	//3.�����ʼ���ɹ�,�ú���ͨ����ֵ���û�ȡ��������Ȩ������ӡ����
	

	
/// <summary>
/// ��ֵ����ֵ
/// ��ֵ��ָ���ʽ��������Ȼ��ջ�ڴ��г������ڵ�ֵ(���ڴ治�ᱻ����)
/// ��ֵ��ָ���ʽ��������Ȼ��ջ�ڴ��в��ٴ��ڵ�ֵ(���ڴ���ڱ��ʽ�����󱻷���)
/// </summary>
/// <typeparam name="...T"></typeparam>
/// <param name="...t"></param>



void rvalue_test(int && p) {
	std::cout << p<<"\n";
	//��������¸ú�������������ֵ����,�������ֵͨ����ֵ���õķ�ʽ����ֵ���佫��ת����һ����ֵ,
	//����ú���������ϵͳ�ͷŸ���ֵ���ڴ�,��ֵ���ö�ʧ(����ֵ����ֵ,��ֵ��������ֵ)
	//����
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
	Myarray<int> f;//Myarray<int> f=ma ���ǵ�����������Ǹ��Ƴ�ʼ��
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
	RequireTest<int>();//����Լ��Ҫ��
	//RequireTest<float>();//������Լ��Ҫ��
	RequireTest2<int, Father, Child>();
	int *ptr;
	std::cout << &ptr;
	int p = 7;
	int j = 8;
	const int& ps = 15;//��ͬ�� int ps = 15��
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
	//RequireTest2<int, float, std::string>();//������ڶ���Լ��Ҫ��
	//rvalue_test(10);
	//DeathTemplate<char>(); //������ͬ��������
	//��������һ�¶��Ժ��쳣��ʹ�ó���

	//std::cout<<
#if 0 //Ԥ����ָ���ڱ���ǰִ��
	
	for (int i = 0; i < 5;i++) {
		func();
		func2();
	}
	B <int>b;
	b.Bfunc();
	b.n = 10;
	B<int> bb(b);
	std::cout << "address: " << &b << "��\nb's Value->" << b.n << "\n";
	std::cout << "address: " << &bb << "��\nbb's Value->" << bb.n << "\n";
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