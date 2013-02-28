
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\Queue\Beanstalk\Job initializer
 */
PHALCON_INIT_CLASS(Phalcon_Queue_Beanstalk_Job){

	PHALCON_REGISTER_CLASS(Phalcon\\Queue\\Beanstalk, Job, queue_beanstalk_job, phalcon_queue_beanstalk_job_method_entry, 0);

	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_queue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_queue_beanstalk_job_ce, SL("_body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Queue\Beanstalk\Job constructor
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __construct){

	zval *queue, *id, *body;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &queue, &id, &body) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_queue"), queue TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_id"), id TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_body"), body TSRMLS_CC);
	
}

/**
 * Removes a job from the server entirely
 *
 * @param integer $id
 * @return boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, delete){

	zval *id, *command, *queue, *response, *status;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(id);
	phalcon_read_property(&id, this_ptr, SL("_id"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SV(command, "delete ", id);
	
	PHALCON_OBS_VAR(queue);
	phalcon_read_property(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(queue, "write", command);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD(response, queue, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY_CC);
	if (PHALCON_IS_STRING(status, "DELETED")) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

