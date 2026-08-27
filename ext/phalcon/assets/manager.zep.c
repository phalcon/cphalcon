
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
#include "kernel/concat.h"
#include "kernel/file.h"
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 418, tagFactory);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 419, &options);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_asset_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &asset);
	ZEPHIR_CALL_METHOD(&_0, asset, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addassetbytype", NULL, 0, &_0, asset);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_asset_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	asset = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "checkandcreatecollection", NULL, 376, &type_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &collection, "add", NULL, 0, asset);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 377, &path_zv, &_1, &_2, &attributes, &version_zv, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "css");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addassetbytype", NULL, 0, &_4, &_0);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(code, phalcon_assets_inline_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &code);
	ZEPHIR_CALL_METHOD(&_0, code, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, &_0, code);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_OBJECT_OF_CLASS(code, phalcon_assets_inline_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	code = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "checkandcreatecollection", NULL, 376, &type_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &collection, "addinline", NULL, 0, code);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 378, &content_zv, &_1, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "css");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, &_2, &_0);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 379, &content_zv, &_1, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "js");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, &_2, &_0);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 380, &path_zv, &_1, &_2, &attributes, &version_zv, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "js");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addassetbytype", NULL, 0, &_4, &_0);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "checkandcreatecollection", NULL, 376, &name_zv);
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
				ZEPHIR_CALL_METHOD(&_2$$3, &asset, "gettype", NULL, 0);
				zephir_check_call_status();
				_1$$3 = ZEPHIR_IS_IDENTICAL(&type_zv, &_2$$3);
			}
			if (_1$$3) {
				zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/Assets/Manager.zep", 243);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &assets, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &assets, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &assets, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&asset, &assets, "current", NULL, 0);
			zephir_check_call_status();
				_5$$5 = zephir_instance_of_ev(&asset, phalcon_assets_assetinterface_ce);
				if (_5$$5) {
					ZEPHIR_CALL_METHOD(&_6$$5, &asset, "gettype", NULL, 0);
					zephir_check_call_status();
					_5$$5 = ZEPHIR_IS_IDENTICAL(&type_zv, &_6$$5);
				}
				if (_5$$5) {
					zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/Assets/Manager.zep", 243);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &name_zv);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _2, _3, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 420, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(1 != zephir_array_isset_value(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_assets_exceptions_collectionnotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 381, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Assets/Manager.zep", 277);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 420, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Assets/Manager.zep", 280);
	RETURN_CTOR(&_3);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "css");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "checkandcreatecollection", NULL, 376, &_0);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "js");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "checkandcreatecollection", NULL, 376, &_0);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 420, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &name_zv));
}

/**
 * Traverses a collection calling the callback to generate its HTML
 */
