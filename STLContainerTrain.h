#pragma once
#include <stdc++.h>

void vectorStudy() {
	//Myprintf(0,'*',2,5,'o');
	std::vector<int> Vector;//vector(vector直译为向量,是一种单方向生长的无限长度数组)特点:
	//尾插极快,头插和间插较慢,查找慢(该数据类型有头部向尾部生长,
	//所以查询顺序与生长方向相反),时间复杂度:O(n)
	Vector.push_back(1);//vector的插入
	Vector.push_back(2);
	Vector.push_back(5);
	Vector.pop_back();
	/*std::cout << Vector[0] << "\n";
	for (int itr:Vector) {
		std::cout << itr << " ";//遍历
	}
	std::cout << "\n";*/
	std::cout << "vector's Data:";
	for (std::vector<int>::iterator itr = Vector.begin(); itr != Vector.end(); ++itr) {
		std::cout << *itr << " ";//迭代器版本遍历
	}
	std::cout << "\n";
	std::cout << Vector.size() << std::endl;//查看数组大小
	Vector.clear();//清空
	std::cout << Vector.empty() << std::endl;//是否为空
	// Vector.swap();可进行容器内容交换
	std::cout << Vector.size() << std::endl;//查看数组大小
	//迭代器全解

	//1.输出迭代器(Output Iterator),仅支持将数据从容器中输出到外界,不支持迭代器间比较。(仅能自增)
	//2.输入迭代器(Input Iterator),仅支持将数据输入到容器中,支持迭代器间比较。(仅能自增)
	//3.前向迭代器(Forward Iterator),结合了输入迭代器全部功能和输出迭代器的部分功能。(仅能自增),
	// 代表:forward_list
	// 4.双向迭代器(Bidirectional Iterator),前向迭代器的强化版,在前向迭代器的基础上添加了自减运算符,
	// 代表:list,set/multiset,map/multimap
	//5.随机存储迭代器(Random Access Iterator),在双向迭代器的基础上添加了跨距离存取的功能,
	// 即可以通过数学运算获取间隔超过一个单位的数据,这就是为什么该类型迭代器支持下标运算符重载
	// 代表:vector,deque,array
	//功能划分:插入迭代器(Insert Iterator),流迭代器(Stream Iterator),
	//反转迭代器(Reverse Iterator),移动迭代器(Move Iterator)

}

void dequestudy() {
	std::deque<int> Deque;//deque特点:(double-end-queue，又称双头队列)尾插头插极快，
	//间插较慢,查找速度中等(该数据类型由中央向两端生长,查询顺序与生长方向相反)
	Deque.push_front(1);//头插
	Deque.push_back(2);//尾插
	Deque.push_front(5);//头插
	Deque.push_back(4);//尾插
	Deque.push_front(11); //头插 ,结构应为:{11,5,1,2,4}
	std::deque<int>::iterator itr = find(Deque.begin(), Deque.end(), 2);
	Deque.insert(itr, 22);//现结构:{11,5,1,22,2,4}
	std::cout << "deque's Data:";
	for (std::deque<int>::iterator itr = Deque.begin(); itr != Deque.end(); itr++) {
		std::cout << *itr << " "; //迭代器版本遍历
	}
	std::cout << std::endl;
	std::cout << Deque.size() << std::endl;//查看容器大小
	Deque.clear();//清空
	std::cout << Deque.empty() << std::endl;//是否为空
	std::cout << Deque.size() << std::endl;//查看容器大小
}

void listStudy() {
	std::list<int> List = { 1,0,0,8,6 };//list(链表)特点:所有位置插入时间相同，查询速度慢,插入时间复杂度O(1),查找O(n)
	std::list<int>::iterator itr = find(List.begin(), List.end(), 2);
	//可通过该方式查找链表的指定位置
	List.insert(itr, 15);//通过迭代器进行指定位置插入
	std::cout << "List's Data:";
	for (std::list<int>::iterator itr = List.begin(); itr != List.end(); itr++) {
		std::cout << *itr << " "; //迭代器版本遍历
	}

}

void SetStudy() {
	std::set<int> Set;//set特点:遍历慢,查找快，时间复杂度O(log(n))
	Set.insert(0);//加入集合
	Set.insert(54);
	Set.insert(18);
	Set.insert(23);
	Set.erase(0);//从集合中去除
	Set.find(15);//查找是否含有该数据
}

void MapStudy() {
	std::map<int, int>Map;//map特点:参数2~4个,<键,值,比较键的对象,为map分配内存的对象>,可看作一个单元存储两个数据的set
	Map.emplace(0, 12);//Map插入
	Map.insert(std::pair<int, int>(12, 15));//可以与pair结合使用
	for (std::map<int, int>::iterator itr = Map.begin(); itr != Map.end(); itr++) {
		std::cout << (*itr).first << "=>" << (*itr).second << std::endl;
		//从该代码可知,迭代器实质是另一对象的指针,该对象包含了容器单元的存储信息
		//通过重载自增运算符实现了容器的遍历
	}
}


void stlStudy() {
	vectorStudy();
	dequestudy();
	listStudy();
	MapStudy();


	std::unordered_set<int> UnSet;//快速插入和查找(通过哈希函数查找),时间复杂度为O(1)
	std::unordered_map<int, char> UnMap;//

	UnMap[0] = 'a';//UnMap插入
}