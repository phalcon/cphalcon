
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
#include "kernel/exception.h"

/**
 * Phalcon\Translate
 *
 * Translate component allows the creation of multi-language applications using
 * different adapters for translation lists.
 */

/**
 * Returns the translation string of the given key
 *
 * @param string $translateKey
 * @param array $placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate, _){

	zval *translate_key = NULL, *placeholders = NULL, *translation = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &translate_key, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!placeholders) {
		PHALCON_ALLOC_ZVAL_MM(placeholders);
		ZVAL_NULL(placeholders);
	}
	
	PHALCON_INIT_VAR(translation);
	PHALCON_CALL_METHOD_PARAMS_2(translation, this_ptr, "query", translate_key, placeholders, PH_NO_CHECK);
	
	RETURN_CCTOR(translation);
}

/**
 * Sets a translation value
 *
 * @param 	string $offset
 * @param 	string $value
 */
PHP_METHOD(Phalcon_Translate, offsetSet){

	zval *offset = NULL, *value = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &offset, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_THROW_EXCEPTION_STR(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object");
	return;
}

/**
 * Check whether a translation key exists
 *
 * @param string $translateKey
 * @return boolean
 */
PHP_METHOD(Phalcon_Translate, offsetExists){

	zval *translate_key = NULL, *exists = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &translate_key) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_1(exists, this_ptr, "exists", translate_key, PH_NO_CHECK);
	
	RETURN_CCTOR(exists);
}

/**
 * Elimina un indice del diccionario
 *
 * @param string $offset
 */
PHP_METHOD(Phalcon_Translate, offsetUnset){

	zval *offset = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &offset) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_THROW_EXCEPTION_STR(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object");
	return;
}

/**
 * Returns the translation related to the given key
 *
 * @param string $traslateKey
 * @return string
 */
PHP_METHOD(Phalcon_Translate, offsetGet){

	zval *traslate_key = NULL, *null_value = NULL, *translation = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &traslate_key) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(null_value);
	ZVAL_NULL(null_value);
	
	PHALCON_INIT_VAR(translation);
	PHALCON_CALL_METHOD_PARAMS_2(translation, this_ptr, "query", traslate_key, null_value, PH_NO_CHECK);
	
	RETURN_CCTOR(translation);
}

