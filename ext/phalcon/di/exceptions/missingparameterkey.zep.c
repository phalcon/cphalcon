
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
ZEPHIR_INIT_CLASS(Phalcon_Di_Exceptions_MissingParameterKey)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Di\\Exceptions, MissingParameterKey, phalcon, di_exceptions_missingparameterkey, phalcon_di_exception_ce, phalcon_di_exceptions_missingparameterkey_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Di_Exceptions_MissingParameterKey, __construct)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *position_param = NULL, _0;
	zend_string *key = NULL;

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	position_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, position);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVSV(&_1, "Service '", &key_zv, "' is required in parameter on position ", &_0);
	ZEPHIR_CALL_PARENT(NULL, phalcon_di_exceptions_missingparameterkey_ce, getThis(), "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

