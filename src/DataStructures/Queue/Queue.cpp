#include "Queue.h"

namespace s21 {

Queue::Queue() : AbstractList() { head_ = nullptr; }

Queue *Queue::init() { return new Queue(); }

void Queue::push(int value) {
    if (head_ == nullptr) {
        head_ = create(value, nullptr);
    } else {
        node *tmp = head_;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = create(value, nullptr);
    }
}

int Queue::pop() {
    if (head_ == nullptr) {
        throw "Pop from empty queue";
    }
    int ret = head_->value;
    node *tmp = head_;
    head_ = head_->next;
    delete tmp;
    return ret;
}

int Queue::peek() const {
    if (head_ == nullptr) {
        throw "Peek from empty queue";
    }
    return head_->value;
}

bool Queue::empty() const { return head_ == nullptr; }

}  // namespace s21