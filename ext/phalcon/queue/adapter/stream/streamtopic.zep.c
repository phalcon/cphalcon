
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
 * A named filesystem topic destination.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamTopic)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Stream, StreamTopic, phalcon, queue_adapter_stream_streamtopic, phalcon_queue_adapter_stream_streamtopic_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_stream_streamtopic_ce, SL("topicName"), "", ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_queue_adapter_stream_streamtopic_ce, 1, phalcon_contracts_queue_topic_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamTopic, __construct)
{
	zval topicName_zv;
	zend_string *topicName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&topicName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(topicName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&topicName_zv, topicName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("topicName"), &topicName_zv);
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamTopic, getTopicName)
{

	RETURN_MEMBER_TYPED(getThis(), "topicName", IS_STRING);
}

