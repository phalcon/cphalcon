
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
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
 * Collection of asset objects
 *
 * @property array  $assets
 * @property array  $attributes
 * @property bool   $autoVersion
 * @property array  $codes
 * @property array  $filters
 * @property bool   $join
 * @property bool   $isLocal
 * @property string $prefix
 * @property string $sourcePath
 * @property bool   $targetIsLocal
 * @property string $targetPath
 * @property string $targetUri
 * @property string $version
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection)
{
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
	 *
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
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("join"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("isLocal"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_assets_collection_ce, SL("prefix"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_assets_collection_ce, SL("sourcePath"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("targetIsLocal"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_assets_collection_ce, SL("targetPath"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_assets_collection_ce, SL("targetUri"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_assets_collection_ce, SL("version"), "", ZEND_ACC_PROTECTED);
	phalcon_assets_collection_ce->create_object = zephir_init_properties_Phalcon_Assets_Collection;

	zend_class_implements(phalcon_assets_collection_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_assets_collection_ce, 1, zend_ce_aggregate);
	return SUCCESS;
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getAssets)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "assets");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getAttributes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "attributes");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getCodes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "codes");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getFilters)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "filters");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getJoin)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "join");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getPrefix)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "prefix");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getSourcePath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "sourcePath");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetIsLocal)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "targetIsLocal");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetPath)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "targetPath");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetUri)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "targetUri");
}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getVersion)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "version");
}

/**
 * Adds an asset to the collection
 *
 * @param AssetInterface $asset
 */
