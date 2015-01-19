
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


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
 *if ($status->success() == true) {
 *   echo 'OK';
 *}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Status) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Status, phalcon, mvc_model_query_status, phalcon_mvc_model_query_status_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_status_ce, SL("_success"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_query_status_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_query_status_ce TSRMLS_CC, 1, phalcon_mvc_model_query_statusinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Query\Status
 *
 * @param boolean success
 * @param Phalcon\Mvc\ModelInterface model
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct) {

	zval *success_param = NULL, *model = NULL;
	zend_bool success, _0;

	zephir_fetch_params(0, 1, 1, &success_param, &model);

	success = zephir_get_boolval(success_param);
	if (!model) {
		model = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(model) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(model, phalcon_mvc_modelinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_success"), success ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);

}

/**
 * Returns the model that executed the action
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel) {


	RETURN_MEMBER(this_ptr, "_model");

}

/**
 * Returns the messages produced because of a failed operation
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(model);
	zephir_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (Z_TYPE_P(model) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(model, "getmessages", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Allows to check if the executed operation was successful
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success) {


	RETURN_MEMBER(this_ptr, "_success");

}

