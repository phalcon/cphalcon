
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class AbstractAdapter
 *
 * @property string             $defaultFormatter
 * @property FormatterInterface $formatter
 * @property bool               $inTransaction
 * @property array              $queue
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger\\Adapter, AbstractAdapter, phalcon, logger_adapter_abstractadapter, phalcon_logger_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Name of the default formatter class
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_adapter_abstractadapter_ce, SL("defaultFormatter"), "Phalcon\\Logger\\Formatter\\Line", ZEND_ACC_PROTECTED);
	/**
	 * Formatter
	 *
	 * @var FormatterInterface|null
	 */
	zend_declare_property_null(phalcon_logger_adapter_abstractadapter_ce, SL("formatter"), ZEND_ACC_PROTECTED);
	/**
	 * Tells if there is an active transaction or not
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_logger_adapter_abstractadapter_ce, SL("inTransaction"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Array with messages queued in the transaction
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_logger_adapter_abstractadapter_ce, SL("queue"), ZEND_ACC_PROTECTED);
	/**
	 * Maximum number of items retained in the transaction queue.
	 * 0 (default) keeps the original unbounded behavior; a positive
	 * value drops the oldest queued item FIFO before a new one is
	 * appended in add().
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_adapter_abstractadapter_ce, SL("queueLimit"), 0, ZEND_ACC_PROTECTED);
	phalcon_logger_adapter_abstractadapter_ce->create_object = zephir_init_properties_Phalcon_Logger_Adapter_AbstractAdapter;

	zend_class_implements(phalcon_logger_adapter_abstractadapter_ce, 1, phalcon_logger_adapter_adapterinterface_ce);
	return SUCCESS;
}

/**
 * Destructor cleanup
 *
 * @throws TransactionAlreadyActive
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, __destruct)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_logger_exceptions_transactionalreadyactive_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 115);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Logger/Adapter/AbstractAdapter.zep", 77);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Prevent serialization
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, __serialize)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_logger_exceptions_serializationfailed_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 116);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Logger/Adapter/AbstractAdapter.zep", 88);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Prevent unserialization
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, __unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, _0;
	zval data;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_logger_exceptions_deserializationfailed_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 117);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Logger/Adapter/AbstractAdapter.zep", 96);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Adds a message to the queue
 *
 * @param Item $item
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, add)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, firstKey, _0, _2, _3, _4$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&firstKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("queueLimit"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GT_LONG(&_0, 0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3, this_ptr, ZEND_STRL("queueLimit"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LE_LONG(&_3, zephir_fast_count_int(&_2));
	}
	if (_1) {
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&firstKey, "array_key_first", NULL, 18, &_4$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&firstKey) != IS_NULL) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("queue"), &firstKey);
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_5$$4, &firstKey, PH_SEPARATE);
		}
	}
	zephir_update_property_array_append(this_ptr, SL("queue"), item);
	RETURN_THIS();
}

/**
 * Starts a transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, begin)
{
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Commits the internal transaction
 *
 * @return AdapterInterface
 * @throws TransactionNotActive
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, commit)
{
	zend_bool _4;
	zval item, queue, _0, *_1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktransaction", NULL, 118);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&queue, &_0);
	zephir_is_iterable(&queue, 0, "phalcon/Logger/Adapter/AbstractAdapter.zep", 154);
	if (Z_TYPE_P(&queue) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _1)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "process", &_2, 0, &item);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &queue, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &queue, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &queue, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &queue, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "process", &_2, 0, &item);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "resettransaction", NULL, 119);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @return FormatterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, getFormatter)
{
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("formatter"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("defaultFormatter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("formatter"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "formatter");
}

/**
 * Returns the configured transaction-queue cap (0 = unlimited)
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, getQueueLimit)
{

	RETURN_MEMBER_TYPED(getThis(), "queueLimit", IS_LONG);
}

/**
 * Returns the whether the logger is currently in an active transaction or
 * not
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, inTransaction)
{

	RETURN_MEMBER(getThis(), "inTransaction");
}

/**
 * Processes the message in the adapter
 *
 * @param Item $item
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, process)
{
}

/**
 * Rollbacks the internal transaction
 *
 * @return AdapterInterface
 * @throws TransactionNotActive
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, rollback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktransaction", NULL, 118);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "resettransaction", NULL, 119);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets the message formatter
 *
 * @param FormatterInterface $formatter
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, setFormatter)
{
	zval *formatter, formatter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&formatter_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(formatter, phalcon_logger_formatter_formatterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &formatter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("formatter"), formatter);
	RETURN_THISW();
}

/**
 * Sets the maximum number of items retained in the transaction
 * queue. 0 disables the cap (the default; preserves the original
 * unbounded behavior).
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, setQueueLimit)
{
	zval *queueLimit_param = NULL, _0;
	zend_long queueLimit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(queueLimit)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &queueLimit_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, queueLimit);
	zephir_update_property_zval(this_ptr, ZEND_STRL("queueLimit"), &_0);
	RETURN_THISW();
}

/**
 * Returns the formatted item
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, getFormattedItem)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, formatter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&formatter);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	ZEPHIR_CALL_METHOD(&formatter, this_ptr, "getformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&formatter, "format", NULL, 0, item);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks if the transaction is active
 *
 * @throws TransactionNotActive
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, checkTransaction)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_logger_exceptions_transactionnotactive_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 120);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Logger/Adapter/AbstractAdapter.zep", 255);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Resets the transaction flag and queue array
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, resetTransaction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("queue"), &_0);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Logger_Adapter_AbstractAdapter(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("queue"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

