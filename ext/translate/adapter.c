
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
#include "kernel/exception.h"

/**
 * Phalcon\Translate\Adapter
 *
 * Base class for Phalcon\Translate adapters
 */


/**
 * Phalcon\Translate\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Translate_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Translate, Adapter, translate_adapter, phalcon_translate_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_translate_adapter_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	return SUCCESS;
}

/**
 * Returns the translation string of the given key
 *
 * @param string $translateKey
 * @param array $placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, _){

	zval *translate_key, *placeholders = NULL, *translation;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &translate_key, &placeholders);
	
	if (!placeholders) {
		PHALCON_INIT_VAR(placeholders);
	}
	
	PHALCON_INIT_VAR(translation);
	phalcon_call_method_p2(translation, this_ptr, "query", translate_key, placeholders);
	RETURN_CCTOR(translation);
}

/**
 * Sets a translation value
 *
 * @param 	string $offset
 * @param 	string $value
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetSet){

	zval *offset, *value;

	phalcon_fetch_params(0, 2, 0, &offset, &value);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object");
	return;
}

/**
 * Check whether a translation key exists
 *
 * @param string $translateKey
 * @return boolean
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists){

	zval *translate_key, *exists;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &translate_key);
	
	PHALCON_INIT_VAR(exists);
	phalcon_call_method_p1(exists, this_ptr, "exists", translate_key);
	RETURN_CCTOR(exists);
}

/**
 * Unsets a translation from the dictionary
 *
 * @param string $offset
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset){

	zval *offset;

	phalcon_fetch_params(0, 1, 0, &offset);
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_translate_exception_ce, "Translate is an immutable ArrayAccess object");
	return;
}

/**
 * Returns the translation related to the given key
 *
 * @param string $translateKey
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetGet){

	zval *translate_key, *null_value, *translation;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &translate_key);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(translation);
	phalcon_call_method_p2(translation, this_ptr, "query", translate_key, null_value);
	RETURN_CCTOR(translation);
}

