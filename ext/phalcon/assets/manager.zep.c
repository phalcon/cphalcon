
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Manages collections of CSS/JavaScript assets
 *
 * @phpstan-import-type assets_asset_list from AssetsTypes
 * @phpstan-import-type assets_attributes from AssetsTypes
 * @phpstan-import-type assets_callback from AssetsTypes
 * @phpstan-import-type assets_collections from AssetsTypes
 * @phpstan-import-type assets_filters from AssetsTypes
 * @phpstan-import-type assets_options from AssetsTypes
 * @phpstan-import-type assets_parameters from AssetsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Manager)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets, Manager, phalcon, assets_manager, phalcon_di_abstractinjectionaware_ce, phalcon_assets_manager_method_entry, 0);

	/**
	 * @var assets_collections
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_manager_ce, SL("collections"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_manager_ce, SL("implicitOutput"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_manager_ce, SL("options"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_assets_manager_ce, SL("tagFactory"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Html\\TagFactory"));
	}

	return SUCCESS;
}

/**
 * Manager constructor.
 *
 * @param TagFactory $tagFactory
 * @param assets_options $options
 */
PHP_METHOD(Phalcon_Assets_Manager, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval *tagFactory, tagFactory_sub, *options_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tagFactory_sub);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tagFactory", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(tagFactory, phalcon_html_tagfactory_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &tagFactory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 434, tagFactory);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 435, &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a raw asset to the manager
 *
 * @param Asset $asset
 */
PHP_METHOD(Phalcon_Assets_Manager, addAsset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_asset_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &asset);
	ZEPHIR_CALL_METHOD_CACHED(&_0, asset, "getType", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addAssetByType", &_zephir_call_cache[1], &_0, asset);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an asset by its type
 *
 * @param string $type
 * @param Asset  $asset
 */
PHP_METHOD(Phalcon_Assets_Manager, addAssetByType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, *asset, asset_sub, collection;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&collection);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_asset_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	asset = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "checkAndCreateCollection", &_zephir_call_cache[0], &type_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "add", &_zephir_call_cache[1], asset);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds a CSS asset to the 'css' collection
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Manager, addCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool local, filter, autoVersion;
	zval path_zv, *local_param = NULL, *filter_param = NULL, *attributes_param = NULL, version_zv, *autoVersion_param = NULL, _0, _1, _2, _3, _4;
	zend_string *path = NULL, *version = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&version_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(local)
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		local_param = ZEND_CALL_ARG(execute_data, 2);
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
	if (!local_param) {
		local = 1;
	} else {
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
	object_init_ex(&_0, phalcon_assets_asset_css_ce);
	if (local) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (filter) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (autoVersion) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0], &path_zv, &_1, &_2, &attributes, &version_zv, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "css");
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addAssetByType", &_zephir_call_cache[1], &_4, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds a raw inline code to the manager
 *
 * @param Inline $code
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(code, phalcon_assets_inline_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &code);
	ZEPHIR_CALL_METHOD_CACHED(&_0, code, "getType", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addInlineCodeByType", &_zephir_call_cache[1], &_0, code);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an inline code by its type
 *
 * @param string $type
 * @param Inline $code
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCodeByType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, *code, code_sub, collection;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&collection);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_OBJECT_OF_CLASS(code, phalcon_assets_inline_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	code = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "checkAndCreateCollection", &_zephir_call_cache[0], &type_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "addInline", &_zephir_call_cache[1], code);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an inline CSS to the 'css' collection
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval content_zv, *filter_param = NULL, *attributes_param = NULL, _0, _1, _2;
	zend_string *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	object_init_ex(&_0, phalcon_assets_inline_css_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0], &content_zv, &_1, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "css");
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addInlineCodeByType", &_zephir_call_cache[1], &_2, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an inline JavaScript to the 'js' collection
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval content_zv, *filter_param = NULL, *attributes_param = NULL, _0, _1, _2;
	zend_string *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	object_init_ex(&_0, phalcon_assets_inline_js_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0], &content_zv, &_1, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "js");
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addInlineCodeByType", &_zephir_call_cache[1], &_2, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds a JavaScript asset to the 'js' collection
 *
 *```php
 * $assets->addJs("scripts/jquery.js");
 * $assets->addJs("https://jquery.my-cdn.com/jquery.js", false);
 *```
 *
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Manager, addJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool local, filter, autoVersion;
	zval path_zv, *local_param = NULL, *filter_param = NULL, *attributes_param = NULL, version_zv, *autoVersion_param = NULL, _0, _1, _2, _3, _4;
	zend_string *path = NULL, *version = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&version_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(local)
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		local_param = ZEND_CALL_ARG(execute_data, 2);
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
	if (!local_param) {
		local = 1;
	} else {
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
	object_init_ex(&_0, phalcon_assets_asset_js_ce);
	if (local) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (filter) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (autoVersion) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0], &path_zv, &_1, &_2, &attributes, &version_zv, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "js");
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "addAssetByType", &_zephir_call_cache[1], &_4, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Creates/Returns a collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, collection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "checkAndCreateCollection", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates/Returns a collection of assets by type
 *
 * The `instanceof` guard below is the validation, so the parameter stays a
 * plain array here.
 *
 * @param  array<array-key, mixed> $assets
 * @return assets_asset_list
 */
