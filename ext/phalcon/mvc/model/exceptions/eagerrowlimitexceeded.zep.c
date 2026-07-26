
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Exceptions_EagerRowLimitExceeded)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Exceptions, EagerRowLimitExceeded, phalcon, mvc_model_exceptions_eagerrowlimitexceeded, phalcon_mvc_model_exception_ce, phalcon_mvc_model_exceptions_eagerrowlimitexceeded_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_Exceptions_EagerRowLimitExceeded, __construct)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long rowCount, limit, ZEPHIR_LAST_CALL_STATUS;
	zval modelName_zv, *rowCount_param = NULL, *limit_param = NULL, _0, _1;
	zend_string *modelName = NULL;

	ZVAL_UNDEF(&modelName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(modelName)
		Z_PARAM_LONG(rowCount)
		Z_PARAM_LONG(limit)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	rowCount_param = ZEND_CALL_ARG(execute_data, 2);
	limit_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&modelName_zv);
	ZVAL_STR_COPY(&modelName_zv, modelName);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, rowCount);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, limit);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSVSV(&_2, "Eager loading '", &modelName_zv, "' returned ", &_0, " rows which exceeds the limit of ", &_1);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_exceptions_eagerrowlimitexceeded_ce, getThis(), "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

