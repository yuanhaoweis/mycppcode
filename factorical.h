#pragma once
#include <iostream>
#include <string>
#include <memory>
class Basicinterface{
public:
	virtual ~Basicinterface(){};
};

template <typename T>
class DataProviderInterface:virtual public Basicinterface {
public:
	//DataProviderInterface(DataProviderInterface& pi) { this = pi; };
	virtual T firstData() { return T{}; };
	virtual T lastData() { return T{}; };
	virtual T next(T t) { return t; };
	virtual ~DataProviderInterface(){};
};

template<typename T1,typename T2>
class CalulatorInterface :virtual public Basicinterface {
public:
	//CalulatorInterface(CalulatorInterface& ci) { this = ci; };
	virtual T1 Calulate(DataProviderInterface <T2>_dataProviderInterface) { return T1{}; };
	virtual ~CalulatorInterface(){};
};

template <typename T>
void RealFactorical(T& res, T t, DataProviderInterface<T> dpi) {
	if (t != dpi.lastData()) {
		RealFactorical(res * dpi.next(), dpi.next(), dpi);
	}
	res* dpi.lastData();
}

class PrinterInterface :virtual public Basicinterface {
public:
	//PrinterInterface(PrinterInterface& pi) { *this = pi; };
	virtual void Print(const std::string str){};
	virtual ~PrinterInterface(){};
};

template<typename T>
class SerializerInterface :virtual public Basicinterface {
public:
	//SerializerInterface(SerializerInterface& _si) { this = _si; };
	virtual std::string Serialize(T t) { return "Serialize"; };
	virtual ~SerializerInterface(){};
};


class RunableInterface :virtual public Basicinterface {
public:
	virtual void Run() = 0;
};
template <typename C,typename F>
concept IsDataProviderInterface = std::is_base_of<DataProviderInterface<F>,C>::value;


template <typename T>
class IDataProvider :virtual public DataProviderInterface<T>{
	T LastData;
	T FirstData;
public:
	IDataProvider(T _first,T _last):FirstData(_first),LastData(_last){}
	T firstData() override{
		return this->FirstData;
	}
	T lastData() override{
		return this->LastData;
	}
	T next(T t) override{
		return t++;
	}
	~IDataProvider() {
		//~DataProviderInterface<T>();
	}
};

template<typename T1,typename T2>
class ICalulator :virtual public CalulatorInterface<T1,T2> {
public:
	T1 Calulate(IDataProvider<T2> _dataProviderInterface){
		T1 i = _dataProviderInterface.firstData();
		T1 j = i;
		do {
			j *= _dataProviderInterface.next(i++);
		} while (i <= _dataProviderInterface.lastData());
		return j;
	}
	
	~ICalulator() {
		//~CalulatorInterface<T1,T2>();
	}
};

template<typename T>
class ISerializer :virtual public SerializerInterface<T>{
public:
	std::string Serialize(T t) override{ return std::to_string(t); }
	~ISerializer() {
		//~SerializerInterface<T>();
	}
};

class IPrinter:virtual public PrinterInterface {
	std::ostream& os;
public:
	IPrinter(std::ostream& o) :os(o){}; //{};
	void Print(const std::string str) override{
		os << str << std::endl;
	}
	~IPrinter() {
		//~PrinterInterface();
	}
};

template<typename T1, typename T2>
class Factorical :virtual public RunableInterface {
	//多继承情况下,派生类实例化顺序与基类声明顺序一致 
	//std::shared_ptr <IDataProvider<T1>> _dpi;
	IDataProvider<T1> _dpi;
	//std::shared_ptr<IPrinter> _pi;
	//std::shared_ptr <ICalulator<T2, T1>> _ci;
	IPrinter  _pi;
	ICalulator<T2, T1> _ci;
	//std::shared_ptr <ISerializer<T2>> _si;
	ISerializer<T2> _si;
public:
	Factorical(IDataProvider<T1> dpi, IPrinter pi,
		ICalulator<T2, T1> ci, ISerializer<T2> si)
		:_dpi(dpi), _pi(pi),_ci(ci), _si(si) {};
	~Factorical() {};
	void Run() override {
		this->_pi.Print(this->_si.Serialize(this->_ci.Calulate(this->_dpi)));
	}
	void operator()() {
		this->Run();
	}
};
template <typename T1,typename T2>
void ConceptTest() requires IsDataProviderInterface<T1,T2>{
	
}

void Myfactorical(const int n1=1,const int n2=10) {
	if (n1 < n2) {
		auto a = [](int m, int n) {
			Factorical<int, long> {IDataProvider<int>{m, n}, IPrinter{ std::cout },
				ICalulator<long, int>{}, ISerializer<long>{}}();
		};
		a(n1, n2);
		//ConceptTest<IDataProvider<int>,int>();
	}

}