
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

#include "translate/adapter.h"
#include "translate/adapterinterface.h"
#include "translate/exception.h"
#include "internal/arginfo.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

/**
 * Phalcon\Translate\Adapter
 *
 * Base class for Phalcon\Translate adapters
 */
zend_class_entry *phalcon_translate_adapter_ce;

PHP_METHOD(Phalcon_Translate_Adapter, __construct);
PHP_METHOD(Phalcon_Translate_Adapter, _);
PHP_METHOD(Phalcon_Translate_Adapter, offsetSet);
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists);
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset);
PHP_METHOD(Phalcon_Translate_Adapter, offsetGet);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter__, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_translate_adapter_method_entry[] = {
	PHP_ME(Phalcon_Translate_Adapter, __construct, arginfo_empty, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter, _, arginfo_phalcon_translate_adapter__, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetSet, arginfo_arrayaccess_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetExists, arginfo_arrayaccess_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetUnset, arginfo_arrayaccess_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetGet, arginfo_arrayaccess_offsetget, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

PHALCON_STATIC zend_object_handlers phalcon_translate_adapter_object_handlers;

static zval* phalcon_translate_adapter_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	zval *ret = NULL;
	int status;
	zval *params[] = { offset, PHALCON_GLOBAL(z_null) };

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		return zend_get_std_object_handlers()->read_dimension(object, offset, type TSRMLS_CC);
	}

	status = phalcon_call_method(&ret, object, "query", 2, params TSRMLS_CC);
	return UNEXPECTED(status == FAILURE) ? NULL : ret;
}

static void phalcon_translate_adapter_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC)
{
	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		zend_get_std_object_handlers()->write_dimension(object, offset, value TSRMLS_CC);
		return;
	}

	zend_throw_exception_ex(phalcon_translate_exception_ce, 0 TSRMLS_CC, "'%s' is an immutable ArrayAccess object", "Phalcon\\Translate\\Adapter");
}

static int phalcon_translate_adapter_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	zval *exists = NULL;
	int retval;
	zval *params[] = { offset };

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		return zend_get_std_object_handlers()->has_dimension(object, offset, check_empty TSRMLS_CC);
	}

	if (FAILURE == phalcon_call_method(&exists, object, "exists", 1, params TSRMLS_CC)) {
		return 0;
	}

	retval = zend_is_true(exists);
	zval_ptr_dtor(&exists);
	return retval;
}

static void phalcon_translate_adapter_unset_dimension(zval *object, zval *offset TSRMLS_DC)
{
	if (!is_phalcon_class(Z_OBJCE_P(object))) {
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

	zend_class_implements(phalcon_translate_adapter_ce TSRMLS_CC, 2, zend_ce_arrayaccess, phalcon_translate_adapterinterface_ce);

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

	PHALCON_RETURN_CALL_METHODW(this_ptr, "query", translate_key, placeholders);
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
