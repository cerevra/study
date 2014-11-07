#ifndef COUNTNOTNULLS_H
#define COUNTNOTNULLS_H

short countNotNulls(int value){
    int count = 0;
    while(value){
        if (value & 0x01)
            ++count;
        value = value >> 1;
    }
    return count;
}

#endif // COUNTNOTNULLS_H
