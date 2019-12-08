
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
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
 * Phalcon\Assets\Manager
 *
 * Manages collections of CSS/Javascript assets
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets, Manager, phalcon, assets_manager, phalcon_di_abstractinjectionaware_ce, phalcon_assets_manager_method_entry, 0);

	zend_declare_property_null(phalcon_assets_manager_ce, SL("collections"), ZEND_ACC_PROTECTED);

	/**
	 * Options configure
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_manager_ce, SL("options"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_manager_ce, SL("implicitOutput"), 1, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Assets\Manager constructor
 */
PHP_METHOD(Phalcon_Assets_Manager, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a raw asset to the manager
 *
 *```php
 * $assets->addAsset(
 *     new Phalcon\Assets\Asset("css", "css/style.css")
 * );
 *```
 */
PHP_METHOD(Phalcon_Assets_Manager, addAsset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
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
 *```php
 * $assets->addAssetByType(
 *     "css",
 *     new \Phalcon\Assets\Asset\Css("css/style.css")
 * );
 *```
 */
PHP_METHOD(Phalcon_Assets_Manager, addAssetByType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *asset, asset_sub, collection, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &asset);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	ZEPHIR_OBS_VAR(&collection);
	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&collection, &_0, &type, 0))) {
		ZEPHIR_INIT_NVAR(&collection);
		object_init_ex(&collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 152);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("collections"), &type, &collection);
	}
	ZEPHIR_CALL_METHOD(NULL, &collection, "add", NULL, 153, asset);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a Css asset to the 'css' collection
 *
 *```php
 * $assets->addCss("css/bootstrap.css");
 * $assets->addCss("http://bootstrap.my-cdn.com/style.css", false);
 *```
 */
PHP_METHOD(Phalcon_Assets_Manager, addCss) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter, autoVersion;
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, *version_param = NULL, *autoVersion_param = NULL, __$true, __$null, _0, _1, _2, _3;
	zval path, version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &path_param, &local, &filter_param, &attributes, &version_param, &autoVersion_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!local) {
		local = &local_sub;
		local = &__$true;
	}
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}
	if (!version_param) {
		ZEPHIR_INIT_VAR(&version);
		ZVAL_STRING(&version, "");
	} else {
		zephir_get_strval(&version, version_param);
	}
	if (!autoVersion_param) {
		autoVersion = 0;
	} else {
		autoVersion = zephir_get_boolval(autoVersion_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_asset_css_ce);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 148, &path, local, &_1, attributes, &version, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "css");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addassetbytype", NULL, 0, &_3, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a raw inline code to the manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCode) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	ZEPHIR_CALL_METHOD(&_0, code, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, &_0, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline code by its type
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCodeByType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *code, code_sub, collection, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &code);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	ZEPHIR_OBS_VAR(&collection);
	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&collection, &_0, &type, 0))) {
		ZEPHIR_INIT_NVAR(&collection);
		object_init_ex(&collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 152);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("collections"), &type, &collection);
	}
	ZEPHIR_CALL_METHOD(NULL, &collection, "addinline", NULL, 154, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline Css to the 'css' collection
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCss) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, *filter = NULL, filter_sub, *attributes = NULL, attributes_sub, __$true, __$null, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter, &attributes);

	zephir_get_strval(&content, content_param);
	if (!filter) {
		filter = &filter_sub;
		filter = &__$true;
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_css_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 149, &content, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline javascript to the 'js' collection
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineJs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, *filter = NULL, filter_sub, *attributes = NULL, attributes_sub, __$true, __$null, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter, &attributes);

	zephir_get_strval(&content, content_param);
	if (!filter) {
		filter = &filter_sub;
		filter = &__$true;
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_js_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 150, &content, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a javascript asset to the 'js' collection
 *
 *```php
 * $assets->addJs("scripts/jquery.js");
 * $assets->addJs("http://jquery.my-cdn.com/jquery.js", false);
 *```
 */
PHP_METHOD(Phalcon_Assets_Manager, addJs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter, autoVersion;
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, *version_param = NULL, *autoVersion_param = NULL, __$true, __$null, _0, _1, _2, _3;
	zval path, version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &path_param, &local, &filter_param, &attributes, &version_param, &autoVersion_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!local) {
		local = &local_sub;
		local = &__$true;
	}
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}
	if (!version_param) {
		ZEPHIR_INIT_VAR(&version);
		ZVAL_STRING(&version, "");
	} else {
		zephir_get_strval(&version, version_param);
	}
	if (!autoVersion_param) {
		autoVersion = 0;
	} else {
		autoVersion = zephir_get_boolval(autoVersion_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_asset_js_ce);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 151, &path, local, &_1, attributes, &version, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "js");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addassetbytype", NULL, 0, &_3, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Creates/Returns a collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, collection) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, collection, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_OBS_VAR(&collection);
	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&collection, &_0, &name, 0))) {
		ZEPHIR_INIT_NVAR(&collection);
		object_init_ex(&collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 152);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("collections"), &name, &collection);
	}
	RETURN_CCTOR(&collection);

}

/**
 * Creates/Returns a collection of assets by type
 */
PHP_METHOD(Phalcon_Assets_Manager, collectionAssetsByType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type;
	zval *assets_param = NULL, *type_param = NULL, asset, *_0, _1, _2$$3, _3$$5;
	zval assets, filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&assets);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&asset);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &assets_param, &type_param);

	zephir_get_arrval(&assets, assets_param);
	zephir_get_strval(&type, type_param);


	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&assets, 0, "phalcon/Assets/Manager.zep", 236);
	if (Z_TYPE_P(&assets) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assets), _0)
		{
			ZEPHIR_INIT_NVAR(&asset);
			ZVAL_COPY(&asset, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, &asset, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&_2$$3, &type)) {
				zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/Assets/Manager.zep", 232);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &assets, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &assets, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&asset, &assets, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_3$$5, &asset, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&_3$$5, &type)) {
					zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/Assets/Manager.zep", 232);
				}
			ZEPHIR_CALL_METHOD(NULL, &assets, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&asset);
	RETURN_CTOR(&filtered);

}