PHP_METHOD(Phalcon_Assets_Collection, add)
{
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addasset", NULL, 157, asset);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds a CSS asset to the collection
 *
 * @param string      $path
 * @param bool|null   $isLocal
 * @param bool        $filter
 * @param array       $attributes
 * @param string|null $version
 * @param bool        $autoVersion
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter, autoVersion;
	zval *path_param = NULL, *isLocal = NULL, isLocal_sub, *filter_param = NULL, *attributes_param = NULL, *version_param = NULL, *autoVersion_param = NULL, __$null, _0, _1, _2;
	zval path, version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&isLocal_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(isLocal)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &path_param, &isLocal, &filter_param, &attributes_param, &version_param, &autoVersion_param);
	zephir_get_strval(&path, path_param);
	if (!isLocal) {
		isLocal = &isLocal_sub;
		isLocal = &__$null;
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Css");
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processadd", NULL, 158, &_0, &path, isLocal, &_1, &attributes, &version, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a filter to the collection
 *
 * @param FilterInterface $filter
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter)
{
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
 *
 * @param Inline $code
 */
PHP_METHOD(Phalcon_Assets_Collection, addInline)
{
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addasset", NULL, 157, code);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an inline CSS to the collection
 *
 * @param string $content
 * @param bool   $filter
 * @param array  $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes_param = NULL, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes_param);
	zephir_get_strval(&content, content_param);
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Css");
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processaddinline", NULL, 159, &_0, &content, &_1, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds an inline JavaScript to the collection
 *
 * @param string $content
 * @param bool   $filter
 * @param array  $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes_param = NULL, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes_param);
	zephir_get_strval(&content, content_param);
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Js");
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processaddinline", NULL, 159, &_0, &content, &_1, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds a JavaScript asset to the collection
 *
 * @param string      $path
 * @param bool|null   $isLocal
 * @param bool        $filter
 * @param array       $attributes
 * @param string|null $version
 * @param bool        $autoVersion
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter, autoVersion;
	zval *path_param = NULL, *isLocal = NULL, isLocal_sub, *filter_param = NULL, *attributes_param = NULL, *version_param = NULL, *autoVersion_param = NULL, __$null, _0, _1, _2;
	zval path, version;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&isLocal_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(isLocal)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &path_param, &isLocal, &filter_param, &attributes_param, &version_param, &autoVersion_param);
	zephir_get_strval(&path, path_param);
	if (!isLocal) {
		isLocal = &isLocal_sub;
		isLocal = &__$null;
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Js");
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processadd", NULL, 158, &_0, &path, isLocal, &_1, &attributes, &version, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the count of the assets
 *
 * @return int
 *
 * @link https://php.net/manual/en/countable.count.php
 */
PHP_METHOD(Phalcon_Assets_Collection, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("assets"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Returns the generator of the class
 *
 * @link https://php.net/manual/en/iteratoraggregate.getiterator.php
 */
PHP_METHOD(Phalcon_Assets_Collection, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("assets"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 13, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the complete location where the joined/filtered collection must
 * be written
 *
 * @param string $basePath
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, completePath, _0;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
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
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("targetPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &_0);
	if (1 == (zephir_file_exists(&completePath) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 71, &completePath);
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
 *
 * @param AssetInterface $asset
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Collection, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, key, storedAsset, _0, *_1, _2, _3$$3, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&storedAsset);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("assets"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Assets/Collection.zep", 307);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&storedAsset);
			ZVAL_COPY(&storedAsset, _1);
			ZEPHIR_CALL_METHOD(&_3$$3, &storedAsset, "getassetkey", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_IDENTICAL(&key, &_3$$3)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&storedAsset, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$5, &storedAsset, "getassetkey", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&key, &_4$$5)) {
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&storedAsset);
	RETURN_MM_BOOL(0);
}

/**
 * Checks if collection is using auto version
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Collection, isAutoVersion)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "autoVersion");
}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Collection, isLocal)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "isLocal");
}

/**
 * Sets if all filtered assets in the collection must be joined in a single
 * result file
 *
 * @param bool $flag
 *
 * @return Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, join)
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("join"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("join"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets extra HTML attributes
 *
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, setAttributes)
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
 */
PHP_METHOD(Phalcon_Assets_Collection, setAutoVersion)
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoVersion"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoVersion"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets an array of filters in the collection
 *
 * @param array $filters
 */
PHP_METHOD(Phalcon_Assets_Collection, setFilters)
{
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
	zephir_get_arrval(&filters, filters_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), &filters);
	RETURN_THIS();
}

/**
 * Sets if the collection uses local assets by default
 *
 * @param bool $flag
 */
PHP_METHOD(Phalcon_Assets_Collection, setIsLocal)
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
 * Sets a common prefix for all the assets
 *
 * @param string $prefix
 */
PHP_METHOD(Phalcon_Assets_Collection, setPrefix)
{
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
	zephir_get_strval(&prefix, prefix_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &prefix);
	RETURN_THIS();
}

/**
 * Sets if the target local or not
 *
 * @param bool $flag
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetIsLocal)
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("targetIsLocal"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("targetIsLocal"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the target path of the file for the filtered/join output
 *
 * @param string $targetPath
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath)
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
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri)
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
 * Sets a base source path for all the assets in this collection
 *
 * @param string $sourcePath
 */
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath)
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
 * Sets the version
 *
 * @param string $version
 */
PHP_METHOD(Phalcon_Assets_Collection, setVersion)
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
 * Adds an asset or inline-code to the collection
 *
 * @param AssetInterface $asset
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Assets_Collection, addAsset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, _0, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
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
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_instance_of_ev(asset, phalcon_assets_asset_ce)) {
		ZEPHIR_CALL_METHOD(&_1$$4, asset, "getassetkey", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("assets"), &_1$$4, asset);
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_array_append(this_ptr, SL("codes"), asset);
	RETURN_MM_BOOL(1);
}

/**
 * Adds an inline asset
 */
PHP_METHOD(Phalcon_Assets_Collection, processAdd)
{
	zend_class_entry *_3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter, autoVersion;
	zval *className_param = NULL, *path_param = NULL, *isLocal = NULL, isLocal_sub, *filter_param = NULL, *attributes_param = NULL, *version_param = NULL, *autoVersion_param = NULL, __$null, attrs, flag, name, _1, _2, _4, _5;
	zval className, path, version, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&isLocal_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&flag);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 7)
		Z_PARAM_STR(className)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(isLocal)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 5, &className_param, &path_param, &isLocal, &filter_param, &attributes_param, &version_param, &autoVersion_param);
	zephir_get_strval(&className, className_param);
	zephir_get_strval(&path, path_param);
	if (!isLocal) {
		isLocal = &isLocal_sub;
		isLocal = &__$null;
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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "Phalcon\\Assets\\Asset\\", &className);
	ZEPHIR_CPY_WRT(&name, &_0);
	ZEPHIR_OBS_VAR(&flag);
	zephir_read_property(&flag, this_ptr, ZEND_STRL("isLocal"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&attrs, this_ptr, "processattributes", NULL, 160, &attributes);
	zephir_check_call_status();
	if (Z_TYPE_P(isLocal) != IS_NULL) {
		ZEPHIR_INIT_NVAR(&flag);
		ZVAL_BOOL(&flag, zephir_get_boolval(isLocal));
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_fetch_safe_class(&_2, &name);
	_3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2), Z_STRLEN_P(&_2), ZEND_FETCH_CLASS_AUTO);
	if(!_3) {
		RETURN_MM_NULL();
	}
	object_init_ex(&_1, _3);
	if (zephir_has_constructor(&_1)) {
		if (filter) {
			ZVAL_BOOL(&_4, 1);
		} else {
			ZVAL_BOOL(&_4, 0);
		}
		if (autoVersion) {
			ZVAL_BOOL(&_5, 1);
		} else {
			ZVAL_BOOL(&_5, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &path, &flag, &_4, &attrs, &version, &_5);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Adds an inline asset
 */
PHP_METHOD(Phalcon_Assets_Collection, processAddInline)
{
	zend_class_entry *_2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool filter;
	zval *className_param = NULL, *content_param = NULL, *filter_param = NULL, *attributes_param = NULL, asset, attrs, name, _1, _3, _4;
	zval className, content, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&asset);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(className)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &className_param, &content_param, &filter_param, &attributes_param);
	zephir_get_strval(&className, className_param);
	zephir_get_strval(&content, content_param);
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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "Phalcon\\Assets\\Inline\\", &className);
	ZEPHIR_CPY_WRT(&name, &_0);
	ZEPHIR_CALL_METHOD(&attrs, this_ptr, "processattributes", NULL, 160, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&asset);
	zephir_fetch_safe_class(&_1, &name);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	if(!_2) {
		RETURN_MM_NULL();
	}
	object_init_ex(&asset, _2);
	if (zephir_has_constructor(&asset)) {
		if (filter) {
			ZVAL_BOOL(&_3, 1);
		} else {
			ZVAL_BOOL(&_3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &asset, "__construct", NULL, 0, &content, &_3, &attrs);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(&_4, &asset, "getassetkey", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("codes"), &_4, &asset);
	RETURN_THIS();
}

/**
 * @param array $attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Collection, processAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL, _0;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&_0);
	if (1 != ZEPHIR_IS_EMPTY(&attributes)) {
		ZEPHIR_CPY_WRT(&_0, &attributes);
	} else {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);
}

zend_object *zephir_init_properties_Phalcon_Assets_Collection(zend_class_entry *class_type)
{
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

