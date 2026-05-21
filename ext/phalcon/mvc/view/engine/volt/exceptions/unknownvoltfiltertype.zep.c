
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exceptions_UnknownVoltFilterType)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine\\Volt\\Exceptions, UnknownVoltFilterType, phalcon, mvc_view_engine_volt_exceptions_unknownvoltfiltertype, phalcon_mvc_view_engine_volt_exception_ce, phalcon_mvc_view_engine_volt_exceptions_unknownvoltfiltertype_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exceptions_UnknownVoltFilterType, __construct)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long line, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *line_param = NULL, _0;
	zend_string *file = NULL;

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(line)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	line_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, line);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVSV(&_1, "Unknown filter type in ", &file_zv, " on line ", &_0);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_view_engine_volt_exceptions_unknownvoltfiltertype_ce, getThis(), "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

