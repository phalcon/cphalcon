
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Text
 *
 * Provides utilities to work with texts
 */


/**
 * Phalcon\Text initializer
 */
PHALCON_INIT_CLASS(Phalcon_Text){

	PHALCON_REGISTER_CLASS(Phalcon, Text, text, phalcon_text_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALNUM"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALPHA"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_HEXDEC"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NUMERIC"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NOZERO"), 4 TSRMLS_CC);

	return SUCCESS;
}

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

	zval *str, *camelized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &str);
	
	PHALCON_INIT_VAR(camelized);
	phalcon_camelize(camelized, str TSRMLS_CC);
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

	zval *str, *uncamelized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &str);
	
	PHALCON_INIT_VAR(uncamelized);
	phalcon_uncamelize(uncamelized, str TSRMLS_CC);
	RETURN_CTOR(uncamelized);
}

/**
 * Adds a number to a string or increment that number if it already is defined
 *
 *<code>
 *	echo Phalcon\Text::increment("a"); // "a_1"
 *	echo Phalcon\Text::increment("a_1"); // "a_2"
 *</code>
 *
 * @param string $str
 * @param string $separator
 * @return string
 */
PHP_METHOD(Phalcon_Text, increment){

	zval *str, *separator = NULL, *parts, *number = NULL, *first_part;
	zval *incremented;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &str, &separator);
	
	if (!separator) {
		PHALCON_INIT_VAR(separator);
	} else {
		PHALCON_SEPARATE_PARAM(separator);
	}
	
	if (Z_TYPE_P(separator) == IS_NULL) {
		PHALCON_INIT_NVAR(separator);
		ZVAL_STRING(separator, "_", 1);
	}
	
	PHALCON_INIT_VAR(parts);
	phalcon_fast_explode(parts, separator, str TSRMLS_CC);
	if (phalcon_array_isset_long(parts, 1)) {
		PHALCON_OBS_VAR(number);
		phalcon_array_fetch_long(&number, parts, 1, PH_NOISY_CC);
		PHALCON_SEPARATE(number);
		phalcon_increment(number);
	} else {
		PHALCON_INIT_NVAR(number);
		ZVAL_LONG(number, 1);
	}
	
	PHALCON_OBS_VAR(first_part);
	phalcon_array_fetch_long(&first_part, parts, 0, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(incremented);
	PHALCON_CONCAT_VVV(incremented, first_part, separator, number);
	
	RETURN_CTOR(incremented);
}

/**
 * Generates a random string based on the given type. Type is one of the RANDOM_* constants
 *
 *<code>
 *	echo Phalcon\Text::random(Phalcon\Text::RANDOM_ALNUM); //"aloiwkqz"
 *</code>
 *
 * @param int $type
 * @param int $length
 * @return string
 */
PHP_METHOD(Phalcon_Text, random){

	zval *type, *length = NULL, *random;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &type, &length);
	
	if (!length) {
		PHALCON_INIT_VAR(length);
		ZVAL_LONG(length, 8);
	}
	
	PHALCON_INIT_VAR(random);
	phalcon_random_string(random, type, length TSRMLS_CC);
	RETURN_CTOR(random);
}

/**
 * Check if a string starts with a given string
 *
 *<code>
 *	echo Phalcon\Text::startsWith("Hello", "He"); // true
 *	echo Phalcon\Text::startsWith("Hello", "he"); // false
 *	echo Phalcon\Text::startsWith("Hello", "he", false); // true
 *</code>
 *
 * @param string $str
 * @param string $start
 * @param boolean $ignoreCase
 * @return boolean
 */
PHP_METHOD(Phalcon_Text, startsWith){

	zval *str, *start, *ignore_case = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &str, &start, &ignore_case);
	
	if (!ignore_case) {
		PHALCON_INIT_VAR(ignore_case);
		ZVAL_BOOL(ignore_case, 1);
	}
	
	if (phalcon_start_with(str, start, ignore_case)) {
		RETURN_MM_TRUE;
	}
	RETURN_MM_FALSE;
}

/**
 * Check if a string ends with a given string
 *
 *<code>
 *	echo Phalcon\Text::endsWith("Hello", "llo"); // true
 *	echo Phalcon\Text::endsWith("Hello", "LLO"); // false
 *	echo Phalcon\Text::endsWith("Hello", "LLO", false); // true
 *</code>
 *
 * @param string $str
 * @param string $end
 * @param boolean $ignoreCase
 * @return boolean
 */
PHP_METHOD(Phalcon_Text, endsWith){

	zval *str, *end, *ignore_case = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &str, &end, &ignore_case);
	
	if (!ignore_case) {
		PHALCON_INIT_VAR(ignore_case);
		ZVAL_BOOL(ignore_case, 1);
	}
	
	if (phalcon_end_with(str, end, ignore_case)) {
		RETURN_MM_TRUE;
	}
	RETURN_MM_FALSE;
}

/**
 * Lowercases a string, this function makes use of the mbstring extension if available
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, lower){

	zval *str, *lower = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &str);
	
	/** 
	 * 'lower' checks for the mbstring extension to make a correct lowercase
	 * transformation
	 */
	if (phalcon_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(lower);
		phalcon_call_func_p1(lower, "mb_strtolower", str);
	} else {
		PHALCON_INIT_NVAR(lower);
		phalcon_fast_strtolower(lower, str);
	}
	
	RETURN_CCTOR(lower);
}

/**
 * Uppercases a string, this function makes use of the mbstring extension if available
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, upper){

	zval *str, *upper = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &str);
	
	/** 
	 * 'upper' checks for the mbstring extension to make a correct lowercase
	 * transformation
	 */
	if (phalcon_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(upper);
		phalcon_call_func_p1(upper, "mb_strtoupper", str);
	} else {
		PHALCON_INIT_NVAR(upper);
		phalcon_call_func_p1(upper, "strtoupper", str);
	}
	
	RETURN_CCTOR(upper);
}

