
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Autoload_Exceptions_LoaderDirectoriesNotArray)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Autoload\\Exceptions, LoaderDirectoriesNotArray, phalcon, autoload_exceptions_loaderdirectoriesnotarray, phalcon_autoload_exception_ce, phalcon_autoload_exceptions_loaderdirectoriesnotarray_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Autoload_Exceptions_LoaderDirectoriesNotArray, __construct)
{
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, message, _0;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		name = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&name_zv);
		ZVAL_STR(&name_zv, name);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "The directories parameter is not a string or array");
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (!ZEPHIR_IS_IDENTICAL(&_0, &name_zv)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, " for the '", &name_zv, "' namespace");
		zephir_concat_self(&message, &_1$$3);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_autoload_exceptions_loaderdirectoriesnotarray_ce, getThis(), "__construct", NULL, 0, &message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

