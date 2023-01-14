#pragma once
#include <map>
#include <string>
class Node
{
public:
	Node() = delete;
	Node(const char c);
	~Node() = default;
public:
	bool addWord(std::string& word);

private:
	char addWord(std::string& word, int i);
	char c;
	std::map<char, Node> m_next;
};
