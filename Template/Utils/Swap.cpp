#pragma once

template<typename type>
void swap(type &a, type &b) {
    type temp = a;
    a = b;
    b = temp;
}