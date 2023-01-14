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
	bool addWord(const std::string& word);
	std::string searchWord(const std::string& word);
private:
	bool addWord(const std::string& word, int i);
	std::string searchWord(const std::string& word, int i);
	std::string searchWord() const;
	char c;
	std::map<char, Node> m_next;
};

