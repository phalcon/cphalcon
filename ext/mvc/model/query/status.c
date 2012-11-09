
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Model\Query\Status
 *
 * This class represents the status returned by a PHQL
 * statement like INSERT, UPDATE or DELETE. It offers context
 * information and the related messages produced by the
 * model which finally executes the operations when it fails
 *
 *<code>
 *$phql = "UPDATE Robots SET name = :name:, type = :type:, year = :year: WHERE id = :id:";
 *$status = $app->modelsManager->executeQuery($phql, array(
 *   'id' => 100,
 *   'name' => 'Astroy Boy',
 *   'type' => 'mechanical',
 *   'year' => 1959
 *));
 *
 *\//Check if the update was successful
 *if($status->success()==true){
 *   echo 'OK';
 *}
 *</code>
 */


/**
 * Phalcon\Mvc\Model\Query\Status initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Status){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Status, mvc_model_query_status, phalcon_mvc_model_query_status_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_status_ce, SL("_success"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_status_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query\Status
 *
 * @param boolean $success
 * @param Phalcon\Mvc\Model $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct){

	zval *success, *model;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &success, &model) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_success"), success TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_model"), model TSRMLS_CC);
	
}

/**
 * Returns the model which executed the action
 *
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel){


	RETURN_MEMBER(this_ptr, "_model");
}

/**
 * Returns the messages produced by a operation failed
 *
 * @return Phalcon\Mvc\Model\Message[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages){

	zval *model, *messages, *empty_arr;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(model);
	phalcon_read_property(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (Z_TYPE_P(model) == IS_OBJECT) {
		PHALCON_INIT_VAR(messages);
		PHALCON_CALL_METHOD(messages, model, "getmessages", PH_NO_CHECK);
	
		RETURN_CCTOR(messages);
	}
	
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	
	RETURN_CTOR(empty_arr);
}

/**
 * Allows to check if the executed operation was successful
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success){


	RETURN_MEMBER(this_ptr, "_success");
}

