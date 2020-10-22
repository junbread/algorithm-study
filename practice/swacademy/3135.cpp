#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

inline char alphabet(char c)
{
	return c - 'a';
}

class TrieNode
{
	TrieNode *children[26];
	int children_size;

public:
	TrieNode()
	{
		children_size = 0;
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
		for (int i = 0; i < 26; i++)
			if (children[i])
				delete children[i];
	}

	void insert(int str_size, char *str)
	{
		if (!str_size)
		{
			children_size++;
			return;
		}

		TrieNode *next_node = children[alphabet(str[0])];

		if (!next_node)
		{
			next_node = new TrieNode();
			children[alphabet(str[0])] = next_node;
		}

		next_node->insert(str_size - 1, str + 1);
		children_size++;
	}

	int query(int str_size, char *str)
	{
		if (!str_size)
			return children_size;

		TrieNode *next_node = children[alphabet(str[0])];

		if (!next_node)
			return 0;

		return next_node->query(str_size - 1, str + 1);
	}
};

TrieNode *data;

void init(void)
{
	data = new TrieNode();
}

void insert(int buffer_size, char *buf)
{
	return data->insert(buffer_size, buf);
}

int query(int buffer_size, char *buf)
{
	return data->query(buffer_size, buf);
}

int main(void)
{
	int test_case;
	for (scanf("%d", &test_case); test_case--;)
	{
		int query_n;
		scanf("%d", &query_n);

		init();

		static int tc = 0;
		printf("#%d", ++tc);

		for (int i = 1; i <= query_n; i++)
		{
			int type;
			scanf("%d", &type);

			if (type == 1)
			{
				char buf[15] = {
					0,
				};
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size])
					buffer_size++;

				insert(buffer_size, buf);
			}
			else
			{
				char buf[15] = {
					0,
				};
				scanf("%s", buf);

				int buffer_size = 0;
				while (buf[buffer_size])
					buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
		fflush(stdout);
	}
}