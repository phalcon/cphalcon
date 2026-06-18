
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_Exceptions_RouterArgumentsInvalidType)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli\\Router\\Exceptions, RouterArgumentsInvalidType, phalcon, cli_router_exceptions_routerargumentsinvalidtype, phalcon_cli_router_exception_ce, phalcon_cli_router_exceptions_routerargumentsinvalidtype_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Cli_Router_Exceptions_RouterArgumentsInvalidType, __construct)
{
	zval _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, message;
	zend_string *type = NULL;

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!type) {
		type = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&type_zv);
		ZVAL_STR(&type_zv, type);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "Arguments must be an array or string");
	if (!ZEPHIR_IS_STRING_IDENTICAL(&type_zv, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVS(&_0$$3, ", ", &type_zv, " given");
		zephir_concat_self(&message, &_0$$3);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cli_router_exceptions_routerargumentsinvalidtype_ce, getThis(), "__construct", NULL, 0, &message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

