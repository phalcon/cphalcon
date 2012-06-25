
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

#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
/**
 * Phalcon_Translate
 *
 * Translate component allows the creation of multi-language applications using
 * different adapters for translation lists.
 */

/**
 * Phalcon_Translate constructor
 *
 * @param string $adapter
 * @param array $options
 */
PHP_METHOD(Phalcon_Translate, __construct){

	zval *adapter = NULL, *options = NULL, *adapter_class = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &adapter, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SV(r0, "Phalcon_Translate_Adapter_", adapter);
	PHALCON_CPY_WRT(adapter_class, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", adapter_class);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_translate_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SVS(r2, "No existe el adaptador \"", adapter, "\"");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	ce0 = phalcon_fetch_class(adapter_class TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", options, PHALCON_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_adapter"), i1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the translation string of the given key
 *
 * @param string $translateKey
 * @param array $placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate, _){

	zval *translate_key = NULL, *placeholders = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &translate_key, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!placeholders) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(placeholders, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_adapter"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2(r0, t0, "query", translate_key, placeholders, PHALCON_NO_CHECK);
	RETURN_DZVAL(r0);
}

/**
 * Sets a translation value
 *
 * @param string $offset
 * @param string $value
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

	zval *translate_key = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &translate_key) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_adapter"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t0, "exists", translate_key, PHALCON_NO_CHECK);
	RETURN_DZVAL(r0);
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

	zval *traslate_key = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &traslate_key) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_adapter"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_INIT_VAR(c0);
	ZVAL_NULL(c0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, t0, "query", traslate_key, c0, PHALCON_NO_CHECK);
	RETURN_DZVAL(r0);
}

