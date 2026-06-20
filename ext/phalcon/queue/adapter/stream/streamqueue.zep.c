
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * A named filesystem queue destination.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamQueue)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Stream, StreamQueue, phalcon, queue_adapter_stream_streamqueue, phalcon_queue_adapter_stream_streamqueue_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_stream_streamqueue_ce, SL("queueName"), "", ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_queue_adapter_stream_streamqueue_ce, 1, phalcon_contracts_queue_queue_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamQueue, __construct)
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

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamQueue, getQueueName)
{

	RETURN_MEMBER_TYPED(getThis(), "queueName", IS_STRING);
}

