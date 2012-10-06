
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
 * Phalcon\Text
 *
 * Provides utilities when working with strings
 */

/**
 * Converts strings to camelize style
 *
 *<code>
 *	echo Phalcon\Text::camelize('coco_bongo'); //CocoBongo
 *</code>
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, camelize){

	zval *str, *space, *lower_str, *underscore, *no_underscore_str;
	zval *dash, *no_dash_str, *empty_str, *uc_string;
	zval *camelized;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &str) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(space);
	ZVAL_STRING(space, " ", 1);
	
	PHALCON_INIT_VAR(lower_str);
	PHALCON_CALL_FUNC_PARAMS_1(lower_str, "strtolower", str);
	
	PHALCON_INIT_VAR(underscore);
	ZVAL_STRING(underscore, "_", 1);
	
	PHALCON_INIT_VAR(no_underscore_str);
	phalcon_fast_str_replace(no_underscore_str, underscore, space, lower_str TSRMLS_CC);
	
	PHALCON_INIT_VAR(dash);
	ZVAL_STRING(dash, "-", 1);
	
	PHALCON_INIT_VAR(no_dash_str);
	phalcon_fast_str_replace(no_dash_str, dash, space, no_underscore_str TSRMLS_CC);
	
	PHALCON_INIT_VAR(empty_str);
	ZVAL_STRING(empty_str, "", 1);
	
	PHALCON_INIT_VAR(uc_string);
	PHALCON_CALL_FUNC_PARAMS_1(uc_string, "ucwords", no_dash_str);
	
	PHALCON_INIT_VAR(camelized);
	phalcon_fast_str_replace(camelized, space, empty_str, uc_string TSRMLS_CC);
	
	RETURN_CTOR(camelized);
}

/**
 * Uncamelize strings which are camelized
 *
 *<code>
 *	echo Phalcon\Text::camelize('CocoBongo'); //coco_bongo
 *</code>
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, uncamelize){

	zval *str, *patterns, *replacement = NULL, *pattern = NULL, *match_pattern = NULL;
	zval *pattern_replace = NULL, *lower_pattern = NULL, *lower_str;
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
	add_assoc_stringl_ex(patterns, SS("/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/"), SL("\\1_\\2"), 1);
	add_assoc_stringl_ex(patterns, SS("/(?<=(?:[a-z]))([A-Z])/"), SL("_\\1"), 1);
	
	if (!phalcon_valid_foreach(patterns TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(patterns);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_INIT_NVAR(pattern);
		PHALCON_GET_FOREACH_KEY(pattern, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(replacement);
		
		PHALCON_INIT_NVAR(match_pattern);
		PHALCON_CALL_FUNC_PARAMS_2(match_pattern, "preg_match", pattern, str);
		if (zend_is_true(match_pattern)) {
			PHALCON_INIT_NVAR(pattern_replace);
			PHALCON_CALL_FUNC_PARAMS_3(pattern_replace, "preg_replace", pattern, replacement, str);
			
			PHALCON_INIT_NVAR(lower_pattern);
			PHALCON_CALL_FUNC_PARAMS_1(lower_pattern, "strtolower", pattern_replace);
			
			RETURN_CTOR(lower_pattern);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(lower_str);
	PHALCON_CALL_FUNC_PARAMS_1(lower_str, "strtolower", str);
	
	RETURN_CTOR(lower_str);
}

