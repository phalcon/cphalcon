
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * In-process message. All behavior comes from AbstractMessage.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Memory_MemoryMessage)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Memory, MemoryMessage, phalcon, queue_adapter_memory_memorymessage, phalcon_queue_adapter_abstractmessage_ce, NULL, 0);

	return SUCCESS;
}

