
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exceptions_UnknownVoltStatement)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine\\Volt\\Exceptions, UnknownVoltStatement, phalcon, mvc_view_engine_volt_exceptions_unknownvoltstatement, phalcon_mvc_view_engine_volt_exception_ce, phalcon_mvc_view_engine_volt_exceptions_unknownvoltstatement_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exceptions_UnknownVoltStatement, __construct)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *file = NULL;
	zval *type_param = NULL, file_zv, *line_param = NULL, _0, _1;
	zend_long type, line, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(type)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(line)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	type_param = ZEND_CALL_ARG(execute_data, 1);
	line_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, type);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, line);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSVSV(&_2, "Unknown statement ", &_0, " in ", &file_zv, " on line ", &_1);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_view_engine_volt_exceptions_unknownvoltstatement_ce, getThis(), "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

