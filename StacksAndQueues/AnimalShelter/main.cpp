#include <iostream>
#include <list>

using namespace std;

class Animal {
public:
    string name;
    int age;
    virtual void noise() = 0;
};

class Cat: public Animal {
public:
    virtual void noise() {
        cout << "Meow!" << endl;
    }
};

class Dog: public Animal {
public:
    virtual void noise() {
        cout << "Woof!" << endl;
    }
};

template < typename T, typename C=std::list<T> >
class myQueue {
private:
    C _c;
public:
    myQueue (const C & c = C()) : _c(c) {}
    bool empty() {return _c.empty();}
    int size() {return _c.size();}
    void enqueue (const T& v) {_c.push_back(v);}
    void dequeue() { _c.pop_front(); }
    T& peek() {return _c.front(); }
};

enum Pet {DOG,
          CAT};

class AnimalShelter {
private:
    myQueue<Cat> cqueue;
    myQueue<Dog> dqueue;
    int time;
public:
    AnimalShelter(): time(0) {}
    void enqueue (Pet animal, string name);
    void dequeueCat();
    void dequeueDog();
    void dequeueAny();
};

void AnimalShelter::enqueue(Pet animal, string name) {
    string out;
    if (animal == DOG) {
        Dog newDog = Dog();
        newDog.age = time;
        newDog.name = name;
        dqueue.enqueue(newDog);
        out = "Dog " + name + " added to shelter";
    } else {
        Cat newCat = Cat();
        newCat.age = time;
        newCat.name = name;
        cqueue.enqueue(newCat);
        out = "Cat " + name + " added to shelter";
    }
    ++time;
    cout << out << endl;
}

void AnimalShelter::dequeueDog() {
    if(dqueue.empty()) {
        cout << "No Dogs anymore" << endl;
        return;
    }
    Dog d = dqueue.peek();
    dqueue.dequeue();
    cout << "Adopted a dog: " + d.name << endl;
}

void AnimalShelter::dequeueCat() {
    if(cqueue.empty()) {
        cout << "No Cats anymore" << endl;
        return;
    }
    Cat c = cqueue.peek();
    cqueue.dequeue();
    cout << "Adopted a cat: " + c.name << endl;
}

void AnimalShelter::dequeueAny() {
    if (dqueue.empty() && cqueue.empty()) {
        cout << "No Dogs or Cats" << endl;
        return;
    } else if (!dqueue.empty() && cqueue.empty()) {
        return dequeueDog();
    } else if (dqueue.empty() && !cqueue.empty()) {
        return dequeueCat();
    }

    Cat c = cqueue.peek();
    Dog d = dqueue.peek();
    return d.age > c.age ? dequeueCat() : dequeueDog();
}

int main()
{
    AnimalShelter as;
    as.enqueue(DOG, "Carl");
    as.enqueue(DOG, "Jelly");
    as.enqueue(CAT, "Salt");
    as.enqueue(CAT, "Red");

    as.dequeueCat();
    as.dequeueDog();
    as.dequeueAny();
    as.dequeueAny();
    as.dequeueCat();
    as.dequeueAny();

    return 0;
}
