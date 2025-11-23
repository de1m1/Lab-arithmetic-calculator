#pragma once

template<typename T>
class List {
private:
    struct Node {
        T data;          // Полезные данные
        Node* next;      // Указатель на следующий узел
        Node* prev;      // Указатель на предыдущий узел

        // Конструктор узла
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;    // Указатель на первый элемент
    Node* tail;    // Указатель на последний элемент  
    size_t size_;  // Количество элементов в списке

public:
    // Итератор для прохода по списку
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        // Доступ к данным
        T& operator*() { return current->data; }
        T* operator->() { return &current->data; }  // Для доступа к полям через ->

        // Префиксные инкременты
        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator& operator--() {
            current = current->prev;
            return *this;
        }

        // Постфиксные инкременты  
        Iterator operator++(int) {
            Iterator temp = *this;
            current = current->next;
            return temp;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            current = current->prev;
            return temp;
        }

        // Операторы сравнения
        bool operator!=(const Iterator& other) const { return current != other.current; }
        bool operator==(const Iterator& other) const { return current == other.current; }

        friend class List<T>;
        
    };

    // Конструктор по умолчанию
    List() : head(nullptr), tail(nullptr), size_(0) {}

    // Конструктор копирования
    List(const List& other) : head(nullptr), tail(nullptr), size_(0) {
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    // Деструктор - освобождает всю память
    ~List();

    // Основные методы
    void push_back(const T& value);   // Добавить в конец
    void push_front(const T& value);  // Добавить в начало
    void pop_back();                  // Удалить последний
    void pop_front();                 // Удалить первый
    void clear();                     // Очистить список
    
    // Доступы к элементам
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    // Оператор присваивания 
    List& operator=(const List& other);

    // Вставка и удаление по позиции
    void insert(const Iterator& pos, const T& value);
    void erase(const Iterator& pos);

    // Методы доступа
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    // Итераторы
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

template<typename T>
void List<T>::push_back(const T& value) {
    Node* newNode = new Node(value);

    if (empty()) {
        // Если список пустой
        head = tail = newNode;
    }
    else {
        // Если есть элементы
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    size_++;
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size_ = 0;
}

template<typename T>
void List<T>::push_front(const T& value) {
    Node* newNode = new Node(value);

    if (empty()) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    size_++;
}

template<typename T>
void List<T>::pop_back() {
    if (empty()) {
        throw std::runtime_error("List is empty!");
    }

    if (head == tail) {
        // Один элемент в списке
        delete tail;
        head = tail = nullptr;
    }
    else {
        // Много элементов
        Node* newTail = tail->prev;
        newTail->next = nullptr;
        delete tail;
        tail = newTail;
    }

    size_--;
}

template<typename T>
void List<T>::pop_front() {
    if (empty()) {
        throw std::runtime_error("List is empty!");
    }

    if (head == tail) {
        // Один элемент в списке
        delete head;
        head = tail = nullptr;
    }
    else {
        // Много элементов
        Node* newHead = head->next;
        newHead->prev = nullptr;
        delete head;
        head = newHead;
    }

    size_--;
}

template<typename T>
T& List<T>::front() {
    if (empty()) {
        throw std::runtime_error("List is empty!");
    }
    return head->data;
}

template<typename T>
const T& List<T>::front() const {
    if (empty()) {
        throw std::runtime_error("List is empty!");
    }
    return head->data;
}

template<typename T>
T& List<T>::back() {
    if (empty()) {
        throw std::runtime_error("List is empty!");
    }
    return tail->data;
}

template<typename T>
const T& List<T>::back() const {
    if (empty()) {
        throw std::runtime_error("List is empty!");
    }
    return tail->data;
}

template<typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
void List<T>::insert(const Iterator& pos, const T& value) {
    if (pos == begin()) {
        push_front(value);
    }
    else if (pos == end()) {
        push_back(value);
    }
    else {
        Node* newNode = new Node(value);
        Node* current = pos.current;
        Node* prevNode = current->prev;

        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = current;
        current->prev = newNode;

        size_++;
    }
}

template<typename T>
void List<T>::erase(const Iterator& pos) {
    if (pos == end() || empty()) {
        throw std::runtime_error("Invalid iterator!");
    }

    Node* toDelete = pos.current;

    if (toDelete == head) {
        pop_front();
    }
    else if (toDelete == tail) {
        pop_back();
    }
    else {
        Node* prevNode = toDelete->prev;
        Node* nextNode = toDelete->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete toDelete;
        size_--;
    }
}