/**
 * Returns true or false if collection exists.
 *
 * ```php
 * if ($assets->exists("jsHeader")) {
 *     // \Phalcon\Assets\Collection
 *     $collection = $assets->get("jsHeader");
 * }
 * ```
 */
PHP_METHOD(Phalcon_Assets_Manager, exists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *id_param = NULL, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_EMPTY_STRING(&id);
	}


	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &id));

}

/**
 * Returns a collection by its id.
 *
 * ```php
 * $scripts = $assets->get("js");
 * ```
 */
PHP_METHOD(Phalcon_Assets_Manager, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *id_param = NULL, collection, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_EMPTY_STRING(&id);
	}


	ZEPHIR_OBS_VAR(&collection);
	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&collection, &_0, &id, 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "The collection does not exist in the manager", "phalcon/Assets/Manager.zep", 266);
		return;
	}
	RETURN_CCTOR(&collection);

}

/**
 * Returns existing collections in the manager
 */
PHP_METHOD(Phalcon_Assets_Manager, getCollections) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "collections");

}

/**
 * Returns the CSS collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, getCss) {

	zval collection, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&collection, &_0, SL("css"), 1))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 152);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&collection);

}

/**
 * Returns the CSS collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, getJs) {

	zval collection, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&collection, &_0, SL("js"), 1))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 152);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&collection);

}

/**
 * Returns the manager options
 */
PHP_METHOD(Phalcon_Assets_Manager, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

}

/**
 * Traverses a collection calling the callback to generate its HTML
 *
 * @param callback callback
 * @param string type
 */
