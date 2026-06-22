
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
 * Thrown when a destination is not valid for the operation, for example a
 * Topic passed where a Queue is required. The action verb ("send to",
 * "consume from") tailors the message to the failing operation.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Exceptions_InvalidDestinationException)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Exceptions, InvalidDestinationException, phalcon, queue_exceptions_invaliddestinationexception, phalcon_queue_exceptions_exception_ce, phalcon_queue_exceptions_invaliddestinationexception_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Exceptions_InvalidDestinationException, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval action_zv;
	zend_string *action = NULL;

	ZVAL_UNDEF(&action_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(action)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&action_zv);
	ZVAL_STR_COPY(&action_zv, action);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "This transport can only ", &action_zv, " a Queue destination");
	ZEPHIR_CALL_PARENT(NULL, phalcon_queue_exceptions_invaliddestinationexception_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