PHP_METHOD(Phalcon_Assets_Manager, collectionAssetsByType)
{
	zend_bool _4, _1$$3, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *type = NULL;
	zval *assets_param = NULL, type_zv, asset, *_0, _3, _2$$3, _6$$5;
	zval assets, filtered;

	ZVAL_UNDEF(&assets);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&asset);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(assets, assets_param)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	assets_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&assets, assets_param);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&assets, 0, "phalcon/Assets/Manager.zep", 247);
	if (Z_TYPE_P(&assets) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assets), _0)
		{
			ZEPHIR_INIT_NVAR(&asset);
			ZVAL_COPY(&asset, _0);
			_1$$3 = zephir_instance_of_ev(&asset, phalcon_assets_assetinterface_ce);
			if (_1$$3) {
				ZEPHIR_CALL_METHOD_CACHED(&_2$$3, &asset, "getType", &_zephir_call_cache[0]);
				zephir_check_call_status();
				_1$$3 = ZEPHIR_IS_IDENTICAL(&type_zv, &_2$$3);
			}
			if (_1$$3) {
				zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/Assets/Manager.zep", 243);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &assets, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &assets, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_3, &assets, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&asset, &assets, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				_5$$5 = zephir_instance_of_ev(&asset, phalcon_assets_assetinterface_ce);
				if (_5$$5) {
					ZEPHIR_CALL_METHOD_CACHED(&_6$$5, &asset, "getType", &_zephir_call_cache[5]);
					zephir_check_call_status();
					_5$$5 = ZEPHIR_IS_IDENTICAL(&type_zv, &_6$$5);
				}
				if (_5$$5) {
					zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/Assets/Manager.zep", 243);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&asset);
	RETURN_CTOR(&filtered);
}

/**
 * Returns true or false if collection exists.
 *
 * ```php
 * if ($manager->exists("jsHeader")) {
 *     // \Phalcon\Assets\Collection
 *     $collection = $manager->get("jsHeader");
 * }
 * ```
 *
 * @deprecated
 */
PHP_METHOD(Phalcon_Assets_Manager, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "has", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a collection by its id.
 *
 * ```php
 * $scripts = $assets->get("js");
 * ```
 */
PHP_METHOD(Phalcon_Assets_Manager, get)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _3, _4, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("collections", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 436, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(1 != _1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_assets_exceptions_collectionnotfound_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0], &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Assets/Manager.zep", 277);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 436, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_4);
	zephir_array_fetch(&_4, &_3, &name_zv, PH_NOISY, "phalcon/Assets/Manager.zep", 280);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_4);
}

/**
 * Returns existing collections in the manager
 *
 * @return assets_collections
 */
PHP_METHOD(Phalcon_Assets_Manager, getCollections)
{

	RETURN_MEMBER_TYPED(getThis(), "collections", IS_ARRAY);
}

/**
 * Returns the CSS collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, getCss)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "css");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "checkAndCreateCollection", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the CSS collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, getJs)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "js");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "checkAndCreateCollection", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the manager options
 *
 * @return assets_options
 */
PHP_METHOD(Phalcon_Assets_Manager, getOptions)
{

	RETURN_MEMBER_TYPED(getThis(), "options", IS_ARRAY);
}

/**
 * Returns true or false if collection exists.
 *
 * ```php
 * if ($manager->has("jsHeader")) {
 *     // \Phalcon\Assets\Collection
 *     $collection = $manager->get("jsHeader");
 * }
 * ```
 */
PHP_METHOD(Phalcon_Assets_Manager, has)
{
	zend_bool _1;
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("collections", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 436, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
}

/**
 * Traverses a collection calling the callback to generate its HTML
 */
PHP_METHOD(Phalcon_Assets_Manager, output)
{
	zend_bool filterNeeded = 0, _25, _42, _3$$3, _4$$3, _18$$16, _36$$30;
	zval output;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *type = NULL;
	zval *collection, collection_sub, type_zv, asset, assets, callback, callbackMethod, collectionSourcePath, collectionTargetPath, content, filters, html, mustFilter, options, prefixedPath, sourceBasePath, sourcePath, targetBasePath, typeCss, completeSourcePath, completeTargetPath, filteredContent, filteredJoinedContent, join, targetPath, _0, _1, _2, *_5, _6, *_7, _24, _8$$9, _11$$9, _12$$9, _9$$11, _10$$11, _13$$12, _14$$12, _15$$12, _16$$12, _17$$12, _19$$16, _20$$19, _21$$19, _22$$19, _23$$19, _26$$23, _29$$23, _30$$23, _27$$25, _28$$25, _31$$26, _32$$26, _33$$26, _34$$26, _35$$26, _37$$30, _38$$33, _39$$33, _40$$33, _41$$33, _43$$36, _45$$36, _44$$37;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&asset);
	ZVAL_UNDEF(&assets);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&callbackMethod);
	ZVAL_UNDEF(&collectionSourcePath);
	ZVAL_UNDEF(&collectionTargetPath);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&mustFilter);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&prefixedPath);
	ZVAL_UNDEF(&sourceBasePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&targetBasePath);
	ZVAL_UNDEF(&typeCss);
	ZVAL_UNDEF(&completeSourcePath);
	ZVAL_UNDEF(&completeTargetPath);
	ZVAL_UNDEF(&filteredContent);
	ZVAL_UNDEF(&filteredJoinedContent);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_23$$19);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_28$$25);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_33$$26);
	ZVAL_UNDEF(&_34$$26);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_37$$30);
	ZVAL_UNDEF(&_38$$33);
	ZVAL_UNDEF(&_39$$33);
	ZVAL_UNDEF(&_40$$33);
	ZVAL_UNDEF(&_41$$33);
	ZVAL_UNDEF(&_43$$36);
	ZVAL_UNDEF(&_45$$36);
	ZVAL_UNDEF(&_44$$37);
	ZVAL_UNDEF(&output);
	ZEND_TLS zephir_method_cache _zephir_call_cache[59];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("implicitOutput", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_assets_collection_ce)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_INIT_VAR(&completeSourcePath);
	ZVAL_STRING(&completeSourcePath, "");
	ZEPHIR_INIT_VAR(&completeTargetPath);
	ZVAL_STRING(&completeTargetPath, "");
	ZEPHIR_INIT_VAR(&filteredContent);
	ZVAL_STRING(&filteredContent, "");
	ZEPHIR_INIT_VAR(&filteredJoinedContent);
	ZVAL_STRING(&filteredJoinedContent, "");
	ZEPHIR_INIT_VAR(&join);
	ZVAL_BOOL(&join, 0);
	ZEPHIR_INIT_VAR(&targetPath);
	ZVAL_STRING(&targetPath, "");
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "css");
	if (ZEPHIR_IS_IDENTICAL(&_0, &type_zv)) {
		ZEPHIR_INIT_VAR(&callbackMethod);
		ZVAL_STRING(&callbackMethod, "cssLink");
	} else {
		ZEPHIR_INIT_NVAR(&callbackMethod);
		ZVAL_STRING(&callbackMethod, "jsLink");
	}
	ZEPHIR_INIT_VAR(&callback);
	zephir_create_array(&callback, 2, 0);
	zephir_array_fast_append(&callback, this_ptr);
	zephir_array_fast_append(&callback, &callbackMethod);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 435, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&options, &_1);
	ZEPHIR_CALL_METHOD_CACHED(&_2, collection, "getAssets", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&assets, this_ptr, "collectionAssetsByType", &_zephir_call_cache[1], &_2, &type_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&filters, collection, "getFilters", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&typeCss);
	ZVAL_STRING(&typeCss, "css");
	if (1 != ZEPHIR_IS_EMPTY(&filters)) {
		zephir_memory_observe(&sourceBasePath);
		_3$$3 = zephir_array_isset_string_fetch(&sourceBasePath, &options, SL("sourceBasePath"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_3$$3)) {
			ZEPHIR_INIT_NVAR(&sourceBasePath);
			ZVAL_STRING(&sourceBasePath, "");
		}
		zephir_memory_observe(&targetBasePath);
		_4$$3 = zephir_array_isset_string_fetch(&targetBasePath, &options, SL("targetBasePath"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_4$$3)) {
			ZEPHIR_INIT_NVAR(&targetBasePath);
			ZVAL_STRING(&targetBasePath, "");
		}
		ZEPHIR_CALL_METHOD_CACHED(&collectionSourcePath, collection, "getSourcePath", &_zephir_call_cache[3]);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&completeSourcePath, &sourceBasePath);
		if (1 != ZEPHIR_IS_EMPTY(&collectionSourcePath)) {
			zephir_concat_self(&completeSourcePath, &collectionSourcePath);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&collectionTargetPath, collection, "getTargetPath", &_zephir_call_cache[4]);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&completeTargetPath, &targetBasePath);
		if (1 != ZEPHIR_IS_EMPTY(&collectionTargetPath)) {
			zephir_concat_self(&completeTargetPath, &collectionTargetPath);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&join, this_ptr, "getJoin", &_zephir_call_cache[5], collection, &completeTargetPath);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&assets) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &assets);
		_5 = &_6;
	} else {
		_5 = &assets;
	}
	zephir_is_iterable(_5, 0, "phalcon/Assets/Manager.zep", 551);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5), _7)
		{
			ZEPHIR_INIT_NVAR(&asset);
			ZVAL_COPY(&asset, _7);
			filterNeeded = 0;
			if (1 != ZEPHIR_IS_EMPTY(&filters)) {
				ZEPHIR_CALL_METHOD_CACHED(&sourcePath, &asset, "getPath", &_zephir_call_cache[6]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_8$$9, &asset, "isLocal", &_zephir_call_cache[7]);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_8$$9)) {
					filterNeeded = 1;
					ZEPHIR_CALL_METHOD_CACHED(&sourcePath, this_ptr, "getSourcePath", &_zephir_call_cache[8], &asset, &completeSourcePath);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&targetPath, &asset, "getRealTargetPath", &_zephir_call_cache[9], &completeTargetPath);
				zephir_check_call_status();
				if (1 == ZEPHIR_IS_EMPTY(&targetPath)) {
					ZEPHIR_INIT_NVAR(&_9$$11);
					object_init_ex(&_9$$11, phalcon_assets_exceptions_invalidassettargetpath_ce);
					ZEPHIR_CALL_METHOD_CACHED(&_10$$11, &asset, "getPath", &_zephir_call_cache[10]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_9$$11, "__construct", &_zephir_call_cache[11], &_10$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$11, "phalcon/Assets/Manager.zep", 447);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (filterNeeded) {
					ZVAL_BOOL(&_12$$9, 1);
				} else {
					ZVAL_BOOL(&_12$$9, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_11$$9, this_ptr, "isFilterNeeded", &_zephir_call_cache[12], &asset, &targetPath, &sourcePath, &_12$$9);
				zephir_check_call_status();
				filterNeeded = zephir_is_true(&_11$$9);
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&_13$$12, &asset, "getRealTargetUri", &_zephir_call_cache[13]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_14$$12, &asset, "getRealSourcePath", &_zephir_call_cache[14]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&prefixedPath, this_ptr, "calculatePrefixedPath", &_zephir_call_cache[15], collection, &_13$$12, &_14$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_15$$12, &asset, "getAttributes", &_zephir_call_cache[16]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_16$$12, &asset, "isLocal", &_zephir_call_cache[17]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "doCallback", &_zephir_call_cache[18], &callback, &_15$$12, &prefixedPath, &_16$$12);
				zephir_check_call_status();
				zephir_read_property_cached(&_17$$12, this_ptr, _zephir_prop_1, 437, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_17$$12)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&output, &html);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				continue;
			}
			if (filterNeeded) {
				ZEPHIR_CALL_METHOD_CACHED(&content, &asset, "getContent", &_zephir_call_cache[19], &completeSourcePath);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&mustFilter, &asset, "getFilter", &_zephir_call_cache[20]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&filteredContent, this_ptr, "applyFilters", &_zephir_call_cache[21], &content, &filters, &mustFilter);
				zephir_check_call_status();
				if (zephir_is_true(&join)) {
					zephir_concat_self(&filteredJoinedContent, &filteredContent);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_18$$16 = zephir_is_true(&mustFilter);
					if (_18$$16) {
						ZEPHIR_CALL_METHOD_CACHED(&_19$$16, &asset, "getType", &_zephir_call_cache[22]);
						zephir_check_call_status();
						_18$$16 = !ZEPHIR_IS_IDENTICAL(&_19$$16, &typeCss);
					}
					if (_18$$16) {
						zephir_concat_self_str(&filteredJoinedContent, SL(";"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				if (!zephir_is_true(&join)) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "phpFilePutContents", &_zephir_call_cache[23], &targetPath, &filteredContent);
					zephir_check_call_status();
				}
			}
			if (!zephir_is_true(&join)) {
				ZEPHIR_CALL_METHOD_CACHED(&_20$$19, &asset, "getRealTargetUri", &_zephir_call_cache[24]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_21$$19, &asset, "getRealSourcePath", &_zephir_call_cache[25]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&prefixedPath, this_ptr, "calculatePrefixedPath", &_zephir_call_cache[26], collection, &_20$$19, &_21$$19);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_22$$19, collection, "getAttributes", &_zephir_call_cache[27]);
				zephir_check_call_status();
				ZVAL_BOOL(&_23$$19, 1);
				ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "doCallback", &_zephir_call_cache[28], &callback, &_22$$19, &prefixedPath, &_23$$19);
				zephir_check_call_status();
				zephir_read_property_cached(&_23$$19, this_ptr, _zephir_prop_1, 437, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_23$$19)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&output, &html);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "rewind", &_zephir_call_cache[29]);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "next", &_zephir_call_cache[30]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_24, _5, "valid", &_zephir_call_cache[31]);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&asset, _5, "current", &_zephir_call_cache[32]);
			zephir_check_call_status();
				filterNeeded = 0;
				if (1 != ZEPHIR_IS_EMPTY(&filters)) {
					ZEPHIR_CALL_METHOD_CACHED(&sourcePath, &asset, "getPath", &_zephir_call_cache[33]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_26$$23, &asset, "isLocal", &_zephir_call_cache[34]);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_26$$23)) {
						filterNeeded = 1;
						ZEPHIR_CALL_METHOD_CACHED(&sourcePath, this_ptr, "getSourcePath", &_zephir_call_cache[35], &asset, &completeSourcePath);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&targetPath, &asset, "getRealTargetPath", &_zephir_call_cache[36], &completeTargetPath);
					zephir_check_call_status();
					if (1 == ZEPHIR_IS_EMPTY(&targetPath)) {
						ZEPHIR_INIT_NVAR(&_27$$25);
						object_init_ex(&_27$$25, phalcon_assets_exceptions_invalidassettargetpath_ce);
						ZEPHIR_CALL_METHOD_CACHED(&_28$$25, &asset, "getPath", &_zephir_call_cache[37]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_27$$25, "__construct", &_zephir_call_cache[38], &_28$$25);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_27$$25, "phalcon/Assets/Manager.zep", 447);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (filterNeeded) {
						ZVAL_BOOL(&_30$$23, 1);
					} else {
						ZVAL_BOOL(&_30$$23, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_29$$23, this_ptr, "isFilterNeeded", &_zephir_call_cache[39], &asset, &targetPath, &sourcePath, &_30$$23);
					zephir_check_call_status();
					filterNeeded = zephir_is_true(&_29$$23);
				} else {
					ZEPHIR_CALL_METHOD_CACHED(&_31$$26, &asset, "getRealTargetUri", &_zephir_call_cache[40]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_32$$26, &asset, "getRealSourcePath", &_zephir_call_cache[41]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&prefixedPath, this_ptr, "calculatePrefixedPath", &_zephir_call_cache[42], collection, &_31$$26, &_32$$26);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_33$$26, &asset, "getAttributes", &_zephir_call_cache[43]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_34$$26, &asset, "isLocal", &_zephir_call_cache[44]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "doCallback", &_zephir_call_cache[45], &callback, &_33$$26, &prefixedPath, &_34$$26);
					zephir_check_call_status();
					zephir_read_property_cached(&_35$$26, this_ptr, _zephir_prop_1, 437, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_35$$26)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_concat_self(&output, &html);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					continue;
				}
				if (filterNeeded) {
					ZEPHIR_CALL_METHOD_CACHED(&content, &asset, "getContent", &_zephir_call_cache[46], &completeSourcePath);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&mustFilter, &asset, "getFilter", &_zephir_call_cache[47]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&filteredContent, this_ptr, "applyFilters", &_zephir_call_cache[48], &content, &filters, &mustFilter);
					zephir_check_call_status();
					if (zephir_is_true(&join)) {
						zephir_concat_self(&filteredJoinedContent, &filteredContent);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_36$$30 = zephir_is_true(&mustFilter);
						if (_36$$30) {
							ZEPHIR_CALL_METHOD_CACHED(&_37$$30, &asset, "getType", &_zephir_call_cache[49]);
							zephir_check_call_status();
							_36$$30 = !ZEPHIR_IS_IDENTICAL(&_37$$30, &typeCss);
						}
						if (_36$$30) {
							zephir_concat_self_str(&filteredJoinedContent, SL(";"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
					if (!zephir_is_true(&join)) {
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "phpFilePutContents", &_zephir_call_cache[50], &targetPath, &filteredContent);
						zephir_check_call_status();
					}
				}
				if (!zephir_is_true(&join)) {
					ZEPHIR_CALL_METHOD_CACHED(&_38$$33, &asset, "getRealTargetUri", &_zephir_call_cache[51]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_39$$33, &asset, "getRealSourcePath", &_zephir_call_cache[52]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&prefixedPath, this_ptr, "calculatePrefixedPath", &_zephir_call_cache[53], collection, &_38$$33, &_39$$33);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_40$$33, collection, "getAttributes", &_zephir_call_cache[54]);
					zephir_check_call_status();
					ZVAL_BOOL(&_41$$33, 1);
					ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "doCallback", &_zephir_call_cache[55], &callback, &_40$$33, &prefixedPath, &_41$$33);
					zephir_check_call_status();
					zephir_read_property_cached(&_41$$33, this_ptr, _zephir_prop_1, 437, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_41$$33)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_concat_self(&output, &html);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&asset);
	_42 = 1 != ZEPHIR_IS_EMPTY(&filters);
	if (_42) {
		_42 = zephir_is_true(&join);
	}
	if (_42) {
		ZEPHIR_CALL_FUNCTION(&_43$$36, "is_link", NULL, 43, &completeTargetPath);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_43$$36)) {
			ZEPHIR_INIT_VAR(&_44$$37);
			object_init_ex(&_44$$37, phalcon_assets_exceptions_invalidassettargetpath_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_44$$37, "__construct", &_zephir_call_cache[56], &completeTargetPath);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_44$$37, "phalcon/Assets/Manager.zep", 557);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "phpFilePutContents", &_zephir_call_cache[57], &completeTargetPath, &filteredJoinedContent);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_45$$36, this_ptr, "getOutput", &_zephir_call_cache[58], collection, &completeTargetPath, &callback, &output);
		zephir_check_call_status();
		zephir_get_strval(&output, &_45$$36);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&output);
}

