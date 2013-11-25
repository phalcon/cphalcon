
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
* Phalcon\Queue\Beanstalk\Job
*
* Represents a job in a beanstalk queue
*/
ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk_Job) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Beanstalk, Job, phalcon, queue_beanstalk_job, phalcon_queue_beanstalk_job_method_entry, 0);

	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_body"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_queue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getId) {



}

PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getBody) {



}

/**
 * Phalcon\Queue\Beanstalk\Job
 *
 * @param Phalcon\Queue\Beanstalk queue
 * @param string id
 * @param string body
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __construct) {

	zval *queue, *id, *body;

	zephir_fetch_params(0, 3, 0, &queue, &id, &body);



	zephir_update_property_this(this_ptr, SL("_queue"), queue TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_id"), id TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_body"), body TSRMLS_CC);

}

/**
 * Removes a job from the server entirely
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, delete) {

	zval *queue, *response, *status, *_0, *_1;

	ZEPHIR_MM_GROW();

	queue = zephir_fetch_nproperty_this(this_ptr, SL("_queue"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_id"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "delete ", _0);
	zephir_call_method_p1_noret(queue, "write", _1);
	ZEPHIR_INIT_VAR(response);
	zephir_call_method(response, queue, "readstatus");
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(status, "DELETED")) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

