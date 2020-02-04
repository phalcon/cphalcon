
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Php) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, Php, phalcon, storage_serializer_php, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_php_method_entry, 0);

	return SUCCESS;

}

/**
 * Serializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, serialize) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	zephir_read_property(&_2, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 13, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Php, unserialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, __$false, __$null, _0, _1$$4, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isserializable", NULL, 0, data);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		zephir_update_property_zval(this_ptr, SL("data"), data);
	} else {
		if (Z_TYPE_P(data) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data for the unserializer must of type string", "phalcon/Storage/Serializer/Php.zep", 43);
			return;
		}
		ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_INIT_NVAR(&_1$$4);
		zephir_create_closure_ex(&_1$$4, NULL, phalcon_7__closure_ce, SL("__invoke"));
		ZVAL_LONG(&_2$$4, 8);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 85, &_1$$4, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3$$4, "unserialize", NULL, 15, data);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("data"), &_3$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 87);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_GLOBAL(warning).enable)) {
			zephir_update_property_zval(this_ptr, SL("data"), &__$null);
		}
	}
	ZEPHIR_MM_RESTORE();

}

