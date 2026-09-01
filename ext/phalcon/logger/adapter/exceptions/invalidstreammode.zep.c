
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
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Exceptions_InvalidStreamMode)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter\\Exceptions, InvalidStreamMode, phalcon, logger_adapter_exceptions_invalidstreammode, phalcon_logger_exception_ce, phalcon_logger_adapter_exceptions_invalidstreammode_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Logger_Adapter_Exceptions_InvalidStreamMode, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Adapter cannot be opened in read mode");
	ZEPHIR_CALL_PARENT(NULL, phalcon_logger_adapter_exceptions_invalidstreammode_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

