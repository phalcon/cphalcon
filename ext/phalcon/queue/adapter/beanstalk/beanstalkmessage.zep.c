
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
 * Beanstalkd-backed message. Carries the reserved job id so the consumer can
 * delete, release, bury or touch it; all other behavior comes from
 * MessageTrait.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkMessage)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Beanstalk, BeanstalkMessage, phalcon, queue_adapter_beanstalk_beanstalkmessage, phalcon_queue_adapter_abstractmessage_ce, phalcon_queue_adapter_beanstalk_beanstalkmessage_method_entry, 0);

	/**
	 * The reserved Beanstalkd job id, or null before it is reserved.
	 *
	 * @var string | null
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkmessage_ce, SL("jobId"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkMessage, getJobId)
{

	RETURN_MEMBER(getThis(), "jobId");
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkMessage, setJobId)
{
	zval jobId_zv;
	zend_string *jobId = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&jobId_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("jobId", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(jobId)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&jobId_zv, jobId);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1233, &jobId_zv);
}

