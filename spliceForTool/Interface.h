
#ifndef _INTERFACE_
#define _INTERFACE_

#include <thread>
#include <iostream>
#include <random>

#include "WaitSetData_DCPS.hpp"
#include "ini.hpp"

typedef void(*initTool)(double, double);
typedef void(*setToTool)(double, char*, char*);
typedef void(*setFinish)(double);
typedef void(*endTool)();

#define ACQUIRE_READY_STATE "acquire_ready_state"
#define NODE_READY "node_ready"
#define INITIAL_FEDERATE "initial_federate"
#define ADVANCE_REQUEST "advance_request"
#define ADVANCE_GRANT "advance_grant"
#define SIMULATION_RUN "simulation_run"
#define SIMULATION_END "simulation_end"

// current engine name
#define ENGINENAME "SIMUengine777"

using namespace std;
using namespace WaitSetData;

class Interface {

private:
	Interface();
	~Interface() {}
	Interface(const Interface&);
	Interface& operator=(const Interface&);

public:
	// singleton
	static Interface& getInstance() {
		static Interface instance;
		return instance;
	}

	// real interfaces
	bool start(const char* configName,
		initTool p_initTool, setToTool p_setToTool,
		setFinish p_setFinish, endTool p_endTool);
	bool setValue(string name, string data);
	bool advance();
	bool end();

	bool process(Msg);

private:
	// node management
	string systemId;
	int systemRunId;
	string nodeName;

	// 解析配置文件
	bool parseConfig(const char* configName);

	// time management
	double currentTime;
	double step;

	// 订阅发布的存储
	vector<string> pubNames;
	vector<string> subNames;

	// DDS相关
	map<string, dds::pub::DataWriter<Msg>> writers;
	map<string, dds::sub::DataReader<Msg>> readers;
	dds::core::cond::WaitSet waitSet;
	bool startServerDDS();
	bool publish(string, string);

	// data management
	map<string, string> dataMap;
	map<string, string> backupDataMap;

	// callback
	initTool p_initTool;
	setToTool p_setToTool;
	setFinish p_setFinish;
	endTool p_endTool;
};

#endif
