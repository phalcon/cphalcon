
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Base64) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, Base64, phalcon, storage_serializer_base64, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_base64_method_entry, 0);

	return SUCCESS;

}

/**
 * Serializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Base64, serialize) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data for the serializer must of type string", "phalcon/Storage/Serializer/Base64.zep", 25);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 185, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_Base64, unserialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data for the unserializer must of type string", "phalcon/Storage/Serializer/Base64.zep", 39);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", NULL, 182, data);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("data"), &_0);
	ZEPHIR_MM_RESTORE();

}