PHP_METHOD(Phalcon_Assets_Manager, output) {

	zend_bool filterNeeded = 0, _18$$23, _22$$24, _32$$44, _34$$45, _48$$63, _50$$64, _60$$84, _62$$85, _68$$93;
	zval output;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_20 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, *callback, callback_sub, *type = NULL, type_sub, asset, assets, attributes, autoVersion, collectionSourcePath, collectionTargetPath, completeSourcePath, completeTargetPath, content, filter, filters, filteredContent, filteredJoinedContent, html, join, local, modificationTime, mustFilter, options, parameters, path, prefixedPath, sourceBasePath, sourcePath, targetBasePath, targetPath, targetUri, typeCss, useImplicitOutput, version, _0, *_7, _8, _1$$3, _2$$10, _3$$10, _4$$9, _5$$11, _6$$11, _9$$15, _10$$15, _11$$17, _12$$17, _13$$19, _14$$19, _15$$20, _17$$23, _19$$23, _23$$25, _24$$25, _25$$26, _26$$27, _27$$28, *_28$$32, _29$$32, _30$$39, _31$$44, _33$$44, _35$$46, _36$$46, _37$$47, _38$$48, _39$$49, _40$$55, _41$$55, _42$$57, _43$$57, _44$$59, _45$$59, _46$$60, _47$$63, _49$$63, _51$$65, _52$$65, _53$$66, _54$$67, _55$$68, *_56$$72, _57$$72, _58$$79, _59$$84, _61$$84, _63$$86, _64$$86, _65$$87, _66$$88, _67$$89, _69$$94, _70$$95, _71$$96, _72$$97;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&asset);
	ZVAL_UNDEF(&assets);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&autoVersion);
	ZVAL_UNDEF(&collectionSourcePath);
	ZVAL_UNDEF(&collectionTargetPath);
	ZVAL_UNDEF(&completeSourcePath);
	ZVAL_UNDEF(&completeTargetPath);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&filteredContent);
	ZVAL_UNDEF(&filteredJoinedContent);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&modificationTime);
	ZVAL_UNDEF(&mustFilter);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&prefixedPath);
	ZVAL_UNDEF(&sourceBasePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&targetBasePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&targetUri);
	ZVAL_UNDEF(&typeCss);
	ZVAL_UNDEF(&useImplicitOutput);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$19);
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_17$$23);
	ZVAL_UNDEF(&_19$$23);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_24$$25);
	ZVAL_UNDEF(&_25$$26);
	ZVAL_UNDEF(&_26$$27);
	ZVAL_UNDEF(&_27$$28);
	ZVAL_UNDEF(&_29$$32);
	ZVAL_UNDEF(&_30$$39);
	ZVAL_UNDEF(&_31$$44);
	ZVAL_UNDEF(&_33$$44);
	ZVAL_UNDEF(&_35$$46);
	ZVAL_UNDEF(&_36$$46);
	ZVAL_UNDEF(&_37$$47);
	ZVAL_UNDEF(&_38$$48);
	ZVAL_UNDEF(&_39$$49);
	ZVAL_UNDEF(&_40$$55);
	ZVAL_UNDEF(&_41$$55);
	ZVAL_UNDEF(&_42$$57);
	ZVAL_UNDEF(&_43$$57);
	ZVAL_UNDEF(&_44$$59);
	ZVAL_UNDEF(&_45$$59);
	ZVAL_UNDEF(&_46$$60);
	ZVAL_UNDEF(&_47$$63);
	ZVAL_UNDEF(&_49$$63);
	ZVAL_UNDEF(&_51$$65);
	ZVAL_UNDEF(&_52$$65);
	ZVAL_UNDEF(&_53$$66);
	ZVAL_UNDEF(&_54$$67);
	ZVAL_UNDEF(&_55$$68);
	ZVAL_UNDEF(&_57$$72);
	ZVAL_UNDEF(&_58$$79);
	ZVAL_UNDEF(&_59$$84);
	ZVAL_UNDEF(&_61$$84);
	ZVAL_UNDEF(&_63$$86);
	ZVAL_UNDEF(&_64$$86);
	ZVAL_UNDEF(&_65$$87);
	ZVAL_UNDEF(&_66$$88);
	ZVAL_UNDEF(&_67$$89);
	ZVAL_UNDEF(&_69$$94);
	ZVAL_UNDEF(&_70$$95);
	ZVAL_UNDEF(&_71$$96);
	ZVAL_UNDEF(&_72$$97);
	ZVAL_UNDEF(&output);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &collection, &callback, &type);

	ZEPHIR_SEPARATE_PARAM(type);


	ZEPHIR_INIT_VAR(&sourceBasePath);
	ZVAL_NULL(&sourceBasePath);
	ZEPHIR_INIT_VAR(&targetBasePath);
	ZVAL_NULL(&targetBasePath);
	ZEPHIR_OBS_VAR(&useImplicitOutput);
	zephir_read_property(&useImplicitOutput, this_ptr, SL("implicitOutput"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_CALL_METHOD(&_0, collection, "getassets", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&assets, this_ptr, "collectionassetsbytype", NULL, 0, &_0, type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&filters, collection, "getfilters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&typeCss);
	ZVAL_STRING(&typeCss, "css");
	if (zephir_fast_count_int(&filters)) {
		zephir_read_property(&_1$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&options, &_1$$3);
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&sourceBasePath);
			zephir_array_isset_string_fetch(&sourceBasePath, &options, SL("sourceBasePath"), 0);
			ZEPHIR_OBS_NVAR(&targetBasePath);
			zephir_array_isset_string_fetch(&targetBasePath, &options, SL("targetBasePath"), 0);
		}
		ZEPHIR_CALL_METHOD(&collectionSourcePath, collection, "getsourcepath", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&collectionSourcePath)) {
			ZEPHIR_INIT_VAR(&completeSourcePath);
			ZEPHIR_CONCAT_VV(&completeSourcePath, &sourceBasePath, &collectionSourcePath);
		} else {
			ZEPHIR_CPY_WRT(&completeSourcePath, &sourceBasePath);
		}
		ZEPHIR_CALL_METHOD(&collectionTargetPath, collection, "gettargetpath", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&collectionTargetPath)) {
			ZEPHIR_INIT_VAR(&completeTargetPath);
			ZEPHIR_CONCAT_VV(&completeTargetPath, &targetBasePath, &collectionTargetPath);
		} else {
			ZEPHIR_CPY_WRT(&completeTargetPath, &targetBasePath);
		}
		ZEPHIR_INIT_VAR(&filteredJoinedContent);
		ZVAL_STRING(&filteredJoinedContent, "");
		ZEPHIR_CALL_METHOD(&join, collection, "getjoin", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&join)) {
			if (UNEXPECTED(!zephir_is_true(&completeTargetPath))) {
				ZEPHIR_INIT_VAR(&_2$$10);
				object_init_ex(&_2$$10, phalcon_assets_exception_ce);
				ZEPHIR_INIT_VAR(&_3$$10);
				ZEPHIR_CONCAT_SVS(&_3$$10, "Path '", &completeTargetPath, "' is not a valid target path (1)");
				ZEPHIR_CALL_METHOD(NULL, &_2$$10, "__construct", NULL, 6, &_3$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$10, "phalcon/Assets/Manager.zep", 429);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&_4$$9, "is_dir", NULL, 123, &completeTargetPath);
			zephir_check_call_status();
			if (UNEXPECTED(zephir_is_true(&_4$$9))) {
				ZEPHIR_INIT_VAR(&_5$$11);
				object_init_ex(&_5$$11, phalcon_assets_exception_ce);
				ZEPHIR_INIT_VAR(&_6$$11);
				ZEPHIR_CONCAT_SVS(&_6$$11, "Path '", &completeTargetPath, "' is not a valid target path (2), is dir.");
				ZEPHIR_CALL_METHOD(NULL, &_5$$11, "__construct", NULL, 6, &_6$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$11, "phalcon/Assets/Manager.zep", 435);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_is_iterable(&assets, 0, "phalcon/Assets/Manager.zep", 693);
	if (Z_TYPE_P(&assets) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assets), _7)
		{
			ZEPHIR_INIT_NVAR(&asset);
			ZVAL_COPY(&asset, _7);
			filterNeeded = 0;
			ZEPHIR_CALL_METHOD(type, &asset, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&local, &asset, "getlocal", NULL, 0);
			zephir_check_call_status();
			if (zephir_fast_count_int(&filters)) {
				if (zephir_is_true(&local)) {
					ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getrealsourcepath", NULL, 0, &completeSourcePath);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&sourcePath))) {
						ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_9$$15);
						object_init_ex(&_9$$15, phalcon_assets_exception_ce);
						ZEPHIR_INIT_NVAR(&_10$$15);
						ZEPHIR_CONCAT_SVS(&_10$$15, "Asset '", &sourcePath, "' does not have a valid source path");
						ZEPHIR_CALL_METHOD(NULL, &_9$$15, "__construct", NULL, 6, &_10$$15);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$15, "phalcon/Assets/Manager.zep", 473);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
					zephir_check_call_status();
					filterNeeded = 1;
				}
				ZEPHIR_CALL_METHOD(&targetPath, &asset, "getrealtargetpath", NULL, 0, &completeTargetPath);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&targetPath))) {
					ZEPHIR_INIT_NVAR(&_11$$17);
					object_init_ex(&_11$$17, phalcon_assets_exception_ce);
					ZEPHIR_INIT_NVAR(&_12$$17);
					ZEPHIR_CONCAT_SVS(&_12$$17, "Asset '", &sourcePath, "' does not have a valid target path");
					ZEPHIR_CALL_METHOD(NULL, &_11$$17, "__construct", NULL, 6, &_12$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$17, "phalcon/Assets/Manager.zep", 499);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&local)) {
					if (UNEXPECTED(ZEPHIR_IS_EQUAL(&targetPath, &sourcePath))) {
						ZEPHIR_INIT_NVAR(&_13$$19);
						object_init_ex(&_13$$19, phalcon_assets_exception_ce);
						ZEPHIR_INIT_NVAR(&_14$$19);
						ZEPHIR_CONCAT_SVS(&_14$$19, "Asset '", &targetPath, "' have the same source and target paths");
						ZEPHIR_CALL_METHOD(NULL, &_13$$19, "__construct", NULL, 6, &_14$$19);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_13$$19, "phalcon/Assets/Manager.zep", 509);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if ((zephir_file_exists(&targetPath) == SUCCESS)) {
						ZEPHIR_INIT_NVAR(&_15$$20);
						if (zephir_compare_mtime(&targetPath, &sourcePath)) {
							filterNeeded = 1;
						}
					} else {
						filterNeeded = 1;
					}
				}
			} else {
				ZEPHIR_CALL_METHOD(&path, &asset, "getrealtargeturi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "getprefixedpath", &_16, 155, collection, &path);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_17$$23, &asset, "getversion", NULL, 0);
				zephir_check_call_status();
				_18$$23 = Z_TYPE_P(&_17$$23) == IS_NULL;
				if (_18$$23) {
					ZEPHIR_CALL_METHOD(&_19$$23, &asset, "isautoversion", NULL, 0);
					zephir_check_call_status();
					_18$$23 = zephir_is_true(&_19$$23);
				}
				if (_18$$23) {
					ZEPHIR_CALL_METHOD(&version, collection, "getversion", &_20, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&autoVersion, collection, "isautoversion", &_21, 0);
					zephir_check_call_status();
					_22$$24 = zephir_is_true(&autoVersion);
					if (_22$$24) {
						_22$$24 = zephir_is_true(&local);
					}
					if (_22$$24) {
						ZEPHIR_CALL_METHOD(&_23$$25, &asset, "getrealsourcepath", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&modificationTime);
						zephir_filemtime(&modificationTime, &_23$$25);
						ZEPHIR_INIT_NVAR(&_24$$25);
						if (zephir_is_true(&version)) {
							ZEPHIR_INIT_NVAR(&_24$$25);
							ZEPHIR_CONCAT_VSV(&_24$$25, &version, ".", &modificationTime);
						} else {
							ZEPHIR_CPY_WRT(&_24$$25, &modificationTime);
						}
						ZEPHIR_CPY_WRT(&version, &_24$$25);
					}
					if (zephir_is_true(&version)) {
						ZEPHIR_INIT_NVAR(&_25$$26);
						ZEPHIR_CONCAT_VSV(&_25$$26, &prefixedPath, "?ver=", &version);
						ZEPHIR_CPY_WRT(&prefixedPath, &_25$$26);
					}
				}
				ZEPHIR_CALL_METHOD(&attributes, &asset, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&parameters);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					ZEPHIR_INIT_NVAR(&_26$$27);
					zephir_create_array(&_26$$27, 1, 0);
					zephir_array_fast_append(&_26$$27, &attributes);
					ZEPHIR_CPY_WRT(&parameters, &_26$$27);
				} else {
					ZEPHIR_INIT_NVAR(&_27$$28);
					zephir_create_array(&_27$$28, 1, 0);
					zephir_array_fast_append(&_27$$28, &prefixedPath);
					ZEPHIR_CPY_WRT(&parameters, &_27$$28);
				}
				zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/Assets/Manager.zep", 555);
				ZEPHIR_INIT_NVAR(&html);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&output, &html);
				}
				continue;
			}
			if (filterNeeded == 1) {
				ZEPHIR_CALL_METHOD(&content, &asset, "getcontent", NULL, 0, &completeSourcePath);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&mustFilter, &asset, "getfilter", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE(&mustFilter)) {
					zephir_is_iterable(&filters, 0, "phalcon/Assets/Manager.zep", 608);
					if (Z_TYPE_P(&filters) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _28$$32)
						{
							ZEPHIR_INIT_NVAR(&filter);
							ZVAL_COPY(&filter, _28$$32);
							if (UNEXPECTED(Z_TYPE_P(&filter) != IS_OBJECT)) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/Assets/Manager.zep", 594);
								return;
							}
							ZEPHIR_CALL_METHOD(&filteredContent, &filter, "filter", NULL, 0, &content);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&content, &filteredContent);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_29$$32, &filters, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_29$$32)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&filter, &filters, "current", NULL, 0);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&filter) != IS_OBJECT)) {
									ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/Assets/Manager.zep", 594);
									return;
								}
								ZEPHIR_CALL_METHOD(&filteredContent, &filter, "filter", NULL, 0, &content);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&content, &filteredContent);
							ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&filter);
					if (ZEPHIR_IS_TRUE(&join)) {
						if (ZEPHIR_IS_EQUAL(type, &typeCss)) {
							zephir_concat_self(&filteredJoinedContent, &filteredContent);
						} else {
							ZEPHIR_INIT_NVAR(&_30$$39);
							ZEPHIR_CONCAT_VS(&_30$$39, &filteredContent, ";");
							zephir_concat_self(&filteredJoinedContent, &_30$$39);
						}
					}
				} else {
					if (ZEPHIR_IS_TRUE(&join)) {
						zephir_concat_self(&filteredJoinedContent, &content);
					} else {
						ZEPHIR_CPY_WRT(&filteredContent, &content);
					}
				}
				if (!(zephir_is_true(&join))) {
					zephir_file_put_contents(NULL, &targetPath, &filteredContent);
				}
			}
			if (!(zephir_is_true(&join))) {
				ZEPHIR_CALL_METHOD(&path, &asset, "getrealtargeturi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "getprefixedpath", &_16, 155, collection, &path);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_31$$44, &asset, "getversion", NULL, 0);
				zephir_check_call_status();
				_32$$44 = Z_TYPE_P(&_31$$44) == IS_NULL;
				if (_32$$44) {
					ZEPHIR_CALL_METHOD(&_33$$44, &asset, "isautoversion", NULL, 0);
					zephir_check_call_status();
					_32$$44 = zephir_is_true(&_33$$44);
				}
				if (_32$$44) {
					ZEPHIR_CALL_METHOD(&version, collection, "getversion", &_20, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&autoVersion, collection, "isautoversion", &_21, 0);
					zephir_check_call_status();
					_34$$45 = zephir_is_true(&autoVersion);
					if (_34$$45) {
						_34$$45 = zephir_is_true(&local);
					}
					if (_34$$45) {
						ZEPHIR_CALL_METHOD(&_35$$46, &asset, "getrealsourcepath", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&modificationTime);
						zephir_filemtime(&modificationTime, &_35$$46);
						ZEPHIR_INIT_NVAR(&_36$$46);
						if (zephir_is_true(&version)) {
							ZEPHIR_INIT_NVAR(&_36$$46);
							ZEPHIR_CONCAT_VSV(&_36$$46, &version, ".", &modificationTime);
						} else {
							ZEPHIR_CPY_WRT(&_36$$46, &modificationTime);
						}
						ZEPHIR_CPY_WRT(&version, &_36$$46);
					}
					if (zephir_is_true(&version)) {
						ZEPHIR_INIT_NVAR(&_37$$47);
						ZEPHIR_CONCAT_VSV(&_37$$47, &prefixedPath, "?ver=", &version);
						ZEPHIR_CPY_WRT(&prefixedPath, &_37$$47);
					}
				}
				ZEPHIR_CALL_METHOD(&attributes, &asset, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&local);
				ZVAL_BOOL(&local, 1);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					ZEPHIR_INIT_NVAR(&_38$$48);
					zephir_create_array(&_38$$48, 1, 0);
					zephir_array_fast_append(&_38$$48, &attributes);
					ZEPHIR_CPY_WRT(&parameters, &_38$$48);
				} else {
					ZEPHIR_INIT_NVAR(&_39$$49);
					zephir_create_array(&_39$$49, 1, 0);
					zephir_array_fast_append(&_39$$49, &prefixedPath);
					ZEPHIR_CPY_WRT(&parameters, &_39$$49);
				}
				zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/Assets/Manager.zep", 675);
				ZEPHIR_INIT_NVAR(&html);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&output, &html);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &assets, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &assets, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&asset, &assets, "current", NULL, 0);
			zephir_check_call_status();
				filterNeeded = 0;
				ZEPHIR_CALL_METHOD(type, &asset, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&local, &asset, "getlocal", NULL, 0);
				zephir_check_call_status();
				if (zephir_fast_count_int(&filters)) {
					if (zephir_is_true(&local)) {
						ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getrealsourcepath", NULL, 0, &completeSourcePath);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&sourcePath))) {
							ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_40$$55);
							object_init_ex(&_40$$55, phalcon_assets_exception_ce);
							ZEPHIR_INIT_NVAR(&_41$$55);
							ZEPHIR_CONCAT_SVS(&_41$$55, "Asset '", &sourcePath, "' does not have a valid source path");
							ZEPHIR_CALL_METHOD(NULL, &_40$$55, "__construct", NULL, 6, &_41$$55);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_40$$55, "phalcon/Assets/Manager.zep", 473);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
						zephir_check_call_status();
						filterNeeded = 1;
					}
					ZEPHIR_CALL_METHOD(&targetPath, &asset, "getrealtargetpath", NULL, 0, &completeTargetPath);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&targetPath))) {
						ZEPHIR_INIT_NVAR(&_42$$57);
						object_init_ex(&_42$$57, phalcon_assets_exception_ce);
						ZEPHIR_INIT_NVAR(&_43$$57);
						ZEPHIR_CONCAT_SVS(&_43$$57, "Asset '", &sourcePath, "' does not have a valid target path");
						ZEPHIR_CALL_METHOD(NULL, &_42$$57, "__construct", NULL, 6, &_43$$57);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_42$$57, "phalcon/Assets/Manager.zep", 499);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&local)) {
						if (UNEXPECTED(ZEPHIR_IS_EQUAL(&targetPath, &sourcePath))) {
							ZEPHIR_INIT_NVAR(&_44$$59);
							object_init_ex(&_44$$59, phalcon_assets_exception_ce);
							ZEPHIR_INIT_NVAR(&_45$$59);
							ZEPHIR_CONCAT_SVS(&_45$$59, "Asset '", &targetPath, "' have the same source and target paths");
							ZEPHIR_CALL_METHOD(NULL, &_44$$59, "__construct", NULL, 6, &_45$$59);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_44$$59, "phalcon/Assets/Manager.zep", 509);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if ((zephir_file_exists(&targetPath) == SUCCESS)) {
							ZEPHIR_INIT_NVAR(&_46$$60);
							if (zephir_compare_mtime(&targetPath, &sourcePath)) {
								filterNeeded = 1;
							}
						} else {
							filterNeeded = 1;
						}
					}
				} else {
					ZEPHIR_CALL_METHOD(&path, &asset, "getrealtargeturi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "getprefixedpath", &_16, 155, collection, &path);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_47$$63, &asset, "getversion", NULL, 0);
					zephir_check_call_status();
					_48$$63 = Z_TYPE_P(&_47$$63) == IS_NULL;
					if (_48$$63) {
						ZEPHIR_CALL_METHOD(&_49$$63, &asset, "isautoversion", NULL, 0);
						zephir_check_call_status();
						_48$$63 = zephir_is_true(&_49$$63);
					}
					if (_48$$63) {
						ZEPHIR_CALL_METHOD(&version, collection, "getversion", &_20, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&autoVersion, collection, "isautoversion", &_21, 0);
						zephir_check_call_status();
						_50$$64 = zephir_is_true(&autoVersion);
						if (_50$$64) {
							_50$$64 = zephir_is_true(&local);
						}
						if (_50$$64) {
							ZEPHIR_CALL_METHOD(&_51$$65, &asset, "getrealsourcepath", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&modificationTime);
							zephir_filemtime(&modificationTime, &_51$$65);
							ZEPHIR_INIT_NVAR(&_52$$65);
							if (zephir_is_true(&version)) {
								ZEPHIR_INIT_NVAR(&_52$$65);
								ZEPHIR_CONCAT_VSV(&_52$$65, &version, ".", &modificationTime);
							} else {
								ZEPHIR_CPY_WRT(&_52$$65, &modificationTime);
							}
							ZEPHIR_CPY_WRT(&version, &_52$$65);
						}
						if (zephir_is_true(&version)) {
							ZEPHIR_INIT_NVAR(&_53$$66);
							ZEPHIR_CONCAT_VSV(&_53$$66, &prefixedPath, "?ver=", &version);
							ZEPHIR_CPY_WRT(&prefixedPath, &_53$$66);
						}
					}
					ZEPHIR_CALL_METHOD(&attributes, &asset, "getattributes", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						ZEPHIR_INIT_NVAR(&_54$$67);
						zephir_create_array(&_54$$67, 1, 0);
						zephir_array_fast_append(&_54$$67, &attributes);
						ZEPHIR_CPY_WRT(&parameters, &_54$$67);
					} else {
						ZEPHIR_INIT_NVAR(&_55$$68);
						zephir_create_array(&_55$$68, 1, 0);
						zephir_array_fast_append(&_55$$68, &prefixedPath);
						ZEPHIR_CPY_WRT(&parameters, &_55$$68);
					}
					zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/Assets/Manager.zep", 555);
					ZEPHIR_INIT_NVAR(&html);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_concat_self(&output, &html);
					}
					continue;
				}
				if (filterNeeded == 1) {
					ZEPHIR_CALL_METHOD(&content, &asset, "getcontent", NULL, 0, &completeSourcePath);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mustFilter, &asset, "getfilter", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE(&mustFilter)) {
						zephir_is_iterable(&filters, 0, "phalcon/Assets/Manager.zep", 608);
						if (Z_TYPE_P(&filters) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _56$$72)
							{
								ZEPHIR_INIT_NVAR(&filter);
								ZVAL_COPY(&filter, _56$$72);
								if (UNEXPECTED(Z_TYPE_P(&filter) != IS_OBJECT)) {
									ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/Assets/Manager.zep", 594);
									return;
								}
								ZEPHIR_CALL_METHOD(&filteredContent, &filter, "filter", NULL, 0, &content);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&content, &filteredContent);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_57$$72, &filters, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_57$$72)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&filter, &filters, "current", NULL, 0);
								zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&filter) != IS_OBJECT)) {
										ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/Assets/Manager.zep", 594);
										return;
									}
									ZEPHIR_CALL_METHOD(&filteredContent, &filter, "filter", NULL, 0, &content);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&content, &filteredContent);
								ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&filter);
						if (ZEPHIR_IS_TRUE(&join)) {
							if (ZEPHIR_IS_EQUAL(type, &typeCss)) {
								zephir_concat_self(&filteredJoinedContent, &filteredContent);
							} else {
								ZEPHIR_INIT_NVAR(&_58$$79);
								ZEPHIR_CONCAT_VS(&_58$$79, &filteredContent, ";");
								zephir_concat_self(&filteredJoinedContent, &_58$$79);
							}
						}
					} else {
						if (ZEPHIR_IS_TRUE(&join)) {
							zephir_concat_self(&filteredJoinedContent, &content);
						} else {
							ZEPHIR_CPY_WRT(&filteredContent, &content);
						}
					}
					if (!(zephir_is_true(&join))) {
						zephir_file_put_contents(NULL, &targetPath, &filteredContent);
					}
				}
				if (!(zephir_is_true(&join))) {
					ZEPHIR_CALL_METHOD(&path, &asset, "getrealtargeturi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "getprefixedpath", &_16, 155, collection, &path);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_59$$84, &asset, "getversion", NULL, 0);
					zephir_check_call_status();
					_60$$84 = Z_TYPE_P(&_59$$84) == IS_NULL;
					if (_60$$84) {
						ZEPHIR_CALL_METHOD(&_61$$84, &asset, "isautoversion", NULL, 0);
						zephir_check_call_status();
						_60$$84 = zephir_is_true(&_61$$84);
					}
					if (_60$$84) {
						ZEPHIR_CALL_METHOD(&version, collection, "getversion", &_20, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&autoVersion, collection, "isautoversion", &_21, 0);
						zephir_check_call_status();
						_62$$85 = zephir_is_true(&autoVersion);
						if (_62$$85) {
							_62$$85 = zephir_is_true(&local);
						}
						if (_62$$85) {
							ZEPHIR_CALL_METHOD(&_63$$86, &asset, "getrealsourcepath", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&modificationTime);
							zephir_filemtime(&modificationTime, &_63$$86);
							ZEPHIR_INIT_NVAR(&_64$$86);
							if (zephir_is_true(&version)) {
								ZEPHIR_INIT_NVAR(&_64$$86);
								ZEPHIR_CONCAT_VSV(&_64$$86, &version, ".", &modificationTime);
							} else {
								ZEPHIR_CPY_WRT(&_64$$86, &modificationTime);
							}
							ZEPHIR_CPY_WRT(&version, &_64$$86);
						}
						if (zephir_is_true(&version)) {
							ZEPHIR_INIT_NVAR(&_65$$87);
							ZEPHIR_CONCAT_VSV(&_65$$87, &prefixedPath, "?ver=", &version);
							ZEPHIR_CPY_WRT(&prefixedPath, &_65$$87);
						}
					}
					ZEPHIR_CALL_METHOD(&attributes, &asset, "getattributes", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&local);
					ZVAL_BOOL(&local, 1);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						ZEPHIR_INIT_NVAR(&_66$$88);
						zephir_create_array(&_66$$88, 1, 0);
						zephir_array_fast_append(&_66$$88, &attributes);
						ZEPHIR_CPY_WRT(&parameters, &_66$$88);
					} else {
						ZEPHIR_INIT_NVAR(&_67$$89);
						zephir_create_array(&_67$$89, 1, 0);
						zephir_array_fast_append(&_67$$89, &prefixedPath);
						ZEPHIR_CPY_WRT(&parameters, &_67$$89);
					}
					zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/Assets/Manager.zep", 675);
					ZEPHIR_INIT_NVAR(&html);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_concat_self(&output, &html);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &assets, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&asset);
	if (zephir_fast_count_int(&filters)) {
		if (ZEPHIR_IS_TRUE(&join)) {
			zephir_file_put_contents(NULL, &completeTargetPath, &filteredJoinedContent);
			ZEPHIR_CALL_METHOD(&targetUri, collection, "gettargeturi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&prefixedPath, this_ptr, "getprefixedpath", &_16, 155, collection, &targetUri);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&version, collection, "getversion", &_20, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&autoVersion, collection, "isautoversion", &_21, 0);
			zephir_check_call_status();
			_68$$93 = zephir_is_true(&autoVersion);
			if (_68$$93) {
				_68$$93 = zephir_is_true(&local);
			}
			if (_68$$93) {
				ZEPHIR_INIT_NVAR(&modificationTime);
				zephir_filemtime(&modificationTime, &completeTargetPath);
				ZEPHIR_INIT_VAR(&_69$$94);
				if (zephir_is_true(&version)) {
					ZEPHIR_INIT_NVAR(&_69$$94);
					ZEPHIR_CONCAT_VSV(&_69$$94, &version, ".", &modificationTime);
				} else {
					ZEPHIR_CPY_WRT(&_69$$94, &modificationTime);
				}
				ZEPHIR_CPY_WRT(&version, &_69$$94);
			}
			if (zephir_is_true(&version)) {
				ZEPHIR_INIT_VAR(&_70$$95);
				ZEPHIR_CONCAT_VSV(&_70$$95, &prefixedPath, "?ver=", &version);
				ZEPHIR_CPY_WRT(&prefixedPath, &_70$$95);
			}
			ZEPHIR_CALL_METHOD(&attributes, collection, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&local, collection, "gettargetlocal", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&attributes) == IS_ARRAY) {
				zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_INIT_VAR(&_71$$96);
				zephir_create_array(&_71$$96, 1, 0);
				zephir_array_fast_append(&_71$$96, &attributes);
				ZEPHIR_CPY_WRT(&parameters, &_71$$96);
			} else {
				ZEPHIR_INIT_VAR(&_72$$97);
				zephir_create_array(&_72$$97, 1, 0);
				zephir_array_fast_append(&_72$$97, &prefixedPath);
				ZEPHIR_CPY_WRT(&parameters, &_72$$97);
			}
			zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/Assets/Manager.zep", 737);
			ZEPHIR_INIT_NVAR(&html);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
				zend_print_zval(&html, 0);
			} else {
				zephir_concat_self(&output, &html);
			}
		}
	}
	RETURN_CTOR(&output);

}

