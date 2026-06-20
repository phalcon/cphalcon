
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
 * A topic destination (publish/subscribe).
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Topic)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Topic, phalcon, contracts_queue_topic, phalcon_contracts_queue_topic_method_entry);

	zend_class_implements(phalcon_contracts_queue_topic_ce, 1, phalcon_contracts_queue_destination_ce);
	return SUCCESS;
}

/**
 * Returns the topic name.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Topic, getTopicName);
