#ifndef PHPSCI_EXT_SCALAR_H
#define PHPSCI_EXT_SCALAR_H

#include "carray.h"

/**
 * SCALARS STRUCTURES
 */ 
typedef struct {
        int obval;
} CArrayIntegerScalarObject;

typedef struct {
        float obval;
} CArrayFloatScalarObject;

typedef struct {
        double obval;
} CArrayDoubleScalarObject;

typedef struct {
        double obval;
} CArrayLongScalarObject;

typedef struct CArrayScalar {
    void * obval;
    int  type;
} CArrayScalar;

CArrayDescriptor * CArray_DescrFromScalar(CArrayScalar *sc);
CArrayScalar * CArrayScalar_FromZval(PHPObject * obj, int is_double, int is_long);
void CArrayScalar_FREE(CArrayScalar * sc);
CArrayScalar * CArrayScalar_NewInt(int sc);
CArrayScalar * CArrayScalar_NewDouble(double sc);
CArrayScalar * CArrayScalar_NewFloat(float sc);
CArrayScalar * CArrayScalar_NewLong(long sc);

#endif //PHPSCI_EXT_SCALAR_H