/**
 * Prints the HTML for CSS assets
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, collection, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "getCss", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&name_zv)) {
		ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "get", &_zephir_call_cache[1], &name_zv);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "output", &_zephir_call_cache[2], &collection, &_1);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&_2);
}

/**
 * Traverses a collection and generate its HTML
 *
 * @param Collection $collection
 * @param string     $type
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInline)
{
	zend_bool _11$$3;
	zval html, joinedContent, output;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, *type, type_sub, code, codes, content, filters, join, attributes, *_0$$3, _1$$3, *_2$$3, _10$$3, _24$$3, _3$$4, _4$$4, _5$$6, _6$$6, _7$$6, _8$$6, _9$$6, _12$$7, _13$$7, _14$$9, _15$$9, _16$$9, _17$$9, _18$$9, _19$$10, _20$$10, _21$$10, _22$$10, _23$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&codes);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&joinedContent);
	ZVAL_UNDEF(&output);
	ZEND_TLS zephir_method_cache _zephir_call_cache[16];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("tagFactory", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("implicitOutput", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_assets_collection_ce)
		Z_PARAM_ZVAL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &collection, &type);
	ZEPHIR_INIT_VAR(&attributes);
	ZVAL_NULL(&attributes);
	ZEPHIR_INIT_VAR(&html);
	ZVAL_STRING(&html, "");
	ZEPHIR_INIT_VAR(&joinedContent);
	ZVAL_STRING(&joinedContent, "");
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_CALL_METHOD_CACHED(&codes, collection, "getCodes", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&filters, collection, "getFilters", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&join, collection, "getJoin", &_zephir_call_cache[2]);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&codes)) {
		if (Z_TYPE_P(&codes) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_string_to_char_array(&_1$$3, &codes);
			_0$$3 = &_1$$3;
		} else {
			_0$$3 = &codes;
		}
		zephir_is_iterable(_0$$3, 0, "phalcon/Assets/Manager.zep", 640);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&code);
				ZVAL_COPY(&code, _2$$3);
				ZEPHIR_CALL_METHOD_CACHED(&attributes, &code, "getAttributes", &_zephir_call_cache[3]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&content, &code, "getContent", &_zephir_call_cache[4]);
				zephir_check_call_status();
				ZVAL_BOOL(&_4$$4, 1);
				ZEPHIR_CALL_METHOD_CACHED(&_3$$4, this_ptr, "applyFilters", &_zephir_call_cache[5], &content, &filters, &_4$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&content, &_3$$4);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
					zephir_concat_self(&joinedContent, &content);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_read_property_cached(&_5$$6, this_ptr, _zephir_prop_0, 434, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_BOOL(&_7$$6, 1);
					ZEPHIR_CALL_METHOD_CACHED(&_6$$6, &_5$$6, "element", &_zephir_call_cache[6], type, &content, &attributes, &_7$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_8$$6);
					ZEPHIR_GET_CONSTANT(&_8$$6, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_9$$6);
					ZEPHIR_CONCAT_VV(&_9$$6, &_6$$6, &_8$$6);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&html, &_9$$6);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _0$$3, "rewind", &_zephir_call_cache[7]);
			zephir_check_call_status();
			_11$$3 = 1;
			while (1) {
				if (_11$$3) {
					_11$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _0$$3, "next", &_zephir_call_cache[8]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_10$$3, _0$$3, "valid", &_zephir_call_cache[9]);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&code, _0$$3, "current", &_zephir_call_cache[10]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&attributes, &code, "getAttributes", &_zephir_call_cache[11]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&content, &code, "getContent", &_zephir_call_cache[12]);
					zephir_check_call_status();
					ZVAL_BOOL(&_13$$7, 1);
					ZEPHIR_CALL_METHOD_CACHED(&_12$$7, this_ptr, "applyFilters", &_zephir_call_cache[13], &content, &filters, &_13$$7);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&content, &_12$$7);
					if (ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
						zephir_concat_self(&joinedContent, &content);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_read_property_cached(&_14$$9, this_ptr, _zephir_prop_0, 434, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZVAL_BOOL(&_16$$9, 1);
						ZEPHIR_CALL_METHOD_CACHED(&_15$$9, &_14$$9, "element", &_zephir_call_cache[14], type, &content, &attributes, &_16$$9);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_17$$9);
						ZEPHIR_GET_CONSTANT(&_17$$9, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_18$$9);
						ZEPHIR_CONCAT_VV(&_18$$9, &_15$$9, &_17$$9);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&html, &_18$$9);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&code);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
			zephir_read_property_cached(&_19$$10, this_ptr, _zephir_prop_0, 434, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_BOOL(&_21$$10, 1);
			ZEPHIR_CALL_METHOD_CACHED(&_20$$10, &_19$$10, "element", &_zephir_call_cache[15], type, &joinedContent, &attributes, &_21$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_22$$10);
			ZEPHIR_GET_CONSTANT(&_22$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_23$$10);
			ZEPHIR_CONCAT_VV(&_23$$10, &_20$$10, &_22$$10);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&html, &_23$$10);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_read_property_cached(&_24$$3, this_ptr, _zephir_prop_1, 437, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_24$$3)) {
			zend_print_zval(&html, 0);
		} else {
			zephir_concat_self(&output, &html);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_CTOR(&output);
}

/**
 * Prints the HTML for inline CSS
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInlineCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, collection, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "getCss", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&name_zv)) {
		ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "get", &_zephir_call_cache[1], &name_zv);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "style");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "outputInline", &_zephir_call_cache[2], &collection, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Prints the HTML for inline JS
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInlineJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, collection, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "getJs", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&name_zv)) {
		ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "get", &_zephir_call_cache[1], &name_zv);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "script");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "outputInline", &_zephir_call_cache[2], &collection, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Prints the HTML for JS assets
 */
