
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
 * Represents an asset
 *
 *```php
 * $asset = new \Phalcon\Assets\Asset("js", "js/jquery.js");
 *```
 *
 * @property array       $attributes
 * @property bool        $isAutoVersion
 * @property bool        $filter
 * @property bool        $isLocal
 * @property string      $path
 * @property string      $sourcePath
 * @property string      $targetPath
 * @property string      $targetUri
 * @property string      $type
 * @property string|null $version
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Asset)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Asset, phalcon, assets_asset, phalcon_assets_asset_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_asset_ce, SL("isAutoVersion"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("filter"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("isLocal"), ZEND_ACC_PROTECTED);
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
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("version"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_assets_asset_ce, 1, phalcon_assets_assetinterface_ce);
	return SUCCESS;
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
 * Asset constructor.
 *
 * @param string      $type
 * @param string      $path
 * @param bool        $isLocal
 * @param bool        $filter
 * @param array       $attributes
 * @param string|null $version
 * @param bool        $isAutoVersion
 */
PHP_METHOD(Phalcon_Assets_Asset, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes;
	zend_bool isLocal, filter, isAutoVersion;
	zval *type_param = NULL, *path_param = NULL, *isLocal_param = NULL, *filter_param = NULL, *attributes_param = NULL, *version_param = NULL, *isAutoVersion_param = NULL, __$true, __$false;
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
		Z_PARAM_BOOL(isLocal)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(isAutoVersion)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 5, &type_param, &path_param, &isLocal_param, &filter_param, &attributes_param, &version_param, &isAutoVersion_param);
	zephir_get_strval(&type, type_param);
	zephir_get_strval(&path, path_param);
	if (!isLocal_param) {
		isLocal = 1;
	} else {
		isLocal = zephir_get_boolval(isLocal_param);
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
	if (!isAutoVersion_param) {
		isAutoVersion = 0;
	} else {
		isAutoVersion = zephir_get_boolval(isAutoVersion_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path);
	if (isLocal) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isLocal"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isLocal"), &__$false);
	}
	if (filter) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	zephir_update_property_zval(this_ptr, ZEND_STRL("version"), &version);
	if (isAutoVersion) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isAutoVersion"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isAutoVersion"), &__$false);
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
	ZEPHIR_RETURN_CALL_FUNCTION("sha1", NULL, 96, &key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets extra HTML attributes.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Asset, getAttributes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "attributes");
}

