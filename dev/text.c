
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"

/**
 * Phalcon_Text
 *
 * Provides utilities when working with strings
 */

/**
 * Converts strings to camelize style
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, camelize){

	zval *str = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, " ", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "", 1);
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "_", 1);
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, " ", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "strtolower", str);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_str_replace(r1, c2, c3, r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "ucwords", r1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_fast_str_replace(r3, c0, c1, r2 TSRMLS_CC);
	RETURN_CTOR(r3);
}

/**
 * Uncamelize strings which are camelized
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, uncamelize){

	zval *str = NULL, *patterns = NULL, *replacement = NULL, *pattern = NULL;
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

	PHALCON_INIT_VAR(patterns);
	array_init(patterns);
	add_assoc_stringl_ex(patterns, SL("/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/")+1, SL("\\1_\\2"), 1);
	add_assoc_stringl_ex(patterns, SL("/(?<=(?:[a-z]))([A-Z])/")+1, SL("_\\1"), 1);
	if (!phalcon_valid_foreach(patterns TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(patterns);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_f8ee_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f8ee_0;
		}
		
		PHALCON_INIT_VAR(pattern);
		PHALCON_GET_FOREACH_KEY(pattern, ah0, hp0);
		PHALCON_INIT_VAR(replacement);
		ZVAL_ZVAL(replacement, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "preg_match", pattern, str);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(r1);
			PHALCON_CALL_FUNC_PARAMS_3(r1, "preg_replace", pattern, replacement, str);
			PHALCON_INIT_VAR(r2);
			PHALCON_CALL_FUNC_PARAMS_1(r2, "strtolower", r1);
			RETURN_CTOR(r2);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f8ee_0;
	fee_f8ee_0:
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", str);
	RETURN_CTOR(r3);
}

