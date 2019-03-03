
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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
 * Phalcon\Assets\Collection
 *
 * Represents a collection of assets
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Collection, phalcon, assets_collection, phalcon_assets_collection_method_entry, 0);

	/**
	 * @var string 
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool 
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("local"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array 
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("assets"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array 
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("codes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("position"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array 
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array 
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool 
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("join"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string 
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("targetUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string 
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("targetPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool 
	 */
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("targetLocal"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string 
	 */
	zend_declare_property_null(phalcon_assets_collection_ce, SL("sourcePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("includedAssets"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_assets_collection_ce->create_object = zephir_init_properties_Phalcon_Assets_Collection;

	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getPrefix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "prefix");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getLocal) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "local");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getAssets) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "assets");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getCodes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "codes");

}

PHP_METHOD(Phalcon_Assets_Collection, getPosition) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "position");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getFilters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "filters");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getJoin) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "join");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "targetUri");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "targetPath");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "targetLocal");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Collection, getSourcePath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sourcePath");

}

/**
 * Phalcon\Assets\Collection constructor
 */
PHP_METHOD(Phalcon_Assets_Collection, __construct) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("includedAssets"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a asset to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &asset);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addasset", NULL, 87, asset);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInline) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addasset", NULL, 87, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Checks this the asset is added to the collection.
 *
 * <code>
 * use Phalcon\Assets\Asset;
 * use Phalcon\Assets\Collection;
 *
 * $collection = new Collection();
 * $asset = new Asset("js", "js/jquery.js");
 * $collection->add($asset);
 * $collection->has($asset); // true
 * </code>
 */
