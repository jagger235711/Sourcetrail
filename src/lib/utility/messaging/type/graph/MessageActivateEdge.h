#ifndef MESSAGE_ACTIVATE_EDGE_H
#define MESSAGE_ACTIVATE_EDGE_H

#include "Edge.h"
#include "NameHierarchy.h"

#include "Message.h"
#include "TabIds.h"
#include "types.h"
#include "utilityString.h"

class MessageActivateEdge: public Message<MessageActivateEdge>
{
public:
	MessageActivateEdge(
		Id tokenId,
		Edge::EdgeType type,
		const NameHierarchy& sourceNameHierarchy,
		const NameHierarchy& targetNameHierarchy)
		: tokenId(tokenId)
		, type(type)
		, sourceNameHierarchy(sourceNameHierarchy)
		, targetNameHierarchy(targetNameHierarchy)
	{
		if (!isBundledEdges())
		{
			setKeepContent(true);
		}

		setSchedulerId(TabIds::currentTab());
	}

	static const std::string getStaticType()
	{
		return "MessageActivateEdge";
	}

	bool isBundledEdges() const
	{
		return type == Edge::EDGE_BUNDLED_EDGES;
	}

	std::wstring getFullName() const
	{
		std::wstring name = Edge::getReadableTypeString(type) + L":";
		name += sourceNameHierarchy.getQualifiedNameWithSignature() + L"->";
		name += targetNameHierarchy.getQualifiedNameWithSignature();
		return name;
	}

	void print(std::wostream& os) const override
	{
		os << tokenId << L" - " << getFullName();
	}

	const Id tokenId;
	const Edge::EdgeType type;
	const NameHierarchy sourceNameHierarchy;
	const NameHierarchy targetNameHierarchy;

	std::vector<Id> bundledEdgesIds;
};

#endif	  // MESSAGE_ACTIVATE_EDGE_H
