
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
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

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Manager, phalcon, assets_manager, phalcon_assets_manager_method_entry, 0);

	/**
	 * Options configure
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_manager_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_manager_ce, SL("collections"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool 
	 */
	zend_declare_property_bool(phalcon_assets_manager_ce, SL("implicitOutput"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, __construct) {

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
 * Sets the manager options
 */
PHP_METHOD(Phalcon_Assets_Manager, setOptions) {

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
 * Returns the manager options
 */
PHP_METHOD(Phalcon_Assets_Manager, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

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

	zephir_fetch_params(0, 1, 0, &implicitOutput_param);

	implicitOutput = zephir_get_boolval(implicitOutput_param);


	if (implicitOutput) {
		zephir_update_property_zval(this_ptr, SL("implicitOutput"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("implicitOutput"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Adds a Css asset to the 'css' collection
 *
 *<code>
 *	assets->addCss("css/bootstrap.css");
 *	assets->addCss("http://bootstrap.my-cdn.com/style.css", false);
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, addCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *local = NULL, local_sub, *filter = NULL, filter_sub, *attributes = NULL, attributes_sub, __$true, __$null, _0, _1;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter, &attributes);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string") TSRMLS_CC);
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
	if (!filter) {
		filter = &filter_sub;
		filter = &__$true;
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_asset_css_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 88, &path, local, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addassetbytype", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline Css to the 'css' collection
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCss) {

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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 89, &content, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a javascript asset to the 'js' collection
 *
 *<code>
 * assets->addJs("scripts/jquery.js");
 * assets->addJs("http://jquery.my-cdn.com/jquery.js", false);
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, addJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *local = NULL, local_sub, *filter = NULL, filter_sub, *attributes = NULL, attributes_sub, __$true, __$null, _0, _1;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter, &attributes);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string") TSRMLS_CC);
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
	if (!filter) {
		filter = &filter_sub;
		filter = &__$true;
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_asset_js_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 90, &path, local, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addassetbytype", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline javascript to the 'js' collection
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineJs) {

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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 91, &content, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinlinecodebytype", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a asset by its type
 *
 *<code>
 * assets->addAssetByType("css",
 *     new \Phalcon\Assets\Asset\Css("css/style.css")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, addAssetByType) {

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
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
	if (!(zephir_array_isset_fetch(&collection, &_0, &type, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&collection);
		object_init_ex(&collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 92);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("collections"), &type, &collection);
	}
	ZEPHIR_CALL_METHOD(NULL, &collection, "add", NULL, 93, asset);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline code by its type
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCodeByType) {

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
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
	if (!(zephir_array_isset_fetch(&collection, &_0, &type, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&collection);
		object_init_ex(&collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 92);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("collections"), &type, &collection);
	}
	ZEPHIR_CALL_METHOD(NULL, &collection, "addinline", NULL, 94, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a raw asset to the manager
 *
 *<code>
 * assets->addAsset(
 *     new Phalcon\Assets\Asset("css", "css/style.css")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, addAsset) {

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
 * Adds a raw inline code to the manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addInlineCode) {

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
 * Sets a collection in the Assets Manager
 *
 *<code>
 * assets->set("js", $collection);
 *</code>
 */
PHP_METHOD(Phalcon_Assets_Manager, set) {

	zval *id_param = NULL, *collection, collection_sub;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&collection_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &collection);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string") TSRMLS_CC);
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
 * Returns a collection by its id.
 *
 * <code>
 * $scripts = assets->get("js");
 * </code>
 */
PHP_METHOD(Phalcon_Assets_Manager, get) {

	zval *id_param = NULL, collection, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string") TSRMLS_CC);
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
	if (!(zephir_array_isset_fetch(&collection, &_0, &id, 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "The collection does not exist in the manager", "phalcon/assets/manager.zep", 225);
		return;
	}
	RETURN_CCTOR(&collection);

}

/**
 * Returns the CSS collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, getCss) {

	zval collection, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&collection, &_0, SL("css"), 1))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 92);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("collections"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string_fetch(&collection, &_0, SL("js"), 1))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 92);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&collection);

}

/**
 * Creates/Returns a collection of assets
 */
PHP_METHOD(Phalcon_Assets_Manager, collection) {

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
	if (!(zephir_array_isset_fetch(&collection, &_0, &name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&collection);
		object_init_ex(&collection, phalcon_assets_collection_ce);
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 92);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("collections"), &name, &collection);
	}
	RETURN_CCTOR(&collection);

}

PHP_METHOD(Phalcon_Assets_Manager, collectionAssetsByType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type;
	zval *assets_param = NULL, *type_param = NULL, filtered, asset, *_0, _1, _2$$3, _3$$5;
	zval assets;
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
	zephir_is_iterable(&assets, 0, "phalcon/assets/manager.zep", 289);
	if (Z_TYPE_P(&assets) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assets), _0)
		{
			ZEPHIR_INIT_NVAR(&asset);
			ZVAL_COPY(&asset, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, &asset, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&_2$$3, &type)) {
				zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/assets/manager.zep", 285);
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
					zephir_array_append(&filtered, &asset, PH_SEPARATE, "phalcon/assets/manager.zep", 285);
				}
			ZEPHIR_CALL_METHOD(NULL, &assets, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&asset);
	RETURN_CCTOR(&filtered);

}

/**
 * Traverses a collection calling the callback to generate its HTML
 *
 * @param callback callback
 * @param string type
 */
PHP_METHOD(Phalcon_Assets_Manager, output) {

	zend_bool filterNeeded = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, *callback, callback_sub, *type = NULL, type_sub, output, assets, filters, prefix, sourceBasePath, targetBasePath, options, collectionSourcePath, completeSourcePath, collectionTargetPath, completeTargetPath, filteredJoinedContent, join, asset, local, sourcePath, targetPath, path, prefixedPath, attributes, parameters, html, useImplicitOutput, content, mustFilter, filter, filteredContent, typeCss, targetUri, _0, *_7, _8, _1$$3, _2$$10, _3$$10, _4$$9, _5$$11, _6$$11, _9$$15, _10$$15, _11$$17, _12$$17, _13$$19, _14$$19, _15$$20, *_16$$31, _17$$31, _18$$38, _19$$53, _20$$53, _21$$55, _22$$55, _23$$57, _24$$57, _25$$58, *_26$$69, _27$$69, _28$$76;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&assets);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&sourceBasePath);
	ZVAL_UNDEF(&targetBasePath);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&collectionSourcePath);
	ZVAL_UNDEF(&completeSourcePath);
	ZVAL_UNDEF(&collectionTargetPath);
	ZVAL_UNDEF(&completeTargetPath);
	ZVAL_UNDEF(&filteredJoinedContent);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&asset);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&prefixedPath);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&useImplicitOutput);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&mustFilter);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&filteredContent);
	ZVAL_UNDEF(&typeCss);
	ZVAL_UNDEF(&targetUri);
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
	ZVAL_UNDEF(&_17$$31);
	ZVAL_UNDEF(&_18$$38);
	ZVAL_UNDEF(&_19$$53);
	ZVAL_UNDEF(&_20$$53);
	ZVAL_UNDEF(&_21$$55);
	ZVAL_UNDEF(&_22$$55);
	ZVAL_UNDEF(&_23$$57);
	ZVAL_UNDEF(&_24$$57);
	ZVAL_UNDEF(&_25$$58);
	ZVAL_UNDEF(&_27$$69);
	ZVAL_UNDEF(&_28$$76);

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
	ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&typeCss);
	ZVAL_STRING(&typeCss, "css");
	if (zephir_fast_count_int(&filters TSRMLS_CC)) {
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
			if (!(zephir_is_true(&completeTargetPath))) {
				ZEPHIR_INIT_VAR(&_2$$10);
				object_init_ex(&_2$$10, phalcon_assets_exception_ce);
				ZEPHIR_INIT_VAR(&_3$$10);
				ZEPHIR_CONCAT_SVS(&_3$$10, "Path '", &completeTargetPath, "' is not a valid target path (1)");
				ZEPHIR_CALL_METHOD(NULL, &_2$$10, "__construct", NULL, 4, &_3$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$10, "phalcon/assets/manager.zep", 397 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&_4$$9, "is_dir", NULL, 95, &completeTargetPath);
			zephir_check_call_status();
			if (zephir_is_true(&_4$$9)) {
				ZEPHIR_INIT_VAR(&_5$$11);
				object_init_ex(&_5$$11, phalcon_assets_exception_ce);
				ZEPHIR_INIT_VAR(&_6$$11);
				ZEPHIR_CONCAT_SVS(&_6$$11, "Path '", &completeTargetPath, "' is not a valid target path (2), is dir.");
				ZEPHIR_CALL_METHOD(NULL, &_5$$11, "__construct", NULL, 4, &_6$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$11, "phalcon/assets/manager.zep", 401 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_is_iterable(&assets, 0, "phalcon/assets/manager.zep", 639);
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
			if (zephir_fast_count_int(&filters TSRMLS_CC)) {
				if (zephir_is_true(&local)) {
					ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getrealsourcepath", NULL, 0, &completeSourcePath);
					zephir_check_call_status();
					if (!(zephir_is_true(&sourcePath))) {
						ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_9$$15);
						object_init_ex(&_9$$15, phalcon_assets_exception_ce);
						ZEPHIR_INIT_LNVAR(_10$$15);
						ZEPHIR_CONCAT_SVS(&_10$$15, "Asset '", &sourcePath, "' does not have a valid source path");
						ZEPHIR_CALL_METHOD(NULL, &_9$$15, "__construct", NULL, 4, &_10$$15);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$15, "phalcon/assets/manager.zep", 435 TSRMLS_CC);
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
				if (!(zephir_is_true(&targetPath))) {
					ZEPHIR_INIT_NVAR(&_11$$17);
					object_init_ex(&_11$$17, phalcon_assets_exception_ce);
					ZEPHIR_INIT_LNVAR(_12$$17);
					ZEPHIR_CONCAT_SVS(&_12$$17, "Asset '", &sourcePath, "' does not have a valid target path");
					ZEPHIR_CALL_METHOD(NULL, &_11$$17, "__construct", NULL, 4, &_12$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$17, "phalcon/assets/manager.zep", 459 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&local)) {
					if (ZEPHIR_IS_EQUAL(&targetPath, &sourcePath)) {
						ZEPHIR_INIT_NVAR(&_13$$19);
						object_init_ex(&_13$$19, phalcon_assets_exception_ce);
						ZEPHIR_INIT_LNVAR(_14$$19);
						ZEPHIR_CONCAT_SVS(&_14$$19, "Asset '", &targetPath, "' have the same source and target paths");
						ZEPHIR_CALL_METHOD(NULL, &_13$$19, "__construct", NULL, 4, &_14$$19);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_13$$19, "phalcon/assets/manager.zep", 468 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if ((zephir_file_exists(&targetPath TSRMLS_CC) == SUCCESS)) {
						ZEPHIR_INIT_NVAR(&_15$$20);
						if (zephir_compare_mtime(&targetPath, &sourcePath TSRMLS_CC)) {
							filterNeeded = 1;
						}
					} else {
						filterNeeded = 1;
					}
				}
			} else {
				ZEPHIR_CALL_METHOD(&path, &asset, "getrealtargeturi", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&prefix)) {
					ZEPHIR_INIT_NVAR(&prefixedPath);
					ZEPHIR_CONCAT_VV(&prefixedPath, &prefix, &path);
				} else {
					ZEPHIR_CPY_WRT(&prefixedPath, &path);
				}
				ZEPHIR_CALL_METHOD(&attributes, &asset, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&parameters);
				array_init(&parameters);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					zephir_array_append(&parameters, &attributes, PH_SEPARATE, "phalcon/assets/manager.zep", 503);
				} else {
					zephir_array_append(&parameters, &prefixedPath, PH_SEPARATE, "phalcon/assets/manager.zep", 505);
				}
				zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/assets/manager.zep", 507);
				ZEPHIR_INIT_NVAR(&html);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&output, &html TSRMLS_CC);
				}
				continue;
			}
			if (filterNeeded == 1) {
				ZEPHIR_CALL_METHOD(&content, &asset, "getcontent", NULL, 0, &completeSourcePath);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&mustFilter, &asset, "getfilter", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE(&mustFilter)) {
					zephir_is_iterable(&filters, 0, "phalcon/assets/manager.zep", 560);
					if (Z_TYPE_P(&filters) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _16$$31)
						{
							ZEPHIR_INIT_NVAR(&filter);
							ZVAL_COPY(&filter, _16$$31);
							if (Z_TYPE_P(&filter) != IS_OBJECT) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 548);
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
							ZEPHIR_CALL_METHOD(&_17$$31, &filters, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_17$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&filter, &filters, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&filter) != IS_OBJECT) {
									ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 548);
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
							zephir_concat_self(&filteredJoinedContent, &filteredContent TSRMLS_CC);
						} else {
							ZEPHIR_INIT_LNVAR(_18$$38);
							ZEPHIR_CONCAT_VS(&_18$$38, &filteredContent, ";");
							zephir_concat_self(&filteredJoinedContent, &_18$$38 TSRMLS_CC);
						}
					}
				} else {
					if (ZEPHIR_IS_TRUE(&join)) {
						zephir_concat_self(&filteredJoinedContent, &content TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(&filteredContent, &content);
					}
				}
				if (!(zephir_is_true(&join))) {
					zephir_file_put_contents(NULL, &targetPath, &filteredContent TSRMLS_CC);
				}
			}
			if (!(zephir_is_true(&join))) {
				ZEPHIR_CALL_METHOD(&path, &asset, "getrealtargeturi", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&prefix)) {
					ZEPHIR_INIT_NVAR(&prefixedPath);
					ZEPHIR_CONCAT_VV(&prefixedPath, &prefix, &path);
				} else {
					ZEPHIR_CPY_WRT(&prefixedPath, &path);
				}
				ZEPHIR_CALL_METHOD(&attributes, &asset, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&local);
				ZVAL_BOOL(&local, 1);
				ZEPHIR_INIT_NVAR(&parameters);
				array_init(&parameters);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					zephir_array_append(&parameters, &attributes, PH_SEPARATE, "phalcon/assets/manager.zep", 617);
				} else {
					zephir_array_append(&parameters, &prefixedPath, PH_SEPARATE, "phalcon/assets/manager.zep", 619);
				}
				zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/assets/manager.zep", 621);
				ZEPHIR_INIT_NVAR(&html);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&output, &html TSRMLS_CC);
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
				if (zephir_fast_count_int(&filters TSRMLS_CC)) {
					if (zephir_is_true(&local)) {
						ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getrealsourcepath", NULL, 0, &completeSourcePath);
						zephir_check_call_status();
						if (!(zephir_is_true(&sourcePath))) {
							ZEPHIR_CALL_METHOD(&sourcePath, &asset, "getpath", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_19$$53);
							object_init_ex(&_19$$53, phalcon_assets_exception_ce);
							ZEPHIR_INIT_LNVAR(_20$$53);
							ZEPHIR_CONCAT_SVS(&_20$$53, "Asset '", &sourcePath, "' does not have a valid source path");
							ZEPHIR_CALL_METHOD(NULL, &_19$$53, "__construct", NULL, 4, &_20$$53);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_19$$53, "phalcon/assets/manager.zep", 435 TSRMLS_CC);
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
					if (!(zephir_is_true(&targetPath))) {
						ZEPHIR_INIT_NVAR(&_21$$55);
						object_init_ex(&_21$$55, phalcon_assets_exception_ce);
						ZEPHIR_INIT_LNVAR(_22$$55);
						ZEPHIR_CONCAT_SVS(&_22$$55, "Asset '", &sourcePath, "' does not have a valid target path");
						ZEPHIR_CALL_METHOD(NULL, &_21$$55, "__construct", NULL, 4, &_22$$55);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_21$$55, "phalcon/assets/manager.zep", 459 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&local)) {
						if (ZEPHIR_IS_EQUAL(&targetPath, &sourcePath)) {
							ZEPHIR_INIT_NVAR(&_23$$57);
							object_init_ex(&_23$$57, phalcon_assets_exception_ce);
							ZEPHIR_INIT_LNVAR(_24$$57);
							ZEPHIR_CONCAT_SVS(&_24$$57, "Asset '", &targetPath, "' have the same source and target paths");
							ZEPHIR_CALL_METHOD(NULL, &_23$$57, "__construct", NULL, 4, &_24$$57);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_23$$57, "phalcon/assets/manager.zep", 468 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if ((zephir_file_exists(&targetPath TSRMLS_CC) == SUCCESS)) {
							ZEPHIR_INIT_NVAR(&_25$$58);
							if (zephir_compare_mtime(&targetPath, &sourcePath TSRMLS_CC)) {
								filterNeeded = 1;
							}
						} else {
							filterNeeded = 1;
						}
					}
				} else {
					ZEPHIR_CALL_METHOD(&path, &asset, "getrealtargeturi", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&prefix)) {
						ZEPHIR_INIT_NVAR(&prefixedPath);
						ZEPHIR_CONCAT_VV(&prefixedPath, &prefix, &path);
					} else {
						ZEPHIR_CPY_WRT(&prefixedPath, &path);
					}
					ZEPHIR_CALL_METHOD(&attributes, &asset, "getattributes", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&parameters);
					array_init(&parameters);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						zephir_array_append(&parameters, &attributes, PH_SEPARATE, "phalcon/assets/manager.zep", 503);
					} else {
						zephir_array_append(&parameters, &prefixedPath, PH_SEPARATE, "phalcon/assets/manager.zep", 505);
					}
					zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/assets/manager.zep", 507);
					ZEPHIR_INIT_NVAR(&html);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_concat_self(&output, &html TSRMLS_CC);
					}
					continue;
				}
				if (filterNeeded == 1) {
					ZEPHIR_CALL_METHOD(&content, &asset, "getcontent", NULL, 0, &completeSourcePath);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&mustFilter, &asset, "getfilter", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE(&mustFilter)) {
						zephir_is_iterable(&filters, 0, "phalcon/assets/manager.zep", 560);
						if (Z_TYPE_P(&filters) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _26$$69)
							{
								ZEPHIR_INIT_NVAR(&filter);
								ZVAL_COPY(&filter, _26$$69);
								if (Z_TYPE_P(&filter) != IS_OBJECT) {
									ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 548);
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
								ZEPHIR_CALL_METHOD(&_27$$69, &filters, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_27$$69)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&filter, &filters, "current", NULL, 0);
								zephir_check_call_status();
									if (Z_TYPE_P(&filter) != IS_OBJECT) {
										ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 548);
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
								zephir_concat_self(&filteredJoinedContent, &filteredContent TSRMLS_CC);
							} else {
								ZEPHIR_INIT_LNVAR(_28$$76);
								ZEPHIR_CONCAT_VS(&_28$$76, &filteredContent, ";");
								zephir_concat_self(&filteredJoinedContent, &_28$$76 TSRMLS_CC);
							}
						}
					} else {
						if (ZEPHIR_IS_TRUE(&join)) {
							zephir_concat_self(&filteredJoinedContent, &content TSRMLS_CC);
						} else {
							ZEPHIR_CPY_WRT(&filteredContent, &content);
						}
					}
					if (!(zephir_is_true(&join))) {
						zephir_file_put_contents(NULL, &targetPath, &filteredContent TSRMLS_CC);
					}
				}
				if (!(zephir_is_true(&join))) {
					ZEPHIR_CALL_METHOD(&path, &asset, "getrealtargeturi", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&prefix)) {
						ZEPHIR_INIT_NVAR(&prefixedPath);
						ZEPHIR_CONCAT_VV(&prefixedPath, &prefix, &path);
					} else {
						ZEPHIR_CPY_WRT(&prefixedPath, &path);
					}
					ZEPHIR_CALL_METHOD(&attributes, &asset, "getattributes", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&local);
					ZVAL_BOOL(&local, 1);
					ZEPHIR_INIT_NVAR(&parameters);
					array_init(&parameters);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
						zephir_array_append(&parameters, &attributes, PH_SEPARATE, "phalcon/assets/manager.zep", 617);
					} else {
						zephir_array_append(&parameters, &prefixedPath, PH_SEPARATE, "phalcon/assets/manager.zep", 619);
					}
					zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/assets/manager.zep", 621);
					ZEPHIR_INIT_NVAR(&html);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
						zend_print_zval(&html, 0);
					} else {
						zephir_concat_self(&output, &html TSRMLS_CC);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &assets, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&asset);
	if (zephir_fast_count_int(&filters TSRMLS_CC)) {
		if (ZEPHIR_IS_TRUE(&join)) {
			zephir_file_put_contents(NULL, &completeTargetPath, &filteredJoinedContent TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&targetUri, collection, "gettargeturi", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&prefix)) {
				ZEPHIR_INIT_NVAR(&prefixedPath);
				ZEPHIR_CONCAT_VV(&prefixedPath, &prefix, &targetUri);
			} else {
				ZEPHIR_CPY_WRT(&prefixedPath, &targetUri);
			}
			ZEPHIR_CALL_METHOD(&attributes, collection, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&local, collection, "gettargetlocal", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&parameters);
			array_init(&parameters);
			if (Z_TYPE_P(&attributes) == IS_ARRAY) {
				zephir_array_update_long(&attributes, 0, &prefixedPath, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				zephir_array_append(&parameters, &attributes, PH_SEPARATE, "phalcon/assets/manager.zep", 676);
			} else {
				zephir_array_append(&parameters, &prefixedPath, PH_SEPARATE, "phalcon/assets/manager.zep", 678);
			}
			zephir_array_append(&parameters, &local, PH_SEPARATE, "phalcon/assets/manager.zep", 680);
			ZEPHIR_INIT_NVAR(&html);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&html, callback, &parameters);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE(&useImplicitOutput)) {
				zend_print_zval(&html, 0);
			} else {
				zephir_concat_self(&output, &html TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(&output);

}

/**
 * Traverses a collection and generate its HTML
 *
 * @param string type
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInline) {

	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, *type, type_sub, output, html, codes, filters, filter, code, attributes, content, join, joinedContent, *_0$$3, _1$$3, _27$$3, *_2$$4, _3$$4, _4$$5, _5$$7, _6$$10, _8$$10, _9$$10, _10$$10, _12$$10, *_13$$11, _14$$11, _15$$12, _16$$14, _17$$17, _18$$17, _19$$17, _20$$17, _21$$17, _22$$18, _23$$18, _24$$18, _25$$18, _26$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&codes);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&joinedContent);
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
	if (zephir_fast_count_int(&codes TSRMLS_CC)) {
		zephir_is_iterable(&codes, 0, "phalcon/assets/manager.zep", 744);
		if (Z_TYPE_P(&codes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&codes), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&code);
				ZVAL_COPY(&code, _0$$3);
				ZEPHIR_CALL_METHOD(&attributes, &code, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&content, &code, "getcontent", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&filters, 0, "phalcon/assets/manager.zep", 737);
				if (Z_TYPE_P(&filters) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _2$$4)
					{
						ZEPHIR_INIT_NVAR(&filter);
						ZVAL_COPY(&filter, _2$$4);
						if (Z_TYPE_P(&filter) != IS_OBJECT) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 728);
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
							if (Z_TYPE_P(&filter) != IS_OBJECT) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 728);
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
					zephir_concat_self(&joinedContent, &content TSRMLS_CC);
				} else {
					ZVAL_BOOL(&_8$$10, 0);
					ZVAL_BOOL(&_9$$10, 1);
					ZEPHIR_CALL_CE_STATIC(&_6$$10, phalcon_tag_ce, "taghtml", &_7, 0, type, &attributes, &_8$$10, &_9$$10);
					zephir_check_call_status();
					ZVAL_BOOL(&_8$$10, 1);
					ZEPHIR_CALL_CE_STATIC(&_10$$10, phalcon_tag_ce, "taghtmlclose", &_11, 0, type, &_8$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_12$$10);
					ZEPHIR_CONCAT_VVV(&_12$$10, &_6$$10, &content, &_10$$10);
					zephir_concat_self(&html, &_12$$10 TSRMLS_CC);
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
					zephir_is_iterable(&filters, 0, "phalcon/assets/manager.zep", 737);
					if (Z_TYPE_P(&filters) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _13$$11)
						{
							ZEPHIR_INIT_NVAR(&filter);
							ZVAL_COPY(&filter, _13$$11);
							if (Z_TYPE_P(&filter) != IS_OBJECT) {
								ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 728);
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
								if (Z_TYPE_P(&filter) != IS_OBJECT) {
									ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_assets_exception_ce, "Filter is invalid", "phalcon/assets/manager.zep", 728);
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
						zephir_concat_self(&joinedContent, &content TSRMLS_CC);
					} else {
						ZVAL_BOOL(&_18$$17, 0);
						ZVAL_BOOL(&_19$$17, 1);
						ZEPHIR_CALL_CE_STATIC(&_17$$17, phalcon_tag_ce, "taghtml", &_7, 0, type, &attributes, &_18$$17, &_19$$17);
						zephir_check_call_status();
						ZVAL_BOOL(&_18$$17, 1);
						ZEPHIR_CALL_CE_STATIC(&_20$$17, phalcon_tag_ce, "taghtmlclose", &_11, 0, type, &_18$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_21$$17);
						ZEPHIR_CONCAT_VVV(&_21$$17, &_17$$17, &content, &_20$$17);
						zephir_concat_self(&html, &_21$$17 TSRMLS_CC);
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
			zephir_concat_self(&html, &_26$$18 TSRMLS_CC);
		}
		zephir_read_property(&_27$$3, this_ptr, SL("implicitOutput"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE(&_27$$3)) {
			zend_print_zval(&html, 0);
		} else {
			zephir_concat_self(&output, &html TSRMLS_CC);
		}
	}
	RETURN_CCTOR(&output);

}

/**
 * Prints the HTML for CSS assets
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName_param = NULL, collection, _1;
	zval collectionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_1);
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
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Tag");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "stylesheetLink");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "output", NULL, 0, &collection, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the HTML for inline CSS
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInlineCss) {

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
 * Prints the HTML for JS assets
 */
PHP_METHOD(Phalcon_Assets_Manager, outputJs) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName_param = NULL, collection, _1;
	zval collectionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_1);
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
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Tag");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "javascriptInclude");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "output", NULL, 0, &collection, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the HTML for inline JS
 */
PHP_METHOD(Phalcon_Assets_Manager, outputInlineJs) {

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
 * Returns existing collections in the manager
 */
PHP_METHOD(Phalcon_Assets_Manager, getCollections) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "collections");

}

/**
 * Returns true or false if collection exists.
 *
 * <code>
 * if (assets->exists("jsHeader")) {
 *     // \Phalcon\Assets\Collection
 *     $collection = assets->get("jsHeader");
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Assets_Manager, exists) {

	zval *id_param = NULL, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	if (UNEXPECTED(Z_TYPE_P(id_param) != IS_STRING && Z_TYPE_P(id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'id' must be of the type string") TSRMLS_CC);
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

