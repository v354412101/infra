#pragma once

#include <queue>
#include <mutex>

#include "glog/logging.h"

namespace Infra {
    template<class T>
    class DoubleQueue {
    public:
        explicit DoubleQueue(unsigned int max_capacity)
            : max_capacity_(max_capacity) {}

        void push(T& e) {
            std::lock_guard<std::mutex> lock(swap_mutex_);
            if (write_queue_.size() > max_capacity_) {
                LOG(ERROR) << "write_queue_ overflow!";
                return ;
            }
            write_queue_.emplace(e);
        }

        T pop() {
            if (read_queue_.empty()) {
                std::lock_guard<std::mutex> lock(swap_mutex_);
                if (write_queue_.empty()) {
                    LOG(ERROR) << "DoubleQueue is null!";
                    return nullptr;
                }
                read_queue_.swap(write_queue_);
            }
            auto e = read_queue_.front();
            read_queue_.pop();
            return e;
        }

    private:
        unsigned int max_capacity_;
        std::queue<T>  write_queue_;
        std::queue<T>  read_queue_;
        std::mutex swap_mutex_;
    };
}
