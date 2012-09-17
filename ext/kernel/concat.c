
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "ext/standard/php_string.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"

void phalcon_concat_sv(zval *result, char *op1, zend_uint op1_len, zval *op2 TSRMLS_DC){

	zval op2_copy;
	int use_copy2 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	Z_STRLEN_P(result) = op1_len + Z_STRLEN_P(op2);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_len);
	memcpy(Z_STRVAL_P(result)+op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

}

void phalcon_concat_svs(zval *result, char *op1, zend_uint op1_len, zval *op2, char *op3, zend_uint op3_len TSRMLS_DC){

	zval op2_copy;
	int use_copy2 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	Z_STRLEN_P(result) = op1_len + Z_STRLEN_P(op2) + op3_len;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_len);
	memcpy(Z_STRVAL_P(result)+op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2), op3, op3_len);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

}

void phalcon_concat_svsv(zval *result, char *op1, zend_uint op1_len, zval *op2, char *op3, zend_uint op3_len, zval *op4 TSRMLS_DC){

	zval op2_copy, op4_copy;
	int use_copy2 = 0, use_copy4 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
		zend_make_printable_zval(op4, &op4_copy, &use_copy4);
		if (use_copy4) {
			op4 = &op4_copy;
		}
	}

	Z_STRLEN_P(result) = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_len);
	memcpy(Z_STRVAL_P(result)+op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	if (use_copy4) {
		zval_dtor(op4);
	}

}

void phalcon_concat_svsvs(zval *result, char *op1, zend_uint op1_len, zval *op2, char *op3, zend_uint op3_len, zval *op4, char *op5, zend_uint op5_len TSRMLS_DC){

	zval op2_copy, op4_copy;
	int use_copy2 = 0, use_copy4 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
		zend_make_printable_zval(op4, &op4_copy, &use_copy4);
		if (use_copy4) {
			op4 = &op4_copy;
		}
	}

	Z_STRLEN_P(result) = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_len);
	memcpy(Z_STRVAL_P(result)+op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len+Z_STRLEN_P(op4), op5, op5_len);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	if (use_copy4) {
		zval_dtor(op4);
	}

}

void phalcon_concat_svsvsv(zval *result, char *op1, zend_uint op1_len, zval *op2, char *op3, zend_uint op3_len, zval *op4, char *op5, zend_uint op5_len, zval *op6 TSRMLS_DC){

	zval op2_copy, op4_copy, op6_copy;
	int use_copy2 = 0, use_copy4 = 0, use_copy6 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
		zend_make_printable_zval(op4, &op4_copy, &use_copy4);
		if (use_copy4) {
			op4 = &op4_copy;
		}
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
		zend_make_printable_zval(op6, &op6_copy, &use_copy6);
		if (use_copy6) {
			op6 = &op6_copy;
		}
	}

	Z_STRLEN_P(result) = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_len);
	memcpy(Z_STRVAL_P(result)+op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len+Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len+Z_STRLEN_P(op4)+op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	if (use_copy4) {
		zval_dtor(op4);
	}

	if (use_copy6) {
		zval_dtor(op6);
	}

}

void phalcon_concat_svsvsvs(zval *result, char *op1, zend_uint op1_len, zval *op2, char *op3, zend_uint op3_len, zval *op4, char *op5, zend_uint op5_len, zval *op6, char *op7, zend_uint op7_len TSRMLS_DC){

	zval op2_copy, op4_copy, op6_copy;
	int use_copy2 = 0, use_copy4 = 0, use_copy6 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
		zend_make_printable_zval(op4, &op4_copy, &use_copy4);
		if (use_copy4) {
			op4 = &op4_copy;
		}
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
		zend_make_printable_zval(op6, &op6_copy, &use_copy6);
		if (use_copy6) {
			op6 = &op6_copy;
		}
	}

	Z_STRLEN_P(result) = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_len);
	memcpy(Z_STRVAL_P(result)+op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len+Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len+Z_STRLEN_P(op4)+op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len+Z_STRLEN_P(op4)+op5_len+Z_STRLEN_P(op6), op7, op7_len);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	if (use_copy4) {
		zval_dtor(op4);
	}

	if (use_copy6) {
		zval_dtor(op6);
	}

}

void phalcon_concat_svsvv(zval *result, char *op1, zend_uint op1_len, zval *op2, char *op3, zend_uint op3_len, zval *op4, zval *op5 TSRMLS_DC){

	zval op2_copy, op4_copy, op5_copy;
	int use_copy2 = 0, use_copy4 = 0, use_copy5 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
		zend_make_printable_zval(op4, &op4_copy, &use_copy4);
		if (use_copy4) {
			op4 = &op4_copy;
		}
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
		zend_make_printable_zval(op5, &op5_copy, &use_copy5);
		if (use_copy5) {
			op5 = &op5_copy;
		}
	}

	Z_STRLEN_P(result) = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_len);
	memcpy(Z_STRVAL_P(result)+op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2)+op3_len+Z_STRLEN_P(op4), Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	if (use_copy4) {
		zval_dtor(op4);
	}

	if (use_copy5) {
		zval_dtor(op5);
	}

}

void phalcon_concat_svv(zval *result, char *op1, zend_uint op1_len, zval *op2, zval *op3 TSRMLS_DC){

	zval op2_copy, op3_copy;
	int use_copy2 = 0, use_copy3 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
		if (use_copy3) {
			op3 = &op3_copy;
		}
	}

	Z_STRLEN_P(result) = op1_len + Z_STRLEN_P(op2) + Z_STRLEN_P(op3);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_len);
	memcpy(Z_STRVAL_P(result)+op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_len+Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	if (use_copy3) {
		zval_dtor(op3);
	}

}

