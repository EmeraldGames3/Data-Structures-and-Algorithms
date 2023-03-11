#pragma once

template<typename type>
void swap(type &a, type &b){
    a ^= b;
    b ^= a;
    a ^= b;
}
