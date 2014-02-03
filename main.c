#include <stdint.h>

#define MB_CONTROL_PAGE_ADDRESS 0x00708000
#include "mb/sw/control.h"

#include "lcd.h"
#include "examples/ui.h"

#define UNUSED(x) (void)(x)
 
static void* mem = (void*) 0x20000000;
	
void *vista_malloc(int size)
{
	void *ret = mem;
	mem += size;
	void foo
	return ret;
}

// kernel main function, it all begins here
void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags) {
    UNUSED(r0);
    UNUSED(r1);
    UNUSED(atags);
    

    // example of semi hosting print message
#ifdef GPU
    mb_core_message("*** ARM A9 OpenGL Platform - GPU ENABLED ***");
#else
    mb_core_message("*** ARM A9 OpenGL Platform ***");
#endif

#ifndef TEST
    init_lcd();
  
    ui_loop();
#else
    // emit beginning of testing message
    mb_core_message("---begin testing---");
    #include "examples/gearsdrawmath.h"

    // test setup
    GLfloat actual_output[10], return_value;
    #define FAIL 0
    #define PASS 1
    int test_result = FAIL;

    // ------------------------------------------------------------------------
    // test 1 setup
    GLfloat input1[10] = {0.0, 1.0, 2.0, 3.0, 4.5, 5.9, -1.1, -2.3, -3.0, -4.4};
    GLfloat expected_output1[10] = {0.0, 1.0, 2.0, 3.0, 4.5, 5.9, -1.1, -2.3, -3.0, -4.4};
    test_result = FAIL;
    
    // run tests
    for (int i = 0; i < 10; i++) {
      return_value = gearsDrawMathIdentity(input1[i]);
      actual_output[i] = return_value;
    }

    // compare values
    for (int i = 0; i < 10; i++) {
      if (expected_output1[i] == actual_output[i]) {
	test_result = PASS;
      }
      else {
	test_result = FAIL;
	break;
      }
    }
    
    // emit result
    if (test_result == FAIL)
      mb_core_message("test_gearsDrawMathIdentity ... FAILED");
    if (test_result == PASS)
      mb_core_message("test_gearsDrawMathIdentity ... ok");

    // ------------------------------------------------------------------------
    // test 2 setup
    GLfloat input2[10] = {0.0, 1.0, 2.0, 3.0, 4.5, 5.9, -1.1, -2.3, -3.0, -4.4};
    GLfloat expected_output2[10] = {-9, -11, -13, -15, -18, -20.7999992, -6.80000019, -4.4000001, -3, -0.199999809};
    // initialize test result
    test_result = FAIL ;
    
    // run tests
    for (int i = 0; i < 10; i++) {
      return_value = gearsDrawMathNine(input2[i]);
      actual_output[i] = return_value;
    }

    // compare values
    for (int i = 0; i < 10; i++) {
      if (expected_output2[i] == actual_output[i]) {
	test_result = PASS;
      }
      else {
	test_result = FAIL;
	break;
      }
    }
    
    // emit result
    if (test_result == FAIL)
      mb_core_message("test_gearsDrawMathNine ... FAILED");
    if (test_result == PASS)
      mb_core_message("test_gearsDrawMathNine ... ok");

    // ------------------------------------------------------------------------
    // test 3 setup
    GLfloat input3[10] = {0.0, 1.0, 2.0, 3.0, 4.5, 5.9, -1.1, -2.3, -3.0, -4.4};
    GLfloat expected_output3[10] = {-25, -27, -29, -31, -34, -36.7999992, -22.7999992, -20.3999996, -19, -16.2000008};

    // initialize test result
    test_result = FAIL ;
    
    // run tests
    for (int i = 0; i < 10; i++) {
      return_value = gearsDrawMathTwentyFive(input3[i]);
      actual_output[i] = return_value;
    }

    // compare values
    for (int i = 0; i < 10; i++) {
      if (expected_output3[i] == actual_output[i]) {
	test_result = PASS;
      }
      else {
	test_result = FAIL;
	break;
      }
    }
    
    // emit result
    if (test_result == FAIL)
      mb_core_message("test_gearsDrawMathTwentyFive ... FAILED");
    if (test_result == PASS)
      mb_core_message("test_gearsDrawMathTwentyFive ... ok");
    // ------------------------------------------------------------------------
    

    // emit end of testing message
    mb_core_message("---end testing---");    

    // halt the vp after emitting message.
    mb_core_message("---halting vp---");
    mb_stop(0);
#endif
}

