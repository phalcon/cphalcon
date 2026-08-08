
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
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_asset_ce, SL("isAutoVersion"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("filter"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("path"), ZEND_ACC_PROTECTED);
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
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_asset_ce, SL("isLocal"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_assets_asset_ce, SL("sourcePath"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_assets_asset_ce, SL("targetPath"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_assets_asset_ce, SL("targetUri"), "", ZEND_ACC_PROTECTED);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("path", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("isLocal", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("filter", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("attributes", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("version", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("isAutoVersion", 13, 1);
	}

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
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&path_zv);
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
		zephir_memory_observe(&version_zv);
	ZVAL_STR_COPY(&version_zv, version);
	}
	if (!isAutoVersion_param) {
		isAutoVersion = 0;
	} else {
		}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 140, &type_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 141, &path_zv);
	if (isLocal) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 142, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 142, &__$false);
	}
	if (filter) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 143, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 143, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 144, &attributes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 145, &version_zv);
	if (isAutoVersion) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 146, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 146, &__$false);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phphash", NULL, 0, &_2, &key);
	zephir_check_call_status();
	RETURN_MM();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isLocal", 7, 1);
	}

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
		zephir_memory_observe(&basePath_zv);
	ZVAL_STR_COPY(&basePath_zv, basePath);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sourcePath");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkpath", NULL, 155, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath_zv, &_0);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 142, PH_NOISY_CC | PH_READONLY);
	_3 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "phpfileexists", NULL, 0, &completePath);
		zephir_check_call_status();
		_3 = !ZEPHIR_IS_TRUE_IDENTICAL(&_4);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwexception", NULL, 156, &completePath);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&content, this_ptr, "phpfilegetcontents", NULL, 0, &completePath);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&content)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwexception", NULL, 156, &completePath);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&content);
}

/**
 * Gets if the asset must be filtered or not.
 */
PHP_METHOD(Phalcon_Assets_Asset, getFilter)
{

	RETURN_MEMBER(getThis(), "filter");
}

/**
 * Returns the path for this asset
 */
PHP_METHOD(Phalcon_Assets_Asset, getPath)
{

	RETURN_MEMBER_TYPED(getThis(), "path", IS_STRING);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isLocal", 7, 1);
	}

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
		zephir_memory_observe(&basePath_zv);
	ZVAL_STR_COPY(&basePath_zv, basePath);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sourcePath");
	ZEPHIR_CALL_METHOD(&source, this_ptr, "checkpath", NULL, 155, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 142, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VV(&_2$$3, &basePath_zv, &source);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "realpath", NULL, 157, &_2$$3);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isLocal", 7, 1);
	}

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
		zephir_memory_observe(&basePath_zv);
	ZVAL_STR_COPY(&basePath_zv, basePath);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "targetPath");
	ZEPHIR_CALL_METHOD(&target, this_ptr, "checkpath", NULL, 155, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 142, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&completePath);
		ZEPHIR_CONCAT_VV(&completePath, &basePath_zv, &target);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "phpfileexists", NULL, 0, &completePath);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_2$$3)) {
			ZEPHIR_CALL_FUNCTION(&_3$$4, "realpath", NULL, 157, &completePath);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("version", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("isAutoVersion", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("isLocal", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "targetUri");
	ZEPHIR_CALL_METHOD(&target, this_ptr, "checkpath", NULL, 155, &_0);
	zephir_check_call_status();
	zephir_memory_observe(&ver);
	zephir_read_property_cached(&ver, this_ptr, _zephir_prop_0, 145, PH_NOISY_CC);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 146, PH_NOISY_CC | PH_READONLY);
	_2 = zephir_is_true(&_1);
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 142, PH_NOISY_CC | PH_READONLY);
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
 * Gets the asset's type.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_STRING);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 144, &attributes);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isAutoVersion", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 146, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 146, &__$false);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filter", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(filter)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &filter_param);
	if (filter) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 143, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 143, &__$false);
	}
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("type", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&type_zv, type);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 140, &type_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&path_zv, path);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 141, &path_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("version", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(version)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&version_zv, version);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 145, &version_zv);
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
	zephir_memory_observe(&property_zv);
	ZVAL_STR_COPY(&property_zv, property);
	zephir_memory_observe(&_0);
	zephir_read_property_zval(&_0, this_ptr, &property_zv, PH_NOISY_CC);
	if (1 == ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_MEMBER_TYPED(getThis(), "path", IS_STRING);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval completePath_zv, _0;
	zend_string *completePath = NULL;

	ZVAL_UNDEF(&completePath_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(completePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&completePath_zv);
	ZVAL_STR_COPY(&completePath_zv, completePath);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_exceptions_cannotreadasset_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 158, &completePath_zv);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Assets/Asset.zep", 373);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Gets extra HTML attributes.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Asset, getAttributes)
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 144, PH_NOISY_CC);
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
PHP_METHOD(Phalcon_Assets_Asset, phpFclose)
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
PHP_METHOD(Phalcon_Assets_Asset, phpFgetCsv)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 159, stream, &_0, &separator_zv, enclosure, escape);
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
PHP_METHOD(Phalcon_Assets_Asset, phpFileGetContents)
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
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_2, context, &_3, &_4);
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
PHP_METHOD(Phalcon_Assets_Asset, phpFilePutContents)
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 161, &filename_zv, data, &_0, context);
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
PHP_METHOD(Phalcon_Assets_Asset, phpFopen)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 162, &filename_zv, &mode_zv, &_0, context);
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
PHP_METHOD(Phalcon_Assets_Asset, phpFwrite)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 163, handle, &data_zv, &_0);
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
PHP_METHOD(Phalcon_Assets_Asset, phpIsWritable)
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 164, &filename_zv);
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
PHP_METHOD(Phalcon_Assets_Asset, phpUnlink)
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 165, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $algorithm
 * @param string $data
 * @param bool   $binary
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.hash.php
 */