/**
 * Returns the content of the asset as an string
 * Optionally a base path where the asset is located can be set
 *
 * @param string|null $basePath
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Asset, getContent)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, completePath, content, _0, _1, _2, _4;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
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


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sourcePath");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkpath", NULL, 97, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &_0);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("isLocal"), PH_NOISY_CC | PH_READONLY);
	_3 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "phpfileexists", NULL, 0, &completePath);
		zephir_check_call_status();
		_3 = !ZEPHIR_IS_TRUE_IDENTICAL(&_4);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwexception", NULL, 98, &completePath);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&content, this_ptr, "phpfilegetcontents", NULL, 0, &completePath);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&content)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwexception", NULL, 98, &completePath);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&content);
}

/**
 * Returns the complete location where the asset is located
 *
 * @param string|null $basePath
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealSourcePath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, source, _0, _1, _2$$3, _3$$3;
	zval basePath, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sourcePath");
	ZEPHIR_CALL_METHOD(&source, this_ptr, "checkpath", NULL, 97, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("isLocal"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VV(&_2$$3, &basePath, &source);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "realpath", NULL, 99, &_2$$3);
		zephir_check_call_status();
		zephir_cast_to_string(&_4$$3, &_3$$3);
		ZEPHIR_CPY_WRT(&source, &_4$$3);
	}
	RETURN_CCTOR(&source);
}

/**
 * Returns the complete location where the asset must be written
 *
 * @param string|null $basePath
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealTargetPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, completePath, target, _0, _1, _2$$3, _3$$4;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "targetPath");
	ZEPHIR_CALL_METHOD(&target, this_ptr, "checkpath", NULL, 97, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("isLocal"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&completePath);
		ZEPHIR_CONCAT_VV(&completePath, &basePath, &target);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "phpfileexists", NULL, 0, &completePath);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_2$$3)) {
			ZEPHIR_CALL_FUNCTION(&_3$$4, "realpath", NULL, 99, &completePath);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&completePath, &_3$$4);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&completePath)) {
				ZEPHIR_INIT_NVAR(&completePath);
				ZVAL_STRING(&completePath, "");
			}
		}
		RETURN_CCTOR(&completePath);
	}
	RETURN_CCTOR(&target);
}

/**
 * Returns the real target uri for the generated HTML
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealTargetUri)
{
	zend_bool _2;
	zval modTime, target, ver, _0, _1, _3, _4$$3, _5$$3, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modTime);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&ver);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "targetUri");
	ZEPHIR_CALL_METHOD(&target, this_ptr, "checkpath", NULL, 97, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&ver);
	zephir_read_property(&ver, this_ptr, ZEND_STRL("version"), PH_NOISY_CC);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("isAutoVersion"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_is_true(&_1);
	if (_2) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("isLocal"), PH_NOISY_CC | PH_READONLY);
		_2 = zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getrealsourcepath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&modTime);
		zephir_filemtime(&modTime, &_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		if (zephir_is_true(&ver)) {
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZEPHIR_CONCAT_VSV(&_5$$3, &ver, ".", &modTime);
		} else {
			ZEPHIR_CPY_WRT(&_5$$3, &modTime);
		}
		ZEPHIR_CPY_WRT(&ver, &_5$$3);
	}
	if (1 != ZEPHIR_IS_EMPTY(&ver)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_VSV(&_6$$4, &target, "?ver=", &ver);
		ZEPHIR_CPY_WRT(&target, &_6$$4);
	}
	RETURN_CCTOR(&target);
}

/**
 * Checks if the asset is using auto version
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Asset, isAutoVersion)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "isAutoVersion");
}

/**
 * Checks if the asset is local or not
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Asset, isLocal)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "isLocal");
}

/**
 * Sets extra HTML attributes
 *
 * @param array $attributes
 *
 * @return AssetInterface
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
 * @param bool $flag
 *
 * @return AssetInterface
 */
PHP_METHOD(Phalcon_Assets_Asset, setAutoVersion)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	flag = zephir_get_boolval(flag_param);


	if (flag) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isAutoVersion"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isAutoVersion"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets if the asset must be filtered or not
 *
 * @param bool $filter
 *
 * @return AssetInterface
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
 *
 * @param bool $flag
 *
 * @return AssetInterface
 */
PHP_METHOD(Phalcon_Assets_Asset, setLocal)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	flag = zephir_get_boolval(flag_param);


	if (flag) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isLocal"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isLocal"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the asset's source path
 *
 * @param string $sourcePath
 *
 * @return AssetInterface
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
 *
 * @param string $targetPath
 *
 * @return AssetInterface
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
 *
 * @param string $targetUri
 *
 * @return AssetInterface
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
 *
 * @param string $type
 *
 * @return AssetInterface
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
 *
 * @param string $path
 *
 * @return AssetInterface
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

/**
 * Sets the asset's version
 *
 * @param string $version
 *
 * @return AssetInterface
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
 * @param string $property
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, checkPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *property_param = NULL, _0, _1;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);
	zephir_get_strval(&property, property_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &property, PH_NOISY_CC);
	if (1 == ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_MEMBER(getThis(), "path");
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property_zval(&_1, this_ptr, &property, PH_NOISY_CC);
	RETURN_CCTOR(&_1);
}

/**
 * @param string $completePath
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Asset, throwException)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *completePath_param = NULL, _0;
	zval completePath, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(completePath)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &completePath_param);
	zephir_get_strval(&completePath, completePath_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_exception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "Asset's content for '", &completePath, "' cannot be read");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 30, &_1);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Assets/Asset.zep", 441);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Assets_Asset, phpFileExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filename_param = NULL;
	zval filename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);
	zephir_get_strval(&filename, filename_param);


	RETURN_MM_BOOL((zephir_file_exists(&filename) == SUCCESS));
}

PHP_METHOD(Phalcon_Assets_Asset, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filename_param = NULL;
	zval filename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);
	zephir_get_strval(&filename, filename_param);


	zephir_file_get_contents(return_value, &filename);
	RETURN_MM();
}

