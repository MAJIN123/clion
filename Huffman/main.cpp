#include <iostream>
#include "Huffman.h"
int main() {
    float a[]={2,6,3,1,7};
  //  Huffman hh;
    cout<<a[3];
    Huffman hh(a,5);
    hh.PreOrder();
    return 1;
}