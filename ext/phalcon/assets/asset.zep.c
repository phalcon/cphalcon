
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
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Assets\Asset
 *
 * Represents an asset asset
 *
 *<code>
 * $asset = new \Phalcon\Assets\Asset("js", "javascripts/jquery.js");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Asset) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Asset, phalcon, assets_asset, phalcon_assets_asset_method_entry, 0);

	/**
	 * @var array | null
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("local"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("sourcePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("targetPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("targetUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_asset_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_assets_asset_ce TSRMLS_CC, 1, phalcon_assets_assetinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getFilter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "filter");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getLocal) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "local");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getSourcePath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sourcePath");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getTargetPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "targetPath");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getTargetUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "targetUri");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Asset, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * Phalcon\Assets\Asset constructor
 */
PHP_METHOD(Phalcon_Assets_Asset, __construct) {

	zval attributes;
	zend_bool local, filter;
	zval *type_param = NULL, *path_param = NULL, *local_param = NULL, *filter_param = NULL, *attributes_param = NULL, __$true, __$false;
	zval type, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&path);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &type_param, &path_param, &local_param, &filter_param, &attributes_param);

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


	zephir_update_property_zval(this_ptr, SL("type"), &type);
	zephir_update_property_zval(this_ptr, SL("path"), &path);
	if (local) {
		zephir_update_property_zval(this_ptr, SL("local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("local"), &__$false);
	}
	if (filter) {
		zephir_update_property_zval(this_ptr, SL("filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("filter"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("attributes"), &attributes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the asset's type
 */
PHP_METHOD(Phalcon_Assets_Asset, setType) {

	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_update_property_zval(this_ptr, SL("type"), &type);
	RETURN_THIS();

}

/**
 * Sets the asset's path
 */
PHP_METHOD(Phalcon_Assets_Asset, setPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("path"), &path);
	RETURN_THIS();

}

/**
 * Sets if the asset is local or external
 */
PHP_METHOD(Phalcon_Assets_Asset, setLocal) {

	zval *local_param = NULL, __$true, __$false;
	zend_bool local;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &local_param);

	local = zephir_get_boolval(local_param);


	if (local) {
		zephir_update_property_zval(this_ptr, SL("local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("local"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if the asset must be filtered or not
 */
PHP_METHOD(Phalcon_Assets_Asset, setFilter) {

	zval *filter_param = NULL, __$true, __$false;
	zend_bool filter;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &filter_param);

	filter = zephir_get_boolval(filter_param);


	if (filter) {
		zephir_update_property_zval(this_ptr, SL("filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("filter"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Asset, setAttributes) {

	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, SL("attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Asset, setTargetUri) {

	zval *targetUri_param = NULL;
	zval targetUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetUri_param);

	zephir_get_strval(&targetUri, targetUri_param);


	zephir_update_property_zval(this_ptr, SL("targetUri"), &targetUri);
	RETURN_THIS();

}

/**
 * Sets the asset's source path
 */
PHP_METHOD(Phalcon_Assets_Asset, setSourcePath) {

	zval *sourcePath_param = NULL;
	zval sourcePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sourcePath_param);

	zephir_get_strval(&sourcePath, sourcePath_param);


	zephir_update_property_zval(this_ptr, SL("sourcePath"), &sourcePath);
	RETURN_THIS();

}

/**
 * Sets the asset's target path
 */
PHP_METHOD(Phalcon_Assets_Asset, setTargetPath) {

	zval *targetPath_param = NULL;
	zval targetPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	zephir_get_strval(&targetPath, targetPath_param);


	zephir_update_property_zval(this_ptr, SL("targetPath"), &targetPath);
	RETURN_THIS();

}

/**
 * Returns the content of the asset as an string
 * Optionally a base path where the asset is located can be set
 */
PHP_METHOD(Phalcon_Assets_Asset, getContent) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	zephir_read_property(&_0, this_ptr, SL("sourcePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sourcePath, &_0);
	if (ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_OBS_NVAR(&sourcePath);
		zephir_read_property(&sourcePath, this_ptr, SL("path"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &sourcePath);
	zephir_read_property(&_0, this_ptr, SL("local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		if (!((zephir_file_exists(&completePath TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_assets_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_SVS(&_2$$5, "Asset's content for '", &completePath, "' cannot be read");
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 4, &_2$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/assets/asset.zep", 175 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&content);
	zephir_file_get_contents(&content, &completePath TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&content)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_assets_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVS(&_4$$6, "Asset's content for '", &completePath, "' cannot be read");
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 4, &_4$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "phalcon/assets/asset.zep", 184 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&content);

}

/**
 * Returns the real target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealTargetUri) {

	zval targetUri, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("targetUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&targetUri, &_0);
	if (ZEPHIR_IS_EMPTY(&targetUri)) {
		ZEPHIR_OBS_NVAR(&targetUri);
		zephir_read_property(&targetUri, this_ptr, SL("path"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&targetUri);

}

/**
 * Returns the complete location where the asset is located
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealSourcePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, sourcePath, _0, _1$$4;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	zephir_read_property(&_0, this_ptr, SL("sourcePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sourcePath, &_0);
	if (ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_OBS_NVAR(&sourcePath);
		zephir_read_property(&sourcePath, this_ptr, SL("path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, SL("local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_VV(&_1$$4, &basePath, &sourcePath);
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 49, &_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&sourcePath);

}

/**
 * Returns the complete location where the asset must be written
 */
PHP_METHOD(Phalcon_Assets_Asset, getRealTargetPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, targetPath, completePath, _0;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	zephir_read_property(&_0, this_ptr, SL("targetPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&targetPath, &_0);
	if (ZEPHIR_IS_EMPTY(&targetPath)) {
		ZEPHIR_OBS_NVAR(&targetPath);
		zephir_read_property(&targetPath, this_ptr, SL("path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, SL("local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&completePath);
		ZEPHIR_CONCAT_VV(&completePath, &basePath, &targetPath);
		if ((zephir_file_exists(&completePath TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 49, &completePath);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&completePath);
	}
	RETURN_CCTOR(&targetPath);

}

/**
 * Gets the asset's key.
 */
PHP_METHOD(Phalcon_Assets_Asset, getAssetKey) {

	zval key, _0, _1;
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