PHP_METHOD(Phalcon_Assets_Manager, outputJs)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, collection, _0, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "getJs", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&name_zv)) {
		ZEPHIR_CALL_METHOD_CACHED(&collection, this_ptr, "get", &_zephir_call_cache[1], &name_zv);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "output", &_zephir_call_cache[2], &collection, &_1);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&_2);
}

/**
 * Sets a collection in the Assets Manager
 *
 *```php
 * $assets->set("js", $collection);
 *```
 */
PHP_METHOD(Phalcon_Assets_Manager, set)
{
	zval name_zv, *collection, collection_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&collection_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_assets_collection_ce)
	ZEND_PARSE_PARAMETERS_END();
	collection = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("collections"), &name_zv, collection);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * Sets the manager options
 *
 * @param assets_options $options
 */
PHP_METHOD(Phalcon_Assets_Manager, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 435, &options);
	RETURN_THIS();
}

/**
 * Sets if the HTML generated must be directly printed or returned
 */
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput)
{
	zval *implicitOutput_param = NULL, __$true, __$false;
	zend_bool implicitOutput;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("implicitOutput", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(implicitOutput)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &implicitOutput_param);
	if (implicitOutput) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 437, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 437, &__$false);
	}
	RETURN_THISW();
}

/**
 * Applies the collection filters to the content. Filtering only happens
 * when `$mustFilter` is true; every filter must be a `FilterInterface`
 * instance.
 *
 * The `instanceof` guard below is the validation, so the parameter stays a
 * plain array here.
 *
 * @param array<array-key, mixed> $filters
 *
 * @throws InvalidFilter
 */
