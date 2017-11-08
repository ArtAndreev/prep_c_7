#ifndef C_TASK7_LIST_H
#define C_TASK7_LIST_H

#include <exception>

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

template <class T>
class List {
public:
    List();
    List(std::initializer_list<T> list);
    List(const List<T>& obj);
    ~List();

    void push_back(T elem);
    void pop_back();
    void push_front(T elem);
    void pop_front();
    void clear();

    size_t size() const;
    bool empty() const;

    T& pop() const;
    T& pop();
    T& front() const;
    T& front();

    List<T>& operator=(const List<T>& rhs);
    T& operator[](size_t index) const;
    T& operator[](size_t index);
    List<T> operator+(const List<T>& rhs) const;
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& rhs);
private:
    Node<T>* head;
    Node<T>* tail;
    size_t list_size;
};

template <class T>
List<T>::List(): head(nullptr),
                 tail(nullptr),
                 list_size(0) {

}

template <class T>
List<T>::List(std::initializer_list<T> list): head(nullptr),
                                              tail(nullptr),
                                              list_size(0) {
    for (auto& i: list) {
        push_back(i);
    }
}

template <class T>
List<T>::List(const List& obj) {
    Node<T>* temp = obj.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
    list_size = obj.list_size;
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
void List<T>::push_back(T elem) {
    auto temp = new Node<T>(elem);

    if (tail != nullptr) {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    else {
        head = temp;
        tail = head;
    }
    list_size++;
}

template <class T>
void List<T>::pop_back() {
    if (tail == nullptr)
        throw std::range_error("List is empty.");

    if (tail->prev != nullptr) {
        Node<T>* prev = tail->prev;
        delete prev->next;
        prev->next = nullptr;
        tail = prev;
    }
    else {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    list_size--;
}

template <class T>
void List<T>::push_front(T elem) {
    auto temp = new Node<T>(elem);

    if (head != nullptr) {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else {
        head = temp;
        tail = head;
    }
    list_size++;
}

template <class T>
void List<T>::pop_front() {
    if (head == nullptr)
        throw std::range_error("List is empty.");

    if (head->next != nullptr) {
        Node<T>* next = head->next;
        delete next->prev;
        next->prev = nullptr;
        head = next;
    }
    else {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    list_size--;
}

template <class T>
void List<T>::clear() {
    if (head == nullptr)
        return;

    Node<T>* temp = head;
    while (temp != nullptr) {
        delete temp->prev;
        temp = temp->next;
    }
    delete temp;
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

template <class T>
size_t List<T>::size() const {
    return list_size;
}

template <class T>
bool List<T>::empty() const {
    return list_size == 0;
}

template <class T>
T& List<T>::pop() const {
    if (tail == nullptr)
        throw std::range_error("List is empty.");

    return tail->data;
}

template <class T>
T& List<T>::pop() {
    if (tail == nullptr)
        throw std::range_error("List is empty.");

    return tail->data;
}

template <class T>
T& List<T>::front() const {
    if (head == nullptr)
        throw std::range_error("List is empty.");

    return head->data;
}

template <class T>
T& List<T>::front() {
    if (head == nullptr)
        throw std::range_error("List is empty.");

    return head->data;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& rhs) {
    if (this == &rhs)
        return *this;

    clear();
    Node<T>* temp = rhs.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }

    return *this;
}

template <class T>
T& List<T>::operator[](size_t index) const {
    if (index >= list_size)
        throw std::invalid_argument("Wrong index given.");

    if (index == 0)
        return front();
    if (index == list_size - 1)
        return pop();

    Node<T>* temp = head;
    for (size_t i = 0; i < index; i++)
        temp = temp->next;

    return temp->data;
}

template <class T>
T& List<T>::operator[](size_t index) {
    if (index >= list_size)
        throw std::invalid_argument("Wrong index given.");

    if (index == 0)
        return front();
    if (index == list_size - 1)
        return pop();

    Node<T>* temp = head;
    for (size_t i = 0; i < index; i++)
        temp = temp->next;

    return temp->data;
}

template <class T>
List<T> List<T>::operator+(const List<T>& rhs) const {
    List<T> temp_list(*this);

    Node<T>* temp_node = rhs.head;
    while (temp_node != nullptr) {
        temp_list.push_back(temp_node->data);
        temp_node = temp_node->next;
    }

    return temp_list;
}

template <class U>
std::ostream& operator<<(std::ostream& os, const List<U>& rhs) {
    if (rhs.head != nullptr) {
        Node<U>* temp_node = rhs.head;
        while (temp_node->next != nullptr) {
            os << temp_node->data << ' ';
            temp_node = temp_node->next;
        }
        os << temp_node->data;
    }

    return os;
}

#endif //C_TASK7_LIST_H
