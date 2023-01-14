#include "node.h"
#include "Trie.h"
#include <fstream>

Trie::Trie(std::fstream& data)
{
	for (char c = 'a'; c <= 'z'; ++c)
		m_next.emplace(c, Node(c));

	if (!data.is_open())
		throw std::exception("File is not open! Failed to initialize dictionary trie!");

	std::string tmp;
	while (std::getline(data,tmp))
	{
		if (m_next.find(tmp[0]) != m_next.end())
			m_next.at(tmp[0]).addWord(tmp);
	}

}

std::string Trie::findWord(const std::string& word)
{
	if (m_next.find(word[0]) == m_next.end())
		return std::string();
	return m_next.at(word[0]).searchWord(word);
}
