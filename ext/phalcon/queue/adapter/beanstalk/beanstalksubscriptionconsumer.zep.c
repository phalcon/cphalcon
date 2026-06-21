
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
 * Consumes from several Beanstalkd tubes at once. The round-robin poll loop
 * lives in AbstractSubscriptionConsumer.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkSubscriptionConsumer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Beanstalk, BeanstalkSubscriptionConsumer, phalcon, queue_adapter_beanstalk_beanstalksubscriptionconsumer, phalcon_queue_adapter_abstractsubscriptionconsumer_ce, phalcon_queue_adapter_beanstalk_beanstalksubscriptionconsumer_method_entry, 0);

	/**
	 * Retained for transports that may later need it for a native multi-queue
	 * receive; the shared poll loop does not use it.
	 *
	 * @var BeanstalkContext
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalksubscriptionconsumer_ce, SL("context"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkSubscriptionConsumer, __construct)
{
	zend_long pollInterval;
	zval *context, context_sub, *pollInterval_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_beanstalk_beanstalkcontext_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(pollInterval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 1, &context, &pollInterval_param);
	if (!pollInterval_param) {
		pollInterval = 200;
	} else {
		}
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), context);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, pollInterval);
	zephir_update_property_zval(this_ptr, ZEND_STRL("pollInterval"), &_0);
}

