#pragma once

#include <utility>

template <typename T>
class Singleton {
public:
    template<typename... Args>
    static T* Instance(Args&&... args) {
        if (instance_ == nullptr) {
            instance_ = new T(std::forward<Args>(args)...);
        }
        return instance_;
    }

    static void destroyInstance() {
        delete instance_;
        instance_ = nullptr;
    }

private:
    static T* instance_;
};

template <class T> T* Singleton<T>::instance_ = nullptr;