PHP_METHOD(Phalcon_Assets_Collection, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, key, assets;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&assets);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &asset);



	ZEPHIR_CALL_METHOD(&key, asset, "getassetkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&assets);
	zephir_read_property(&assets, this_ptr, SL("includedAssets"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_fast_in_array(&key, &assets TSRMLS_CC));

}

/**
 * Adds a CSS asset to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionLocal, collectionAttributes, _0, _1;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionLocal);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter_param, &attributes);

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


	if (((Z_TYPE_P(local) == IS_TRUE || Z_TYPE_P(local) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&collectionLocal, local);
	} else {
		ZEPHIR_OBS_NVAR(&collectionLocal);
		zephir_read_property(&collectionLocal, this_ptr, SL("local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, SL("attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_asset_css_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 88, &path, &collectionLocal, &_1, &collectionAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline CSS to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss) {

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
		zephir_read_property(&collectionAttributes, this_ptr, SL("attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_css_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 89, &content, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("codes"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	RETURN_THIS();

}

/**
 * Adds a javascript asset to the collection
 *
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local, filter;
	zval *path_param = NULL, *local_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionLocal, collectionAttributes, _0, _1;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionLocal);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local_param, &filter_param, &attributes);

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
	if (!local_param) {
		local = 0;
	} else {
		local = zephir_get_boolval(local_param);
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


	if (1 == 1) {
		ZEPHIR_INIT_VAR(&collectionLocal);
		ZVAL_BOOL(&collectionLocal, local);
	} else {
		ZEPHIR_OBS_NVAR(&collectionLocal);
		zephir_read_property(&collectionLocal, this_ptr, SL("local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, SL("attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_asset_js_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 90, &path, &collectionLocal, &_1, &collectionAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline javascript to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs) {

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
		zephir_read_property(&collectionAttributes, this_ptr, SL("attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_js_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 91, &content, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("codes"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Assets_Collection, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("assets"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

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
	zephir_update_property_zval(this_ptr, SL("position"), &_0);

}

/**
 * Returns the current asset in the iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, current) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("assets"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalcon/assets/collection.zep", 244 TSRMLS_CC);
	RETURN_CTOR(&_1);

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


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("position") TSRMLS_CC));

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Assets_Collection, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("assets"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Sets the target path of the file for the filtered/join output
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath) {

	zval *targetPath_param = NULL;
	zval targetPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	if (UNEXPECTED(Z_TYPE_P(targetPath_param) != IS_STRING && Z_TYPE_P(targetPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetPath' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(targetPath_param) == IS_STRING)) {
		zephir_get_strval(&targetPath, targetPath_param);
	} else {
		ZEPHIR_INIT_VAR(&targetPath);
		ZVAL_EMPTY_STRING(&targetPath);
	}


	zephir_update_property_zval(this_ptr, SL("targetPath"), &targetPath);
	RETURN_THIS();

}

/**
 * Sets a base source path for all the assets in this collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath) {

	zval *sourcePath_param = NULL;
	zval sourcePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sourcePath_param);

	if (UNEXPECTED(Z_TYPE_P(sourcePath_param) != IS_STRING && Z_TYPE_P(sourcePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sourcePath' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sourcePath_param) == IS_STRING)) {
		zephir_get_strval(&sourcePath, sourcePath_param);
	} else {
		ZEPHIR_INIT_VAR(&sourcePath);
		ZVAL_EMPTY_STRING(&sourcePath);
	}


	zephir_update_property_zval(this_ptr, SL("sourcePath"), &sourcePath);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri) {

	zval *targetUri_param = NULL;
	zval targetUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetUri_param);

	if (UNEXPECTED(Z_TYPE_P(targetUri_param) != IS_STRING && Z_TYPE_P(targetUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetUri' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(targetUri_param) == IS_STRING)) {
		zephir_get_strval(&targetUri, targetUri_param);
	} else {
		ZEPHIR_INIT_VAR(&targetUri);
		ZVAL_EMPTY_STRING(&targetUri);
	}


	zephir_update_property_zval(this_ptr, SL("targetUri"), &targetUri);
	RETURN_THIS();

}

/**
 * Sets a common prefix for all the assets
 */
PHP_METHOD(Phalcon_Assets_Collection, setPrefix) {

	zval *prefix_param = NULL;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}


	zephir_update_property_zval(this_ptr, SL("prefix"), &prefix);
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

	zephir_fetch_params(0, 1, 0, &local_param);

	if (UNEXPECTED(Z_TYPE_P(local_param) != IS_TRUE && Z_TYPE_P(local_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'local' must be of the type bool") TSRMLS_CC);
		RETURN_NULL();
	}
	local = (Z_TYPE_P(local_param) == IS_TRUE);


	if (local) {
		zephir_update_property_zval(this_ptr, SL("local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("local"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, setAttributes) {

	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, SL("attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Sets an array of filters in the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setFilters) {

	zval *filters_param = NULL;
	zval filters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filters_param);

	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);


	zephir_update_property_zval(this_ptr, SL("filters"), &filters);
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

	zephir_fetch_params(0, 1, 0, &targetLocal_param);

	if (UNEXPECTED(Z_TYPE_P(targetLocal_param) != IS_TRUE && Z_TYPE_P(targetLocal_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetLocal' must be of the type bool") TSRMLS_CC);
		RETURN_NULL();
	}
	targetLocal = (Z_TYPE_P(targetLocal_param) == IS_TRUE);


	if (targetLocal) {
		zephir_update_property_zval(this_ptr, SL("targetLocal"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("targetLocal"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if all filtered assets in the collection must be joined in a single result file
 */
PHP_METHOD(Phalcon_Assets_Collection, join) {

	zval *join_param = NULL, __$true, __$false;
	zend_bool join;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &join_param);

	join = zephir_get_boolval(join_param);


	if (join) {
		zephir_update_property_zval(this_ptr, SL("join"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("join"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Returns the complete location where the joined/filtered collection must be written
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, targetPath, completePath, _0;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (UNEXPECTED(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(basePath_param) == IS_STRING)) {
		zephir_get_strval(&basePath, basePath_param);
	} else {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_EMPTY_STRING(&basePath);
	}


	zephir_read_property(&_0, this_ptr, SL("targetPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&targetPath, &_0);
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &targetPath);
	if ((zephir_file_exists(&completePath TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 49, &completePath);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&completePath);

}

/**
 * Adds a filter to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter) {

	zval *filter, filter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);

	zephir_fetch_params(0, 1, 0, &filter);



	zephir_update_property_array_append(this_ptr, SL("filters"), filter);
	RETURN_THISW();

}

/**
 * Adds a asset or inline-code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addAsset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *asset, asset_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&asset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &asset);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, asset);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		if (zephir_instance_of_ev(asset, phalcon_assets_asset_ce TSRMLS_CC)) {
			zephir_update_property_array_append(this_ptr, SL("assets"), asset);
		} else {
			zephir_update_property_array_append(this_ptr, SL("codes"), asset);
		}
		ZEPHIR_CALL_METHOD(&_1$$3, asset, "getassetkey", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("includedAssets"), &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

zend_object *zephir_init_properties_Phalcon_Assets_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
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
		zephir_read_property(&_0, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("attributes"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("filters"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("codes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("codes"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("assets"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("assets"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