/**
 * Prints the HTML for CSS assets
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss) {

	zend_bool _2;
	zval callback;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName_param = NULL, collection, container, tag, _0, _1, _3, _4$$5, _5$$5;
	zval collectionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&callback);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName_param);

	if (!collectionName_param) {
		ZEPHIR_INIT_VAR(&collectionName);
		ZVAL_STRING(&collectionName, "");
	} else {
		zephir_get_strval(&collectionName, collectionName_param);
	}


	if (!(!(Z_TYPE_P(&collectionName) == IS_UNDEF) && Z_STRLEN_P(&collectionName))) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "getcss", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, &collectionName);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&callback);
	zephir_create_array(&callback, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Tag");
	zephir_array_fast_append(&callback, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "stylesheetLink");
	zephir_array_fast_append(&callback, &_0);
	zephir_read_property(&_1, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_1);
	_2 = Z_TYPE_P(&container) == IS_OBJECT;
	if (_2) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "tag");
		ZEPHIR_CALL_METHOD(&_3, &container, "has", NULL, 0, &_0);
		zephir_check_call_status();
		_2 = zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "tag");
		ZEPHIR_CALL_METHOD(&tag, &container, "getshared", NULL, 0, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_create_array(&_5$$5, 2, 0);
		zephir_array_fast_append(&_5$$5, &tag);
		ZEPHIR_INIT_NVAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "stylesheetLink");
		zephir_array_fast_append(&_5$$5, &_4$$5);
		ZEPHIR_CPY_WRT(&callback, &_5$$5);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "css");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "output", NULL, 0, &collection, &callback, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Traverses a collection and generate its HTML
 *
 * @param string type
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInline) {

	zval html, joinedContent, output;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, *type, type_sub, attributes, code, codes, content, filter, filters, join, *_0$$3, _1$$3, _27$$3, *_2$$4, _3$$4, _4$$5, _5$$7, _6$$10, _8$$10, _9$$10, _10$$10, _12$$10, *_13$$11, _14$$11, _15$$12, _16$$14, _17$$17, _18$$17, _19$$17, _20$$17, _21$$17, _22$$18, _23$$18, _24$$18, _25$$18, _26$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&codes);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_27$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&joinedContent);
	ZVAL_UNDEF(&output);

	ZEPHIR_MM_GROW();
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
	if (zephir_fast_count_int(&codes)) {
		zephir_is_iterable(&codes, 0, "phalcon/Assets/Manager.zep", 829);
		if (Z_TYPE_P(&codes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&codes), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&code);
				ZVAL_COPY(&code, _0$$3);
				ZEPHIR_CALL_METHOD(&attributes, &code, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&content, &code, "getcontent", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&filters, 0, "phalcon/Assets/Manager.zep", 820);
				if (Z_TYPE_P(&filters) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _2$$4)
					{
						ZEPHIR_INIT_NVAR(&filter);
						ZVAL_COPY(&filter, _2$$4);
						if (UNEXPECTED(Z_TYPE_P(&filter) != IS_OBJECT)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/Assets/Manager.zep", 810);
							return;
						}
						ZEPHIR_CALL_METHOD(&_4$$5, &filter, "filter", NULL, 0, &content);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&content, &_4$$5);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_3$$4, &filters, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_3$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&filter, &filters, "current", NULL, 0);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&filter) != IS_OBJECT)) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/Assets/Manager.zep", 810);
								return;
							}
							ZEPHIR_CALL_METHOD(&_5$$7, &filter, "filter", NULL, 0, &content);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&content, &_5$$7);
						ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&filter);
				if (zephir_is_true(&join)) {
					zephir_concat_self(&joinedContent, &content);
				} else {
					ZVAL_BOOL(&_8$$10, 0);
					ZVAL_BOOL(&_9$$10, 1);
					ZEPHIR_CALL_CE_STATIC(&_6$$10, phalcon_tag_ce, "taghtml", &_7, 0, type, &attributes, &_8$$10, &_9$$10);
					zephir_check_call_status();
					ZVAL_BOOL(&_8$$10, 1);
					ZEPHIR_CALL_CE_STATIC(&_10$$10, phalcon_tag_ce, "taghtmlclose", &_11, 0, type, &_8$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_12$$10);
					ZEPHIR_CONCAT_VVV(&_12$$10, &_6$$10, &content, &_10$$10);
					zephir_concat_self(&html, &_12$$10);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &codes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &codes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&code, &codes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attributes, &code, "getattributes", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&content, &code, "getcontent", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&filters, 0, "phalcon/Assets/Manager.zep", 820);
					if (Z_TYPE_P(&filters) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _13$$11)
						{
							ZEPHIR_INIT_NVAR(&filter);
							ZVAL_COPY(&filter, _13$$11);
							if (UNEXPECTED(Z_TYPE_P(&filter) != IS_OBJECT)) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/Assets/Manager.zep", 810);
								return;
							}
							ZEPHIR_CALL_METHOD(&_15$$12, &filter, "filter", NULL, 0, &content);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&content, &_15$$12);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &filters, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_14$$11, &filters, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_14$$11)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&filter, &filters, "current", NULL, 0);
							zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&filter) != IS_OBJECT)) {
									ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/Assets/Manager.zep", 810);
									return;
								}
								ZEPHIR_CALL_METHOD(&_16$$14, &filter, "filter", NULL, 0, &content);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&content, &_16$$14);
							ZEPHIR_CALL_METHOD(NULL, &filters, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&filter);
					if (zephir_is_true(&join)) {
						zephir_concat_self(&joinedContent, &content);
					} else {
						ZVAL_BOOL(&_18$$17, 0);
						ZVAL_BOOL(&_19$$17, 1);
						ZEPHIR_CALL_CE_STATIC(&_17$$17, phalcon_tag_ce, "taghtml", &_7, 0, type, &attributes, &_18$$17, &_19$$17);
						zephir_check_call_status();
						ZVAL_BOOL(&_18$$17, 1);
						ZEPHIR_CALL_CE_STATIC(&_20$$17, phalcon_tag_ce, "taghtmlclose", &_11, 0, type, &_18$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_21$$17);
						ZEPHIR_CONCAT_VVV(&_21$$17, &_17$$17, &content, &_20$$17);
						zephir_concat_self(&html, &_21$$17);
					}
				ZEPHIR_CALL_METHOD(NULL, &codes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&code);
		if (zephir_is_true(&join)) {
			ZVAL_BOOL(&_23$$18, 0);
			ZVAL_BOOL(&_24$$18, 1);
			ZEPHIR_CALL_CE_STATIC(&_22$$18, phalcon_tag_ce, "taghtml", &_7, 0, type, &attributes, &_23$$18, &_24$$18);
			zephir_check_call_status();
			ZVAL_BOOL(&_23$$18, 1);
			ZEPHIR_CALL_CE_STATIC(&_25$$18, phalcon_tag_ce, "taghtmlclose", &_11, 0, type, &_23$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_26$$18);
			ZEPHIR_CONCAT_VVV(&_26$$18, &_22$$18, &joinedContent, &_25$$18);
			zephir_concat_self(&html, &_26$$18);
		}
		zephir_read_property(&_27$$3, this_ptr, SL("implicitOutput"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE(&_27$$3)) {
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
PHP_METHOD(Phalcon_Assets_Manager, outputInlineCss) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName_param = NULL, collection, _0;
	zval collectionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName_param);

	if (!collectionName_param) {
		ZEPHIR_INIT_VAR(&collectionName);
		ZVAL_STRING(&collectionName, "");
	} else {
		zephir_get_strval(&collectionName, collectionName_param);
	}


	if (!(!(Z_TYPE_P(&collectionName) == IS_UNDEF) && Z_STRLEN_P(&collectionName))) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "getcss", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, &collectionName);
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
PHP_METHOD(Phalcon_Assets_Manager, outputInlineJs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName_param = NULL, collection, _0;
	zval collectionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName_param);

	if (!collectionName_param) {
		ZEPHIR_INIT_VAR(&collectionName);
		ZVAL_STRING(&collectionName, "");
	} else {
		zephir_get_strval(&collectionName, collectionName_param);
	}


	if (!(!(Z_TYPE_P(&collectionName) == IS_UNDEF) && Z_STRLEN_P(&collectionName))) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "getjs", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, &collectionName);
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
PHP_METHOD(Phalcon_Assets_Manager, outputJs) {

	zend_bool _2;
	zval callback;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName_param = NULL, collection, container, tag, _0, _1, _3, _4$$5, _5$$5;
	zval collectionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&callback);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName_param);

	if (!collectionName_param) {
		ZEPHIR_INIT_VAR(&collectionName);
		ZVAL_STRING(&collectionName, "");
	} else {
		zephir_get_strval(&collectionName, collectionName_param);
	}


	if (!(!(Z_TYPE_P(&collectionName) == IS_UNDEF) && Z_STRLEN_P(&collectionName))) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "getjs", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "get", NULL, 0, &collectionName);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&callback);
	zephir_create_array(&callback, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Tag");
	zephir_array_fast_append(&callback, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "javascriptInclude");
	zephir_array_fast_append(&callback, &_0);
	zephir_read_property(&_1, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_1);
	_2 = Z_TYPE_P(&container) == IS_OBJECT;
	if (_2) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "tag");
		ZEPHIR_CALL_METHOD(&_3, &container, "has", NULL, 0, &_0);
		zephir_check_call_status();
		_2 = zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "tag");
		ZEPHIR_CALL_METHOD(&tag, &container, "getshared", NULL, 0, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_create_array(&_5$$5, 2, 0);
		zephir_array_fast_append(&_5$$5, &tag);
		ZEPHIR_INIT_NVAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "javascriptInclude");
		zephir_array_fast_append(&_5$$5, &_4$$5);
		ZEPHIR_CPY_WRT(&callback, &_5$$5);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "js");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "output", NULL, 0, &collection, &callback, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a collection in the Assets Manager
 *
 *```php
 * $assets->set("js", $collection);
 *```
 */
PHP_METHOD(Phalcon_Assets_Manager, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *id_param = NULL, *collection, collection_sub;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&collection_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &collection);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(id_param) == IS_STRING)) {
		zephir_get_strval(&id, id_param);
	} else {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_EMPTY_STRING(&id);
	}


	zephir_update_property_array(this_ptr, SL("collections"), &id, collection);
	RETURN_THIS();

}

/**
 * Sets the manager options
 */
PHP_METHOD(Phalcon_Assets_Manager, setOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	RETURN_THIS();

}

/**
 * Sets if the HTML generated must be directly printed or returned
 */
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput) {

	zval *implicitOutput_param = NULL, __$true, __$false;
	zend_bool implicitOutput;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &implicitOutput_param);

	implicitOutput = zephir_get_boolval(implicitOutput_param);


	if (implicitOutput) {
		zephir_update_property_zval(this_ptr, SL("implicitOutput"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("implicitOutput"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Returns the prefixed path
 */
PHP_METHOD(Phalcon_Assets_Manager, getPrefixedPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path;
	zval *collection, collection_sub, *path_param = NULL, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&prefix))) {
		RETURN_CTOR(&path);
	}
	ZEPHIR_CONCAT_VV(return_value, &prefix, &path);
	RETURN_MM();

}

