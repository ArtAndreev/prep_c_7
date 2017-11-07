#ifndef C_TASK7_NODE_H
#define C_TASK7_NODE_H

template <class T>
struct Node {
    explicit Node(T elem);
    Node<T>* next;
    Node<T>* prev;
    T data;
};

template <class T>
Node<T>::Node(T elem): next(nullptr),
                       prev(nullptr),
                       data(elem) {

}

#endif //C_TASK7_NODE_H
