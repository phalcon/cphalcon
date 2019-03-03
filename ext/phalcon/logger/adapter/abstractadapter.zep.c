
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_AbstractAdapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger\\Adapter, AbstractAdapter, phalcon, logger_adapter_abstractadapter, phalcon_logger_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Name of the default formatter class
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_logger_adapter_abstractadapter_ce, SL("defaultFormatter"), "Line", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Formatter
	 *
	 * @var <FormatterInterface>
	 */
	zend_declare_property_null(phalcon_logger_adapter_abstractadapter_ce, SL("formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Tells if there is an active transaction or not
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_logger_adapter_abstractadapter_ce, SL("inTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Array with messages queued in the transaction
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_logger_adapter_abstractadapter_ce, SL("queue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_logger_adapter_abstractadapter_ce->create_object = zephir_init_properties_Phalcon_Logger_Adapter_AbstractAdapter;

	zend_class_implements(phalcon_logger_adapter_abstractadapter_ce TSRMLS_CC, 1, phalcon_logger_adapter_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Destructor cleanup
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, __destruct) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "commit", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a message to the queue
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, add) {

	zval *item, item_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);

	zephir_fetch_params(0, 1, 0, &item);



	zephir_update_property_array_append(this_ptr, SL("queue"), item);
	RETURN_THISW();

}

/**
 * Starts a transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, begin) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (1) {
		zephir_update_property_zval(this_ptr, SL("inTransaction"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("inTransaction"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Commits the internal transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, commit) {

	zval inTransaction, item, queue, _0, *_1, _2, _4;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inTransaction);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&inTransaction, &_0);
	zephir_read_property(&_0, this_ptr, SL("queue"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&queue, &_0);
	if (!(zephir_is_true(&inTransaction))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "There is no active transaction", "phalcon/logger/adapter/abstractadapter.zep", 92);
		return;
	}
	zephir_is_iterable(&queue, 0, "phalcon/logger/adapter/abstractadapter.zep", 103);
	if (Z_TYPE_P(&queue) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _1)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "process", &_3, 0, &item);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &queue, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &queue, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &queue, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "process", &_3, 0, &item);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &queue, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&inTransaction);
	ZVAL_BOOL(&inTransaction, 0);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval(this_ptr, SL("queue"), &_4);
	zephir_update_property_zval(this_ptr, SL("inTransaction"), &inTransaction);
	RETURN_THIS();

}

PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, getFormatter) {

	zend_class_entry *_5$$3;
	zval _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zval className;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		zephir_read_property(&_1$$3, this_ptr, SL("defaultFormatter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Phalcon\\Logger\\Formatter\\", &_1$$3);
		zephir_get_strval(&className, &_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fetch_safe_class(&_4$$3, &className);
		_5$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4$$3), Z_STRLEN_P(&_4$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_3$$3, _5$$3);
		if (zephir_has_constructor(&_3$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("formatter"), &_3$$3);
	}
	RETURN_MM_MEMBER(getThis(), "formatter");

}

/**
 * Returns the whether the logger is currently in an active transaction or not
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, inTransaction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "inTransaction");

}

/**
 * Processes the message in the adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, process) {

	zval *item, item_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);

	zephir_fetch_params(0, 1, 0, &item);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_logger_exception_ce, "This method cannot be called directly in the adapter", "phalcon/logger/adapter/abstractadapter.zep", 135);
	return;

}

/**
 * Rollbacks the internal transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, rollback) {

	zval inTransaction, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inTransaction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&inTransaction, &_0);
	if (!(zephir_is_true(&inTransaction))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "There is no active transaction", "phalcon/logger/adapter/abstractadapter.zep", 148);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("queue"), &_1);
	ZEPHIR_INIT_NVAR(&inTransaction);
	ZVAL_BOOL(&inTransaction, 0);
	zephir_update_property_zval(this_ptr, SL("inTransaction"), &inTransaction);
	RETURN_THIS();

}

/**
 * Sets the message formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, setFormatter) {

	zval *formatter, formatter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&formatter_sub);

	zephir_fetch_params(0, 1, 0, &formatter);



	zephir_update_property_zval(this_ptr, SL("formatter"), formatter);
	RETURN_THISW();

}

zend_object *zephir_init_properties_Phalcon_Logger_Adapter_AbstractAdapter(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("queue"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("queue"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

