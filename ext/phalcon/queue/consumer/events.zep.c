
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Lifecycle event names fired by the queue consumer through
 * Phalcon\Events\Manager. One public constant per event.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_Events)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Consumer, Events, phalcon, queue_consumer_events, NULL, 0);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_queue_consumer_events_ce, SL("AFTER_END"), "queue:afterEnd");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_queue_consumer_events_ce, SL("AFTER_PROCESS"), "queue:afterProcess");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_queue_consumer_events_ce, SL("AFTER_RECEIVE"), "queue:afterReceive");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_queue_consumer_events_ce, SL("BEFORE_PROCESS"), "queue:beforeProcess");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_queue_consumer_events_ce, SL("BEFORE_RECEIVE"), "queue:beforeReceive");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_queue_consumer_events_ce, SL("BEFORE_START"), "queue:beforeStart");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_queue_consumer_events_ce, SL("PROCESSOR_EXCEPTION"), "queue:processorException");

	return SUCCESS;
}

