#ifndef MESSAGE_CHANGE_FILE_VIEW_H
#define MESSAGE_CHANGE_FILE_VIEW_H

#include "CodeScrollParams.h"
#include "CodeSnippetParams.h"
#include "FilePath.h"
#include "Message.h"
#include "TabIds.h"

class MessageChangeFileView: public Message<MessageChangeFileView>
{
public:
	enum FileState
	{
		FILE_MINIMIZED,
		FILE_SNIPPETS,
		FILE_MAXIMIZED
	};

	enum ViewMode
	{
		VIEW_LIST,
		VIEW_SINGLE,
		VIEW_CURRENT
	};

	MessageChangeFileView(
		const FilePath& filePath,
		FileState state,
		ViewMode viewMode,
		CodeScrollParams scrollParams,
		bool switchesViewMode = false)
		: filePath(filePath)
		, state(state)
		, viewMode(viewMode)
		, scrollParams(scrollParams)
		, switchesViewMode(switchesViewMode)
	{
		setSchedulerId(TabIds::currentTab());
	}

	static const std::string getStaticType()
	{
		return "MessageChangeFileView";
	}

	void print(std::wostream& os) const override
	{
		os << filePath.wstr();

		switch (state)
		{
		case FILE_MINIMIZED:
			os << L", minimize";
			break;
		case FILE_SNIPPETS:
			os << L", snippets";
			break;
		case FILE_MAXIMIZED:
			os << L", maximize";
			break;
		}

		switch (viewMode)
		{
		case VIEW_LIST:
			os << L", list";
			break;
		case VIEW_SINGLE:
			os << L", single";
			break;
		case VIEW_CURRENT:
			os << L", current";
			break;
		}
	}

	const FilePath filePath;
	const FileState state;
	const ViewMode viewMode;
	const CodeScrollParams scrollParams;
	const bool switchesViewMode;
};

#endif	  // MESSAGE_CHANGE_FILE_VIEW_H
