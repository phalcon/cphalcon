
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
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Loader
 *
 * This component helps to load your project classes automatically based on some conventions
 *
 *
 */

PHP_METHOD(Phalcon_Loader, __construct){

	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_loader_class_entry, this_ptr, "_namespaces", strlen("_namespaces"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_loader_class_entry, this_ptr, "_directories", strlen("_directories"), a1 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Register namespaces and its related directories
 *
 * @param array $directories
 */
PHP_METHOD(Phalcon_Loader, registerNamespaces){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_namespaces", strlen("_namespaces"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Register directories on which not found classes could be found
 *
 * @param array $directories
 */
PHP_METHOD(Phalcon_Loader, registerDirs){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_directories", strlen("_directories"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Register the autoload method
 */
PHP_METHOD(Phalcon_Loader, register){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	Z_ADDREF_P(this_ptr);
	PHALCON_SEPARATE_ARRAY(a0);
	add_next_index_zval(a0, this_ptr);
	add_next_index_stringl(a0, "autoLoad", strlen("autoLoad"), 1);
	Z_ADDREF_P(a0);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("spl_autoload_register", a0, 0x03F);
	Z_DELREF_P(a0);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Makes the work of autoload registered classes
 *
 * @param string $className
 */
PHP_METHOD(Phalcon_Loader, autoLoad){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *p1[] = { NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_namespaces", sizeof("_namespaces")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_0c08_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_0c08_0;
		} else {
			PHALCON_INIT_VAR(v2);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v2, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v2, num);
				}
			}
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "strlen", v0, 0x021);
		PHALCON_INIT_VAR(r1);
		is_smaller_function(r1, v2, r0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(r2);
			Z_ADDREF_P(v0);
			p1[0] = v0;
			PHALCON_INIT_VAR(p1[1]);
			ZVAL_LONG(p1[1], 0);
			PHALCON_INIT_VAR(r3);
			PHALCON_CALL_FUNC_PARAMS_1(r3, "strlen", v2, 0x021);
			Z_ADDREF_P(r3);
			p1[2] = r3;
			PHALCON_CALL_FUNC_PARAMS(r2, "substr", 3, p1, 0x00A);
			Z_DELREF_P(p1[0]);
			Z_DELREF_P(p1[2]);
			PHALCON_INIT_VAR(r4);
			is_equal_function(r4, r2, v2 TSRMLS_CC);
			if (zend_is_true(r4)) {
				PHALCON_INIT_VAR(r5);
				p3[0] = v2;
				PHALCON_INIT_VAR(p3[1]);
				ZVAL_STRING(p3[1], "", 1);
				p3[2] = v0;
				PHALCON_CALL_FUNC_PARAMS(r5, "str_replace", 3, p3, 0x01A);
				PHALCON_CPY_WRT(v3, r5);
				PHALCON_INIT_VAR(r6);
				concat_function(r6, v1, v3 TSRMLS_CC);
				if (phalcon_file_exists(r6 TSRMLS_CC) == SUCCESS) {
					phalcon_require(v3 TSRMLS_CC);
					if (EG(exception) || EG(exit_status) == 255) {
						return;
					}
					PHALCON_MM_RESTORE();
					RETURN_TRUE;
				}
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_0c08_0;
		fee_0c08_0:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_directories", sizeof("_directories")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah1 = Z_ARRVAL_P(t1);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_0c08_1:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_0c08_1;
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		PHALCON_INIT_VAR(r7);
		concat_function(r7, v1, v3 TSRMLS_CC);
		if (phalcon_file_exists(r7 TSRMLS_CC) == SUCCESS) {
			phalcon_require(v3 TSRMLS_CC);
			if (EG(exception) || EG(exit_status) == 255) {
				return;
			}
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_0c08_1;
		fee_0c08_1:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

