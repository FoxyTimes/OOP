#include <iostream>
#include <math.h>
#include "BitArray.h"

using namespace std;


BitArray::BitArray() {
    size=0;
}

BitArray::~BitArray() = default;

BitArray::BitArray(int num_bits, unsigned long value) {
    size = num_bits;
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8));
    massive.resize(count_of_blocks);
    if (size!=0) {
        massive[0]=value;
    }
}

BitArray::BitArray(const BitArray& b){
    *this = b;
}

void BitArray::resize(int num_bits, bool value){ //доделать
    int last_size = size;
    int count_of_blocks_last = ceil((float) size / (sizeof(int) * 8));
    size = num_bits;
    int count_of_blocks_new = ceil((float) size / (sizeof(int) * 8));
    massive.resize(count_of_blocks_new);
    if (num_bits>last_size) {
        unsigned int mask=0;
        if (value) {
            mask=0xFFFFFFFF;
        }
        //ставлю блоки
        for (int i=count_of_blocks_last; i!=count_of_blocks_new; i++) {
            massive[i] = mask;
        }
        //ставлю оставшиеся биты
        for (int i=last_size; i%(sizeof(int)*8)!=0; i++) {
            set(i, value);
        }
    }
}

void BitArray::clear() {
    for (int i=0; i!=(int)ceil((float) size / (sizeof(int) * 8)); i++) {
        massive[i] = 0;
    }
}

void BitArray::swap(BitArray& b) {
    BitArray temp_array(b);
    b = (*this);
    (*this) = temp_array;
}


BitArray& BitArray::operator=(const BitArray& b) = default;

BitArray& BitArray::operator&=(const BitArray& b) {
    if(size != b.size) {
        throw invalid_argument("The sizes of the bit arrays do not match");
    }
    for (int i=0; i!=(int)ceil((float) size / (sizeof(int) * 8)); i++) {
        massive[i] &= b.massive[i];
    }
    return (*this);
}

BitArray& BitArray::operator|=(const BitArray& b) {
    if(size != b.size) {
        throw invalid_argument("The sizes of the bit arrays do not match");
    }
    for (int i=0; i!=(int)ceil((float) size / (sizeof(int) * 8)); i++) {
        massive[i] |= b.massive[i];
    }
    return (*this);
}

BitArray& BitArray::operator^=(const BitArray& b) {
    if(size != b.size) {
        throw invalid_argument("The sizes of the bit arrays do not match");
    }
    for (int i=0; i!=(int)ceil((float) size / (sizeof(int) * 8)); i++) {
        massive[i] ^= b.massive[i];
    }
    return (*this);
}

BitArray& BitArray::operator<<=(int n) {
    // проверка на чрезмерный сдвиг
    if (n>=size) {
        clear();
        return (*this);
    }

    // сдвиг блоков
    int blocks_shift = n/32;
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8));
    for (int i=0; i!=(count_of_blocks-blocks_shift); i++) {
        massive[i] = massive[i+blocks_shift];
    }

    //зануление крайних блоков
    for (int i=(count_of_blocks-blocks_shift); i!=count_of_blocks; i++) {
        massive[i] = 0;
    }

    //проверка на завершение сдвига
    if (n%32==0) {
        return (*this);
    }

    //сдвиг оставшихся битов
    unsigned int our_mask;
    unsigned int bits;
    massive[0]<<=(n%32);
    for (int i=0; i!=count_of_blocks-1; i++) {
        our_mask=0|(~((1<<(32-(n%32)))-1));
        bits = (massive[i+1]&our_mask)>>(32-(n%32));
        massive[i] |= bits;
        massive[i+1]<<=(n%32);
    }
    return (*this);
}

BitArray& BitArray::operator>>=(int n) {
    // проверка на чрезмерный сдвиг
    if (n>=size) {
        clear();
        return (*this);
    }

    // сдвиг блоков
    int four_bytes_shift = n/32;
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8));
    for (int i=(count_of_blocks-1); i!=four_bytes_shift-1; i--) {
        massive[i] = massive[i-four_bytes_shift];
    }

    //зануление крайних блоков
    for (int i=(four_bytes_shift-1); i!=-1; i--) {
        massive[i] = 0;
    }

    //проверка на завершение сдвига
    if (n%32==0) {
        return (*this);
    }

    //сдвиг оставшихся битов
    unsigned int our_mask;
    unsigned int bits;
    massive[count_of_blocks-1]>>=(n%32);
    for (int i=(count_of_blocks-1); i!=0; i--) {
        our_mask=0|((1<<(n%32))-1);
        bits = (massive[i-1]&our_mask)<<(32-(n%32));
        massive[i] |= bits;
        massive[i-1]>>=(n%32);
    }
    return (*this);
}

