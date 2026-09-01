
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
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_Exceptions_InvalidEventSource)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Events\\Exceptions, InvalidEventSource, phalcon, events_exceptions_invalideventsource, phalcon_events_exception_ce, phalcon_events_exceptions_invalideventsource_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Events_Exceptions_InvalidEventSource, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, sourceType_zv;
	zend_string *type = NULL, *sourceType = NULL;

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&sourceType_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_STR(sourceType)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&sourceType_zv);
	ZVAL_STR_COPY(&sourceType_zv, sourceType);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSV(&_0, "The source of ", &type_zv, " event must be an object, got ", &sourceType_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_events_exceptions_invalideventsource_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

