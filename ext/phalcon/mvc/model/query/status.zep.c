
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
 * $phql = "UPDATE Robots SET name = :name:, type = :type:, year = :year: WHERE id = :id:";
 *
 * $status = $app->modelsManager->executeQuery(
 *     $phql,
 *     [
 *         "id"   => 100,
 *         "name" => "Astroy Boy",
 *         "type" => "mechanical",
 *         "year" => 1959,
 *     ]
 * );
 *
 * // Check if the update was successful
 * if ($status->success() === true) {
 *     echo "OK";
 * }
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct) {

	zval *success_param = NULL, *model = NULL, model_sub, __$true, __$false, __$null;
	zend_bool success;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 1, 1, &success_param, &model);

	success = zephir_get_boolval(success_param);
	if (!model) {
		model = &model_sub;
		model = &__$null;
	}


	if (success) {
		zephir_update_property_zval(this_ptr, SL("_success"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_success"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("_model"), model);

}

/**
 * Returns the model that executed the action
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_model");

}

/**
 * Returns the messages produced because of a failed operation
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages) {

	zval model;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&model);
	zephir_read_property(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (Z_TYPE_P(&model) != IS_OBJECT) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(&model, "getmessages", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to check if the executed operation was successful
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_success");

}

