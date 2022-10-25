
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
 * (c) Phalcon Team <team@phalcon.io>
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
 *```php
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
 * if ($status->success()) {
 *     echo "OK";
 * }
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Status) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Status, phalcon, mvc_model_query_status, phalcon_mvc_model_query_status_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_status_ce, SL("model"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_model_query_status_ce, SL("success"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_mvc_model_query_status_ce, 1, phalcon_mvc_model_query_statusinterface_ce);
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

	zephir_fetch_params_without_memory_grow(1, 1, &success_param, &model);

	success = zephir_get_boolval(success_param);
	if (!model) {
		model = &model_sub;
		model = &__$null;
	}


	if (success) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("success"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("success"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), model);

}

/**
 * Returns the messages produced because of a failed operation
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages) {

	zval model, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&model, &_0);
	if (Z_TYPE_P(&model) != IS_OBJECT) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(&model, "getmessages", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the model that executed the action
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "model");

}

/**
 * Allows to check if the executed operation was successful
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "success");

}

