#include "parameters.h"

#include <stdio.h>

#include <stdlib.h>

struct combo_t;

typedef struct combo_t * Combo;

Combo createParameterCombo();

void addParameterDefCombo(Combo combo, ParameterDef def);

size_t addParameterCombo(Combo combo, Parameter param);

size_t nParamsCombo(Combo combo);

bool hasNextCombo(Combo combo);

Parameter * nextCombo(Combo combo);

void freeParamsCombo(Combo combo, Parameter * params);

void freeCombo(Combo combo);

