
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_array.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Collection of asset objects
 *
 * @phpstan-import-type assets_asset_map from AssetsTypes
 * @phpstan-import-type assets_codes from AssetsTypes
 * @phpstan-import-type assets_attributes from AssetsTypes
 * @phpstan-import-type assets_filters from AssetsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Collection, phalcon, assets_collection, phalcon_assets_collection_method_entry, 0);

	/**
	 * @var assets_asset_map
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("assets"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Should version be determined from file modification time
	 */
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("autoVersion"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var assets_codes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("codes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var assets_filters
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("filters"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("join"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("prefix"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("targetIsLocal"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("version"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @var assets_attributes|null
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("isLocal"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("sourcePath"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("targetPath"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_assets_collection_ce, SL("targetUri"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	zend_class_implements(phalcon_assets_collection_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_assets_collection_ce, 1, zend_ce_aggregate);
	return SUCCESS;
}

/**
 * Adds an asset to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_assetinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &asset);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addasset", NULL, 372, asset);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds a CSS asset to the collection
 *
 * @param bool|null   $isLocal
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter, autoVersion;
	zval path_zv, *isLocal = NULL, isLocal_sub, *filter_param = NULL, *attributes_param = NULL, version_zv, *autoVersion_param = NULL, __$null, _0, _1, _2;
	zend_string *path = NULL, *version = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&isLocal_sub);
	ZVAL_UNDEF(&version_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(isLocal)
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		isLocal = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		filter_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		attributes_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 5) {
		autoVersion_param = ZEND_CALL_ARG(execute_data, 6);
	}
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	if (!isLocal) {
		isLocal = &isLocal_sub;
		isLocal = &__$null;
	}
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
	if (!version) {
		ZEPHIR_INIT_VAR(&version_zv);
	} else {
		zephir_memory_observe(&version_zv);
	ZVAL_STR_COPY(&version_zv, version);
	}
	if (!autoVersion_param) {
		autoVersion = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Css");
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (autoVersion) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processadd", NULL, 373, &_0, &path_zv, isLocal, &_1, &attributes, &version_zv, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a filter to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter)
{
	zval *filter, filter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(filter, phalcon_assets_filterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &filter);
	zephir_update_property_array_append(this_ptr, SL("filters"), filter);
	RETURN_THISW();
}

/**
 * Adds an inline code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInline)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(code, phalcon_assets_inline_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &code);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addasset", NULL, 372, code);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an inline CSS to the collection
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval content_zv, *filter_param = NULL, *attributes_param = NULL, _0, _1;
	zend_string *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filter_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&content_zv);
	ZVAL_STR_COPY(&content_zv, content);
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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Css");
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processaddinline", NULL, 374, &_0, &content_zv, &_1, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds an inline JavaScript to the collection
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval content_zv, *filter_param = NULL, *attributes_param = NULL, _0, _1;
	zend_string *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filter_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&content_zv);
	ZVAL_STR_COPY(&content_zv, content);
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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Js");
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processaddinline", NULL, 374, &_0, &content_zv, &_1, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a JavaScript asset to the collection
 *
 * @param bool|null   $isLocal
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter, autoVersion;
	zval path_zv, *isLocal = NULL, isLocal_sub, *filter_param = NULL, *attributes_param = NULL, version_zv, *autoVersion_param = NULL, __$null, _0, _1, _2;
	zend_string *path = NULL, *version = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&isLocal_sub);
	ZVAL_UNDEF(&version_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(isLocal)
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		isLocal = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		filter_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		attributes_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 5) {
		autoVersion_param = ZEND_CALL_ARG(execute_data, 6);
	}
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	if (!isLocal) {
		isLocal = &isLocal_sub;
		isLocal = &__$null;
	}
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
	if (!version) {
		ZEPHIR_INIT_VAR(&version_zv);
	} else {
		zephir_memory_observe(&version_zv);
	ZVAL_STR_COPY(&version_zv, version);
	}
	if (!autoVersion_param) {
		autoVersion = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Js");
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (autoVersion) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processadd", NULL, 373, &_0, &path_zv, isLocal, &_1, &attributes, &version_zv, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the count of the assets
 */
PHP_METHOD(Phalcon_Assets_Collection, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("assets", 6, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 406, PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Return the stored assets
 *
 * @return assets_asset_map
 */
PHP_METHOD(Phalcon_Assets_Collection, getAssets)
{

	RETURN_MEMBER_TYPED(getThis(), "assets", IS_ARRAY);
}

/**
 * Return the stored codes
 *
 * @return assets_codes
 */
PHP_METHOD(Phalcon_Assets_Collection, getCodes)
{

	RETURN_MEMBER_TYPED(getThis(), "codes", IS_ARRAY);
}

/**
 * Return the stored filters
 *
 * @return assets_filters
 */
PHP_METHOD(Phalcon_Assets_Collection, getFilters)
{

	RETURN_MEMBER_TYPED(getThis(), "filters", IS_ARRAY);
}

/**
 * Returns the iterator of the class
 */
PHP_METHOD(Phalcon_Assets_Collection, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("assets", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 406, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 19, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Collection, getJoin)
{

	RETURN_MEMBER(getThis(), "join");
}

/**
 * Returns the prefix
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getPrefix)
{

	RETURN_MEMBER_TYPED(getThis(), "prefix", IS_STRING);
}

/**
 * Returns the complete location where the joined/filtered collection must
 * be written
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval basePath_zv, completePath, _0, _1;
	zend_string *basePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_zv);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("targetPath", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(basePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&basePath_zv);
	ZVAL_STR_COPY(&basePath_zv, basePath);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 407, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath_zv, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "phpfileexists", NULL, 0, &completePath);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 158, &completePath);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&completePath);
}

/**
 * Returns whether the target is local or not
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetIsLocal)
{

	RETURN_MEMBER(getThis(), "targetIsLocal");
}

/**
 * Returns the version
 */
PHP_METHOD(Phalcon_Assets_Collection, getVersion)
{

	RETURN_MEMBER_TYPED(getThis(), "version", IS_STRING);
}

/**
 * Checks this the asset is added to the collection.
 *
 * ```php
 * use Phalcon\Assets\Asset;
 * use Phalcon\Assets\Collection;
 *
 * $collection = new Collection();
 *
 * $asset = new Asset("js", "js/jquery.js");
 *
 * $collection->add($asset);
 * $collection->has($asset); // true
 * ```
 */
PHP_METHOD(Phalcon_Assets_Collection, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, key, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("assets", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_assetinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &asset);
	ZEPHIR_CALL_METHOD(&key, asset, "getassetkey", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 406, PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset_value(&_0, &key));
}

/**
 * Checks if collection is using auto version
 */
PHP_METHOD(Phalcon_Assets_Collection, isAutoVersion)
{

	RETURN_MEMBER(getThis(), "autoVersion");
}

/**
 * Sets if all filtered assets in the collection must be joined in a single
 * result file
 */
PHP_METHOD(Phalcon_Assets_Collection, join)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("join", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 408, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 408, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets extra HTML attributes
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, setAttributes)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 409, &attributes);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Assets_Collection, setAutoVersion)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("autoVersion", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 410, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 410, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets an array of filters in the collection
 *
 * @param assets_filters $filters
 */
PHP_METHOD(Phalcon_Assets_Collection, setFilters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filters_param = NULL;
	zval filters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filters", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(filters, filters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &filters_param);
	zephir_get_arrval(&filters, filters_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 411, &filters);
	RETURN_THIS();
}

/**
 * Sets a common prefix for all the assets
 */
PHP_METHOD(Phalcon_Assets_Collection, setPrefix)
{
	zval prefix_zv;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&prefix_zv, prefix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 412, &prefix_zv);
	RETURN_THISW();
}

/**
 * Sets if the target local or not
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetIsLocal)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("targetIsLocal", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 413, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 413, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the version
 */
PHP_METHOD(Phalcon_Assets_Collection, setVersion)
{
	zval version_zv;
	zend_string *version = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("version", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(version)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&version_zv, version);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 414, &version_zv);
	RETURN_THISW();
}

/**
 * Adds an asset or inline-code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addAsset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, _0, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_assetinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &asset);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, asset);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_instance_of_ev(asset, phalcon_assets_asset_ce)) {
		ZEPHIR_CALL_METHOD(&_1$$4, asset, "getassetkey", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("assets"), &_1$$4, asset);
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_array_append(this_ptr, SL("codes"), asset);
	RETURN_MM_BOOL(1);
}

/**
 * Adds an inline asset
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, processAdd)
{
	zend_class_entry *_3;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter, autoVersion;
	zval className_zv, path_zv, *isLocal = NULL, isLocal_sub, *filter_param = NULL, *attributes_param = NULL, version_zv, *autoVersion_param = NULL, __$null, attrs, flag, name, _1, _2, _4, _5;
	zend_string *className = NULL, *path = NULL, *version = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&isLocal_sub);
	ZVAL_UNDEF(&version_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&flag);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isLocal", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 7)
		Z_PARAM_STR(className)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(isLocal)
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		isLocal = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		filter_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		attributes_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 6) {
		autoVersion_param = ZEND_CALL_ARG(execute_data, 7);
	}
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	if (!isLocal) {
		isLocal = &isLocal_sub;
		isLocal = &__$null;
	}
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
	if (!version) {
		ZEPHIR_INIT_VAR(&version_zv);
	} else {
		zephir_memory_observe(&version_zv);
	ZVAL_STR_COPY(&version_zv, version);
	}
	if (!autoVersion_param) {
		autoVersion = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "Phalcon\\Assets\\Asset\\", &className_zv);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_memory_observe(&flag);
	zephir_read_property_cached(&flag, this_ptr, _zephir_prop_0, 415, PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&attrs, this_ptr, "processattributes", NULL, 375, &attributes);
	zephir_check_call_status();
	if (Z_TYPE_P(isLocal) != IS_NULL) {
		ZEPHIR_INIT_NVAR(&flag);
		ZVAL_BOOL(&flag, zephir_get_boolval(isLocal));
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_fetch_safe_class(&_2, &name);
	_3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2), Z_STRLEN_P(&_2), ZEND_FETCH_CLASS_AUTO);
	if(!_3) {
		RETURN_MM_NULL();
	}
	object_init_ex(&_1, _3);
	ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_1);
	zephir_check_call_status();
	if (zephir_has_constructor(&_1)) {
		if (filter) {
			ZVAL_BOOL(&_4, 1);
		} else {
			ZVAL_BOOL(&_4, 0);
		}
		if (autoVersion) {
			ZVAL_BOOL(&_5, 1);
		} else {
			ZVAL_BOOL(&_5, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &path_zv, &flag, &_4, &attrs, &version_zv, &_5);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an inline asset
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, processAddInline)
{
	zend_class_entry *_2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval className_zv, content_zv, *filter_param = NULL, *attributes_param = NULL, asset, attrs, name, _1, _3, _4;
	zend_string *className = NULL, *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&asset);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(className)
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
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&content_zv);
	ZVAL_STR_COPY(&content_zv, content);
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
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "Phalcon\\Assets\\Inline\\", &className_zv);
	ZEPHIR_CPY_WRT(&name, &_0);
	ZEPHIR_CALL_METHOD(&attrs, this_ptr, "processattributes", NULL, 375, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&asset);
	zephir_fetch_safe_class(&_1, &name);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	if(!_2) {
		RETURN_MM_NULL();
	}
	object_init_ex(&asset, _2);
	ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&asset);
	zephir_check_call_status();
	if (zephir_has_constructor(&asset)) {
		if (filter) {
			ZVAL_BOOL(&_3, 1);
		} else {
			ZVAL_BOOL(&_3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &asset, "__construct", NULL, 0, &content_zv, &_3, &attrs);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(&_4, &asset, "getassetkey", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("codes"), &_4, &asset);
	RETURN_THIS();
}

/**
 * @param assets_attributes $attributes
 *
 * @return assets_attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, processAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL, _0, _1;
	zval attributes, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	ZEPHIR_INIT_VAR(&_0);
	if (1 != ZEPHIR_IS_EMPTY(&attributes)) {
		ZEPHIR_CPY_WRT(&_0, &attributes);
	} else {
		zephir_memory_observe(&_1);
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 409, PH_NOISY_CC);
		zephir_get_arrval(&_2, &_1);
		ZEPHIR_CPY_WRT(&_0, &_2);
	}
	RETURN_CCTOR(&_0);
}

/**
 * Gets extra HTML attributes.
 *
 * @return assets_attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, getAttributes)
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 409, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Collection, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Assets_Collection, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 161, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Assets_Collection, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Assets_Collection, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _2, _3, _4;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 162, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 162, &filename_zv, &_2, context, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Assets_Collection, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 163, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Assets_Collection, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 164, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Assets_Collection, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 165, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Assets_Collection, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 166, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Assets_Collection, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 167, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Assets_Collection, getSourcePath)
{

	RETURN_MEMBER_TYPED(getThis(), "sourcePath", IS_STRING);
}

PHP_METHOD(Phalcon_Assets_Collection, getTargetPath)
{

	RETURN_MEMBER_TYPED(getThis(), "targetPath", IS_STRING);
}

PHP_METHOD(Phalcon_Assets_Collection, getTargetUri)
{

	RETURN_MEMBER_TYPED(getThis(), "targetUri", IS_STRING);
}

/**
 * Checks if the asset is local or not
 */
PHP_METHOD(Phalcon_Assets_Collection, isLocal)
{

	RETURN_MEMBER(getThis(), "isLocal");
}

/**
 * Sets if the asset is local or external
 */
PHP_METHOD(Phalcon_Assets_Collection, setIsLocal)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isLocal", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 415, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 415, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the asset's source path
 */
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath)
{
	zval sourcePath_zv;
	zend_string *sourcePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("sourcePath", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sourcePath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&sourcePath_zv, sourcePath);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 416, &sourcePath_zv);
	RETURN_THISW();
}

/**
 * Sets the asset's target path
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath)
{
	zval targetPath_zv;
	zend_string *targetPath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("targetPath", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetPath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&targetPath_zv, targetPath);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 407, &targetPath_zv);
	RETURN_THISW();
}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri)
{
	zval targetUri_zv;
	zend_string *targetUri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("targetUri", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetUri)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&targetUri_zv, targetUri);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 417, &targetUri_zv);
	RETURN_THISW();
}

