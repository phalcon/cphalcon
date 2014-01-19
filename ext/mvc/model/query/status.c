/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/query/status.h"
#include "mvc/model/query/statusinterface.h"

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
 * //Check if the update was successful
 * if ($status->success() == true) {
 *   echo 'OK';
 * }
 *</code>
 */
zend_class_entry *phalcon_mvc_model_query_status_ce;

PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success);

static const zend_function_entry phalcon_mvc_model_query_status_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Query_Status, __construct, arginfo_phalcon_mvc_model_query_statusinterface___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, success, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Query\Status initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Status){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Status, mvc_model_query_status, phalcon_mvc_model_query_status_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_status_ce, SL("_success"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_status_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_query_status_ce TSRMLS_CC, 1, phalcon_mvc_model_query_statusinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query\Status
 *
 * @param boolean $success
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct){

	zval *success, *model;

	phalcon_fetch_params(0, 2, 0, &success, &model);
	
	phalcon_update_property_this(this_ptr, SL("_success"), success TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	
}

/**
 * Returns the model that executed the action
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel){


	RETURN_MEMBER(this_ptr, "_model");
}

/**
 * Returns the messages produced by a failed operation
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages){

	zval *model;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(model);
	phalcon_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (Z_TYPE_P(model) == IS_OBJECT) {
		phalcon_call_method(return_value, model, "getmessages");
		RETURN_MM();
	}
	
	RETURN_MM_EMPTY_ARRAY();
}

/**
 * Allows to check if the executed operation was successful
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success){


	RETURN_MEMBER(this_ptr, "_success");
}

