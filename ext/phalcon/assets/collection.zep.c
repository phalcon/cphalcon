
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
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
 * Represents a collection of assets
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Collection, phalcon, assets_collection, phalcon_assets_collection_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("assets"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("attributes"), ZEND_ACC_PROTECTED);

	/**
	 * Should version be determined from file modification time
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("autoVersion"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("codes"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("filters"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("includedAssets"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("join"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("local"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("prefix"), ZEND_ACC_PROTECTED);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_assets_collection_ce, SL("position"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("sourcePath"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("targetLocal"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("targetPath"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("targetUri"), ZEND_ACC_PROTECTED);

	/**
	 * Version of resource
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("version"), ZEND_ACC_PROTECTED);

	phalcon_assets_collection_ce->create_object = zephir_init_properties_Phalcon_Assets_Collection;

	zend_class_implements(phalcon_assets_collection_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_assets_collection_ce, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getAssets) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "assets");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getAttributes) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "attributes");

}

/**
 * Should version be determined from file modification time
 */
PHP_METHOD(Phalcon_Assets_Collection, setAutoVersion) {

	zval *autoVersion_param = NULL, __$true, __$false;
	zend_bool autoVersion;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &autoVersion_param);

	autoVersion = zephir_get_boolval(autoVersion_param);


	if (autoVersion) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoVersion"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoVersion"), &__$false);
	}
	RETURN_THISW();

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getCodes) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "codes");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getFilters) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "filters");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getJoin) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "join");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getLocal) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "local");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getPrefix) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "prefix");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getPosition) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "position");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getSourcePath) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "sourcePath");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "targetLocal");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetPath) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "targetPath");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetUri) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "targetUri");

}

/**
 * Version of resource
 */
PHP_METHOD(Phalcon_Assets_Collection, getVersion) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "version");

}

/**
 * Version of resource
 */
PHP_METHOD(Phalcon_Assets_Collection, setVersion) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *version_param = NULL;
	zval version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(version)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version_param);

	zephir_get_strval(&version, version_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("version"), &version);
	RETURN_THIS();

}

/**
 * Phalcon\Assets\Collection constructor
 */
PHP_METHOD(Phalcon_Assets_Collection, __construct) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("includedAssets"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a asset to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_assetinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &asset);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addasset", NULL, 163, asset);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a CSS asset to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter, autoVersion;
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, *version_param = NULL, *autoVersion_param = NULL, __$null, collectionLocal, collectionAttributes, _0, _1, _2;
	zval path, version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionLocal);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(local)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();

#endif


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
		local = &__$null;
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


	if (((Z_TYPE_P(local) == IS_TRUE || Z_TYPE_P(local) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&collectionLocal, local);
	} else {
		ZEPHIR_OBS_NVAR(&collectionLocal);
		zephir_read_property(&collectionLocal, this_ptr, ZEND_STRL("local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 164, &path, &collectionLocal, &_1, &collectionAttributes, &version, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a filter to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter) {

	zval *filter, filter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(filter, phalcon_assets_filterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &filter);



	zephir_update_property_array_append(this_ptr, SL("filters"), filter);
	RETURN_THISW();

}

/**
 * Adds an inline code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInline) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(code, phalcon_assets_inline_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addasset", NULL, 163, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline CSS to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionAttributes, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes);

	zephir_get_strval(&content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_css_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 165, &content, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("codes"), &_0);
	RETURN_THIS();

}

/**
 * Adds an inline JavaScript to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionAttributes, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes);

	zephir_get_strval(&content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_js_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 166, &content, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("codes"), &_0);
	RETURN_THIS();

}

/**
 * Adds a JavaScript asset to the collection
 *
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter, autoVersion;
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, *version_param = NULL, *autoVersion_param = NULL, __$null, collectionLocal, collectionAttributes, _0, _1, _2;
	zval path, version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionLocal);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(local)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();

#endif


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
		local = &__$null;
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


	if (((Z_TYPE_P(local) == IS_TRUE || Z_TYPE_P(local) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&collectionLocal, local);
	} else {
		ZEPHIR_OBS_NVAR(&collectionLocal);
		zephir_read_property(&collectionLocal, this_ptr, ZEND_STRL("local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 167, &path, &collectionLocal, &_1, &collectionAttributes, &version, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Assets_Collection, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("assets"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));

}

/**
 * Returns the current asset in the iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, current) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("assets"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalcon/Assets/Collection.zep", 261);
	RETURN_CTOR(&_1);

}

/**
 * Returns the complete location where the joined/filtered collection must
 * be written
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, targetPath, completePath, _0;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(basePath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (UNEXPECTED(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(basePath_param) == IS_STRING)) {
		zephir_get_strval(&basePath, basePath_param);
	} else {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_EMPTY_STRING(&basePath);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("targetPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&targetPath, &_0);
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &targetPath);
	if ((zephir_file_exists(&completePath) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 94, &completePath);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&completePath);

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
PHP_METHOD(Phalcon_Assets_Collection, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, key, assets;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&assets);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_assetinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &asset);



	ZEPHIR_CALL_METHOD(&key, asset, "getassetkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&assets);
	zephir_read_property(&assets, this_ptr, ZEND_STRL("includedAssets"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_fast_in_array(&key, &assets));

}

/**
 * Checks if collection is using auto version
 */
PHP_METHOD(Phalcon_Assets_Collection, isAutoVersion) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "autoVersion");

}

/**
 * Sets if all filtered assets in the collection must be joined in a single
 * result file
 */
PHP_METHOD(Phalcon_Assets_Collection, join) {

	zval *join_param = NULL, __$true, __$false;
	zend_bool join;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(join)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &join_param);

	join = zephir_get_boolval(join_param);


	if (join) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("join"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("join"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, key) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Assets_Collection, next) {

	zval *this_ptr = getThis();



	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("position")));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, rewind) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("position"), &_0);

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, setAttributes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Sets an array of filters in the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setFilters) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filters_param = NULL;
	zval filters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(filters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filters_param);

	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), &filters);
	RETURN_THIS();

}

