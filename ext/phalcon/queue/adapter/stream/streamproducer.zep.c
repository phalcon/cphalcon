
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
#include "kernel/memory.h"
#include "kernel/fcall.h"


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
 * Appends messages to a filesystem queue. The Stream transport delivers in
 * insertion order with no scheduling, so delivery delay, priority and time to
 * live are not supported (the defaults from AbstractProducer reject them).
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamProducer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Stream, StreamProducer, phalcon, queue_adapter_stream_streamproducer, phalcon_queue_adapter_abstractproducer_ce, phalcon_queue_adapter_stream_streamproducer_method_entry, 0);

	/**
	 * @var StreamContext
	 */
	zend_declare_property_null(phalcon_queue_adapter_stream_streamproducer_ce, SL("context"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamProducer, __construct)
{
	zval *context, context_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_stream_streamcontext_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &context);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), context);
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamProducer, send)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destination, destination_sub, *message, message_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(destination, phalcon_contracts_queue_destination_ce)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &destination, &message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "send to");
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_queue_adapter_queuedestinationguard_ce, "assertqueue", NULL, 0, destination, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, destination, "getqueuename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "pushmessage", NULL, 0, &_2, message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

