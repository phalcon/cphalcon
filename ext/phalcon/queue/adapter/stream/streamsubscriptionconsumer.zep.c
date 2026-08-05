
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
 * Consumes from several filesystem queues at once. The round-robin poll loop
 * lives in SubscriptionConsumerTrait.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Stream, StreamSubscriptionConsumer, phalcon, queue_adapter_stream_streamsubscriptionconsumer, phalcon_queue_adapter_abstractsubscriptionconsumer_ce, phalcon_queue_adapter_stream_streamsubscriptionconsumer_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_queue_adapter_stream_streamsubscriptionconsumer_ce, SL("context"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Queue\\Adapter\\Stream\\StreamContext"));
	}

	return SUCCESS;
}

/**
 * The context is retained for transports that may later need it for a
 * native multi-queue receive; the shared poll loop does not use it.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, __construct)
{
	zend_long pollInterval;
	zval *context, context_sub, *pollInterval_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("context", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("pollInterval", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_stream_streamcontext_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(pollInterval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 1, &context, &pollInterval_param);
	if (!pollInterval_param) {
		pollInterval = 200;
	} else {
		}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1281, context);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, pollInterval);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1282, &_0);
}

