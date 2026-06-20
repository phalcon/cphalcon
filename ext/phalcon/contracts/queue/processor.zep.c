
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

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
 * Processes a single message. The return value tells the consumer what to
 * do next: acknowledge, reject, or requeue.
 *
 * The literal constant values are kept compatible with the wider interop
 * ecosystem.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Processor)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Processor, phalcon, contracts_queue_processor, phalcon_contracts_queue_processor_method_entry);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_queue_processor_ce, SL("ACK"), "enqueue.ack");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_queue_processor_ce, SL("REJECT"), "enqueue.reject");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_queue_processor_ce, SL("REQUEUE"), "enqueue.requeue");

	return SUCCESS;
}

/**
 * Processes the message and returns one of the ACK / REJECT / REQUEUE
 * constants, or an object whose string form is one of those values.
 *
 * @return string|object
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Processor, process);
