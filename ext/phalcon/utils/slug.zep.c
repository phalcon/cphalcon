
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Utils_Slug) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Utils, Slug, phalcon, utils_slug, phalcon_utils_adapter_ce, phalcon_utils_slug_method_entry, 0);

	zend_class_implements(phalcon_utils_slug_ce TSRMLS_CC, 1, phalcon_utils_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Creates a slug to be used for pretty URLs
 * @link http://cubiq.org/the-perfect-php-clean-url-generator
 * @example unit-test/utisl/SlugTest.php
 * 
 * @return string
 */
PHP_METHOD(Phalcon_Utils_Slug, generate) {

	HashTable *_9;
	HashPosition _8;
	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL, *_16 = NULL;
	zval *replace = NULL;
	zval *str_param = NULL, *replace_param = NULL, *delimiter_param = NULL, *oldLocale = NULL, *clean = NULL, _0 = zval_used_for_init, *_1 = NULL, *_4, _5 = zval_used_for_init, *_7, *key = NULL, *value = NULL, **_10, *_11 = NULL, *_12, _13, *_14, *_15 = NULL;
	zval *str = NULL, *delimiter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &replace_param, &delimiter_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(str_param) == IS_STRING)) {
		str = str_param;
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	ZEPHIR_SEPARATE_PARAM(str);
	if (!replace_param) {
	ZEPHIR_INIT_VAR(replace);
	ZVAL_NULL(replace);
	} else {
		zephir_get_arrval(replace, replace_param);
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(delimiter);
		ZVAL_STRING(delimiter, "-", 1);
	} else {
	if (unlikely(Z_TYPE_P(delimiter_param) != IS_STRING && Z_TYPE_P(delimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'delimiter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(delimiter_param) == IS_STRING)) {
		delimiter = delimiter_param;
	} else {
		ZEPHIR_INIT_VAR(delimiter);
		ZVAL_EMPTY_STRING(delimiter);
	}
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "iconv", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_utils_exception_ce, "iconv module not loaded", "phalcon/utils/slug.zep", 38);
		return;
	}
	_3 = zephir_is_true(replace);
	if (_3) {
		ZEPHIR_INIT_VAR(_4);
		zephir_gettype(_4, replace TSRMLS_CC);
		_3 = !ZEPHIR_IS_STRING(_4, "array");
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_utils_exception_ce, "The replace must be an array", "phalcon/utils/slug.zep", 41);
		return;
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 6);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "en_US.UTF-8", 0);
	ZEPHIR_CALL_FUNCTION(&oldLocale, "setlocale", &_6, &_0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	zephir_gettype(_7, replace TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_7, "array")) {
		zephir_is_iterable(replace, &_9, &_8, 0, 0, "phalcon/utils/slug.zep", 51);
		for (
		  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HMKEY(key, _9, _8);
			ZEPHIR_GET_HVALUE(value, _10);
			ZEPHIR_INIT_NVAR(_11);
			zephir_array_fetch(&_12, replace, key, PH_NOISY | PH_READONLY, "phalcon/utils/slug.zep", 49 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, " ", 0);
			zephir_fast_str_replace(_11, _12, &_0, str);
			zephir_get_strval(str, _11);
		}
	}
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_STRING(&_5, "UTF-8", 0);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "ASCII//TRANSLIT", 0);
	ZEPHIR_CALL_FUNCTION(&clean, "iconv", NULL, &_5, &_13, str);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "/[^a-zA-Z0-9\\/_|+ -]/", 0);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_STRING(_14, "", 0);
	ZEPHIR_CALL_FUNCTION(&_15, "preg_replace", &_16, _11, _14, clean);
	zephir_check_temp_parameter(_11);
	zephir_check_temp_parameter(_14);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(clean, _15);
	ZEPHIR_INIT_NVAR(_11);
	zephir_fast_strtolower(_11, clean);
	ZEPHIR_CPY_WRT(clean, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "/[\\/_|+ -]+/", 0);
	ZEPHIR_CALL_FUNCTION(&_15, "preg_replace", &_16, _11, delimiter, clean);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(clean, _15);
	ZEPHIR_INIT_NVAR(_11);
	zephir_fast_trim(_11, clean, delimiter, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(clean, _11);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 6);
	ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_6, &_5, oldLocale);
	zephir_check_call_status();
	RETURN_CCTOR(clean);

}

