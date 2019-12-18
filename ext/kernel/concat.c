
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <php.h>
#include "php_ext.h"
#include <ext/standard/php_string.h>
#include "ext.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"

void zephir_concat_ss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	size_t offset = 0, length;

	length = op1_len + op2_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	size_t offset = 0, length;

	length = op1_len + op2_len + op3_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_ssssss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	size_t offset = 0, length;

	length = op1_len + op2_len + op3_len + op4_len + op5_len + op6_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len, op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len, op6, op6_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sssvss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, int self_var){

	zval result_copy, op4_copy;
	int use_copy = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + op6_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len, op6, op6_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sssvsvssvsvss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, const char *op8, uint32_t op8_len, zval *op9, const char *op10, uint32_t op10_len, zval *op11, const char *op12, uint32_t op12_len, const char *op13, uint32_t op13_len, int self_var){

	zval result_copy, op4_copy, op6_copy, op9_copy, op11_copy;
	int use_copy = 0, use_copy4 = 0, use_copy6 = 0, use_copy9 = 0, use_copy11 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	if (Z_TYPE_P(op9) != IS_STRING) {
	   use_copy9 = zend_make_printable_zval(op9, &op9_copy);
	   if (use_copy9) {
	       op9 = &op9_copy;
	   }
	}

	if (Z_TYPE_P(op11) != IS_STRING) {
	   use_copy11 = zend_make_printable_zval(op11, &op11_copy);
	   if (use_copy11) {
	       op11 = &op11_copy;
	   }
	}

	length = op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + Z_STRLEN_P(op11) + op12_len + op13_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6), op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len, op8, op8_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len, Z_STRVAL_P(op9), Z_STRLEN_P(op9));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9), op10, op10_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len, Z_STRVAL_P(op11), Z_STRLEN_P(op11));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + Z_STRLEN_P(op11), op12, op12_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + Z_STRLEN_P(op11) + op12_len, op13, op13_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy9) {
	   zval_dtor(op9);
	}

	if (use_copy11) {
	   zval_dtor(op11);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sssvsvsvsvsvs(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, zval *op10, const char *op11, uint32_t op11_len, zval *op12, const char *op13, uint32_t op13_len, int self_var){

	zval result_copy, op4_copy, op6_copy, op8_copy, op10_copy, op12_copy;
	int use_copy = 0, use_copy4 = 0, use_copy6 = 0, use_copy8 = 0, use_copy10 = 0, use_copy12 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	if (Z_TYPE_P(op8) != IS_STRING) {
	   use_copy8 = zend_make_printable_zval(op8, &op8_copy);
	   if (use_copy8) {
	       op8 = &op8_copy;
	   }
	}

	if (Z_TYPE_P(op10) != IS_STRING) {
	   use_copy10 = zend_make_printable_zval(op10, &op10_copy);
	   if (use_copy10) {
	       op10 = &op10_copy;
	   }
	}

	if (Z_TYPE_P(op12) != IS_STRING) {
	   use_copy12 = zend_make_printable_zval(op12, &op12_copy);
	   if (use_copy12) {
	       op12 = &op12_copy;
	   }
	}

	length = op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len + Z_STRLEN_P(op10) + op11_len + Z_STRLEN_P(op12) + op13_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6), op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len, Z_STRVAL_P(op8), Z_STRLEN_P(op8));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8), op9, op9_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len, Z_STRVAL_P(op10), Z_STRLEN_P(op10));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len + Z_STRLEN_P(op10), op11, op11_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len + Z_STRLEN_P(op10) + op11_len, Z_STRVAL_P(op12), Z_STRLEN_P(op12));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len + Z_STRLEN_P(op10) + op11_len + Z_STRLEN_P(op12), op13, op13_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy8) {
	   zval_dtor(op8);
	}

	if (use_copy10) {
	   zval_dtor(op10);
	}

	if (use_copy12) {
	   zval_dtor(op12);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_ssvsvsvs(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, int self_var){

	zval result_copy, op3_copy, op5_copy, op7_copy;
	int use_copy = 0, use_copy3 = 0, use_copy5 = 0, use_copy7 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = op1_len + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7) + op8_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7), op8, op8_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sv(zval *result, const char *op1, uint32_t op1_len, zval *op2, int self_var){

	zval result_copy, op2_copy;
	int use_copy = 0, use_copy2 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, int self_var){

	zval result_copy, op2_copy;
	int use_copy = 0, use_copy2 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svssvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, int self_var){

	zval result_copy, op2_copy, op5_copy;
	int use_copy = 0, use_copy2 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svssvssvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, int self_var){

	zval result_copy, op2_copy, op5_copy, op8_copy;
	int use_copy = 0, use_copy2 = 0, use_copy5 = 0, use_copy8 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op8) != IS_STRING) {
	   use_copy8 = zend_make_printable_zval(op8, &op8_copy);
	   if (use_copy8) {
	       op8 = &op8_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8) + op9_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len, op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len, Z_STRVAL_P(op8), Z_STRLEN_P(op8));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8), op9, op9_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy8) {
	   zval_dtor(op8);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svssvssvssvssvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, const char *op10, uint32_t op10_len, zval *op11, const char *op12, uint32_t op12_len, const char *op13, uint32_t op13_len, zval *op14, const char *op15, uint32_t op15_len, int self_var){

	zval result_copy, op2_copy, op5_copy, op8_copy, op11_copy, op14_copy;
	int use_copy = 0, use_copy2 = 0, use_copy5 = 0, use_copy8 = 0, use_copy11 = 0, use_copy14 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op8) != IS_STRING) {
	   use_copy8 = zend_make_printable_zval(op8, &op8_copy);
	   if (use_copy8) {
	       op8 = &op8_copy;
	   }
	}

	if (Z_TYPE_P(op11) != IS_STRING) {
	   use_copy11 = zend_make_printable_zval(op11, &op11_copy);
	   if (use_copy11) {
	       op11 = &op11_copy;
	   }
	}

	if (Z_TYPE_P(op14) != IS_STRING) {
	   use_copy14 = zend_make_printable_zval(op14, &op14_copy);
	   if (use_copy14) {
	       op14 = &op14_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8) + op9_len + op10_len + Z_STRLEN_P(op11) + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len, op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len, Z_STRVAL_P(op8), Z_STRLEN_P(op8));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8), op9, op9_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8) + op9_len, op10, op10_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8) + op9_len + op10_len, Z_STRVAL_P(op11), Z_STRLEN_P(op11));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8) + op9_len + op10_len + Z_STRLEN_P(op11), op12, op12_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8) + op9_len + op10_len + Z_STRLEN_P(op11) + op12_len, op13, op13_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8) + op9_len + op10_len + Z_STRLEN_P(op11) + op12_len + op13_len, Z_STRVAL_P(op14), Z_STRLEN_P(op14));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + op7_len + Z_STRLEN_P(op8) + op9_len + op10_len + Z_STRLEN_P(op11) + op12_len + op13_len + Z_STRLEN_P(op14), op15, op15_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy8) {
	   zval_dtor(op8);
	}

	if (use_copy11) {
	   zval_dtor(op11);
	}

	if (use_copy14) {
	   zval_dtor(op14);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svssvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, int self_var){

	zval result_copy, op2_copy, op5_copy, op7_copy;
	int use_copy = 0, use_copy2 = 0, use_copy5 = 0, use_copy7 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7) + op8_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7), op8, op8_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, int self_var){

	zval result_copy, op2_copy, op4_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, int self_var){

	zval result_copy, op2_copy, op4_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvssvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, zval *op9, const char *op10, uint32_t op10_len, int self_var){

	zval result_copy, op2_copy, op4_copy, op7_copy, op9_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy7 = 0, use_copy9 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	if (Z_TYPE_P(op9) != IS_STRING) {
	   use_copy9 = zend_make_printable_zval(op9, &op9_copy);
	   if (use_copy9) {
	       op9 = &op9_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + op6_len + Z_STRLEN_P(op7) + op8_len + Z_STRLEN_P(op9) + op10_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len, op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + op6_len + Z_STRLEN_P(op7), op8, op8_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + op6_len + Z_STRLEN_P(op7) + op8_len, Z_STRVAL_P(op9), Z_STRLEN_P(op9));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + op6_len + Z_STRLEN_P(op7) + op8_len + Z_STRLEN_P(op9), op10, op10_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy9) {
	   zval_dtor(op9);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, int self_var){

	zval result_copy, op2_copy, op4_copy, op6_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy6 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, int self_var){

	zval result_copy, op2_copy, op4_copy, op6_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy6 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6), op7, op7_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvsvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, int self_var){

	zval result_copy, op2_copy, op4_copy, op6_copy, op8_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy6 = 0, use_copy8 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	if (Z_TYPE_P(op8) != IS_STRING) {
	   use_copy8 = zend_make_printable_zval(op8, &op8_copy);
	   if (use_copy8) {
	       op8 = &op8_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6), op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len, Z_STRVAL_P(op8), Z_STRLEN_P(op8));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8), op9, op9_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy8) {
	   zval_dtor(op8);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, int self_var){

	zval result_copy, op2_copy, op4_copy, op5_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvvsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, const char *op6, uint32_t op6_len, zval *op7, int self_var){

	zval result_copy, op2_copy, op4_copy, op5_copy, op7_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy5 = 0, use_copy7 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, int self_var){

	zval result_copy, op2_copy, op4_copy, op5_copy, op7_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy5 = 0, use_copy7 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7) + op8_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7), op8, op8_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svv(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, int self_var){

	zval result_copy, op2_copy, op3_copy;
	int use_copy = 0, use_copy2 = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + Z_STRLEN_P(op3);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, const char *op4, uint32_t op4_len, int self_var){

	zval result_copy, op2_copy, op3_copy;
	int use_copy = 0, use_copy2 = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + op4_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + Z_STRLEN_P(op3), op4, op4_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vs(zval *result, zval *op1, const char *op2, uint32_t op2_len, int self_var){

	zval result_copy, op1_copy;
	int use_copy = 0, use_copy1 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, int self_var){

	zval result_copy, op1_copy, op3_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, int self_var){

	zval result_copy, op1_copy, op3_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy, op7_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0, use_copy7 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, zval *op6, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy, op6_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0, use_copy6 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + Z_STRLEN_P(op6);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, zval *op4, int self_var){

	zval result_copy, op1_copy, op3_copy, op4_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + Z_STRLEN_P(op4);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var){

	zval result_copy, op1_copy, op2_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvs(zval *result, zval *op1, zval *op2, const char *op3, uint32_t op3_len, int self_var){

	zval result_copy, op1_copy, op2_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + op3_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), op3, op3_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvsv(zval *result, zval *op1, zval *op2, const char *op3, uint32_t op3_len, zval *op4, int self_var){

	zval result_copy, op1_copy, op2_copy, op4_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvsvs(zval *result, zval *op1, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, int self_var){

	zval result_copy, op1_copy, op2_copy, op4_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvv(zval *result, zval *op1, zval *op2, zval *op3, int self_var){

	zval result_copy, op1_copy, op2_copy, op3_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, int self_var){

	zval result_copy, op1_copy, op2_copy, op3_copy, op4_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0, use_copy3 = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvvvsvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, const char *op5, uint32_t op5_len, zval *op6, zval *op7, int self_var){

	zval result_copy, op1_copy, op2_copy, op3_copy, op4_copy, op6_copy, op7_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0, use_copy3 = 0, use_copy4 = 0, use_copy6 = 0, use_copy7 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + Z_STRLEN_P(op7);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6), Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, zval *op5, int self_var){

	zval result_copy, op1_copy, op2_copy, op3_copy, op4_copy, op5_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0, use_copy3 = 0, use_copy4 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + Z_STRLEN_P(op5);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4), Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_function(zval *result, zval *op1, zval *op2)
{
	zval tmp;
	SEPARATE_ZVAL_IF_NOT_REF(result);

	/*
		res == op1 == op2: won't leak
		res == op1 != op2: won't leak
		res == op2 != op1: will leak
	 */
	if (result == op2 && result != op1) {
		ZVAL_COPY_VALUE(&tmp, result);
		ZVAL_NULL(result);
		op2 = &tmp;
	}
	else {
		ZVAL_UNDEF(&tmp);
	}

	concat_function(result, op1, op2);
	assert(!Z_REFCOUNTED(tmp) || 1 == Z_REFCOUNT(tmp));
	zval_dtor(&tmp);
}