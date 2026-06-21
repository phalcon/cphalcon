
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
 * A named queue destination shared by every transport. A queue name is the
 * only knowledge a destination carries, so the adapters need no transport
 * specific subclass.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_GenericQueue)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter, GenericQueue, phalcon, queue_adapter_genericqueue, phalcon_queue_adapter_genericqueue_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_genericqueue_ce, SL("queueName"), "", ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_queue_adapter_genericqueue_ce, 1, phalcon_contracts_queue_queue_ce);
	return SUCCESS;
}

/**
 * GenericQueue constructor.
 */
PHP_METHOD(Phalcon_Queue_Adapter_GenericQueue, __construct)
{
	zval queueName_zv;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&queueName_zv, queueName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("queueName"), &queueName_zv);
}

/**
 * Returns the queue name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_GenericQueue, getQueueName)
{

	RETURN_MEMBER_TYPED(getThis(), "queueName", IS_STRING);
}