PHP_METHOD(Phalcon_Assets_Manager, applyFilters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool mustFilter, _5, _1$$4, _6$$6;
	zval filters;
	zval *content_param = NULL, *filters_param = NULL, *mustFilter_param = NULL, filter, *_0, _4, _3$$4, _2$$5, _8$$6, _7$$7;
	zval content;

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&filters);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(content_param)
		ZEPHIR_Z_PARAM_ARRAY(filters, filters_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(mustFilter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &content_param, &filters_param, &mustFilter_param);
	zephir_get_strval(&content, content_param);
	zephir_get_arrval(&filters, filters_param);
	if (!mustFilter_param) {
		mustFilter = 1;
	} else {
		}
	if (mustFilter != 1) {
		RETURN_CTOR(&content);
	}
	zephir_is_iterable(&filters, 0, "phalcon/Assets/Manager.zep", 781);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _0)
		{
			ZEPHIR_INIT_NVAR(&filter);
			ZVAL_COPY(&filter, _0);
			_1$$4 = Z_TYPE_P(&filter) != IS_OBJECT;
			if (!(_1$$4)) {
				_1$$4 = !((zephir_instance_of_ev(&filter, phalcon_assets_filterinterface_ce)));
			}
			if (UNEXPECTED(_1$$4)) {
				ZEPHIR_INIT_NVAR(&_2$$5);
				object_init_ex(&_2$$5, phalcon_assets_exceptions_invalidfilter_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[0]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$5, "phalcon/Assets/Manager.zep", 771);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_3$$4, &filter, "filter", &_zephir_call_cache[1], &content);
			zephir_check_call_status();
			zephir_get_strval(&content, &_3$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &filters, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &filters, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &filters, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&filter, &filters, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				_6$$6 = Z_TYPE_P(&filter) != IS_OBJECT;
				if (!(_6$$6)) {
					_6$$6 = !((zephir_instance_of_ev(&filter, phalcon_assets_filterinterface_ce)));
				}
				if (UNEXPECTED(_6$$6)) {
					ZEPHIR_INIT_NVAR(&_7$$7);
					object_init_ex(&_7$$7, phalcon_assets_exceptions_invalidfilter_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$7, "__construct", &_zephir_call_cache[6]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$7, "phalcon/Assets/Manager.zep", 771);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_8$$6, &filter, "filter", &_zephir_call_cache[7], &content);
				zephir_check_call_status();
				zephir_get_strval(&content, &_8$$6);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&filter);
	RETURN_CTOR(&content);
}

