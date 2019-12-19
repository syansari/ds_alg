template <typename T> 
class test {

    T t;
    int x_;
    explicit test(int x);

};


template<typename T>
test<T>::test(int x) : x_(x) {};