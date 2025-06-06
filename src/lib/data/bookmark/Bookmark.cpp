#include "Bookmark.h"

using namespace std;

Bookmark::Bookmark(
	const BookmarkId bookmarkId, 
	const std::wstring& name, 
	const std::wstring& comment, 
	const TimeStamp& timeStamp, 
	const BookmarkCategory& category)
	: m_bookmarkId(bookmarkId)
	, m_name(name)
	, m_comment(comment)
	, m_timeStamp(timeStamp)
	, m_category(category)
{
}

bool Bookmark::isValid() const
{
	return m_isValid;
}

void Bookmark::setIsValid(const bool isValid)
{
	m_isValid = isValid;
}

BookmarkId Bookmark::getId() const
{
	return m_bookmarkId;
}

std::wstring Bookmark::getName() const
{
	return m_name;
}

std::wstring Bookmark::getComment() const
{
	return m_comment;
}

TimeStamp Bookmark::getTimeStamp() const
{
	return m_timeStamp;
}

BookmarkCategory Bookmark::getCategory() const
{
	return m_category;
}

