#include <napi.h>
#include <iostream>

template<typename T>
class Test1
{
public:
    Test1()
    {
		std::cout << "Test1 {ctor}" << std::endl;
        i = 14;
    }

    int hello()
    {
		std::cout << "Test1 hello() = " << i << std::endl;
		return i;
    }

private:
    T i;
};

template <typename T>
class Test2
{
public:
    static Test1<T> test1;
};

template <typename T>
Test1<T> Test2<T>::test1;

Napi::Value fnHello(const Napi::CallbackInfo& info) {
	return Napi::Number::New(info.Env(), Test2<int>::test1.hello());
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
	exports.Set(Napi::String::New(env, "hello"),
                Napi::Function::New<fnHello>(env));
    return exports;
}
NODE_API_MODULE(staticsrepro, Init)
