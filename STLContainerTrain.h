#pragma once
#include <stdc++.h>

void vectorStudy() {
	//Myprintf(0,'*',2,5,'o');
	std::vector<int> Vector;//vector(vectorֱ��Ϊ����,��һ�ֵ��������������޳�������)�ص�:
	//β�弫��,ͷ��ͼ�����,������(������������ͷ����β������,
	//���Բ�ѯ˳�������������෴),ʱ�临�Ӷ�:O(n)
	Vector.push_back(1);//vector�Ĳ���
	Vector.push_back(2);
	Vector.push_back(5);
	Vector.pop_back();
	/*std::cout << Vector[0] << "\n";
	for (int itr:Vector) {
		std::cout << itr << " ";//����
	}
	std::cout << "\n";*/
	std::cout << "vector's Data:";
	for (std::vector<int>::iterator itr = Vector.begin(); itr != Vector.end(); ++itr) {
		std::cout << *itr << " ";//�������汾����
	}
	std::cout << "\n";
	std::cout << Vector.size() << std::endl;//�鿴�����С
	Vector.clear();//���
	std::cout << Vector.empty() << std::endl;//�Ƿ�Ϊ��
	// Vector.swap();�ɽ����������ݽ���
	std::cout << Vector.size() << std::endl;//�鿴�����С
	//������ȫ��

	//1.���������(Output Iterator),��֧�ֽ����ݴ���������������,��֧�ֵ�������Ƚϡ�(��������)
	//2.���������(Input Iterator),��֧�ֽ��������뵽������,֧�ֵ�������Ƚϡ�(��������)
	//3.ǰ�������(Forward Iterator),��������������ȫ�����ܺ�����������Ĳ��ֹ��ܡ�(��������),
	// ����:forward_list
	// 4.˫�������(Bidirectional Iterator),ǰ���������ǿ����,��ǰ��������Ļ�����������Լ������,
	// ����:list,set/multiset,map/multimap
	//5.����洢������(Random Access Iterator),��˫��������Ļ���������˿�����ȡ�Ĺ���,
	// ������ͨ����ѧ�����ȡ�������һ����λ������,�����Ϊʲô�����͵�����֧���±����������
	// ����:vector,deque,array
	//���ܻ���:���������(Insert Iterator),��������(Stream Iterator),
	//��ת������(Reverse Iterator),�ƶ�������(Move Iterator)

}

void dequestudy() {
	std::deque<int> Deque;//deque�ص�:(double-end-queue���ֳ�˫ͷ����)β��ͷ�弫�죬
	//������,�����ٶ��е�(��������������������������,��ѯ˳�������������෴)
	Deque.push_front(1);//ͷ��
	Deque.push_back(2);//β��
	Deque.push_front(5);//ͷ��
	Deque.push_back(4);//β��
	Deque.push_front(11); //ͷ�� ,�ṹӦΪ:{11,5,1,2,4}
	std::deque<int>::iterator itr = find(Deque.begin(), Deque.end(), 2);
	Deque.insert(itr, 22);//�ֽṹ:{11,5,1,22,2,4}
	std::cout << "deque's Data:";
	for (std::deque<int>::iterator itr = Deque.begin(); itr != Deque.end(); itr++) {
		std::cout << *itr << " "; //�������汾����
	}
	std::cout << std::endl;
	std::cout << Deque.size() << std::endl;//�鿴������С
	Deque.clear();//���
	std::cout << Deque.empty() << std::endl;//�Ƿ�Ϊ��
	std::cout << Deque.size() << std::endl;//�鿴������С
}

void listStudy() {
	std::list<int> List = { 1,0,0,8,6 };//list(����)�ص�:����λ�ò���ʱ����ͬ����ѯ�ٶ���,����ʱ�临�Ӷ�O(1),����O(n)
	std::list<int>::iterator itr = find(List.begin(), List.end(), 2);
	//��ͨ���÷�ʽ���������ָ��λ��
	List.insert(itr, 15);//ͨ������������ָ��λ�ò���
	std::cout << "List's Data:";
	for (std::list<int>::iterator itr = List.begin(); itr != List.end(); itr++) {
		std::cout << *itr << " "; //�������汾����
	}

}

void SetStudy() {
	std::set<int> Set;//set�ص�:������,���ҿ죬ʱ�临�Ӷ�O(log(n))
	Set.insert(0);//���뼯��
	Set.insert(54);
	Set.insert(18);
	Set.insert(23);
	Set.erase(0);//�Ӽ�����ȥ��
	Set.find(15);//�����Ƿ��и�����
}

void MapStudy() {
	std::map<int, int>Map;//map�ص�:����2~4��,<��,ֵ,�Ƚϼ��Ķ���,Ϊmap�����ڴ�Ķ���>,�ɿ���һ����Ԫ�洢�������ݵ�set
	Map.emplace(0, 12);//Map����
	Map.insert(std::pair<int, int>(12, 15));//������pair���ʹ��
	for (std::map<int, int>::iterator itr = Map.begin(); itr != Map.end(); itr++) {
		std::cout << (*itr).first << "=>" << (*itr).second << std::endl;
		//�Ӹô����֪,������ʵ������һ�����ָ��,�ö��������������Ԫ�Ĵ洢��Ϣ
		//ͨ���������������ʵ���������ı���
	}
}


void stlStudy() {
	vectorStudy();
	dequestudy();
	listStudy();
	MapStudy();


	std::unordered_set<int> UnSet;//���ٲ���Ͳ���(ͨ����ϣ��������),ʱ�临�Ӷ�ΪO(1)
	std::unordered_map<int, char> UnMap;//

	UnMap[0] = 'a';//UnMap����
}