
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
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Converts strings to camelize style
 *
 * 
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, camelize){

	zval *str = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, " ", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "_", 1);
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, " ", 1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", str, 0x005);
	PHALCON_CALL_FUNC_PARAMS_3(r2, "str_replace", c2, c3, r3, 0x003);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "ucwords", r2, 0x004);
	PHALCON_CALL_FUNC_PARAMS_3(r0, "str_replace", c0, c1, r1, 0x003);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Uncamelize strings which are camelized
 *
 * 
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, uncamelize){

	zval *str = NULL, *patterns = NULL, *replacement = NULL, *pattern = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_stringl_ex(a0, "/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/", strlen("/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/")+1, "\\1_\\2", strlen("\\1_\\2"), 1);
	add_assoc_stringl_ex(a0, "/(?<=(?:[a-z]))([A-Z])/", strlen("/(?<=(?:[a-z]))([A-Z])/")+1, "_\\1", strlen("_\\1"), 1);
	PHALCON_CPY_WRT(patterns, a0);
	if (phalcon_valid_foreach(patterns TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(patterns);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f8ee_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f8ee_0;
		} else {
			
			PHALCON_INIT_VAR(pattern);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(pattern, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(pattern, hash_num);
				}
			}
		}
		
		PHALCON_INIT_VAR(replacement);
		ZVAL_ZVAL(replacement, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		Z_ADDREF_P(pattern);
		Z_ADDREF_P(str);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "preg_match", pattern, str, 0x006);
		Z_DELREF_P(pattern);
		Z_DELREF_P(str);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(r1);
			PHALCON_INIT_VAR(r2);
			PHALCON_CALL_FUNC_PARAMS_3(r2, "preg_replace", pattern, replacement, str, 0x007);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "strtolower", r2, 0x005);
			PHALCON_RETURN_DZVAL(r1);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f8ee_0;
		fee_f8ee_0:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", str, 0x005);
	PHALCON_RETURN_DZVAL(r3);
}

/**
     * Changes only first letter to lowercase
     *
     * @param string $str
     * @return string
     * @static
     **/
PHP_METHOD(Phalcon_Text, lcfirst){

	zval *str = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 1);
	PHALCON_CALL_FUNC_PARAMS_3(r1, "substr", str, c0, c1, 0x002);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "strtolower", r1, 0x005);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(c2);
	ZVAL_LONG(c2, 1);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "substr", str, c2, 0x002);
	PHALCON_ALLOC_ZVAL_MM(r3);
	concat_function(r3, r0, r2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r3);
}