/**
 * Sets if the collection uses local assets by default
 */
PHP_METHOD(Phalcon_Assets_Collection, setLocal) {

	zval *local_param = NULL, __$true, __$false;
	zend_bool local;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(local)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &local_param);

	if (UNEXPECTED(Z_TYPE_P(local_param) != IS_TRUE && Z_TYPE_P(local_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'local' must be of the type bool"));
		RETURN_NULL();
	}
	local = (Z_TYPE_P(local_param) == IS_TRUE);


	if (local) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("local"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets a common prefix for all the assets
 */
PHP_METHOD(Phalcon_Assets_Collection, setPrefix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prefix_param = NULL;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Sets the target local
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal) {

	zval *targetLocal_param = NULL, __$true, __$false;
	zend_bool targetLocal;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(targetLocal)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &targetLocal_param);

	if (UNEXPECTED(Z_TYPE_P(targetLocal_param) != IS_TRUE && Z_TYPE_P(targetLocal_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetLocal' must be of the type bool"));
		RETURN_NULL();
	}
	targetLocal = (Z_TYPE_P(targetLocal_param) == IS_TRUE);


	if (targetLocal) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("targetLocal"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("targetLocal"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets the target path of the file for the filtered/join output
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *targetPath_param = NULL;
	zval targetPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetPath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	if (UNEXPECTED(Z_TYPE_P(targetPath_param) != IS_STRING && Z_TYPE_P(targetPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetPath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(targetPath_param) == IS_STRING)) {
		zephir_get_strval(&targetPath, targetPath_param);
	} else {
		ZEPHIR_INIT_VAR(&targetPath);
		ZVAL_EMPTY_STRING(&targetPath);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("targetPath"), &targetPath);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *targetUri_param = NULL;
	zval targetUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetUri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetUri_param);

	if (UNEXPECTED(Z_TYPE_P(targetUri_param) != IS_STRING && Z_TYPE_P(targetUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetUri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(targetUri_param) == IS_STRING)) {
		zephir_get_strval(&targetUri, targetUri_param);
	} else {
		ZEPHIR_INIT_VAR(&targetUri);
		ZVAL_EMPTY_STRING(&targetUri);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("targetUri"), &targetUri);
	RETURN_THIS();

}

/**
 * Sets a base source path for all the assets in this collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sourcePath_param = NULL;
	zval sourcePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sourcePath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sourcePath_param);

	if (UNEXPECTED(Z_TYPE_P(sourcePath_param) != IS_STRING && Z_TYPE_P(sourcePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sourcePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sourcePath_param) == IS_STRING)) {
		zephir_get_strval(&sourcePath, sourcePath_param);
	} else {
		ZEPHIR_INIT_VAR(&sourcePath);
		ZVAL_EMPTY_STRING(&sourcePath);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("sourcePath"), &sourcePath);
	RETURN_THIS();

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Assets_Collection, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("assets"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Adds a asset or inline-code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addAsset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(asset, phalcon_assets_assetinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &asset);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, asset);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_instance_of_ev(asset, phalcon_assets_asset_ce)) {
		zephir_update_property_array_append(this_ptr, SL("assets"), asset);
	} else {
		zephir_update_property_array_append(this_ptr, SL("codes"), asset);
	}
	ZEPHIR_CALL_METHOD(&_1, asset, "getassetkey", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("includedAssets"), &_1);
	RETURN_MM_BOOL(1);

}

zend_object *zephir_init_properties_Phalcon_Assets_Collection(zend_class_entry *class_type) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("filters"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("codes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("codes"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("assets"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("assets"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

