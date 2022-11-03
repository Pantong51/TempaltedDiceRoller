#pragma once

template<typename T>
struct NonCopyable
{
public:
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable(NonCopyable&&) = delete;
	T& operator=(const T&) = delete;
	T& operator=(T&&) = delete;
protected:
	NonCopyable() = default;
	virtual ~NonCopyable() = default;
};