void phalcon_concat_vs(zval *result, zval *op1, char *op2, zend_uint op2_len TSRMLS_DC){

	zval op1_copy;
	int use_copy1 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_len;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_len);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

}

void phalcon_concat_vsv(zval *result, zval *op1, char *op2, zend_uint op2_len, zval *op3 TSRMLS_DC){

	zval op1_copy, op3_copy;
	int use_copy1 = 0, use_copy3 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
		if (use_copy3) {
			op3 = &op3_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	if (use_copy3) {
		zval_dtor(op3);
	}

}

void phalcon_concat_vsvs(zval *result, zval *op1, char *op2, zend_uint op2_len, zval *op3, char *op4, zend_uint op4_len TSRMLS_DC){

	zval op1_copy, op3_copy;
	int use_copy1 = 0, use_copy3 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
		if (use_copy3) {
			op3 = &op3_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len+Z_STRLEN_P(op3), op4, op4_len);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	if (use_copy3) {
		zval_dtor(op3);
	}

}

void phalcon_concat_vsvsvs(zval *result, zval *op1, char *op2, zend_uint op2_len, zval *op3, char *op4, zend_uint op4_len, zval *op5, char *op6, zend_uint op6_len TSRMLS_DC){

	zval op1_copy, op3_copy, op5_copy;
	int use_copy1 = 0, use_copy3 = 0, use_copy5 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
		if (use_copy3) {
			op3 = &op3_copy;
		}
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
		zend_make_printable_zval(op5, &op5_copy, &use_copy5);
		if (use_copy5) {
			op5 = &op5_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len+Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len+Z_STRLEN_P(op3)+op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len+Z_STRLEN_P(op3)+op4_len+Z_STRLEN_P(op5), op6, op6_len);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	if (use_copy3) {
		zval_dtor(op3);
	}

	if (use_copy5) {
		zval_dtor(op5);
	}

}

void phalcon_concat_vsvsvsv(zval *result, zval *op1, char *op2, zend_uint op2_len, zval *op3, char *op4, zend_uint op4_len, zval *op5, char *op6, zend_uint op6_len, zval *op7 TSRMLS_DC){

	zval op1_copy, op3_copy, op5_copy, op7_copy;
	int use_copy1 = 0, use_copy3 = 0, use_copy5 = 0, use_copy7 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
		if (use_copy3) {
			op3 = &op3_copy;
		}
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
		zend_make_printable_zval(op5, &op5_copy, &use_copy5);
		if (use_copy5) {
			op5 = &op5_copy;
		}
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
		zend_make_printable_zval(op7, &op7_copy, &use_copy7);
		if (use_copy7) {
			op7 = &op7_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len+Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len+Z_STRLEN_P(op3)+op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len+Z_STRLEN_P(op3)+op4_len+Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_len+Z_STRLEN_P(op3)+op4_len+Z_STRLEN_P(op5)+op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

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

}

void phalcon_concat_vv(zval *result, zval *op1, zval *op2 TSRMLS_DC){

	zval op1_copy, op2_copy;
	int use_copy1 = 0, use_copy2 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + Z_STRLEN_P(op2);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	if (use_copy2) {
		zval_dtor(op2);
	}

}

void phalcon_concat_vvsv(zval *result, zval *op1, zval *op2, char *op3, zend_uint op3_len, zval *op4 TSRMLS_DC){

	zval op1_copy, op2_copy, op4_copy;
	int use_copy1 = 0, use_copy2 = 0, use_copy4 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
		zend_make_printable_zval(op4, &op4_copy, &use_copy4);
		if (use_copy4) {
			op4 = &op4_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+Z_STRLEN_P(op2)+op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	if (use_copy2) {
		zval_dtor(op2);
	}

	if (use_copy4) {
		zval_dtor(op4);
	}

}

void phalcon_concat_vvv(zval *result, zval *op1, zval *op2, zval *op3 TSRMLS_DC){

	zval op1_copy, op2_copy, op3_copy;
	int use_copy1 = 0, use_copy2 = 0, use_copy3 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
		if (use_copy3) {
			op3 = &op3_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	if (use_copy2) {
		zval_dtor(op2);
	}

	if (use_copy3) {
		zval_dtor(op3);
	}

}

void phalcon_concat_vvvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, zval *op5 TSRMLS_DC){

	zval op1_copy, op2_copy, op3_copy, op4_copy, op5_copy;
	int use_copy1 = 0, use_copy2 = 0, use_copy3 = 0, use_copy4 = 0, use_copy5 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
		if (use_copy1) {
			op1 = &op1_copy;
		}
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
		if (use_copy2) {
			op2 = &op2_copy;
		}
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
		if (use_copy3) {
			op3 = &op3_copy;
		}
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
		zend_make_printable_zval(op4, &op4_copy, &use_copy4);
		if (use_copy4) {
			op4 = &op4_copy;
		}
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
		zend_make_printable_zval(op5, &op5_copy, &use_copy5);
		if (use_copy5) {
			op5 = &op5_copy;
		}
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + Z_STRLEN_P(op5);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+Z_STRLEN_P(op2)+Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+Z_STRLEN_P(op2)+Z_STRLEN_P(op3)+Z_STRLEN_P(op4), Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

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

}

