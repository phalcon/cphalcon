
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
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_AbstractAdapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Session\\Adapter, AbstractAdapter, phalcon, session_adapter_abstractadapter, phalcon_session_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var AdapterInterface
	 */
	zend_declare_property_null(phalcon_session_adapter_abstractadapter_ce, SL("adapter"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_session_adapter_abstractadapter_ce, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	return SUCCESS;

}

/**
 * Close
 */
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * Destroy
 */
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, destroy) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, _1, _2, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	_0 = !(ZEPHIR_IS_EMPTY(id));
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("adapter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2, &_1, "has", NULL, 0, id);
		zephir_check_call_status();
		_0 = zephir_is_true(&_2);
	}
	if (_0) {
		zephir_read_property(&_3$$3, this_ptr, SL("adapter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_3$$3, "delete", NULL, 0, id);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Garbage Collector
 */
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, gc) {

	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &maxlifetime);



	RETURN_BOOL(1);

}

/**
 * Read
 */
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, data, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	zephir_read_property(&_0, this_ptr, SL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_0, "get", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (Z_TYPE_P(&data) == IS_NULL) {
		ZVAL_STRING(&_1, "");
	} else {
		ZEPHIR_CPY_WRT(&_1, &data);
	}
	RETURN_CCTOR(&_1);

}

/**
 * Open
 */
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, open) {

	zval *savePath, savePath_sub, *sessionName, sessionName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &savePath, &sessionName);



	RETURN_BOOL(1);

}

/**
 * Write
 */
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &data);



	zephir_read_property(&_0, this_ptr, SL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "set", NULL, 0, id, data);
	zephir_check_call_status();
	RETURN_MM();

}