/**
 * Calculates the prefixed path including the version
 */
PHP_METHOD(Phalcon_Assets_Manager, calculatePrefixedPath)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *path = NULL, *filePath = NULL;
	zval *collection, collection_sub, path_zv, filePath_zv, modificationTime, prefixedPath, version, _0, _1, _3, _4$$3, _5$$4;

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&filePath_zv);
	ZVAL_UNDEF(&modificationTime);
	ZVAL_UNDEF(&prefixedPath);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_assets_collection_ce)
		Z_PARAM_STR(path)
		Z_PARAM_STR(filePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	zephir_memory_observe(&filePath_zv);
	ZVAL_STR_COPY(&filePath_zv, filePath);
	ZEPHIR_CALL_METHOD_CACHED(&_0, collection, "getPrefix", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefixedPath);
	ZEPHIR_CONCAT_VV(&prefixedPath, &_0, &path_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&version, collection, "getVersion", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, collection, "isAutoVersion", &_zephir_call_cache[2]);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		ZEPHIR_CALL_METHOD_CACHED(&_3, collection, "isLocal", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_3);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&modificationTime);
		zephir_filemtime(&modificationTime, &filePath_zv);
		ZEPHIR_INIT_VAR(&_4$$3);
		if (zephir_is_true(&version)) {
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZEPHIR_CONCAT_VSV(&_4$$3, &version, ".", &modificationTime);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&_4$$3, &modificationTime);
		}
		ZEPHIR_CPY_WRT(&version, &_4$$3);
	}
	if (zephir_is_true(&version)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VSV(&_5$$4, &prefixedPath, "?ver=", &version);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&prefixedPath, &_5$$4);
	}
	RETURN_CCTOR(&prefixedPath);
}

PHP_METHOD(Phalcon_Assets_Manager, checkAndCreateCollection)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, _0, _3, _4, _2$$3;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("collections", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 436, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &type_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 != _1) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_assets_collection_ce);
		if (zephir_has_constructor(&_2$$3)) {
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0]);
			zephir_check_call_status();
		}

		zephir_update_property_array(this_ptr, SL("collections"), &type_zv, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 436, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_4);
	zephir_array_fetch(&_4, &_3, &type_zv, PH_NOISY, "phalcon/Assets/Manager.zep", 818);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_4);
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, cssLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, parameters_sub, *local_param = NULL, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_BOOL(local)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);
	if (!parameters) {
		parameters = &parameters_sub;
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	}
	if (!local_param) {
		local = 1;
	} else {
		}
	if (local) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "link");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "text/css");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "href");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "processParameters", &_zephir_call_cache[0], parameters, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * The native type stays `var`, which `assets_callback` narrows.
 *
 * @param assets_callback   $callback
 * @param assets_attributes $attributes
 */
PHP_METHOD(Phalcon_Assets_Manager, doCallback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zend_string *prefixedPath = NULL;
	zval attributes, parameters;
	zval *callback, callback_sub, *attributes_param = NULL, prefixedPath_zv, *local_param = NULL, html, _1, _0$$4;

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&prefixedPath_zv);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&parameters);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(callback)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR(prefixedPath)
		Z_PARAM_BOOL(local)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	callback = ZEND_CALL_ARG(execute_data, 1);
	attributes_param = ZEND_CALL_ARG(execute_data, 2);
	local_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_get_arrval(&attributes, attributes_param);
	zephir_memory_observe(&prefixedPath_zv);
	ZVAL_STR_COPY(&prefixedPath_zv, prefixedPath);
	if (1 != ZEPHIR_IS_EMPTY(&attributes)) {
		zephir_array_update_long(&attributes, 0, &prefixedPath_zv, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&parameters);
		zephir_create_array(&parameters, 1, 0);
		zephir_array_fast_append(&parameters, &attributes);
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_create_array(&_0$$4, 1, 0);
		zephir_array_fast_append(&_0$$4, &prefixedPath_zv);
		ZEPHIR_CPY_WRT(&parameters, &_0$$4);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, local);
	zephir_array_append(&parameters, &_1, PH_SEPARATE, "phalcon/Assets/Manager.zep", 861);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
	zephir_check_call_status();
	RETURN_CCTOR(&html);
}

