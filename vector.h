#ifndef VECTOR_H
#define VECTOR_H
#include <bits/stdc++.h>
#include <vector>

using namespace std;

template <class T> class Vector
{
    public: // interfeisas
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    using reference = T&;
    using difference_type = std::ptrdiff_t;

    // rule of three
    Vector(){create();}
    explicit Vector(size_type n, const T& t = T{}){create(n, t);}
    Vector(const Vector& v){create(v.begin(), v.end());}

    ~Vector(){uncreate();}

    T& operator[](size_type i){return data[i];}
    const T& operator[](size_type i) const{return data[i];}

    void push_back(const T& val)
    {
        if (avail == limit) grow();
        append(val);
    }
    void pop_back()
    {
        if (data == avail) return;
        alloc.destroy(--avail);
    }
    void clear()
    {
        if (data)
        {
            iterator it = avail;
            while (it != data)
            {
                alloc.destroy(--it);
            }
        }
        avail = data;
    }

    void reserve(size_type newSize)
    {
        if (newSize <= capacity()) return;
        change_size(newSize);
    }

    size_type size() const { return avail - data;}
    size_type capacity() const noexcept {return limit - data;}
    size_type max_size() const noexcept {return numeric_limits<difference_type>::max();}

    iterator begin(){return data;}
    const_iterator begin() const{return data;}

    iterator end(){return avail;}
    const_iterator end() const{return avail;}

    void shrink_to_fit()
    {
        if (size() == capacity()) return;
        change_size(size());
    }

    reference back(){return *(avail - 1);}

    iterator erase(const_iterator pirmas, const_iterator paskutinis)
    {
        if(pirmas == paskutinis || pirmas < data || paskutinis > avail) return nullptr;
        size_type fromInd = pirmas - data;
        size_type toInd = paskutinis - data;
        iterator from = data + fromInd;
        iterator to = data + toInd;

        for(iterator it = from; it < to; it++) alloc.destroy(from);

        while(to != avail)
        {
            *from = *to;
            from++;
            to++;
        }
        avail -= (toInd - fromInd);
    }

    reference at(size_type i){return data[i];}

    Vector& operator=(const Vector& v)
    {
        if (&v == this) return *this;
        destroy();
        create(v.begin(), v.end());
    }
private:
    iterator data; // kaip buvo anksčiau
    iterator avail; // pirmasis po paskutiniojo sukonstruoto Vector elementas
    iterator limit; // pirmasis po paskutiniojo Vector elementas

    // atminties išskyrimo valdymui
    allocator<T> alloc; // objektas atminties valdymui

    // išskirti atmintį (array) ir ją inicializuoti
    void create()
    {
        data = avail = limit = nullptr;
    }

    void create(size_type n, const T& val) {
     data = alloc.allocate(n); // grąžina ptr į array pirmą elementą
     limit = avail = data + n; // sustato rodykles į vietas
     uninitialized_fill(data, limit, val); // inicializuoja elementus val reikšme
    }

    void create(const_iterator i, const_iterator j) {
     data = alloc.allocate(j - i); // išskirti vietos j-i elementams
     limit = avail = uninitialized_copy(i, j, data); // nukopijuoja elementus iš intervalo
    }

    void uncreate()
    {
        if (data)
        {
            iterator it = avail;
            while (it != data)
            {
                alloc.destroy(--it);
            }
            alloc.deallocate(data, limit - data);
        }
        data = avail = limit = nullptr;
    }

    void destroy()
    {
        if (data)
        {
            iterator it = avail;
            while (it != data)
            {
                alloc.destroy(--it);
            }
            alloc.deallocate(data, limit - data);
        }
        data = avail = limit;
    }

    void change_size(size_type newSize)
    {
        iterator newData = alloc.allocate(newSize);
        iterator newAvail = uninitialized_copy(data, avail, newData);
        destroy();

        data = newData;
        avail = newAvail;
        limit = data + newSize;
    }
    void grow()
    {
        size_type newSize = std::max(size_type(1), 2 * capacity());
        change_size(newSize);
    }
};
//Main class
class Stud_base
{
    protected:   
        std::string name;
        std::string surname;
        std::string id;
        
};
class student : public Stud_base
{
    private:
        vector<int> homework;
        int exam;
        double finalGrade;
        bool random;
        bool cool;
    public:
        //base constructor
        student(std::string n, std::string s);

        student(std::string studentData);

        //getters
        std::string getName() {return name;}
        std::string getSurname() {return surname;}
        std::vector<int> getGrades() {return homework;}
        int getGradesCount() {return homework.size(); }
        int getExam() {return exam;}
        bool getRandom() {return random;}
        double getFinal() {return finalGrade;}
        bool hasGrades() {return !homework.empty();}
        bool getCool() {return cool;}
        //setters
        void setName(std::string n) {name = n;}
        void setSurname (std::string s) {surname = s;}
        void addGrade(int grade) {homework.push_back(grade); }
        void setGrades(std::vector<int> grades) {homework = grades; }
        void setExam(int examg) {exam = examg; }
        void setRandom(bool reiksme) {random = reiksme; }
        void setFinal(double f) {finalGrade = f;}
        void setCool(bool reiksme) {cool = reiksme; }
        //operator
        student& operator=(const student& studd);
        //destructor
    ~student(); 
};
#endif