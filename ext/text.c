
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "text.h"

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
zend_class_entry *phalcon_text_ce;

PHP_METHOD(Phalcon_Text, camelize);
PHP_METHOD(Phalcon_Text, uncamelize);
PHP_METHOD(Phalcon_Text, increment);
PHP_METHOD(Phalcon_Text, random);
PHP_METHOD(Phalcon_Text, startsWith);
PHP_METHOD(Phalcon_Text, endsWith);
PHP_METHOD(Phalcon_Text, lower);
PHP_METHOD(Phalcon_Text, upper);
PHP_METHOD(Phalcon_Text, bytes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_uncamelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_random, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_startswith, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, ignoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_endswith, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, end)
	ZEND_ARG_INFO(0, ignoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_lower, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_upper, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_bytes, 0, 0, 1)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, forceUnit)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, si)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_text_method_entry[] = {
	PHP_ME(Phalcon_Text, camelize, arginfo_phalcon_text_camelize, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Text, uncamelize, arginfo_phalcon_text_uncamelize, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Text, increment, arginfo_phalcon_text_increment, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Text, random, arginfo_phalcon_text_random, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Text, startsWith, arginfo_phalcon_text_startswith, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Text, endsWith, arginfo_phalcon_text_endswith, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Text, lower, arginfo_phalcon_text_lower, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Text, upper, arginfo_phalcon_text_upper, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Text, bytes, arginfo_phalcon_text_bytes, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Text initializer
 */
PHALCON_INIT_CLASS(Phalcon_Text){

	PHALCON_REGISTER_CLASS(Phalcon, Text, text, phalcon_text_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALNUM"),   PHALCON_TEXT_RANDOM_ALNUM   TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_ALPHA"),   PHALCON_TEXT_RANDOM_ALPHA   TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_HEXDEC"),  PHALCON_TEXT_RANDOM_HEXDEC  TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NUMERIC"), PHALCON_TEXT_RANDOM_NUMERIC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_text_ce, SL("RANDOM_NOZERO"),  PHALCON_TEXT_RANDOM_NOZERO  TSRMLS_CC);

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

	zval *str;

	phalcon_fetch_params(0, 1, 0, &str);
	
	phalcon_camelize(return_value, str);
	return;
}

/**
 * Uncamelize strings which are camelized
 *
 *<code>
 *	echo Phalcon\Text::uncamelize('CocoBongo'); //coco_bongo
 *</code>
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, uncamelize){

	zval *str;

	phalcon_fetch_params(0, 1, 0, &str);
	
	phalcon_uncamelize(return_value, str);
	return;
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
	phalcon_fast_explode(parts, separator, str);
	if (phalcon_array_isset_long(parts, 1)) {
		PHALCON_OBS_VAR(number);
		phalcon_array_fetch_long(&number, parts, 1, PH_NOISY);
		SEPARATE_ZVAL(&number);
		phalcon_increment(number);
	} else {
		number = PHALCON_GLOBAL(z_one);
	}
	
	PHALCON_OBS_VAR(first_part);
	phalcon_array_fetch_long(&first_part, parts, 0, PH_NOISY);
	PHALCON_CONCAT_VVV(return_value, first_part, separator, number);
	
	RETURN_MM();
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

	zval *type, *length = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &type, &length);
	
	if (!length) {
		PHALCON_INIT_VAR(length);
		ZVAL_LONG(length, 8);
	}
	
	phalcon_random_string(return_value, type, length TSRMLS_CC);
	RETURN_MM();
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
	zval *case_sensitive;

	phalcon_fetch_params(0, 2, 1, &str, &start, &ignore_case);
	
	if (!ignore_case) {
		case_sensitive = PHALCON_GLOBAL(z_false);
	}
	else {
		case_sensitive = zend_is_true(ignore_case) ? PHALCON_GLOBAL(z_false) : PHALCON_GLOBAL(z_true);
	}

	RETURN_BOOL(phalcon_start_with(str, start, case_sensitive));
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
	zval *case_sensitive;

	phalcon_fetch_params(0, 2, 1, &str, &end, &ignore_case);
	
	if (!ignore_case) {
		case_sensitive = PHALCON_GLOBAL(z_false);
	}
	else {
		case_sensitive = zend_is_true(ignore_case) ? PHALCON_GLOBAL(z_false) : PHALCON_GLOBAL(z_true);
	}

	RETURN_BOOL(phalcon_end_with(str, end, case_sensitive));
}

/**
 * Lowercases a string, this function makes use of the mbstring extension if available
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, lower){

	zval *str;

	phalcon_fetch_params(0, 1, 0, &str);
	
	/** 
	 * 'lower' checks for the mbstring extension to make a correct lowercase
	 * transformation
	 */
	if (phalcon_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS) {
		PHALCON_MM_GROW();
		PHALCON_RETURN_CALL_FUNCTION("mb_strtolower", str);
		RETURN_MM();
	}

	phalcon_fast_strtolower(return_value, str);
}

