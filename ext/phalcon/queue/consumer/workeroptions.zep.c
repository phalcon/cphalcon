
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


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
 * Immutable lifetime bounds for a Worker. A value of 0 means "no limit".
 * The worker stops on whichever bound trips first.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_WorkerOptions)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Consumer, WorkerOptions, phalcon, queue_consumer_workeroptions, phalcon_queue_consumer_workeroptions_method_entry, 0);

	/**
	 * Seconds added to maxSeconds (randomised per worker) so a pool does not
	 * restart in lockstep.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_consumer_workeroptions_ce, SL("jitter"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Memory ceiling in megabytes.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_consumer_workeroptions_ce, SL("maxMemory"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Maximum number of messages to process.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_consumer_workeroptions_ce, SL("maxMessages"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Maximum run time in seconds.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_consumer_workeroptions_ce, SL("maxSeconds"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, __construct)
{
	zval *maxMessages_param = NULL, *maxSeconds_param = NULL, *maxMemory_param = NULL, *jitter_param = NULL, _0;
	zend_long maxMessages, maxSeconds, maxMemory, jitter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(maxMessages)
		Z_PARAM_LONG(maxSeconds)
		Z_PARAM_LONG(maxMemory)
		Z_PARAM_LONG(jitter)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 4, &maxMessages_param, &maxSeconds_param, &maxMemory_param, &jitter_param);
	if (!maxMessages_param) {
		maxMessages = 0;
	} else {
		}
	if (!maxSeconds_param) {
		maxSeconds = 0;
	} else {
		}
	if (!maxMemory_param) {
		maxMemory = 0;
	} else {
		}
	if (!jitter_param) {
		jitter = 0;
	} else {
		}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, maxMessages);
	zephir_update_property_zval(this_ptr, ZEND_STRL("maxMessages"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, maxSeconds);
	zephir_update_property_zval(this_ptr, ZEND_STRL("maxSeconds"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, maxMemory);
	zephir_update_property_zval(this_ptr, ZEND_STRL("maxMemory"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, jitter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("jitter"), &_0);
}

PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, getJitter)
{

	RETURN_MEMBER_TYPED(getThis(), "jitter", IS_LONG);
}

PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, getMaxMemory)
{

	RETURN_MEMBER_TYPED(getThis(), "maxMemory", IS_LONG);
}

PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, getMaxMessages)
{

	RETURN_MEMBER_TYPED(getThis(), "maxMessages", IS_LONG);
}

PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, getMaxSeconds)
{

	RETURN_MEMBER_TYPED(getThis(), "maxSeconds", IS_LONG);
}

