
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
ZEPHIR_INIT_CLASS(Phalcon_Cli_Console_Exceptions_InvalidModuleDefinition)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli\\Console\\Exceptions, InvalidModuleDefinition, phalcon, cli_console_exceptions_invalidmoduledefinition, phalcon_cli_console_exception_ce, phalcon_cli_console_exceptions_invalidmoduledefinition_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Cli_Console_Exceptions_InvalidModuleDefinition, __construct)
{
	zval _0$$3, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, reason_zv, message;
	zend_string *name = NULL, *reason = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&reason_zv);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_STR_OR_NULL(reason)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!reason) {
		ZEPHIR_INIT_VAR(&reason_zv);
	} else {
		zephir_memory_observe(&reason_zv);
	ZVAL_STR_COPY(&reason_zv, reason);
	}
	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "Invalid module definition");
	if (!ZEPHIR_IS_NULL(&name_zv)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVS(&_0$$3, " for module '", &name_zv, "'");
		zephir_concat_self(&message, &_0$$3);
	}
	if (!ZEPHIR_IS_NULL(&reason_zv)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SV(&_1$$4, ": ", &reason_zv);
		zephir_concat_self(&message, &_1$$4);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cli_console_exceptions_invalidmoduledefinition_ce, getThis(), "__construct", NULL, 0, &message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