/**
 * Uppercases a string, this function makes use of the mbstring extension if available
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Text, upper){

	zval *str;

	phalcon_fetch_params(0, 1, 0, &str);
	
	/** 
	 * 'upper' checks for the mbstring extension to make a correct lowercase
	 * transformation
	 */
	if (phalcon_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS) {
		PHALCON_MM_GROW();
		PHALCON_RETURN_CALL_FUNCTION("mb_strtoupper", str);
		RETURN_MM();
	}

	phalcon_fast_strtoupper(return_value, str);
}

/**
 * Returns human readable sizes
 *
 * @param int $size
 * @param string $forceUnit
 * @param string $format
 * @param boolean $si
 * @return string
 */
PHP_METHOD(Phalcon_Text, bytes){

	zval *z_size, *z_force_unit = NULL, *format = NULL, *si = NULL;
	zval *z_mod;
	char *force_unit;
	const char **units;
	const char *units1[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
	const char *units2[] = {"B", "kiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
	double size;
	int mod, power = 0, found = 0, i, j = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &z_size, &z_force_unit, &format, &si);

	PHALCON_SEPARATE_PARAM(z_size);
	convert_to_double(z_size);

	size = Z_DVAL_P(z_size);

	if (!z_force_unit) {
		PHALCON_INIT_VAR(z_force_unit);
	} else {
		PHALCON_SEPARATE_PARAM(z_force_unit);
		convert_to_string(z_force_unit);
	}
	
	if (!format) {
		PHALCON_INIT_VAR(format);
	} else {
		PHALCON_SEPARATE_PARAM(format);
		convert_to_string(format);
	}
		
	if (PHALCON_IS_EMPTY(format)) {
		PHALCON_INIT_NVAR(format);
		ZVAL_STRING(format, "%01.2f %s", 1);
	}

	if (!si) {
		si = PHALCON_GLOBAL(z_true);
	}

	if (!zend_is_true(si)) {
		units = units2;
		mod = 1024;
	} else {
		units = units1;
		mod = 1000;
	}

	PHALCON_INIT_VAR(z_mod);
	ZVAL_LONG(z_mod, mod);

	if (!PHALCON_IS_EMPTY(z_force_unit)) {
		force_unit = Z_STRVAL_P(z_force_unit);
		for (i = 0; i < sizeof(units); i++)
		{
			if (strcasecmp(force_unit, units[i]) == 0) {
				found = 1;
				power = i;
				break;
			}
		}
	}

	if (found) {
		while(j < power) {
			size /= mod;
			j++;
		}
	} else {
		while(size > mod) {
			size /= mod;
			power++;
		}
	}

	ZVAL_DOUBLE(z_size, size);
	ZVAL_STRING(z_force_unit, units[power], 1);

	PHALCON_RETURN_CALL_FUNCTION("sprintf", format, z_size, z_force_unit);

	RETURN_MM();
}
