#include <iostream>
#include <memory>
//using namespace std;

template<typename T>
class A{
    T _t;
public:
    A(T new_T):_t(new_T){}
    A(const A &that){
        _t=that._t;
        std::cout<<"CopyCon1"<<std::endl;
    }
    A(const A *that){
        _t=that->_t;
        std::cout<<"CopyCon2"<<std::endl;
    }
    virtual ~A(void){
        std::cout<<"Destructor"<<std::endl;
    }
    T getT(void) const{return _t;}
    void setT(const T new_T) {_t=new_T;}
};

typedef A<int> IntA;

int main()
{
    IntA a(21);a.setT(42);
    std::shared_ptr< IntA > aa=std::make_shared<IntA>(IntA (32));
    std::shared_ptr< A<int> >aaa=std::make_shared< A<int> >(A<int>(23));

    std::cout << "a:   "<<a.getT() << std::endl;
    std::cout << "aa:  "<<aa->getT() << std::endl;
    std::cout << "aaa: "<<aaa->getT() << std::endl;

    return 0;
}
