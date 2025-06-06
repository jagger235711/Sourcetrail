#ifndef TASK_H
#define TASK_H

#include "Id.h"
#include "TabIds.h"

#include <memory>

class Blackboard;

class Task
{
public:
	enum TaskState
	{
		STATE_RUNNING,
		STATE_HOLD,
		STATE_SUCCESS,
		STATE_FAILURE
	};
	
	static void dispatch(TabId schedulerId, std::shared_ptr<Task> task);
	static void dispatchNext(TabId schedulerId, std::shared_ptr<Task> task);

	virtual ~Task() = default;

	void setIsBackgroundTask(bool background);

	TaskState update(std::shared_ptr<Blackboard> blackboard);
	void reset(std::shared_ptr<Blackboard> blackboard);
	virtual void terminate();	 // caution: this should only be called just before quitting the app.

private:
	virtual void doEnter(std::shared_ptr<Blackboard> blackboard) = 0;
	virtual Task::TaskState doUpdate(std::shared_ptr<Blackboard> blackboard) = 0;
	virtual void doExit(std::shared_ptr<Blackboard> blackboard) = 0;
	virtual void doReset(std::shared_ptr<Blackboard> blackboard) = 0;

	bool m_isBackgroundTask = false;

	bool m_enterCalled = false;
	bool m_exitCalled = false;
};

#endif	  // TASK_H