/**
 * @param mixed $parameters
 * @param Collection $collection
 * @param string     $completeTargetPath
 *
 * @return bool
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, getJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *completeTargetPath = NULL;
	zval *collection, collection_sub, completeTargetPath_zv, join, _0$$4, _1$$3, _2$$5;

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&completeTargetPath_zv);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_assets_collection_ce)
		Z_PARAM_STR(completeTargetPath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&completeTargetPath_zv);
	ZVAL_STR_COPY(&completeTargetPath_zv, completeTargetPath);
	ZEPHIR_CALL_METHOD_CACHED(&join, collection, "getJoin", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
		if (1 == ZEPHIR_IS_EMPTY(&completeTargetPath_zv)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			object_init_ex(&_0$$4, phalcon_assets_exceptions_invalidtargetpath_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$4, "__construct", &_zephir_call_cache[1], &completeTargetPath_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Assets/Manager.zep", 894);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_1$$3, "is_dir", NULL, 49, &completeTargetPath_zv);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_assets_exceptions_targetpathisdirectory_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[2], &completeTargetPath_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Assets/Manager.zep", 898);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&join);
}

/**
 * @param Collection      $collection
 * @param string          $completeTargetPath
 * @param assets_callback $callback
 * @param string          $output
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Manager, getOutput)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval output;
	zval callback;
	zend_string *completeTargetPath = NULL;
	zval *collection, collection_sub, completeTargetPath_zv, *callback_param = NULL, *output_param = NULL, html, prefixedPath, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&completeTargetPath_zv);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&prefixedPath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&output);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("implicitOutput", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_assets_collection_ce)
		Z_PARAM_STR(completeTargetPath)
		ZEPHIR_Z_PARAM_ARRAY(callback, callback_param)
		Z_PARAM_ZVAL(output_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection = ZEND_CALL_ARG(execute_data, 1);
	callback_param = ZEND_CALL_ARG(execute_data, 3);
	output_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&completeTargetPath_zv);
	ZVAL_STR_COPY(&completeTargetPath_zv, completeTargetPath);
	zephir_get_arrval(&callback, callback_param);
	zephir_get_strval(&output, output_param);
	ZEPHIR_CALL_METHOD_CACHED(&_0, collection, "getTargetUri", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&prefixedPath, this_ptr, "calculatePrefixedPath", &_zephir_call_cache[1], collection, &_0, &completeTargetPath_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, collection, "getAttributes", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_2, collection, "getTargetIsLocal", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "doCallback", &_zephir_call_cache[4], &callback, &_1, &prefixedPath, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 437, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_3)) {
		zend_print_zval(&html, 0);
	} else {
		zephir_concat_self(&output, &html);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&output);
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, getSourcePath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *completeSourcePath = NULL;
	zval *asset, asset_sub, completeSourcePath_zv, sourcePath, _0$$3;

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&completeSourcePath_zv);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_asset_ce)
		Z_PARAM_STR(completeSourcePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	asset = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&completeSourcePath_zv);
	ZVAL_STR_COPY(&completeSourcePath_zv, completeSourcePath);
	ZEPHIR_CALL_METHOD_CACHED(&sourcePath, asset, "getRealSourcePath", &_zephir_call_cache[0], &completeSourcePath_zv);
	zephir_check_call_status();
	if (1 == ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_CALL_METHOD_CACHED(&sourcePath, asset, "getPath", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_assets_exceptions_invalidassetsourcepath_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[2], &sourcePath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Assets/Manager.zep", 964);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&sourcePath);
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, isFilterNeeded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filterNeeded;
	zend_string *targetPath = NULL, *sourcePath = NULL;
	zval *asset, asset_sub, targetPath_zv, sourcePath_zv, *filterNeeded_param = NULL, _0, _1$$4, _2$$3, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&targetPath_zv);
	ZVAL_UNDEF(&sourcePath_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_asset_ce)
		Z_PARAM_STR(targetPath)
		Z_PARAM_STR(sourcePath)
		Z_PARAM_BOOL(filterNeeded)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	asset = ZEND_CALL_ARG(execute_data, 1);
	filterNeeded_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&targetPath_zv);
	ZVAL_STR_COPY(&targetPath_zv, targetPath);
	zephir_memory_observe(&sourcePath_zv);
	ZVAL_STR_COPY(&sourcePath_zv, sourcePath);
	ZEPHIR_CALL_METHOD_CACHED(&_0, asset, "isLocal", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		if (ZEPHIR_IS_IDENTICAL(&targetPath_zv, &sourcePath_zv)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_assets_exceptions_assetsourcetargetcollision_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$4, "__construct", &_zephir_call_cache[1], &targetPath_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Assets/Manager.zep", 984);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "phpFileExists", &_zephir_call_cache[2], &targetPath_zv);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_2$$3)) {
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_filemtime(&_3$$5, &targetPath_zv);
			ZEPHIR_INIT_VAR(&_4$$5);
			zephir_filemtime(&_4$$5, &sourcePath_zv);
			if (!ZEPHIR_IS_IDENTICAL(&_3$$5, &_4$$5)) {
				RETURN_MM_BOOL(1);
			}
		} else {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(filterNeeded);
}

/**
 * @param bool  $local
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, jsLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *parameters = NULL, parameters_sub, *local_param = NULL, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_BOOL(local)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &parameters, &local_param);
	if (!parameters) {
		parameters = &parameters_sub;
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	}
	if (!local_param) {
		local = 1;
	} else {
		}
	if (local) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "script");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "application/javascript");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "src");
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "processParameters", &_zephir_call_cache[0], parameters, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Processes common parameters for js/css link generation
 */
