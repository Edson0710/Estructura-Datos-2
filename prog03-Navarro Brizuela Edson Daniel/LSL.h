#ifndef LSL_H
#define LSL_H
#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>

using namespace std;

template<typename T>
class LSL
{
private:
    class NodeLSL
    {
    public:
        T data;
        shared_ptr<NodeLSL> next;
        //Constructor
        //elem : element to be added
        //n : pointer to the next element
        //example: NodeLSL(33);
        //example: NodeLSL(33, nextNode);
        NodeLSL(const T& elem, shared_ptr<NodeLSL> n = nullptr) : data(elem), next(n)
        {}
    };

    size_t listSize;
    shared_ptr<NodeLSL> listFront;
    shared_ptr<NodeLSL> listBack;

public:
    LSL()
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;
    }
    ~LSL()
    {
        clear();
    }


    bool empty() const;
    size_t size() const;
    void push_front(const T& element);
    void push_back(const T& element);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& element);
    void erase(size_t position);
    void clear();
    void remove(const T& element);
    T& getData(size_t position);
    // T& operator [] (size_t position);
    void mostrar();
    void guardar();
    void cargar();
    T* siguiente(size_t position);
    T* anterior(size_t position);
    T* buscar_dato(const T& element);
    void modificar(const T& element);
    int posicion(const T& element);
};


template<typename T>
bool LSL<T>::empty() const
{
    return listSize == 0;
}

template<typename T>
size_t LSL<T>::size() const
{
    return listSize;
}

template<typename T>
void LSL<T>::push_front(const T& element)
{
    if (empty())
    {
        listFront = make_shared<NodeLSL>(element);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodeLSL> temp = make_shared<NodeLSL>(element, listFront);
        listFront = temp;
    }

    ++listSize;
}

template<typename T>
void LSL<T>::push_back(const T& element)
{
    if (empty())
    {
        listFront = make_shared<NodeLSL>(element);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodeLSL> temp = make_shared<NodeLSL>(element);
        listBack->next = temp;
        listBack = temp;
    }

    ++listSize;
}

template<typename T>
const T& LSL<T>::front() const
{
    if (empty())
    {
        throw runtime_error("trying front() from empty list");
    }

    return listFront->data;
}

template<typename T>
const T& LSL<T>::back() const
{
    if (empty())
    {
        throw runtime_error("trying back() from empty list");
    }

    return listBack->data;
}

template<typename T>
void LSL<T>::pop_front()
{
    if (empty())
    {
        throw runtime_error("trying pop_front() from empty list");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        listFront = listFront->next;
    }
    --listSize;
}

template<typename T>
void LSL<T>::pop_back()
{
    if (empty())
    {
        throw runtime_error("Trying pop_back() from empty list");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        shared_ptr<NodeLSL> temp = listFront;
        while(temp->next != listBack)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        listBack = temp;
    }
    --listSize;
}

template<typename T>
void LSL<T>::insert(size_t position, const T& element)
{
    if (empty())
    {
        throw runtime_error("trying insert() on empty list");
    }
    else if (position > size())
    {
        throw range_error("trying insert() in non valid position");
    }
    else if (position == 0)
    {
        push_front(element);
    }
    else if (position == size())
    {
        push_back(element);
    }
    else
    {
        shared_ptr<NodeLSL> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->next;
        }
        shared_ptr<NodeLSL> newNode = make_shared<NodeLSL>(element, temp->next);
        temp->next = newNode;
        ++listSize;
    }
}

template<typename T>
void LSL<T>::erase(size_t position)
{
    if (empty())
    {
        throw runtime_error("trying erase() from empty list");
    }
    else if (position >= size())
    {
        throw range_error("trying erase() from non valid position");
    }
    else if (position == 0)
    {
        pop_front();
    }
    else if (position == size()-1)
    {
        pop_back();
    }
    else
    {
        shared_ptr<NodeLSL> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        --listSize;
    }
}

template<typename T>
void LSL<T>::clear()
{
    while(!empty())
    {
        pop_front();
    }
}

template<typename T>
void LSL<T>::remove(const T& element)
{
    if (empty())
    {
        throw runtime_error("trying remove() from empty list");
    }
    else
    {
        T data;
        size_t i = 0;
        shared_ptr<NodeLSL> temp = listFront;

        while (temp != nullptr)
        {
            data = temp->data;
            temp = temp->next;
            if (element == data)
            {
                erase(i);
                --i;
            }
            ++i;
        }
    }
}

template<typename T>
T& LSL<T>::getData(size_t position)
{
    if (empty())
    {
        throw runtime_error("trying getData() from empty list");
    }
    else if (position >= size())
    {
        throw range_error("trying getData() in non valid position");
    }

    shared_ptr<NodeLSL> temp = listFront;
    for (size_t i(0); i < position; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
void LSL<T>::mostrar()
{   
    if(empty()){
        cout << "La lista esta vacia." << endl;
    }
    else{
        for(size_t i(0); i < size(); i++){
            cout << getData(i);
        }
    }
    
}


template<typename T>
T* LSL<T>::siguiente(size_t position){
    return &getData(position+1);
}

template<typename T>
T* LSL<T>::anterior(size_t position){
    return &getData(position-1);
}

template<typename T>
T* LSL<T>::buscar_dato(const T& element){
    for(size_t i(0); i < size(); i++){
        if(element == getData(i)){
            return &getData(i);
        }
    }
    return nullptr;
}

template<typename T>
void LSL<T>::modificar(const T& element){
    string nombre, liga, pais;
    T* data = this->buscar_dato(element);
    if(data == nullptr){
        cout << "El elemento a modificar no existe" << endl;
    } 
    else{
        cout << "Ingresa el nuevo nombre: ";
        getline(cin, nombre);
        cout << "Ingresa la nueva liga: ";
        getline(cin, liga);
        cout << "Ingresa el nuevo pais: ";
        getline(cin, pais);
        data->setNombre(nombre);
        data->setLiga(liga);
        data->setPais(pais);
        cout << "Elemento modificado" << endl;
    }
}

template<typename T>
int LSL<T>::posicion(const T& element){
    for(size_t i = 0; i < size(); i++){
        if(getData(i) == element){
            return i;
        }
    }
    return -1;
}

#endif // LSL_H
