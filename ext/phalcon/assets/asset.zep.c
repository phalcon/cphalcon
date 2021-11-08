
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
#include "kernel/file.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Represents an asset asset
 *
 *```php
 * $asset = new \Phalcon\Assets\Asset("js", "javascripts/jquery.js");
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Asset)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Asset, phalcon, assets_asset, phalcon_assets_asset_method_entry, 0);

	/**
	 * @var array | null
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_asset_ce, SL("autoVersion"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("filter"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("local"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("path"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("sourcePath"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("targetPath"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("targetUri"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("type"), ZEND_ACC_PROTECTED);
	/**
	 * Version of resource
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("version"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_assets_asset_ce, 1, phalcon_assets_assetinterface_ce);
	return SUCCESS;
}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getAttributes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "attributes");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, setAutoVersion)
{
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
PHP_METHOD(Phalcon_Assets_Asset, getFilter)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "filter");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getLocal)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "local");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "path");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getSourcePath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "sourcePath");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getTargetPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "targetPath");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getTargetUri)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "targetUri");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getType)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "type");
}

/**
 * Version of resource
 */
PHP_METHOD(Phalcon_Assets_Asset, getVersion)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "version");
}

/**
 * Version of resource
 */
PHP_METHOD(Phalcon_Assets_Asset, setVersion)
{
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
 * Phalcon\Assets\Asset constructor
 */
PHP_METHOD(Phalcon_Assets_Asset, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes;
	zend_bool local, filter, autoVersion;
	zval *type_param = NULL, *path_param = NULL, *local_param = NULL, *filter_param = NULL, *attributes_param = NULL, *version_param = NULL, *autoVersion_param = NULL, __$true, __$false;
	zval type, path, version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 7)
		Z_PARAM_STR(type)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(local)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 5, &type_param, &path_param, &local_param, &filter_param, &attributes_param, &version_param, &autoVersion_param);
	zephir_get_strval(&type, type_param);
	zephir_get_strval(&path, path_param);
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!version_param) {
		ZEPHIR_INIT_VAR(&version);
	} else {
		zephir_get_strval(&version, version_param);
	}
	if (!autoVersion_param) {
		autoVersion = 0;
	} else {
		autoVersion = zephir_get_boolval(autoVersion_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path);
	if (local) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("local"), &__$false);
	}
	if (filter) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	zephir_update_property_zval(this_ptr, ZEND_STRL("version"), &version);
	if (autoVersion) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoVersion"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoVersion"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Gets the asset's key.
 */
PHP_METHOD(Phalcon_Assets_Asset, getAssetKey)
{
	zval key, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_VSV(&key, &_0, ":", &_1);
	zephir_md5(return_value, &key);
	RETURN_MM();
}

/**
 * Returns the content of the asset as an string
 * Optionally a base path where the asset is located can be set
 */
PHP_METHOD(Phalcon_Assets_Asset, getContent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, sourcePath, completePath, content, _0, _1$$5, _2$$5, _3$$6, _4$$6;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);
	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("sourcePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sourcePath, &_0);
	if (ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_OBS_NVAR(&sourcePath);
		zephir_read_property(&sourcePath, this_ptr, ZEND_STRL("path"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &sourcePath);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		if (UNEXPECTED(!((zephir_file_exists(&completePath) == SUCCESS)))) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_assets_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_SVS(&_2$$5, "Asset's content for '", &completePath, "' cannot be read");
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 8, &_2$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/Assets/Asset.zep", 135);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&content);
	zephir_file_get_contents(&content, &completePath);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&content))) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_assets_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVS(&_4$$6, "Asset's content for '", &completePath, "' cannot be read");
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 8, &_4$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "phalcon/Assets/Asset.zep", 148);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&content);
}

/**
 * Returns the complete location where the asset is located
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealSourcePath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, sourcePath, _0, _1$$4;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);
	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("sourcePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sourcePath, &_0);
	if (ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_OBS_NVAR(&sourcePath);
		zephir_read_property(&sourcePath, this_ptr, ZEND_STRL("path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_VV(&_1$$4, &basePath, &sourcePath);
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 99, &_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&sourcePath);
}

/**
 * Returns the complete location where the asset must be written
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealTargetPath)
{
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
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);
	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("targetPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&targetPath, &_0);
	if (ZEPHIR_IS_EMPTY(&targetPath)) {
		ZEPHIR_OBS_NVAR(&targetPath);
		zephir_read_property(&targetPath, this_ptr, ZEND_STRL("path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&completePath);
		ZEPHIR_CONCAT_VV(&completePath, &basePath, &targetPath);
		if ((zephir_file_exists(&completePath) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 99, &completePath);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&completePath);
	}
	RETURN_CCTOR(&targetPath);
}

/**
 * Returns the real target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealTargetUri)
{
	zend_bool _1;
	zval modificationTime, targetUri, version, _0, _2, _3$$4, _4$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modificationTime);
	ZVAL_UNDEF(&targetUri);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("targetUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&targetUri, &_0);
	if (ZEPHIR_IS_EMPTY(&targetUri)) {
		ZEPHIR_OBS_NVAR(&targetUri);
		zephir_read_property(&targetUri, this_ptr, ZEND_STRL("path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("version"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&version, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("autoVersion"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("local"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getrealsourcepath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&modificationTime);
		zephir_filemtime(&modificationTime, &_3$$4);
		ZEPHIR_INIT_VAR(&_4$$4);
		if (zephir_is_true(&version)) {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZEPHIR_CONCAT_VSV(&_4$$4, &version, ".", &modificationTime);
		} else {
			ZEPHIR_CPY_WRT(&_4$$4, &modificationTime);
		}
		ZEPHIR_CPY_WRT(&version, &_4$$4);
	}
	if (zephir_is_true(&version)) {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZEPHIR_CONCAT_VSV(&_5$$5, &targetUri, "?ver=", &version);
		ZEPHIR_CPY_WRT(&targetUri, &_5$$5);
	}
	RETURN_CCTOR(&targetUri);
}

/**
 * Checks if resource is using auto version
 */
PHP_METHOD(Phalcon_Assets_Asset, isAutoVersion)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "autoVersion");
}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Asset, setAttributes)
{
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
	zephir_get_arrval(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	RETURN_THIS();
}

/**
 * Sets if the asset must be filtered or not
 */
PHP_METHOD(Phalcon_Assets_Asset, setFilter)
{
	zval *filter_param = NULL, __$true, __$false;
	zend_bool filter;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(filter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &filter_param);
	filter = zephir_get_boolval(filter_param);


	if (filter) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets if the asset is local or external
 */
PHP_METHOD(Phalcon_Assets_Asset, setLocal)
{
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
	local = zephir_get_boolval(local_param);


	if (local) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("local"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the asset's source path
 */
PHP_METHOD(Phalcon_Assets_Asset, setSourcePath)
{
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
	zephir_get_strval(&sourcePath, sourcePath_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("sourcePath"), &sourcePath);
	RETURN_THIS();
}

/**
 * Sets the asset's target path
 */
PHP_METHOD(Phalcon_Assets_Asset, setTargetPath)
{
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
	zephir_get_strval(&targetPath, targetPath_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("targetPath"), &targetPath);
	RETURN_THIS();
}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Asset, setTargetUri)
{
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
	zephir_get_strval(&targetUri, targetUri_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("targetUri"), &targetUri);
	RETURN_THIS();
}

/**
 * Sets the asset's type
 */
PHP_METHOD(Phalcon_Assets_Asset, setType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);
	zephir_get_strval(&type, type_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	RETURN_THIS();
}

/**
 * Sets the asset's path
 */
PHP_METHOD(Phalcon_Assets_Asset, setPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);
	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path);
	RETURN_THIS();
}