PHP_METHOD(Phalcon_Assets_Manager, output)
{
	zend_bool filterNeeded = 0, _29, _46, _20$$16, _40$$30;
	zval output;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_11 = NULL, *_14 = NULL, *_17 = NULL, *_19 = NULL, *_22 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *type = NULL;
	zval *collection, collection_sub, type_zv, asset, assets, callback, callbackMethod, collectionSourcePath, collectionTargetPath, completeSourcePath, completeTargetPath, content, filters, filteredContent, filteredJoinedContent, html, join, mustFilter, options, prefixedPath, sourceBasePath, sourcePath, targetBasePath, targetPath, typeCss, _0, _1, _2, *_3, _28, _4$$9, _9$$9, _10$$9, _6$$11, _7$$11, _12$$12, _13$$12, _15$$12, _16$$12, _18$$12, _21$$16, _23$$19, _24$$19, _25$$19, _27$$19, _30$$23, _33$$23, _34$$23, _31$$25, _32$$25, _35$$26, _36$$26, _37$$26, _38$$26, _39$$26, _41$$30, _42$$33, _43$$33, _44$$33, _45$$33, _47$$36, _49$$36, _48$$37;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&asset);
	ZVAL_UNDEF(&assets);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&callbackMethod);
	ZVAL_UNDEF(&collectionSourcePath);
	ZVAL_UNDEF(&collectionTargetPath);
	ZVAL_UNDEF(&completeSourcePath);
	ZVAL_UNDEF(&completeTargetPath);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&filteredContent);
	ZVAL_UNDEF(&filteredJoinedContent);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&mustFilter);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&prefixedPath);
	ZVAL_UNDEF(&sourceBasePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&targetBasePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&typeCss);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_23$$19);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_41$$30);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$33);
	ZVAL_UNDEF(&_44$$33);
	ZVAL_UNDEF(&_45$$33);
	ZVAL_UNDEF(&_47$$36);
	ZVAL_UNDEF(&_49$$36);
	ZVAL_UNDEF(&_48$$37);
	ZVAL_UNDEF(&output);
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
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 419, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	if (ZEPHIR_IS_IDENTICAL(&_1, &type_zv)) {
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
	ZEPHIR_CALL_METHOD(&_2, collection, "getassets", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&assets, this_ptr, "collectionassetsbytype", NULL, 0, &_2, &type_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&filters, collection, "getfilters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&typeCss);
	ZVAL_STRING(&typeCss, "css");
	if (1 != ZEPHIR_IS_EMPTY(&filters)) {
		zephir_memory_observe(&sourceBasePath);
		if (!(zephir_array_isset_string_fetch(&sourceBasePath, &options, SL("sourceBasePath"), 0))) {
			ZEPHIR_INIT_NVAR(&sourceBasePath);
			ZVAL_STRING(&sourceBasePath, "");
		}
		zephir_memory_observe(&targetBasePath);
		if (!(zephir_array_isset_string_fetch(&targetBasePath, &options, SL("targetBasePath"), 0))) {
			ZEPHIR_INIT_NVAR(&targetBasePath);
			ZVAL_STRING(&targetBasePath, "");
		}
		ZEPHIR_CALL_METHOD(&collectionSourcePath, collection, "getsourcepath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&completeSourcePath, &sourceBasePath);
		if (1 != ZEPHIR_IS_EMPTY(&collectionSourcePath)) {
			zephir_concat_self(&completeSourcePath, &collectionSourcePath);
		}
		ZEPHIR_CALL_METHOD(&collectionTargetPath, collection, "gettargetpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&completeTargetPath, &targetBasePath);
		if (1 != ZEPHIR_IS_EMPTY(&collectionTargetPath)) {
			zephir_concat_self(&completeTargetPath, &collectionTargetPath);
		}
		ZEPHIR_CALL_METHOD(&join, this_ptr, "getjoin", NULL, 382, collection, &completeTargetPath);
		zephir_check_call_status();
	}
	zephir_is_iterable(&assets, 0, "phalcon/Assets/Manager.zep", 553);
	if (Z_TYPE_P(&assets) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assets), _3)
		{
			ZEPHIR_INIT_NVAR(&asset);
			ZVAL_COPY(&asset, _3);
			filterNeeded = 0;
			if (1 != ZEPHIR_IS_EMPTY(&filters)) {
				ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$9, &asset, "islocal", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_4$$9)) {
					filterNeeded = 1;
					ZEPHIR_CALL_METHOD(&sourcePath, this_ptr, "getsourcepath", &_5, 383, &asset, &completeSourcePath);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&targetPath, &asset, "getrealtargetpath", NULL, 0, &completeTargetPath);
				zephir_check_call_status();
				if (1 == ZEPHIR_IS_EMPTY(&targetPath)) {
					ZEPHIR_INIT_NVAR(&_6$$11);
					object_init_ex(&_6$$11, phalcon_assets_exceptions_invalidassettargetpath_ce);
					ZEPHIR_CALL_METHOD(&_7$$11, &asset, "getpath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_6$$11, "__construct", &_8, 384, &_7$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$11, "phalcon/Assets/Manager.zep", 449);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (filterNeeded) {
					ZVAL_BOOL(&_10$$9, 1);
				} else {
					ZVAL_BOOL(&_10$$9, 0);
				}
				ZEPHIR_CALL_METHOD(&_9$$9, this_ptr, "isfilterneeded", &_11, 385, &asset, &targetPath, &sourcePath, &_10$$9);
				zephir_check_call_status();
				filterNeeded = zephir_is_true(&_9$$9);
			} else {
				ZEPHIR_CALL_METHOD(&_12$$12, &asset, "getrealtargeturi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_13$$12, &asset, "getrealsourcepath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_14, 386, collection, &_12$$12, &_13$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_15$$12, &asset, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_16$$12, &asset, "islocal", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_17, 387, &callback, &_15$$12, &prefixedPath, &_16$$12);
				zephir_check_call_status();
				zephir_read_property_cached(&_18$$12, this_ptr, _zephir_prop_1, 421, PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_18$$12)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&output, &html);
				}
				continue;
			}
			if (filterNeeded) {
				ZEPHIR_CALL_METHOD(&content, &asset, "getcontent", NULL, 0, &completeSourcePath);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&mustFilter, &asset, "getfilter", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&filteredContent, this_ptr, "applyfilters", &_19, 388, &content, &filters, &mustFilter);
				zephir_check_call_status();
				if (zephir_is_true(&join)) {
					zephir_concat_self(&filteredJoinedContent, &filteredContent);
					_20$$16 = zephir_is_true(&mustFilter);
					if (_20$$16) {
						ZEPHIR_CALL_METHOD(&_21$$16, &asset, "gettype", NULL, 0);
						zephir_check_call_status();
						_20$$16 = !ZEPHIR_IS_IDENTICAL(&_21$$16, &typeCss);
					}
					if (_20$$16) {
						zephir_concat_self_str(&filteredJoinedContent, SL(";"));
					}
				}
				if (!zephir_is_true(&join)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfileputcontents", &_22, 0, &targetPath, &filteredContent);
					zephir_check_call_status();
				}
			}
			if (!zephir_is_true(&join)) {
				ZEPHIR_CALL_METHOD(&_23$$19, &asset, "getrealtargeturi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_24$$19, &asset, "getrealsourcepath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_14, 386, collection, &_23$$19, &_24$$19);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25$$19, collection, "getattributes", &_26, 0);
				zephir_check_call_status();
				ZVAL_BOOL(&_27$$19, 1);
				ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_17, 387, &callback, &_25$$19, &prefixedPath, &_27$$19);
				zephir_check_call_status();
				zephir_read_property_cached(&_27$$19, this_ptr, _zephir_prop_1, 421, PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_27$$19)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&output, &html);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &assets, "rewind", NULL, 0);
		zephir_check_call_status();
		_29 = 1;
		while (1) {
			if (_29) {
				_29 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &assets, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_28, &assets, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_28)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&asset, &assets, "current", NULL, 0);
			zephir_check_call_status();
				filterNeeded = 0;
				if (1 != ZEPHIR_IS_EMPTY(&filters)) {
					ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_30$$23, &asset, "islocal", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_30$$23)) {
						filterNeeded = 1;
						ZEPHIR_CALL_METHOD(&sourcePath, this_ptr, "getsourcepath", &_5, 383, &asset, &completeSourcePath);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&targetPath, &asset, "getrealtargetpath", NULL, 0, &completeTargetPath);
					zephir_check_call_status();
					if (1 == ZEPHIR_IS_EMPTY(&targetPath)) {
						ZEPHIR_INIT_NVAR(&_31$$25);
						object_init_ex(&_31$$25, phalcon_assets_exceptions_invalidassettargetpath_ce);
						ZEPHIR_CALL_METHOD(&_32$$25, &asset, "getpath", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_31$$25, "__construct", &_8, 384, &_32$$25);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_31$$25, "phalcon/Assets/Manager.zep", 449);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (filterNeeded) {
						ZVAL_BOOL(&_34$$23, 1);
					} else {
						ZVAL_BOOL(&_34$$23, 0);
					}
					ZEPHIR_CALL_METHOD(&_33$$23, this_ptr, "isfilterneeded", &_11, 385, &asset, &targetPath, &sourcePath, &_34$$23);
					zephir_check_call_status();
					filterNeeded = zephir_is_true(&_33$$23);
				} else {
					ZEPHIR_CALL_METHOD(&_35$$26, &asset, "getrealtargeturi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_36$$26, &asset, "getrealsourcepath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_14, 386, collection, &_35$$26, &_36$$26);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_37$$26, &asset, "getattributes", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_38$$26, &asset, "islocal", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_17, 387, &callback, &_37$$26, &prefixedPath, &_38$$26);
					zephir_check_call_status();
					zephir_read_property_cached(&_39$$26, this_ptr, _zephir_prop_1, 421, PH_NOISY_CC | PH_READONLY);
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_39$$26)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_concat_self(&output, &html);
					}
					continue;
				}
				if (filterNeeded) {
					ZEPHIR_CALL_METHOD(&content, &asset, "getcontent", NULL, 0, &completeSourcePath);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mustFilter, &asset, "getfilter", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&filteredContent, this_ptr, "applyfilters", &_19, 388, &content, &filters, &mustFilter);
					zephir_check_call_status();
					if (zephir_is_true(&join)) {
						zephir_concat_self(&filteredJoinedContent, &filteredContent);
						_40$$30 = zephir_is_true(&mustFilter);
						if (_40$$30) {
							ZEPHIR_CALL_METHOD(&_41$$30, &asset, "gettype", NULL, 0);
							zephir_check_call_status();
							_40$$30 = !ZEPHIR_IS_IDENTICAL(&_41$$30, &typeCss);
						}
						if (_40$$30) {
							zephir_concat_self_str(&filteredJoinedContent, SL(";"));
						}
					}
					if (!zephir_is_true(&join)) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfileputcontents", &_22, 0, &targetPath, &filteredContent);
						zephir_check_call_status();
					}
				}
				if (!zephir_is_true(&join)) {
					ZEPHIR_CALL_METHOD(&_42$$33, &asset, "getrealtargeturi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_43$$33, &asset, "getrealsourcepath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_14, 386, collection, &_42$$33, &_43$$33);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_44$$33, collection, "getattributes", &_26, 0);
					zephir_check_call_status();
					ZVAL_BOOL(&_45$$33, 1);
					ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_17, 387, &callback, &_44$$33, &prefixedPath, &_45$$33);
					zephir_check_call_status();
					zephir_read_property_cached(&_45$$33, this_ptr, _zephir_prop_1, 421, PH_NOISY_CC | PH_READONLY);
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_45$$33)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_concat_self(&output, &html);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&asset);
	_46 = 1 != ZEPHIR_IS_EMPTY(&filters);
	if (_46) {
		_46 = zephir_is_true(&join);
	}
	if (_46) {
		ZEPHIR_CALL_FUNCTION(&_47$$36, "is_link", NULL, 159, &completeTargetPath);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_47$$36)) {
			ZEPHIR_INIT_VAR(&_48$$37);
			object_init_ex(&_48$$37, phalcon_assets_exceptions_invalidassettargetpath_ce);
			ZEPHIR_CALL_METHOD(NULL, &_48$$37, "__construct", &_8, 384, &completeTargetPath);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_48$$37, "phalcon/Assets/Manager.zep", 559);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfileputcontents", &_22, 0, &completeTargetPath, &filteredJoinedContent);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_49$$36, this_ptr, "getoutput", NULL, 389, collection, &completeTargetPath, &callback, &output);
		zephir_check_call_status();
		zephir_get_strval(&output, &_49$$36);
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
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "getcss", NULL, 0);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&name_zv)) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, &name_zv);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "output", NULL, 0, &collection, &_1);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_0);
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
	zend_bool _10$$3;
	zval html, joinedContent, output;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, *type, type_sub, attributes, code, codes, content, filters, join, *_0$$3, _9$$3, _23$$3, _1$$4, _2$$4, _4$$6, _5$$6, _6$$6, _7$$6, _8$$6, _11$$7, _12$$7, _13$$9, _14$$9, _15$$9, _16$$9, _17$$9, _18$$10, _19$$10, _20$$10, _21$$10, _22$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&codes);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&joinedContent);
	ZVAL_UNDEF(&output);
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
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&html);
	ZVAL_STRING(&html, "");
	ZEPHIR_INIT_VAR(&joinedContent);
	ZVAL_STRING(&joinedContent, "");
	ZEPHIR_CALL_METHOD(&codes, collection, "getcodes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&filters, collection, "getfilters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&join, collection, "getjoin", NULL, 0);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&codes)) {
		zephir_is_iterable(&codes, 0, "phalcon/Assets/Manager.zep", 642);
		if (Z_TYPE_P(&codes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&codes), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&code);
				ZVAL_COPY(&code, _0$$3);
				ZEPHIR_CALL_METHOD(&attributes, &code, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&content, &code, "getcontent", NULL, 0);
				zephir_check_call_status();
				ZVAL_BOOL(&_2$$4, 1);
				ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "applyfilters", &_3, 388, &content, &filters, &_2$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&content, &_1$$4);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
					zephir_concat_self(&joinedContent, &content);
				} else {
					zephir_read_property_cached(&_4$$6, this_ptr, _zephir_prop_0, 418, PH_NOISY_CC | PH_READONLY);
					ZVAL_BOOL(&_6$$6, 1);
					ZEPHIR_CALL_METHOD(&_5$$6, &_4$$6, "element", NULL, 0, type, &content, &attributes, &_6$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_7$$6);
					ZEPHIR_GET_CONSTANT(&_7$$6, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_8$$6);
					ZEPHIR_CONCAT_VV(&_8$$6, &_5$$6, &_7$$6);
					zephir_concat_self(&html, &_8$$6);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &codes, "rewind", NULL, 0);
			zephir_check_call_status();
			_10$$3 = 1;
			while (1) {
				if (_10$$3) {
					_10$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &codes, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_9$$3, &codes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&code, &codes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attributes, &code, "getattributes", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&content, &code, "getcontent", NULL, 0);
					zephir_check_call_status();
					ZVAL_BOOL(&_12$$7, 1);
					ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "applyfilters", &_3, 388, &content, &filters, &_12$$7);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&content, &_11$$7);
					if (ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
						zephir_concat_self(&joinedContent, &content);
					} else {
						zephir_read_property_cached(&_13$$9, this_ptr, _zephir_prop_0, 418, PH_NOISY_CC | PH_READONLY);
						ZVAL_BOOL(&_15$$9, 1);
						ZEPHIR_CALL_METHOD(&_14$$9, &_13$$9, "element", NULL, 0, type, &content, &attributes, &_15$$9);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_16$$9);
						ZEPHIR_GET_CONSTANT(&_16$$9, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_17$$9);
						ZEPHIR_CONCAT_VV(&_17$$9, &_14$$9, &_16$$9);
						zephir_concat_self(&html, &_17$$9);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&code);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
			zephir_read_property_cached(&_18$$10, this_ptr, _zephir_prop_0, 418, PH_NOISY_CC | PH_READONLY);
			ZVAL_BOOL(&_20$$10, 1);
			ZEPHIR_CALL_METHOD(&_19$$10, &_18$$10, "element", NULL, 0, type, &joinedContent, &attributes, &_20$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_21$$10);
			ZEPHIR_GET_CONSTANT(&_21$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_22$$10);
			ZEPHIR_CONCAT_VV(&_22$$10, &_19$$10, &_21$$10);
			zephir_concat_self(&html, &_22$$10);
		}
		zephir_read_property_cached(&_23$$3, this_ptr, _zephir_prop_1, 421, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_23$$3)) {
			zend_print_zval(&html, 0);
		} else {
			zephir_concat_self(&output, &html);
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
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "getcss", NULL, 0);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&name_zv)) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, &name_zv);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "style");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "outputinline", NULL, 0, &collection, &_0);
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
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "getjs", NULL, 0);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&name_zv)) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, &name_zv);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "script");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "outputinline", NULL, 0, &collection, &_0);
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
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "getjs", NULL, 0);
	zephir_check_call_status();
	if (1 != ZEPHIR_IS_EMPTY(&name_zv)) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, &name_zv);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "output", NULL, 0, &collection, &_1);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_0);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 419, &options);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 421, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 421, &__$false);
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
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool mustFilter, _6, _1$$4, _7$$6;
	zval filters;
	zval *content_param = NULL, *filters_param = NULL, *mustFilter_param = NULL, filter, *_0, _5, _4$$4, _2$$5, _9$$6, _8$$7;
	zval content;

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&filters);
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
	zephir_is_iterable(&filters, 0, "phalcon/Assets/Manager.zep", 783);
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
				ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", &_3, 390);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$5, "phalcon/Assets/Manager.zep", 773);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_4$$4, &filter, "filter", NULL, 0, &content);
			zephir_check_call_status();
			zephir_get_strval(&content, &_4$$4);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &filters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&filter, &filters, "current", NULL, 0);
			zephir_check_call_status();
				_7$$6 = Z_TYPE_P(&filter) != IS_OBJECT;
				if (!(_7$$6)) {
					_7$$6 = !((zephir_instance_of_ev(&filter, phalcon_assets_filterinterface_ce)));
				}
				if (UNEXPECTED(_7$$6)) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					object_init_ex(&_8$$7, phalcon_assets_exceptions_invalidfilter_ce);
					ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", &_3, 390);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$7, "phalcon/Assets/Manager.zep", 773);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_9$$6, &filter, "filter", NULL, 0, &content);
				zephir_check_call_status();
				zephir_get_strval(&content, &_9$$6);
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
	ZEPHIR_CALL_METHOD(&_0, collection, "getprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefixedPath);
	ZEPHIR_CONCAT_VV(&prefixedPath, &_0, &path_zv);
	ZEPHIR_CALL_METHOD(&version, collection, "getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, collection, "isautoversion", NULL, 0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3, collection, "islocal", NULL, 0);
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
		} else {
			ZEPHIR_CPY_WRT(&_4$$3, &modificationTime);
		}
		ZEPHIR_CPY_WRT(&version, &_4$$3);
	}
	if (zephir_is_true(&version)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VSV(&_5$$4, &prefixedPath, "?ver=", &version);
		ZEPHIR_CPY_WRT(&prefixedPath, &_5$$4);
	}
	RETURN_CCTOR(&prefixedPath);
}

