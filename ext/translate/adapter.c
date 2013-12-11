
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


PHALCON_STATIC zend_object_handlers phalcon_translate_adapter_object_handlers;

static zval* phalcon_translate_adapter_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	zval *ret = NULL;

	if (Z_OBJCE_P(object)->type != ZEND_INTERNAL_CLASS) {
		return zend_get_std_object_handlers()->read_dimension(object, offset, type TSRMLS_CC);
	}

	phalcon_call_method_params(ret, &ret, object, SL("query"), zend_inline_hash_func(SS("query")) TSRMLS_CC, 2, offset, PHALCON_GLOBAL(z_null));
	return UNEXPECTED(EG(exception) != NULL) ? NULL : ret;
}

static void phalcon_translate_adapter_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC)
{
	if (Z_OBJCE_P(object)->type != ZEND_INTERNAL_CLASS) {
		zend_get_std_object_handlers()->write_dimension(object, offset, value TSRMLS_CC);
		return;
	}

	zend_throw_exception_ex(phalcon_translate_exception_ce, 0 TSRMLS_CC, "'%s' is an immutable ArrayAccess object", "Phalcon\\Translate\\Adapter");
}

static int phalcon_translate_adapter_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	zval *exists = NULL;
	int retval;

	if (Z_OBJCE_P(object)->type != ZEND_INTERNAL_CLASS) {
		return zend_get_std_object_handlers()->has_dimension(object, offset, check_empty TSRMLS_CC);
	}

	phalcon_call_method_params(exists, &exists, object, SL("exists"), zend_inline_hash_func(SS("exists")) TSRMLS_CC, 1, offset);
	if (UNEXPECTED(EG(exception) != NULL)) {
		return 0;
	}

	retval = zend_is_true(exists);
	zval_ptr_dtor(&exists);
	return retval;
}

static void phalcon_translate_adapter_unset_dimension(zval *object, zval *offset TSRMLS_DC)
{
	if (Z_OBJCE_P(object)->type != ZEND_INTERNAL_CLASS) {
		zend_get_std_object_handlers()->unset_dimension(object, offset TSRMLS_CC);
		return;
	}

	zend_throw_exception_ex(phalcon_translate_exception_ce, 0 TSRMLS_CC, "'%s' is an immutable ArrayAccess object", "Phalcon\\Translate\\Adapter");
}


/**
 * Phalcon\Translate\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Translate_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Translate, Adapter, translate_adapter, phalcon_translate_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	phalcon_translate_adapter_object_handlers = *zend_get_std_object_handlers();
	phalcon_translate_adapter_object_handlers.read_dimension  = phalcon_translate_adapter_read_dimension;
	phalcon_translate_adapter_object_handlers.write_dimension = phalcon_translate_adapter_write_dimension;
	phalcon_translate_adapter_object_handlers.has_dimension   = phalcon_translate_adapter_has_dimension;
	phalcon_translate_adapter_object_handlers.unset_dimension = phalcon_translate_adapter_unset_dimension;

	zend_class_implements(phalcon_translate_adapter_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	return SUCCESS;
}

/**
 * Class constructore
 */
PHP_METHOD(Phalcon_Translate_Adapter, __construct)
{
	Z_OBJ_HT_P(getThis()) = &phalcon_translate_adapter_object_handlers;
}
/**
 * Returns the translation string of the given key
 *
 * @param string $translateKey
 * @param array $placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, _){

	zval *translate_key, *placeholders = NULL;

	phalcon_fetch_params(0, 1, 1, &translate_key, &placeholders);

	if (!placeholders) {
		placeholders = PHALCON_GLOBAL(z_null);
	}

	phalcon_call_method_params(return_value, return_value_ptr, this_ptr, SL("query"), zend_inline_hash_func(SS("query")) TSRMLS_CC, 2, translate_key, placeholders);
	if (return_value_ptr && EG(exception)) {
		ALLOC_INIT_ZVAL(*return_value_ptr);
	}
}

/**
 * Sets a translation value
 *
 * @param 	string $offset
 * @param 	string $value
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetSet){

	zend_throw_exception_ex(phalcon_translate_exception_ce, 0 TSRMLS_CC, "'%s' is an immutable ArrayAccess object", "Phalcon\\Translate\\Adapter");
}

/**
 * Check whether a translation key exists
 *
 * @param string $translateKey
 * @return boolean
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists){

	zval **translate_key;
	int exists;

	phalcon_fetch_params_ex(1, 0, &translate_key);
	exists = phalcon_translate_adapter_has_dimension(getThis(), *translate_key, 1 TSRMLS_CC);
	RETURN_BOOL(exists);
}

/**
 * Unsets a translation from the dictionary
 *
 * @param string $offset
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset){

	zend_throw_exception_ex(phalcon_translate_exception_ce, 0 TSRMLS_CC, "'%s' is an immutable ArrayAccess object", "Phalcon\\Translate\\Adapter");
}

/**
 * Returns the translation related to the given key
 *
 * @param string $translateKey
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter, offsetGet){

	zval **translate_key, *res;

	phalcon_fetch_params_ex(1, 0, &translate_key);
	res = phalcon_translate_adapter_read_dimension(getThis(), *translate_key, BP_VAR_R TSRMLS_CC);
	RETURN_ZVAL(res, 1, 0);
}
