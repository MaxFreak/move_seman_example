#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::vector;

class resource {
	int x = 0;
};

class foo
{
	public:
		foo()
			: p{new resource{}}
		{
            cout << std::hex << std::dec << this << " constructor" << endl;
        }
		foo(const foo& other)
			: p{new resource{*(other.p)}}
		{
            cout << std::hex << std::dec << this << " copy" << endl;
        }
		foo(foo&& other)
			: p{other.p}
		{
			other.p = nullptr;
            cout << std::hex << std::dec << this << " move" << endl;
		}
		foo& operator=(foo other)
		{
            cout << std::hex << std::dec << this << " assign" << endl;
            swap(*this, other);
			return *this;
		}
		~foo()
		{
            cout << std::hex << std::dec << this << " destruct" << endl;
			delete p;
		}
		friend void swap(foo& first, foo& second)
		{
			using std::swap;
			swap(first.p, second.p);
		}
	private:
		resource* p;
};

int main()
{
    cout << "foo f1;" << endl;
    foo f1;
    cout << "foo f2{};" << endl;
    foo f2{};
    cout << "foo f3(f2);" << endl;
    foo f3(f2);

    cout << "f2 = f1;" << endl;
    f2 = f1;

    cout << "foo *fooObj1 = new foo();" << endl;
    foo *fooObj1 = new foo();
    delete fooObj1;
    cout << "foo *fooObj2 = new foo(f1);" << endl;
    foo *fooObj2 = new foo(f1);
    delete fooObj2;

//	vector<foo> v;
//    v.push_back(foo());
    return 0;
}