BitArray BitArray::operator<<(int n) const {
    BitArray temp(*this);
    temp <<= n;
    return temp;
}

BitArray BitArray::operator>>(int n) const {
    BitArray temp(*this);
    temp >>= n;
    return temp;
}

BitArray& BitArray::set(int n, bool val) {
    int block = n/(sizeof(int)*8), pos_in_block = ((sizeof(int)*8-1)-n)%(sizeof(int)*8);
    if (val) {
        massive[block] = massive[block] | (1 << pos_in_block);
    }
    else {
        massive[block] = massive[block]&(~(1 << pos_in_block));
    }
    return (*this);
}

BitArray& BitArray::set() {
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8));
    unsigned int mask=0xFFFFFFFF;
    for (int i=0; i!=count_of_blocks; i++) {
        massive[i] = mask;
    }
    return (*this);
}

BitArray& BitArray::reset(int n) {
    set(n, false);
    return (*this);
}

BitArray& BitArray::reset() {
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8));
    int mask=0;
    for (int i=0; i!=count_of_blocks; i++) {
        massive[i] = mask;
    }
    return (*this);
}

bool BitArray::any() const {
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8));
    for (int i=0; i!=count_of_blocks; i++) {
        if (massive[i]!=0) {
            return true;
        }
    }
    return false;
}

bool BitArray::none() const {
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8));
    for (int i=0; i!=count_of_blocks; i++) {
        if (massive[i]!=0) {
            return false;
        }
    }
    return true;
}

BitArray BitArray::operator~() const {
    BitArray temp_array((*this));
    int count_of_blocks = ceil((float) temp_array.size / (sizeof(int) * 8));
    for (int i=0; i!=count_of_blocks; i++) {
        temp_array.massive[i] = ~temp_array.massive[i];
    }
    return temp_array;
}

int BitArray::count() const {
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8)), count_bits = 0, temp;
    int limit = size;
    for (int i=0; i!=count_of_blocks; i++) {
        temp = massive[i];
        for (int v=0; v!=(sizeof(int)*8); v++) {
            if (limit==0) {
                return count_bits;
            }
            if ((temp & (1<<31))!=0) {
                count_bits++;
            }
            temp <<= 1;
            limit--;
        }
    }
    return count_bits;
}


bool BitArray::operator[](int i) const {
    if (i>=size) {
        throw std::out_of_range("Out of range");
    }
    int block = i/(sizeof(int)*8), pos_in_block = ((sizeof(int)*8-1)-i)%(sizeof(int)*8);
    if ((massive[block] & (1 << pos_in_block))==0) {
        return false;
    }
    else {
        return true;
    }
}


int BitArray::size_array() const {
    return size;
}

bool BitArray::empty() const {
    if (size==0) {
        return true;
    }
    return false;
}

string BitArray::to_string() const {
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8)), temp;
    string string_with_bits;
    int limit = size;
    for (int i=0; i!=count_of_blocks; i++) {
        temp = massive[i];
        for (int v=0; v!=32; v++) {
            if (limit==0) {
                return string_with_bits;
            }
            if ((temp & (1<<31))!=0) {
                string_with_bits += '1';
            }
            else {
                string_with_bits += '0';
            }
            limit--;
            temp <<= 1;
        }
    }
    return string_with_bits;     }


void BitArray::push_back(bool bit) {
    size += 1;
    int count_of_blocks = ceil((float) size / (sizeof(int) * 8));
    massive.resize(count_of_blocks);
    set(size-1, bit);
}

bool operator==(const BitArray &a, const BitArray &b) {
    if(a.size_array() != b.size_array()) {
        return false;
    }
    for (int i=0; i!=a.size_array(); i++) {
        if (a[i]!=b[i]) {
            return false;
        }
    }
    return true;
}


bool operator!=(const BitArray &a, const BitArray &b) {
    return !(a==b);
}

BitArray operator&(const BitArray& a, const BitArray& b) {
    BitArray temp(a);
    temp &= b;
    return temp;
}

BitArray operator|(const BitArray& a, const BitArray& b) {
    BitArray temp(a);
    temp |= b;
    return temp;
}

BitArray operator^(const BitArray& a, const BitArray& b) {
    BitArray temp(a);
    temp ^= b;
    return temp;
}
