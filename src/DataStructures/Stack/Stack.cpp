#include "Stack.h"

namespace s21 {

Stack::Stack() : AbstractList() { head_ = nullptr; }

Stack* Stack::init() { return new Stack(); }

void Stack::push(const int value) {
    if (head_ == nullptr) {
        head_ = create(value, nullptr);
    } else {
        head_ = create(value, head_);
    }
}

int Stack::pop() {
    if (head_ == nullptr) {
        throw("Pop from empty stack");
    }
    int ret = head_->value;
    node* tmp = head_;
    head_ = head_->next;
    delete tmp;
    return ret;
}

int Stack::peek() const {
    if (head_ == nullptr) {
        throw("Peek from empty stack");
    }
    return head_->value;
}

bool Stack::empty() const { return head_ == nullptr; }

}  // namespace s21