PHP_METHOD(Phalcon_Assets_Manager, checkAndCreateCollection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, _0, _2, _3, _1$$3;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 420, PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset_value(&_0, &type_zv)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_assets_collection_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		zephir_update_property_array(this_ptr, SL("collections"), &type_zv, &_1$$3);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 420, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &type_zv, PH_NOISY | PH_READONLY, "phalcon/Assets/Manager.zep", 820);
	RETURN_CTOR(&_3);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processparameters", NULL, 391, parameters, &_0, &_1, &_2, &_3);
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
	zephir_array_append(&parameters, &_1, PH_SEPARATE, "phalcon/Assets/Manager.zep", 863);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_assets_collection_ce)
		Z_PARAM_STR(completeTargetPath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&completeTargetPath_zv);
	ZVAL_STR_COPY(&completeTargetPath_zv, completeTargetPath);
	ZEPHIR_CALL_METHOD(&join, collection, "getjoin", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
		if (1 == ZEPHIR_IS_EMPTY(&completeTargetPath_zv)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			object_init_ex(&_0$$4, phalcon_assets_exceptions_invalidtargetpath_ce);
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 392, &completeTargetPath_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$4, "phalcon/Assets/Manager.zep", 896);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_1$$3, "is_dir", NULL, 305, &completeTargetPath_zv);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_assets_exceptions_targetpathisdirectory_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 393, &completeTargetPath_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Assets/Manager.zep", 900);
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
	ZEPHIR_CALL_METHOD(&_0, collection, "gettargeturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", NULL, 386, collection, &_0, &completeTargetPath_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, collection, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, collection, "gettargetislocal", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", NULL, 387, &callback, &_1, &prefixedPath, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 421, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_3)) {
		zend_print_zval(&html, 0);
	} else {
		zephir_concat_self(&output, &html);
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_asset_ce)
		Z_PARAM_STR(completeSourcePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	asset = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&completeSourcePath_zv);
	ZVAL_STR_COPY(&completeSourcePath_zv, completeSourcePath);
	ZEPHIR_CALL_METHOD(&sourcePath, asset, "getrealsourcepath", NULL, 0, &completeSourcePath_zv);
	zephir_check_call_status();
	if (1 == ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_CALL_METHOD(&sourcePath, asset, "getpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_assets_exceptions_invalidassetsourcepath_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 394, &sourcePath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Assets/Manager.zep", 966);
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
	ZEPHIR_CALL_METHOD(&_0, asset, "islocal", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		if (ZEPHIR_IS_IDENTICAL(&targetPath_zv, &sourcePath_zv)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_assets_exceptions_assetsourcetargetcollision_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 395, &targetPath_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Assets/Manager.zep", 986);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "phpfileexists", NULL, 0, &targetPath_zv);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processparameters", NULL, 391, parameters, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Processes common parameters for js/css link generation
 */
PHP_METHOD(Phalcon_Assets_Manager, processParameters)
{
	zval _21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *helperClass = NULL, *type = NULL, *name = NULL;
	zend_bool local, _9$$11;
	zval *parameters, parameters_sub, *local_param = NULL, helperClass_zv, type_zv, name_zv, helper, output, params, tag, url, _4, _19, _20, _0$$3, _1$$3, _2$$4, _3$$6, _5$$8, _6$$9, _7$$10, _8$$11, _10$$11, _11$$11, _12$$11, _13$$12, _14$$12, _15$$12, _16$$13, _17$$13, _18$$13;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_21);
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
	if (1 == zephir_array_isset_value_long(&params, 1)) {
		zephir_memory_observe(&_2$$4);
		zephir_array_fetch_long(&_2$$4, &params, 1, PH_NOISY, "phalcon/Assets/Manager.zep", 1037);
		local = zephir_get_boolval(&_2$$4);
		zephir_array_unset_long(&params, 1, PH_SEPARATE);
	} else {
		if (1 == zephir_array_isset_value_string(&params, SL("local"))) {
			zephir_memory_observe(&_3$$6);
			zephir_array_fetch_string(&_3$$6, &params, SL("local"), PH_NOISY, "phalcon/Assets/Manager.zep", 1041);
			local = zephir_get_boolval(&_3$$6);
			zephir_array_unset_string(&params, SL("local"), PH_SEPARATE);
		}
	}
	if (1 != zephir_array_isset_value_string(&params, SL("type"))) {
		zephir_array_update_string(&params, SL("type"), &type_zv, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "link");
	if (ZEPHIR_IS_IDENTICAL(&_4, &helperClass_zv)) {
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "stylesheet");
		zephir_array_update_string(&params, SL("rel"), &_5$$8, PH_COPY | PH_SEPARATE);
	}
	if (1 != zephir_array_isset_value(&params, &name_zv)) {
		ZEPHIR_INIT_VAR(&_6$$9);
		ZVAL_STRING(&_6$$9, "");
		zephir_array_update_zval(&params, &name_zv, &_6$$9, PH_COPY | PH_SEPARATE);
		if (1 == zephir_array_isset_value_long(&params, 0)) {
			zephir_array_fetch_long(&_7$$10, &params, 0, PH_NOISY | PH_READONLY, "phalcon/Assets/Manager.zep", 1061);
			zephir_array_update_zval(&params, &name_zv, &_7$$10, PH_COPY | PH_SEPARATE);
			zephir_array_unset_long(&params, 0, PH_SEPARATE);
		}
	}
	zephir_memory_observe(&tag);
	zephir_array_fetch(&tag, &params, &name_zv, PH_NOISY, "phalcon/Assets/Manager.zep", 1066);
	zephir_array_unset(&params, &name_zv, PH_SEPARATE);
	if (local) {
		zephir_read_property_cached(&_8$$11, this_ptr, _zephir_prop_0, 422, PH_NOISY_CC | PH_READONLY);
		_9$$11 = Z_TYPE_P(&_8$$11) != IS_NULL;
		if (_9$$11) {
			zephir_read_property_cached(&_10$$11, this_ptr, _zephir_prop_0, 422, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "url");
			ZEPHIR_CALL_METHOD(&_11$$11, &_10$$11, "has", NULL, 0, &_12$$11);
			zephir_check_call_status();
			_9$$11 = zephir_is_true(&_11$$11);
		}
		if (_9$$11) {
			zephir_read_property_cached(&_13$$12, this_ptr, _zephir_prop_0, 422, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_14$$12);
			ZVAL_STRING(&_14$$12, "url");
			ZEPHIR_CALL_METHOD(&url, &_13$$12, "get", NULL, 0, &_14$$12);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15$$12, &url, "getstatic", NULL, 0, &tag);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&tag, &_15$$12);
		} else {
			ZEPHIR_INIT_VAR(&_16$$13);
			ZEPHIR_INIT_VAR(&_17$$13);
			ZVAL_STRING(&_17$$13, "/");
			zephir_fast_trim(&_16$$13, &tag, &_17$$13, ZEPHIR_TRIM_LEFT);
			ZEPHIR_INIT_VAR(&_18$$13);
			ZEPHIR_CONCAT_SV(&_18$$13, "/", &_16$$13);
			ZEPHIR_CPY_WRT(&tag, &_18$$13);
		}
	}
	zephir_read_property_cached(&_19, this_ptr, _zephir_prop_1, 418, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&helper, &_19, "newinstance", NULL, 0, &helperClass_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_STRING(&_20, "");
	ZEPHIR_CALL_METHOD(NULL, &helper, "__invoke", NULL, 0, &_20);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &helper, "add", NULL, 0, &tag, &params);
	zephir_check_call_status();
	zephir_cast_to_string(&_21, &helper);
	ZEPHIR_CPY_WRT(&output, &_21);
	ZEPHIR_CALL_METHOD(NULL, &helper, "reset", NULL, 0);
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
PHP_METHOD(Phalcon_Assets_Manager, phpFwrite)
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 167, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

