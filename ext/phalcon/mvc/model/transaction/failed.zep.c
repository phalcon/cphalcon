
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Transaction\Failed
 *
 * This class will be thrown to exit a try/catch block for isolated transactions
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Failed, phalcon, mvc_model_transaction_failed, phalcon_mvc_model_transaction_exception_ce, phalcon_mvc_model_transaction_failed_method_entry, 0);

	/**
	 * @var ModelInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_transaction_failed_ce, SL("record"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Transaction\Failed constructor
 *
 * @param string message
 * @param ModelInterface|null record
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, *record = NULL, record_sub, __$null;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&record_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(record, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		record = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	if (!record) {
		record = &record_sub;
		record = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("record"), record);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_transaction_failed_ce, getThis(), "__construct", NULL, 0, &message_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns validation record messages which stop the transaction
 *
 * @return ModelInterface|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecord)
{

	RETURN_MEMBER(getThis(), "record");
}

/**
 * Returns validation record messages which stop the transaction
 *
 * @return MessageInterface[]|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages)
{
	zval record, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("record"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&record, &_0);
	if (Z_TYPE_P(&record) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(&record, "getmessages", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getmessage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

