
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Represents an inline asset
 *
 *```php
 * $inline = new \Phalcon\Assets\Inline("js", "alert('hello world');");
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Inline, phalcon, assets_inline, phalcon_assets_inline_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("content"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("filter"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("type"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_assets_inline_ce, 1, phalcon_assets_assetinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Assets\Inline constructor
 */
PHP_METHOD(Phalcon_Assets_Inline, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes;
	zend_bool filter;
	zval type_zv, content_zv, *filter_param = NULL, *attributes_param = NULL, __$true, __$false;
	zend_string *type = NULL, *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&content_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("content", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("filter", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("attributes", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(type)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		filter_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		attributes_param = ZEND_CALL_ARG(execute_data, 4);
	}
	ZVAL_STR(&type_zv, type);
	ZVAL_STR(&content_zv, content);
	if (!filter_param) {
		filter = 1;
	} else {
		}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 149, &type_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 150, &content_zv);
	if (filter) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 151, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 151, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 152, &attributes);
	ZEPHIR_MM_RESTORE();
}

/**
 * Gets the asset's key.
 */
PHP_METHOD(Phalcon_Assets_Inline, getAssetKey)
{
	zval key, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_VSV(&key, &_0, ":", &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sha256");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phphash", NULL, 0, &_2, &key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Inline, getContent)
{

	RETURN_MEMBER_TYPED(getThis(), "content", IS_STRING);
}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Inline, getFilter)
{

	RETURN_MEMBER(getThis(), "filter");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Inline, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_STRING);
}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Inline, setAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 152, &attributes);
	RETURN_THIS();
}

/**
 * Sets if the asset must be filtered or not
 */
PHP_METHOD(Phalcon_Assets_Inline, setFilter)
{
	zval *filter_param = NULL, __$true, __$false;
	zend_bool filter;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filter", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(filter)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &filter_param);
	if (filter) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 151, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 151, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the inline's type
 */
PHP_METHOD(Phalcon_Assets_Inline, setType)
{
	zval type_zv;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("type", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&type_zv, type);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 149, &type_zv);
	RETURN_THISW();
}

/**
 * Gets extra HTML attributes.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Inline, getAttributes)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 152, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * @param string $algorithm
 * @param string $data
 * @param bool   $binary
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.hash.php
 */
PHP_METHOD(Phalcon_Assets_Inline, phpHash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool binary;
	zval algorithm_zv, data_zv, *binary_param = NULL, _0;
	zend_string *algorithm = NULL, *data = NULL;

	ZVAL_UNDEF(&algorithm_zv);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(algorithm)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(binary)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		binary_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&algorithm_zv);
	ZVAL_STR_COPY(&algorithm_zv, algorithm);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!binary_param) {
		binary = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (binary ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("hash", NULL, 163, &algorithm_zv, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $knownString
 * @param string $userString
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.hash-equals.php
 */
PHP_METHOD(Phalcon_Assets_Inline, phpHashEquals)
{
	zval knownString_zv, userString_zv;
	zend_string *knownString = NULL, *userString = NULL;

	ZVAL_UNDEF(&knownString_zv);
	ZVAL_UNDEF(&userString_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(knownString)
		Z_PARAM_STR(userString)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&knownString_zv, knownString);
	ZVAL_STR(&userString_zv, userString);
	RETURN_BOOL(zephir_hash_equals(&knownString_zv, &userString_zv));
}

/**
 * @param string $algorithm
 * @param string $data
 * @param string $key
 * @param bool   $binary
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.hash-hmac.php
 */
PHP_METHOD(Phalcon_Assets_Inline, phpHashHmac)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool binary;
	zval algorithm_zv, data_zv, key_zv, *binary_param = NULL, _0;
	zend_string *algorithm = NULL, *data = NULL, *key = NULL;

	ZVAL_UNDEF(&algorithm_zv);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(algorithm)
		Z_PARAM_STR(data)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(binary)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 3) {
		binary_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&algorithm_zv);
	ZVAL_STR_COPY(&algorithm_zv, algorithm);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!binary_param) {
		binary = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (binary ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 164, &algorithm_zv, &data_zv, &key_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

