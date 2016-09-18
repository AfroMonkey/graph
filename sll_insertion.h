#ifndef SLL_INSERTION_H
#define SLL_INSERTION_H

template <typename T>
class SLLNode
{
    T data;
    SLLNode* next;
    SLLNode();
    SLLNode(const T data);
    SLLNode(const T data, SLLNode* next);
};

template <typename T>
SLLNode<T>::SLLNode()
{
    next = nullptr;
}

template <typename T>
SLLNode<T>::SLLNode(const T data)
{
    next = nullptr;
    this->data = data;
}

template <typename T>
SLLNode<T>::SLLNode(const T data, SLLNode* next)
{
    next = nullptr;
    this->data = data;
    this->next = next;
}

template <typename T>
class SLLI
{
    SLLNode<T>* start;
};


#endif
