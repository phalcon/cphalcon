
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
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
	zval type_zv, path_zv, *isLocal_param = NULL, *filter_param = NULL, *attributes_param = NULL, version_zv, *isAutoVersion_param = NULL, __$true, __$false;
	zend_string *type = NULL, *path = NULL, *version = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&version_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&attributes);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 7)
		Z_PARAM_STR(type)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isLocal)
		Z_PARAM_BOOL(filter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(isAutoVersion)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		isLocal_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		filter_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		attributes_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 6) {
		isAutoVersion_param = ZEND_CALL_ARG(execute_data, 7);
	}
	ZVAL_STR_COPY(&type_zv, type);
	ZVAL_STR_COPY(&path_zv, path);
	if (!isLocal_param) {
		isLocal = 1;
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
		ZVAL_STR_COPY(&version_zv, version);
	}
	if (!isAutoVersion_param) {
		isAutoVersion = 0;
	} else {
		}
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path_zv);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("version"), &version_zv);
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_VSV(&key, &_0, ":", &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sha256");
	ZEPHIR_RETURN_CALL_FUNCTION("hash", NULL, 77, &_2, &key);
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
	zval basePath_zv, completePath, content, _0, _1, _2, _4;
	zend_string *basePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_zv);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!basePath) {
		ZEPHIR_INIT_VAR(&basePath_zv);
	} else {
		ZVAL_STR_COPY(&basePath_zv, basePath);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sourcePath");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkpath", NULL, 78, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath_zv, &_0);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("isLocal"), PH_NOISY_CC | PH_READONLY);
	_3 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "phpfileexists", NULL, 0, &completePath);
		zephir_check_call_status();
		_3 = !ZEPHIR_IS_TRUE_IDENTICAL(&_4);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwexception", NULL, 79, &completePath);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&content, this_ptr, "phpfilegetcontents", NULL, 0, &completePath);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&content)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwexception", NULL, 79, &completePath);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&content);
}

PHP_METHOD(Phalcon_Assets_Asset, getFilter)
{

	RETURN_MEMBER(getThis(), "filter");
}

PHP_METHOD(Phalcon_Assets_Asset, getPath)
{

	RETURN_MEMBER(getThis(), "path");
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
	zval _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval basePath_zv, source, _0, _1, _2$$3, _3$$3;
	zend_string *basePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_zv);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!basePath) {
		ZEPHIR_INIT_VAR(&basePath_zv);
	} else {
		ZVAL_STR_COPY(&basePath_zv, basePath);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sourcePath");
	ZEPHIR_CALL_METHOD(&source, this_ptr, "checkpath", NULL, 78, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("isLocal"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VV(&_2$$3, &basePath_zv, &source);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "realpath", NULL, 80, &_2$$3);
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
	zval basePath_zv, completePath, target, _0, _1, _2$$3, _3$$4;
	zend_string *basePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_zv);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!basePath) {
		ZEPHIR_INIT_VAR(&basePath_zv);
	} else {
		ZVAL_STR_COPY(&basePath_zv, basePath);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "targetPath");
	ZEPHIR_CALL_METHOD(&target, this_ptr, "checkpath", NULL, 78, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("isLocal"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&completePath);
		ZEPHIR_CONCAT_VV(&completePath, &basePath_zv, &target);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "phpfileexists", NULL, 0, &completePath);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_2$$3)) {
			ZEPHIR_CALL_FUNCTION(&_3$$4, "realpath", NULL, 80, &completePath);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "targetUri");
	ZEPHIR_CALL_METHOD(&target, this_ptr, "checkpath", NULL, 78, &_0);
	zephir_check_call_status();
	zephir_memory_observe(&ver);
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

PHP_METHOD(Phalcon_Assets_Asset, getSourcePath)
{

	RETURN_MEMBER(getThis(), "sourcePath");
}

PHP_METHOD(Phalcon_Assets_Asset, getTargetPath)
{

	RETURN_MEMBER(getThis(), "targetPath");
}

PHP_METHOD(Phalcon_Assets_Asset, getTargetUri)
{

	RETURN_MEMBER(getThis(), "targetUri");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, getType)
{

	RETURN_MEMBER(getThis(), "type");
}

/**
 * Version of resource
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Assets_Asset, getVersion)
{

	RETURN_MEMBER(getThis(), "version");
}

/**
 * Checks if the asset is using auto version
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Asset, isAutoVersion)
{

	RETURN_MEMBER(getThis(), "isAutoVersion");
}

/**
 * Checks if the asset is local or not
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Asset, isLocal)
{

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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(filter)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &filter_param);
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
PHP_METHOD(Phalcon_Assets_Asset, setIsLocal)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
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
	zval sourcePath_zv;
	zend_string *sourcePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sourcePath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&sourcePath_zv, sourcePath);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sourcePath"), &sourcePath_zv);
	RETURN_THISW();
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
	zval targetPath_zv;
	zend_string *targetPath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetPath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&targetPath_zv, targetPath);
	zephir_update_property_zval(this_ptr, ZEND_STRL("targetPath"), &targetPath_zv);
	RETURN_THISW();
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
	zval targetUri_zv;
	zend_string *targetUri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetUri)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&targetUri_zv, targetUri);
	zephir_update_property_zval(this_ptr, ZEND_STRL("targetUri"), &targetUri_zv);
	RETURN_THISW();
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
	zval type_zv;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&type_zv, type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	RETURN_THISW();
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
	zval path_zv;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&path_zv, path);
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path_zv);
	RETURN_THISW();
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
	zval version_zv;
	zend_string *version = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(version)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&version_zv, version);
	zephir_update_property_zval(this_ptr, ZEND_STRL("version"), &version_zv);
	RETURN_THISW();
}

/**
 * @param string $property
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, checkPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval property_zv, _0, _1;
	zend_string *property = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&property_zv, property);
	zephir_memory_observe(&_0);
	zephir_read_property_zval(&_0, this_ptr, &property_zv, PH_NOISY_CC);
	if (1 == ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_MEMBER(getThis(), "path");
	}
	zephir_memory_observe(&_1);
	zephir_read_property_zval(&_1, this_ptr, &property_zv, PH_NOISY_CC);
	RETURN_CCTOR(&_1);
}

/**
 * @param string $completePath
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Assets_Asset, throwException)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval completePath_zv, _0;
	zend_string *completePath = NULL;

	ZVAL_UNDEF(&completePath_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(completePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&completePath_zv, completePath);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_exception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "Asset's content for '", &completePath_zv, "' cannot be read");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 32, &_1);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Assets/Asset.zep", 472);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Assets_Asset, phpFileExists)
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

PHP_METHOD(Phalcon_Assets_Asset, phpFileGetContents)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	zephir_file_get_contents(return_value, &filename_zv);
	return;
}

