
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
#include "kernel/file.h"
#include "kernel/string.h"
#include "kernel/concat.h"


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
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Manager)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets, Manager, phalcon, assets_manager, phalcon_di_abstractinjectionaware_ce, phalcon_assets_manager_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_manager_ce, SL("collections"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_manager_ce, SL("implicitOutput"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_manager_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var TagFactory
	 */
	zend_declare_property_null(phalcon_assets_manager_ce, SL("tagFactory"), ZEND_ACC_PROTECTED);
	phalcon_assets_manager_ce->create_object = zephir_init_properties_Phalcon_Assets_Manager;

	return SUCCESS;
}

/**
 * Manager constructor.
 *
 * @param TagFactory $tagFactory
 * @param array      $options
 */
PHP_METHOD(Phalcon_Assets_Manager, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval *tagFactory, tagFactory_sub, *options_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tagFactory_sub);
	ZVAL_UNDEF(&options);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("tagFactory"), tagFactory);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
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
 * Adds a asset by its type
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
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "checkandcreatecollection", NULL, 304, &type_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &collection, "add", NULL, 0, asset);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds a CSS asset to the 'css' collection
 *
 * @param string      $path
 * @param bool        $local
 * @param bool        $filter
 * @param array       $attributes
 * @param string|null $version
 * @param bool        $autoVersion
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 305, &path_zv, &_1, &_2, &attributes, &version_zv, &_3);
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
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "checkandcreatecollection", NULL, 304, &type_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &collection, "addinline", NULL, 0, code);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an inline CSS to the 'css' collection
 *
 * @param string $content
 * @param bool   $filter
 * @param array  $attributes
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 306, &content_zv, &_1, &attributes);
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
 * @param string $content
 * @param bool   $filter
 * @param array  $attributes
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 307, &content_zv, &_1, &attributes);
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
 * $assets->addJs("http://jquery.my-cdn.com/jquery.js", false);
 *```
 *
 * @param string      $path
 * @param bool        $local
 * @param bool        $filter
 * @param array       $attributes
 * @param string|null $version
 * @param bool        $autoVersion
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 308, &path_zv, &_1, &_2, &attributes, &version_zv, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "js");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addassetbytype", NULL, 0, &_4, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Creates/Returns a collection of assets
 *
 * @param string $name
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "checkandcreatecollection", NULL, 304, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates/Returns a collection of assets by type
 *
 * @param array  $assets
 * @param string $type
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
	zephir_is_iterable(&assets, 0, "phalcon/Assets/Manager.zep", 260);
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
				zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/Assets/Manager.zep", 256);
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
					zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/Assets/Manager.zep", 256);
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
 * @param string $name
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
 *
 * @param string $name
 *
 * @return Collection
 * @throws Exception
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("collections"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(1 != zephir_array_isset_value(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_assets_exceptions_collectionnotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 309, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Assets/Manager.zep", 296);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("collections"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Assets/Manager.zep", 299);
	RETURN_CTOR(&_3);
}

/**
 * Returns existing collections in the manager
 *
 * @return Collection[]
 */
PHP_METHOD(Phalcon_Assets_Manager, getCollections)
{

	RETURN_MEMBER_TYPED(getThis(), "collections", IS_ARRAY);
}

/**
 * Returns the CSS collection of assets
 *
 * @return Collection
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "checkandcreatecollection", NULL, 304, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the CSS collection of assets
 *
 * @return Collection
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "checkandcreatecollection", NULL, 304, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the manager options
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
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_Assets_Manager, has)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("collections"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &name_zv));
}

/**
 * Traverses a collection calling the callback to generate its HTML
 *
 * @param Collection $collection
 * @param string     $type
 *
 * @return string|null
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, output)
{
	zval outputParts;
	zend_bool filterNeeded = 0, _34, _54, _26$$25, _48$$45;
	zval output;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_15 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *type = NULL;
	zval *collection, collection_sub, type_zv, asset, assets, callback, callbackMethod, collectionSourcePath, collectionTargetPath, completeSourcePath, completeTargetPath, content, filters, filteredContent, filteredJoinedContent, html, join, mustFilter, options, prefixedPath, sourceBasePath, sourcePath, targetBasePath, targetPath, typeCss, _0, _1, _2, *_6, _33, _3$$9, _4$$8, _5$$10, _7$$12, _13$$12, _8$$14, _10$$15, _11$$15, _14$$17, _16$$18, _17$$18, _18$$21, _19$$21, _21$$21, _22$$21, _24$$21, _27$$25, _28$$28, _29$$28, _30$$28, _32$$28, _35$$32, _39$$32, _36$$34, _37$$35, _38$$35, _40$$37, _41$$38, _42$$38, _43$$41, _44$$41, _45$$41, _46$$41, _47$$41, _49$$45, _50$$48, _51$$48, _52$$48, _53$$48, _55$$51, _56$$51, _57$$51, _58$$51;
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
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_21$$21);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_28$$28);
	ZVAL_UNDEF(&_29$$28);
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&_32$$28);
	ZVAL_UNDEF(&_35$$32);
	ZVAL_UNDEF(&_39$$32);
	ZVAL_UNDEF(&_36$$34);
	ZVAL_UNDEF(&_37$$35);
	ZVAL_UNDEF(&_38$$35);
	ZVAL_UNDEF(&_40$$37);
	ZVAL_UNDEF(&_41$$38);
	ZVAL_UNDEF(&_42$$38);
	ZVAL_UNDEF(&_43$$41);
	ZVAL_UNDEF(&_44$$41);
	ZVAL_UNDEF(&_45$$41);
	ZVAL_UNDEF(&_46$$41);
	ZVAL_UNDEF(&_47$$41);
	ZVAL_UNDEF(&_49$$45);
	ZVAL_UNDEF(&_50$$48);
	ZVAL_UNDEF(&_51$$48);
	ZVAL_UNDEF(&_52$$48);
	ZVAL_UNDEF(&_53$$48);
	ZVAL_UNDEF(&_55$$51);
	ZVAL_UNDEF(&_56$$51);
	ZVAL_UNDEF(&_57$$51);
	ZVAL_UNDEF(&_58$$51);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&outputParts);
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
	ZEPHIR_INIT_VAR(&outputParts);
	array_init(&outputParts);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_INIT_NVAR(&filteredJoinedContent);
		ZVAL_STRING(&filteredJoinedContent, "");
		ZEPHIR_CALL_METHOD(&join, collection, "getjoin", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&join))) {
			if (1 == ZEPHIR_IS_EMPTY(&completeTargetPath)) {
				ZEPHIR_INIT_VAR(&_3$$9);
				object_init_ex(&_3$$9, phalcon_assets_exceptions_invalidtargetpath_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", NULL, 310, &completeTargetPath);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$9, "phalcon/Assets/Manager.zep", 464);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&_4$$8, "is_dir", NULL, 256, &completeTargetPath);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_4$$8)) {
				ZEPHIR_INIT_VAR(&_5$$10);
				object_init_ex(&_5$$10, phalcon_assets_exceptions_targetpathisdirectory_ce);
				ZEPHIR_CALL_METHOD(NULL, &_5$$10, "__construct", NULL, 311, &completeTargetPath);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$10, "phalcon/Assets/Manager.zep", 468);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_is_iterable(&assets, 0, "phalcon/Assets/Manager.zep", 624);
	if (Z_TYPE_P(&assets) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assets), _6)
		{
			ZEPHIR_INIT_NVAR(&asset);
			ZVAL_COPY(&asset, _6);
			filterNeeded = 0;
			if (1 != ZEPHIR_IS_EMPTY(&filters)) {
				ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$12, &asset, "islocal", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_7$$12)) {
					filterNeeded = 1;
					ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getrealsourcepath", NULL, 0, &completeSourcePath);
					zephir_check_call_status();
					if (1 == ZEPHIR_IS_EMPTY(&sourcePath)) {
						ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_8$$14);
						object_init_ex(&_8$$14, phalcon_assets_exceptions_invalidassetsourcepath_ce);
						ZEPHIR_CALL_METHOD(NULL, &_8$$14, "__construct", &_9, 312, &sourcePath);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_8$$14, "phalcon/Assets/Manager.zep", 496);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD(&targetPath, &asset, "getrealtargetpath", NULL, 0, &completeTargetPath);
				zephir_check_call_status();
				if (1 == ZEPHIR_IS_EMPTY(&targetPath)) {
					ZEPHIR_INIT_NVAR(&_10$$15);
					object_init_ex(&_10$$15, phalcon_assets_exceptions_invalidassettargetpath_ce);
					ZEPHIR_CALL_METHOD(&_11$$15, &asset, "getpath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_10$$15, "__construct", &_12, 313, &_11$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$15, "phalcon/Assets/Manager.zep", 510);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_13$$12, &asset, "islocal", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_13$$12)) {
					if (ZEPHIR_IS_IDENTICAL(&targetPath, &sourcePath)) {
						ZEPHIR_INIT_NVAR(&_14$$17);
						object_init_ex(&_14$$17, phalcon_assets_exceptions_assetsourcetargetcollision_ce);
						ZEPHIR_CALL_METHOD(NULL, &_14$$17, "__construct", &_15, 314, &targetPath);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$17, "phalcon/Assets/Manager.zep", 518);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (1 == (zephir_file_exists(&targetPath) == SUCCESS)) {
						ZEPHIR_INIT_NVAR(&_16$$18);
						zephir_filemtime(&_16$$18, &targetPath);
						ZEPHIR_INIT_NVAR(&_17$$18);
						zephir_filemtime(&_17$$18, &sourcePath);
						if (!ZEPHIR_IS_IDENTICAL(&_16$$18, &_17$$18)) {
							filterNeeded = 1;
						}
					} else {
						filterNeeded = 1;
					}
				}
			} else {
				ZEPHIR_CALL_METHOD(&_18$$21, &asset, "getrealtargeturi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_19$$21, &asset, "getrealsourcepath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_20, 315, collection, &_18$$21, &_19$$21);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_21$$21, &asset, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_22$$21, &asset, "islocal", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_23, 316, &callback, &_21$$21, &prefixedPath, &_22$$21);
				zephir_check_call_status();
				zephir_read_property(&_24$$21, this_ptr, ZEND_STRL("implicitOutput"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_24$$21)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_array_append(&outputParts, &html, PH_SEPARATE, "phalcon/Assets/Manager.zep", 555);
				}
				continue;
			}
			if (filterNeeded) {
				ZEPHIR_CALL_METHOD(&content, &asset, "getcontent", NULL, 0, &completeSourcePath);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&mustFilter, &asset, "getfilter", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&filteredContent, this_ptr, "applyfilters", &_25, 317, &content, &filters, &mustFilter);
				zephir_check_call_status();
				if (zephir_is_true(&join)) {
					zephir_concat_self(&filteredJoinedContent, &filteredContent);
					_26$$25 = zephir_is_true(&mustFilter);
					if (_26$$25) {
						ZEPHIR_CALL_METHOD(&_27$$25, &asset, "gettype", NULL, 0);
						zephir_check_call_status();
						_26$$25 = !ZEPHIR_IS_IDENTICAL(&_27$$25, &typeCss);
					}
					if (_26$$25) {
						zephir_concat_self_str(&filteredJoinedContent, SL(";"));
					}
				}
				if (!zephir_is_true(&join)) {
					zephir_file_put_contents(NULL, &targetPath, &filteredContent);
				}
			}
			if (!zephir_is_true(&join)) {
				ZEPHIR_CALL_METHOD(&_28$$28, &asset, "getrealtargeturi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_29$$28, &asset, "getrealsourcepath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_20, 315, collection, &_28$$28, &_29$$28);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_30$$28, collection, "getattributes", &_31, 0);
				zephir_check_call_status();
				ZVAL_BOOL(&_32$$28, 1);
				ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_23, 316, &callback, &_30$$28, &prefixedPath, &_32$$28);
				zephir_check_call_status();
				zephir_read_property(&_32$$28, this_ptr, ZEND_STRL("implicitOutput"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_32$$28)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_array_append(&outputParts, &html, PH_SEPARATE, "phalcon/Assets/Manager.zep", 619);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &assets, "rewind", NULL, 0);
		zephir_check_call_status();
		_34 = 1;
		while (1) {
			if (_34) {
				_34 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &assets, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_33, &assets, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_33)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&asset, &assets, "current", NULL, 0);
			zephir_check_call_status();
				filterNeeded = 0;
				if (1 != ZEPHIR_IS_EMPTY(&filters)) {
					ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_35$$32, &asset, "islocal", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_35$$32)) {
						filterNeeded = 1;
						ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getrealsourcepath", NULL, 0, &completeSourcePath);
						zephir_check_call_status();
						if (1 == ZEPHIR_IS_EMPTY(&sourcePath)) {
							ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_36$$34);
							object_init_ex(&_36$$34, phalcon_assets_exceptions_invalidassetsourcepath_ce);
							ZEPHIR_CALL_METHOD(NULL, &_36$$34, "__construct", &_9, 312, &sourcePath);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_36$$34, "phalcon/Assets/Manager.zep", 496);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CALL_METHOD(&targetPath, &asset, "getrealtargetpath", NULL, 0, &completeTargetPath);
					zephir_check_call_status();
					if (1 == ZEPHIR_IS_EMPTY(&targetPath)) {
						ZEPHIR_INIT_NVAR(&_37$$35);
						object_init_ex(&_37$$35, phalcon_assets_exceptions_invalidassettargetpath_ce);
						ZEPHIR_CALL_METHOD(&_38$$35, &asset, "getpath", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_37$$35, "__construct", &_12, 313, &_38$$35);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_37$$35, "phalcon/Assets/Manager.zep", 510);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_39$$32, &asset, "islocal", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_39$$32)) {
						if (ZEPHIR_IS_IDENTICAL(&targetPath, &sourcePath)) {
							ZEPHIR_INIT_NVAR(&_40$$37);
							object_init_ex(&_40$$37, phalcon_assets_exceptions_assetsourcetargetcollision_ce);
							ZEPHIR_CALL_METHOD(NULL, &_40$$37, "__construct", &_15, 314, &targetPath);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_40$$37, "phalcon/Assets/Manager.zep", 518);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (1 == (zephir_file_exists(&targetPath) == SUCCESS)) {
							ZEPHIR_INIT_NVAR(&_41$$38);
							zephir_filemtime(&_41$$38, &targetPath);
							ZEPHIR_INIT_NVAR(&_42$$38);
							zephir_filemtime(&_42$$38, &sourcePath);
							if (!ZEPHIR_IS_IDENTICAL(&_41$$38, &_42$$38)) {
								filterNeeded = 1;
							}
						} else {
							filterNeeded = 1;
						}
					}
				} else {
					ZEPHIR_CALL_METHOD(&_43$$41, &asset, "getrealtargeturi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_44$$41, &asset, "getrealsourcepath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_20, 315, collection, &_43$$41, &_44$$41);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_45$$41, &asset, "getattributes", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_46$$41, &asset, "islocal", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_23, 316, &callback, &_45$$41, &prefixedPath, &_46$$41);
					zephir_check_call_status();
					zephir_read_property(&_47$$41, this_ptr, ZEND_STRL("implicitOutput"), PH_NOISY_CC | PH_READONLY);
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_47$$41)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_array_append(&outputParts, &html, PH_SEPARATE, "phalcon/Assets/Manager.zep", 555);
					}
					continue;
				}
				if (filterNeeded) {
					ZEPHIR_CALL_METHOD(&content, &asset, "getcontent", NULL, 0, &completeSourcePath);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mustFilter, &asset, "getfilter", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&filteredContent, this_ptr, "applyfilters", &_25, 317, &content, &filters, &mustFilter);
					zephir_check_call_status();
					if (zephir_is_true(&join)) {
						zephir_concat_self(&filteredJoinedContent, &filteredContent);
						_48$$45 = zephir_is_true(&mustFilter);
						if (_48$$45) {
							ZEPHIR_CALL_METHOD(&_49$$45, &asset, "gettype", NULL, 0);
							zephir_check_call_status();
							_48$$45 = !ZEPHIR_IS_IDENTICAL(&_49$$45, &typeCss);
						}
						if (_48$$45) {
							zephir_concat_self_str(&filteredJoinedContent, SL(";"));
						}
					}
					if (!zephir_is_true(&join)) {
						zephir_file_put_contents(NULL, &targetPath, &filteredContent);
					}
				}
				if (!zephir_is_true(&join)) {
					ZEPHIR_CALL_METHOD(&_50$$48, &asset, "getrealtargeturi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_51$$48, &asset, "getrealsourcepath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_20, 315, collection, &_50$$48, &_51$$48);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_52$$48, collection, "getattributes", &_31, 0);
					zephir_check_call_status();
					ZVAL_BOOL(&_53$$48, 1);
					ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_23, 316, &callback, &_52$$48, &prefixedPath, &_53$$48);
					zephir_check_call_status();
					zephir_read_property(&_53$$48, this_ptr, ZEND_STRL("implicitOutput"), PH_NOISY_CC | PH_READONLY);
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_53$$48)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_array_append(&outputParts, &html, PH_SEPARATE, "phalcon/Assets/Manager.zep", 619);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&asset);
	_54 = 1 != ZEPHIR_IS_EMPTY(&filters);
	if (_54) {
		_54 = zephir_is_true(&join);
	}
	if (_54) {
		zephir_file_put_contents(NULL, &completeTargetPath, &filteredJoinedContent);
		ZEPHIR_CALL_METHOD(&_55$$51, collection, "gettargeturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "calculateprefixedpath", &_20, 315, collection, &_55$$51, &completeTargetPath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_56$$51, collection, "getattributes", &_31, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_57$$51, collection, "gettargetislocal", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&html, this_ptr, "docallback", &_23, 316, &callback, &_56$$51, &prefixedPath, &_57$$51);
		zephir_check_call_status();
		zephir_read_property(&_58$$51, this_ptr, ZEND_STRL("implicitOutput"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_58$$51)) {
			zend_print_zval(&html, 0);
		} else {
			zephir_array_append(&outputParts, &html, PH_SEPARATE, "phalcon/Assets/Manager.zep", 653);
		}
	}
	ZEPHIR_INIT_NVAR(&output);
	zephir_fast_join_str(&output, SL(""), &outputParts);
	RETURN_CTOR(&output);
}

/**
 * Prints the HTML for CSS assets
 *
 * @param string|null $name
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss)
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
	ZVAL_STRING(&_0, "css");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "output", NULL, 0, &collection, &_0);
	zephir_check_call_status();
	RETURN_MM();
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
		zephir_is_iterable(&codes, 0, "phalcon/Assets/Manager.zep", 728);
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
				ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "applyfilters", &_3, 317, &content, &filters, &_2$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&content, &_1$$4);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
					zephir_concat_self(&joinedContent, &content);
				} else {
					zephir_read_property(&_4$$6, this_ptr, ZEND_STRL("tagFactory"), PH_NOISY_CC | PH_READONLY);
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
					ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "applyfilters", &_3, 317, &content, &filters, &_12$$7);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&content, &_11$$7);
					if (ZEPHIR_IS_TRUE_IDENTICAL(&join)) {
						zephir_concat_self(&joinedContent, &content);
					} else {
						zephir_read_property(&_13$$9, this_ptr, ZEND_STRL("tagFactory"), PH_NOISY_CC | PH_READONLY);
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
			zephir_read_property(&_18$$10, this_ptr, ZEND_STRL("tagFactory"), PH_NOISY_CC | PH_READONLY);
			ZVAL_BOOL(&_20$$10, 1);
			ZEPHIR_CALL_METHOD(&_19$$10, &_18$$10, "element", NULL, 0, type, &joinedContent, &attributes, &_20$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_21$$10);
			ZEPHIR_GET_CONSTANT(&_21$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_22$$10);
			ZEPHIR_CONCAT_VV(&_22$$10, &_19$$10, &_21$$10);
			zephir_concat_self(&html, &_22$$10);
		}
		zephir_read_property(&_23$$3, this_ptr, ZEND_STRL("implicitOutput"), PH_NOISY_CC | PH_READONLY);
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
 *
 * @param string|null $name
 *
 * @return string
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
 *
 * @param string|null $name
 *
 * @return string
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
 *
 * @param string|null $name
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Manager, outputJs)
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
	ZVAL_STRING(&_0, "js");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "output", NULL, 0, &collection, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets a collection in the Assets Manager
 *
 *```php
 * $assets->set("js", $collection);
 *```
 *
 * @param string     $name
 * @param Collection $collection
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
 * @param array $options
 */
PHP_METHOD(Phalcon_Assets_Manager, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	RETURN_THIS();
}

/**
 * Sets if the HTML generated must be directly printed or returned
 *
 * @param bool $implicitOutput
 */
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput)
{
	zval *implicitOutput_param = NULL, __$true, __$false;
	zend_bool implicitOutput;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(implicitOutput)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &implicitOutput_param);
	if (implicitOutput) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("implicitOutput"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("implicitOutput"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Applies the collection filters to the content. Filtering only happens
 * when `mustFilter` is true; every filter must be a `FilterInterface`
 * instance.
 *
 * @param string content
 * @param array  filters
 * @param bool   mustFilter
 *
 * @return string
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
	zephir_is_iterable(&filters, 0, "phalcon/Assets/Manager.zep", 887);
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
				ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", &_3, 318);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$5, "phalcon/Assets/Manager.zep", 877);
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
					ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", &_3, 318);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$7, "phalcon/Assets/Manager.zep", 877);
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
 *
 * @param Collection $collection
 * @param string     $path
 * @param string     $filePath
 *
 * @return string
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

/**
 * @param string $type
 */
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("collections"), PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset_value(&_0, &type_zv)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_assets_collection_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		zephir_update_property_array(this_ptr, SL("collections"), &type_zv, &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("collections"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &type_zv, PH_NOISY | PH_READONLY, "phalcon/Assets/Manager.zep", 933);
	RETURN_CTOR(&_3);
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * @param mixed $parameters
 * @param bool  $local
 *
 * @return string
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processparameters", NULL, 319, parameters, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param mixed  $callback
 * @param array  $attributes
 * @param string $prefixedPath
 * @param bool   $local
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Manager, doCallback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zend_string *prefixedPath = NULL;
	zval attributes, parameters;
	zval *callback, callback_sub, *attributes_param = NULL, prefixedPath_zv, *local_param = NULL, _1, _0$$4;

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&prefixedPath_zv);
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
	zephir_array_append(&parameters, &_1, PH_SEPARATE, "phalcon/Assets/Manager.zep", 981);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, callback, &parameters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param mixed $parameters
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processparameters", NULL, 319, parameters, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Processes common parameters for js/css link generation
 */
PHP_METHOD(Phalcon_Assets_Manager, processParameters)
{
	zval _22;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *helperClass = NULL, *type = NULL, *name = NULL;
	zend_bool local, _9$$11;
	zval *parameters, parameters_sub, *local_param = NULL, helperClass_zv, type_zv, name_zv, helper, output, params, tag, _4, _20, _21, _0$$3, _1$$3, _2$$4, _3$$6, _5$$8, _6$$9, _7$$10, _8$$11, _10$$11, _11$$11, _12$$11, _13$$12, _14$$12, _15$$12, _16$$12, _17$$13, _18$$13, _19$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&helperClass_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
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
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_22);
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
		zephir_array_fetch_long(&_2$$4, &params, 1, PH_NOISY, "phalcon/Assets/Manager.zep", 1025);
		local = zephir_get_boolval(&_2$$4);
		zephir_array_unset_long(&params, 1, PH_SEPARATE);
	} else {
		if (1 == zephir_array_isset_value_string(&params, SL("local"))) {
			zephir_memory_observe(&_3$$6);
			zephir_array_fetch_string(&_3$$6, &params, SL("local"), PH_NOISY, "phalcon/Assets/Manager.zep", 1029);
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
			zephir_array_fetch_long(&_7$$10, &params, 0, PH_NOISY | PH_READONLY, "phalcon/Assets/Manager.zep", 1049);
			zephir_array_update_zval(&params, &name_zv, &_7$$10, PH_COPY | PH_SEPARATE);
			zephir_array_unset_long(&params, 0, PH_SEPARATE);
		}
	}
	zephir_memory_observe(&tag);
	zephir_array_fetch(&tag, &params, &name_zv, PH_NOISY, "phalcon/Assets/Manager.zep", 1054);
	zephir_array_unset(&params, &name_zv, PH_SEPARATE);
	if (local) {
		zephir_read_property(&_8$$11, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		_9$$11 = Z_TYPE_P(&_8$$11) != IS_NULL;
		if (_9$$11) {
			zephir_read_property(&_10$$11, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "url");
			ZEPHIR_CALL_METHOD(&_11$$11, &_10$$11, "has", NULL, 0, &_12$$11);
			zephir_check_call_status();
			_9$$11 = zephir_is_true(&_11$$11);
		}
		if (_9$$11) {
			zephir_read_property(&_13$$12, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_15$$12);
			ZVAL_STRING(&_15$$12, "url");
			ZEPHIR_CALL_METHOD(&_14$$12, &_13$$12, "get", NULL, 0, &_15$$12);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16$$12, &_14$$12, "getstatic", NULL, 0, &tag);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&tag, &_16$$12);
		} else {
			ZEPHIR_INIT_VAR(&_17$$13);
			ZEPHIR_INIT_VAR(&_18$$13);
			ZVAL_STRING(&_18$$13, "/");
			zephir_fast_trim(&_17$$13, &tag, &_18$$13, ZEPHIR_TRIM_LEFT);
			ZEPHIR_INIT_VAR(&_19$$13);
			ZEPHIR_CONCAT_SV(&_19$$13, "/", &_17$$13);
			ZEPHIR_CPY_WRT(&tag, &_19$$13);
		}
	}
	zephir_read_property(&_20, this_ptr, ZEND_STRL("tagFactory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&helper, &_20, "newinstance", NULL, 0, &helperClass_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_21);
	ZVAL_STRING(&_21, "");
	ZEPHIR_CALL_METHOD(NULL, &helper, "__invoke", NULL, 0, &_21);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &helper, "add", NULL, 0, &tag, &params);
	zephir_check_call_status();
	zephir_cast_to_string(&_22, &helper);
	ZEPHIR_CPY_WRT(&output, &_22);
	ZEPHIR_CALL_METHOD(NULL, &helper, "reset", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&output);
}

zend_object *zephir_init_properties_Phalcon_Assets_Manager(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("collections"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("collections"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

