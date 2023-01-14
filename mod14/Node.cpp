#include "node.h"
#include <iostream>
Node::Node(const char c) 
	: c(c) 
{
	//constructor
}

bool Node::addWord(const std::string& word)
{
	if (word.empty())
		return false;

	if (word[0] != this->c)
		return false;


	if (m_next.find(word[0]) == m_next.end())
	{
		m_next.emplace(word[0],Node(word[0]));
	}

	return m_next.at(word[0]).addWord(word, 1);
}

std::string Node::searchWord(const std::string& word)
{
	if (word.empty())
		throw std::exception("Empty word was parsed!");

	if (word[0] != this->c)
		throw std::exception("Wrong symbol was parsed!");

	if (m_next.find(word[0]) == m_next.end())
	{
		return std::string();
	}

	return std::string(c + m_next.at(word[0]).searchWord(word, 1));
}

bool Node::addWord(const std::string& word, int i)
{
	if (i < 1)
	{
		return false;
	}
	
	if (i == word.size() - 1)
	{
		c = word[word.size() - 1];
		return true;
	}

	if (m_next.find(word[i]) == m_next.end())
	{
		m_next.emplace(word[i], Node(word[i]));
	}

	return m_next.at(word[0]).addWord(word, ++i);
}

std::string Node::searchWord(const std::string& word, int i)
{
	if (i < 1)
	{
		throw std::exception("Negative iterator was parsed!");
	}
	// return first found
	if (i >= word.size() - 1)
	{
		return std::string(c + searchWord());
	}
	else
	{
		if (m_next.find(word[i]) == m_next.end())
		{
			return std::string(1, c);
		}
		else
		{
			return std::string(c + m_next.at(word[i]).searchWord(word, ++i));
		}
	}
	throw std::exception("Search failed!");
}

std::string Node::searchWord() const
{
	if (m_next.empty())
	{
		return std::string(1,c);
	}
	for (const auto& data : m_next)
	{
		return data.second.searchWord();
	}
}


