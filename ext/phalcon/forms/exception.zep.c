
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Exceptions thrown in Phalcon\Forms will use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms, Exception, phalcon, forms_exception, zend_ce_exception, phalcon_forms_exception_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Forms_Exception, tagFactoryNotFound)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_forms_exception_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "A TagFactory must be provided via setTagFactory() or through a parent Form");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 32, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Forms_Exception, usingParameterRequired)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_forms_exception_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "The 'using' parameter is required for resultset options");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 32, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

