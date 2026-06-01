#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

void unit_Model_constructor(void);
void unit_Model_destructor(void);
void unit_Model_addSystem(void);
void unit_Model_addFlow(void);
void unit_Model_setName(void);
void unit_Model_getName(void);
void unit_Model_run(void);

void run_unit_tests_Model(void);

#endif