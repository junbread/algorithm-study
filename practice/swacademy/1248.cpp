#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int id;
    vector<Node *> children;

    int find(int a, int b)
    {
        bool find_a = false, find_b = false;
        for (Node *child : children)
        {
            int f = child->find(a, b);
            if (f == -a)
                find_a = true;
            else if (f == -b)
                find_b = true;
            else if (f > 0)
                return f;
        }

        if (id == a)
            find_a = true;
        else if (id == b)
            find_b = true;

        if (find_a && find_b)
            return id;
        else if (find_a)
            return -a;
        else if (find_b)
            return -b;

        return 0;
    }

    int size()
    {
        int result = 1;
        for(Node * child : children)
            result += child->size();

        return result;
    }
};

int main(int argc, char **argv)
{
    int T, V, E, a, b, p, c;

    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> V >> E >> a >> b;

        vector<Node> tree(V + 1, Node());
        for (int i = 1; i < V + 1; i++)
            tree[i].id = i;

        for (int i = 0; i < E; i++)
        {
            cin >> p >> c;
            tree[p].children.push_back(&tree[c]);
        }

        int lca = tree[1].find(a, b);
        int subtree_size = tree[lca].size();
        
        cout << "#" << test_case << " " << lca << " " << subtree_size << endl;
    }
    return 0;
}