#include "node.h"

Node::Node(const char c) : c(c) {}

bool Node::addWord(std::string& word)
{
	if (word.empty())
		return false;

	if (word[0] != this->c)
		return false;


	if (std::find(m_next.begin(), m_next.end(), word[0]) == m_next.end())
	{
		m_next.emplace(word[0],Node(word[0]));
	}

	return m_next.at(word[0]).addWord(word, 1);
}

char Node::addWord(std::string& word, int i)
{
	if (i < 1)
	{
		std::exception("Invalid iterator argument.");
	}
	
	if (i == word.size() - 1)
	{
		c = word[word.size() - 1];
		return true;
	}

	if (std::find(m_next.begin(), m_next.end(), word[i]) == m_next.end())
	{
		m_next.emplace(word[i], Node(word[i]));
	}

	return m_next.at(word[0]).addWord(word, ++i);
}