PHP_METHOD(Phalcon_Assets_Asset, phpHash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool binary;
	zval algorithm_zv, data_zv, *binary_param = NULL, _0;
	zend_string *algorithm = NULL, *data = NULL;

	ZVAL_UNDEF(&algorithm_zv);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(algorithm)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(binary)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		binary_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&algorithm_zv);
	ZVAL_STR_COPY(&algorithm_zv, algorithm);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!binary_param) {
		binary = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (binary ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("hash", NULL, 166, &algorithm_zv, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $knownString
 * @param string $userString
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.hash-equals.php
 */
PHP_METHOD(Phalcon_Assets_Asset, phpHashEquals)
{
	zval knownString_zv, userString_zv;
	zend_string *knownString = NULL, *userString = NULL;

	ZVAL_UNDEF(&knownString_zv);
	ZVAL_UNDEF(&userString_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(knownString)
		Z_PARAM_STR(userString)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&knownString_zv, knownString);
	ZVAL_STR(&userString_zv, userString);
	RETURN_BOOL(zephir_hash_equals(&knownString_zv, &userString_zv));
}

/**
 * @param string $algorithm
 * @param string $data
 * @param string $key
 * @param bool   $binary
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.hash-hmac.php
 */
PHP_METHOD(Phalcon_Assets_Asset, phpHashHmac)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool binary;
	zval algorithm_zv, data_zv, key_zv, *binary_param = NULL, _0;
	zend_string *algorithm = NULL, *data = NULL, *key = NULL;

	ZVAL_UNDEF(&algorithm_zv);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(algorithm)
		Z_PARAM_STR(data)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(binary)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 3) {
		binary_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&algorithm_zv);
	ZVAL_STR_COPY(&algorithm_zv, algorithm);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!binary_param) {
		binary = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (binary ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 167, &algorithm_zv, &data_zv, &key_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, getSourcePath)
{

	RETURN_MEMBER_TYPED(getThis(), "sourcePath", IS_STRING);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, getTargetPath)
{

	RETURN_MEMBER_TYPED(getThis(), "targetPath", IS_STRING);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Asset, getTargetUri)
{

	RETURN_MEMBER_TYPED(getThis(), "targetUri", IS_STRING);
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
 * Sets if the asset is local or external
 *
 * @param bool $flag
 *
 * @return static
 */
PHP_METHOD(Phalcon_Assets_Asset, setIsLocal)
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 142, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 142, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the asset's source path
 *
 * @param string $sourcePath
 *
 * @return static
 */
PHP_METHOD(Phalcon_Assets_Asset, setSourcePath)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 147, &sourcePath_zv);
	RETURN_THISW();
}

/**
 * Sets the asset's target path
 *
 * @param string $targetPath
 *
 * @return static
 */
PHP_METHOD(Phalcon_Assets_Asset, setTargetPath)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 148, &targetPath_zv);
	RETURN_THISW();
}

/**
 * Sets a target uri for the generated HTML
 *
 * @param string $targetUri
 *
 * @return static
 */
PHP_METHOD(Phalcon_Assets_Asset, setTargetUri)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 149, &targetUri_zv);
	RETURN_THISW();
}

