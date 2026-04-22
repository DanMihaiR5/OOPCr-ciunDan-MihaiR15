#pragma once
#include <iostream>

template<typename T>
class Tree
{
public:

    struct Node
    {
        T value;
        Node** children;
        int children_count;
        int capacity;

        Node(T val)
        {
            value = val;
            children = nullptr;
            children_count = 0;
            capacity = 0;
        }
    };

private:

    Node* root;

    void resize(Node* node)
    {
        int new_cap = (node->capacity == 0) ? 2 : node->capacity * 2;

        Node** new_children = new Node*[new_cap];

        for(int i = 0; i < node->children_count; i++)
            new_children[i] = node->children[i];

        delete[] node->children;

        node->children = new_children;
        node->capacity = new_cap;
    }

    void delete_recursive(Node* node)
    {
        if(!node) return;

        for(int i = 0; i < node->children_count; i++)
            delete_recursive(node->children[i]);

        delete[] node->children;
        delete node;
    }

    int count_recursive(Node* node)
    {
        if(!node) return 0;

        int total = node->children_count;

        for(int i = 0; i < node->children_count; i++)
            total += count_recursive(node->children[i]);

        return total;
    }

    Node* find_recursive(Node* node, T value, bool (*cmp)(T,T))
    {
        if(!node) return nullptr;

        if(cmp(node->value, value))
            return node;

        for(int i = 0; i < node->children_count; i++)
        {
            Node* r = find_recursive(node->children[i], value, cmp);
            if(r) return r;
        }

        return nullptr;
    }

public:

    Tree()
    {
        root = nullptr;
    }

    Node* add_node(Node* parent, T value)
    {
        Node* newNode = new Node(value);

        if(parent == nullptr)
        {
            root = newNode;
            return root;
        }

        if(parent->children_count >= parent->capacity)
            resize(parent);

        parent->children[parent->children_count++] = newNode;

        return newNode;
    }

    Node* get_node(Node* parent)
    {
        if(parent == nullptr)
            return root;

        return parent;
    }

    void delete_node(Node* node)
    {
        delete_recursive(node);
    }

    Node* find(T value, bool (*cmp)(T,T))
    {
        return find_recursive(root, value, cmp);
    }

    Node* insert(Node* parent, int index, T value)
    {
        if(!parent) return nullptr;

        if(parent->children_count >= parent->capacity)
            resize(parent);

        for(int i = parent->children_count; i > index; i--)
            parent->children[i] = parent->children[i-1];

        Node* newNode = new Node(value);

        parent->children[index] = newNode;
        parent->children_count++;

        return newNode;
    }

    void sort(Node* node, bool (*cmp)(T,T) = nullptr)
    {
        if(!node) return;

        for(int i = 0; i < node->children_count; i++)
        {
            for(int j = i+1; j < node->children_count; j++)
            {
                bool cond;

                if(cmp)
                    cond = cmp(node->children[j]->value, node->children[i]->value);
                else
                    cond = node->children[j]->value < node->children[i]->value;

                if(cond)
                {
                    Node* tmp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = tmp;
                }
            }
        }
    }

    int count(Node* node)
    {
        if(node == nullptr)
            node = root;

        return count_recursive(node);
    }
};