PHP_METHOD(Phalcon_Assets_Manager, processParameters)
{
	zval _26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *helperClass = NULL, *type = NULL, *name = NULL;
	zend_bool local, _2, _6, _9, _4$$5, _11$$9, _14$$11;
	zval *parameters, parameters_sub, *local_param = NULL, helperClass_zv, type_zv, name_zv, helper, output, params, tag, url, _7, _24, _25, _0$$3, _1$$3, _3$$4, _5$$6, _8$$8, _10$$9, _12$$10, _13$$11, _15$$11, _16$$11, _17$$11, _18$$12, _19$$12, _20$$12, _21$$13, _22$$13, _23$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&helperClass_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_26);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("tagFactory", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_BOOL(local)
		Z_PARAM_STR(helperClass)
		Z_PARAM_STR(type)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	parameters = ZEND_CALL_ARG(execute_data, 1);
	local_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&helperClass_zv);
	ZVAL_STR_COPY(&helperClass_zv, helperClass);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CPY_WRT(&params, parameters);
	if (Z_TYPE_P(&params) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 2, 0);
		zephir_array_fast_append(&_0$$3, parameters);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_BOOL(&_1$$3, local);
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&params, &_0$$3);
	}
	_2 = zephir_array_isset_value_long(&params, 1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 == _2) {
		zephir_memory_observe(&_3$$4);
		zephir_array_fetch_long(&_3$$4, &params, 1, PH_NOISY, "phalcon/Assets/Manager.zep", 1035);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		local = zephir_get_boolval(&_3$$4);
		zephir_array_unset_long(&params, 1, PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		_4$$5 = zephir_array_isset_value_string(&params, SL("local"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (1 == _4$$5) {
			zephir_memory_observe(&_5$$6);
			zephir_array_fetch_string(&_5$$6, &params, SL("local"), PH_NOISY, "phalcon/Assets/Manager.zep", 1039);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			local = zephir_get_boolval(&_5$$6);
			zephir_array_unset_string(&params, SL("local"), PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	_6 = zephir_array_isset_value_string(&params, SL("type"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 != _6) {
		zephir_array_update_string(&params, SL("type"), &type_zv, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "link");
	if (ZEPHIR_IS_IDENTICAL(&_7, &helperClass_zv)) {
		ZEPHIR_INIT_VAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "stylesheet");
		zephir_array_update_string(&params, SL("rel"), &_8$$8, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_9 = zephir_array_isset_value(&params, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 != _9) {
		ZEPHIR_INIT_VAR(&_10$$9);
		ZVAL_STRING(&_10$$9, "");
		zephir_array_update_zval(&params, &name_zv, &_10$$9, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_11$$9 = zephir_array_isset_value_long(&params, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (1 == _11$$9) {
			zephir_memory_observe(&_12$$10);
			zephir_array_fetch_long(&_12$$10, &params, 0, PH_NOISY, "phalcon/Assets/Manager.zep", 1059);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&params, &name_zv, &_12$$10, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_unset_long(&params, 0, PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&tag);
	zephir_array_fetch(&tag, &params, &name_zv, PH_NOISY, "phalcon/Assets/Manager.zep", 1064);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_unset(&params, &name_zv, PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (local) {
		zephir_read_property_cached(&_13$$11, this_ptr, _zephir_prop_0, 438, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_14$$11 = Z_TYPE_P(&_13$$11) != IS_NULL;
		if (_14$$11) {
			zephir_read_property_cached(&_15$$11, this_ptr, _zephir_prop_0, 438, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_17$$11);
			ZVAL_STRING(&_17$$11, "url");
			ZEPHIR_CALL_METHOD_CACHED(&_16$$11, &_15$$11, "has", &_zephir_call_cache[0], &_17$$11);
			zephir_check_call_status();
			_14$$11 = zephir_is_true(&_16$$11);
		}
		if (_14$$11) {
			zephir_read_property_cached(&_18$$12, this_ptr, _zephir_prop_0, 438, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_19$$12);
			ZVAL_STRING(&_19$$12, "url");
			ZEPHIR_CALL_METHOD_CACHED(&url, &_18$$12, "get", &_zephir_call_cache[1], &_19$$12);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_20$$12, &url, "getStatic", &_zephir_call_cache[2], &tag);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&tag, &_20$$12);
		} else {
			ZEPHIR_INIT_VAR(&_21$$13);
			ZEPHIR_INIT_VAR(&_22$$13);
			ZVAL_STRING(&_22$$13, "/");
			zephir_fast_trim(&_21$$13, &tag, &_22$$13, ZEPHIR_TRIM_LEFT);
			ZEPHIR_INIT_VAR(&_23$$13);
			ZEPHIR_CONCAT_SV(&_23$$13, "/", &_21$$13);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&tag, &_23$$13);
		}
	}
	zephir_read_property_cached(&_24, this_ptr, _zephir_prop_1, 434, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&helper, &_24, "newInstance", &_zephir_call_cache[3], &helperClass_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_STRING(&_25, "");
	ZEPHIR_CALL_METHOD_CACHED(NULL, &helper, "__invoke", &_zephir_call_cache[4], &_25);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &helper, "add", &_zephir_call_cache[5], &tag, &params);
	zephir_check_call_status();
	zephir_cast_to_string(&_26, &helper);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&output, &_26);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &helper, "reset", &_zephir_call_cache[6]);
	zephir_check_call_status();
	RETURN_CCTOR(&output);
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
PHP_METHOD(Phalcon_Assets_Manager, phpFclose)
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
PHP_METHOD(Phalcon_Assets_Manager, phpFgetCsv)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 44, stream, &_0, &separator_zv, enclosure, escape);
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
PHP_METHOD(Phalcon_Assets_Manager, phpFileExists)
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
PHP_METHOD(Phalcon_Assets_Manager, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _3, _4, _5;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
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
	if (0 == (length != 0)) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_3, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_4, offset);
	ZVAL_LONG(&_5, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_3, context, &_4, &_5);
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
PHP_METHOD(Phalcon_Assets_Manager, phpFilePutContents)
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 46, &filename_zv, data, &_0, context);
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
PHP_METHOD(Phalcon_Assets_Manager, phpFopen)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 47, &filename_zv, &mode_zv, &_0, context);
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
PHP_METHOD(Phalcon_Assets_Manager, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
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
	if (0 == (length != 0)) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, 48, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is a directory
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-dir.php
 */
PHP_METHOD(Phalcon_Assets_Manager, phpIsDir)
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 49, &filename_zv);
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
PHP_METHOD(Phalcon_Assets_Manager, phpIsWritable)
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 50, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Makes a directory
 *
 * @param string        $directory
 * @param int           $permissions
 * @param bool          $recursive
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.mkdir.php
 */
PHP_METHOD(Phalcon_Assets_Manager, phpMkdir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool recursive;
	zend_long permissions, ZEPHIR_LAST_CALL_STATUS;
	zval directory_zv, *permissions_param = NULL, *recursive_param = NULL, *context = NULL, context_sub, __$null, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(directory)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(permissions)
		Z_PARAM_BOOL(recursive)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		permissions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		recursive_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	if (!permissions_param) {
		permissions = 0777;
	} else {
		}
	if (!recursive_param) {
		recursive = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, permissions);
	ZVAL_BOOL(&_1, (recursive ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 51, &directory_zv, &_0, &_1, context);
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
PHP_METHOD(Phalcon_Assets_Manager, phpUnlink)
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 52, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

