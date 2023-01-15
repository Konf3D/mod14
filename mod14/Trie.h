#pragma once
#include "Node.h"
class Trie
{
public:
	Trie() = delete;
	explicit Trie(std::fstream& file);
	~Trie() = default;
public:
	std::string findWord(const std::string& word) const;
private:
	std::map<char, Node> m_next;
};