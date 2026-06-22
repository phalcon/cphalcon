
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
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */
/**
 * Thrown when the transport does not support a delivery delay.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Exceptions_DeliveryDelayNotSupportedException)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Exceptions, DeliveryDelayNotSupportedException, phalcon, queue_exceptions_deliverydelaynotsupportedexception, phalcon_queue_exceptions_exception_ce, phalcon_queue_exceptions_deliverydelaynotsupportedexception_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Exceptions_DeliveryDelayNotSupportedException, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "The transport does not support a delivery delay");
	ZEPHIR_CALL_PARENT(NULL, phalcon_queue_exceptions_deliverydelaynotsupportedexception_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

