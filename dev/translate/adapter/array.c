
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
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Translate_Adapter_Array
 *
 * Allows to define translation lists using PHP arrays
 *
 */

/**
 * Phalcon_Translate_Adapter_Array constructor
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Translate_Adapter_Array, __construct){

	zval *options = NULL, *data = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(options, "content", strlen("content")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, options, "content", strlen("content"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(data, r0);
		if (Z_TYPE_P(data) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_translate_exception_ce, "Translation data must be an array");
			return;
		}
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_translate_exception_ce, "Translation content was not provided");
		return;
	}
	phalcon_update_property_zval(this_ptr, "_traslate", strlen("_traslate"), data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the translation related to the given key
 *
 * @param string $index
 * @param array $placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Array, query){

	zval *index = NULL, *placeholders = NULL, *translation = NULL, *value = NULL;
	zval *key = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_traslate", sizeof("_traslate")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, index);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_traslate", sizeof("_traslate")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, index, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(translation, r0);
		if (zend_is_true(placeholders)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_fast_count(r1, placeholders TSRMLS_CC);
			if (zend_is_true(r1)) {
				if (phalcon_valid_foreach(placeholders TSRMLS_CC)) {
					ah0 = Z_ARRVAL_P(placeholders);
					zend_hash_internal_pointer_reset_ex(ah0, &hp0);
					fes_2f22_0:
					if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
						goto fee_2f22_0;
					} else {
						PHALCON_INIT_VAR(key);
						PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
					}
					PHALCON_INIT_VAR(value);
					ZVAL_ZVAL(value, *hd, 1, 0);
					PHALCON_INIT_VAR(r2);
					PHALCON_INIT_VAR(r3);
					PHALCON_CONCAT_SVS(r3, "%", key, "%");
					PHALCON_CALL_FUNC_PARAMS_3(r2, "str_replace", r3, value, translation, 0x003);
					PHALCON_CPY_WRT(translation, r2);
					zend_hash_move_forward_ex(ah0, &hp0);
					goto fes_2f22_0;
					fee_2f22_0:
					if(0){}
				} else {
					return;
				}
			}
		}
		
		
		PHALCON_RETURN_CHECK_CTOR(translation);
	} else {
		
		PHALCON_RETURN_CHECK_CTOR(index);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Array, exists){

	zval *index = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_traslate", sizeof("_traslate")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, index);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	PHALCON_RETURN_NCTOR(r0);
}

