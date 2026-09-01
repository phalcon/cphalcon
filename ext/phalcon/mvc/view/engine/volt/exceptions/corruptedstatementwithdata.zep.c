
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exceptions_CorruptedStatementWithData)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine\\Volt\\Exceptions, CorruptedStatementWithData, phalcon, mvc_view_engine_volt_exceptions_corruptedstatementwithdata, phalcon_mvc_view_engine_volt_exception_ce, phalcon_mvc_view_engine_volt_exceptions_corruptedstatementwithdata_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exceptions_CorruptedStatementWithData, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, _0;
	zval statement;

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_arrval(&statement, statement_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Corrupt statement");
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_view_engine_volt_exceptions_corruptedstatementwithdata_ce, getThis(), "__construct", NULL, 0, &_0, &statement);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

