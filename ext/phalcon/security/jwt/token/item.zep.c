
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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
 * Class Item
 */
ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Token_Item) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Security\\JWT\\Token, Item, phalcon, security_jwt_token_item, phalcon_security_jwt_token_abstractitem_ce, phalcon_security_jwt_token_item_method_entry, 0);

	return SUCCESS;

}

/**
 * Item constructor.
 *
 * @param array  $payload
 * @param string $encoded
 */
PHP_METHOD(Phalcon_Security_JWT_Token_Item, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval encoded;
	zval *payload_param = NULL, *encoded_param = NULL, _0, _1;
	zval payload;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&encoded);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &payload_param, &encoded_param);

	ZEPHIR_OBS_COPY_OR_DUP(&payload, payload_param);
	if (UNEXPECTED(Z_TYPE_P(encoded_param) != IS_STRING && Z_TYPE_P(encoded_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoded' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoded_param) == IS_STRING)) {
		zephir_get_strval(&encoded, encoded_param);
	} else {
		ZEPHIR_INIT_VAR(&encoded);
		ZVAL_EMPTY_STRING(&encoded);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "encoded");
	zephir_update_property_array(this_ptr, SL("data"), &_0, &encoded);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "payload");
	zephir_update_property_array(this_ptr, SL("data"), &_1, &payload);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string     $name
 * @param mixed|null $defaultValue
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Security_JWT_Token_Item, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1, _2, _3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &name);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("payload"), PH_NOISY | PH_READONLY, "phalcon/Security/JWT/Token/Item.zep", 42);
	zephir_array_fetch(&_3, &_2, &name, PH_NOISY | PH_READONLY, "phalcon/Security/JWT/Token/Item.zep", 42);
	RETURN_CTOR(&_3);

}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Security_JWT_Token_Item, getPayload) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("payload"), PH_NOISY | PH_READONLY, "phalcon/Security/JWT/Token/Item.zep", 50);
	RETURN_CTORW(&_1);

}

/**
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Security_JWT_Token_Item, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("payload"), PH_READONLY, "phalcon/Security/JWT/Token/Item.zep", 60);
	RETURN_MM_BOOL(zephir_array_isset(&_1, &name));

}

