
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
 * Phalcon\Assets\Collection
 *
 * Represents a collection of resources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Collection, phalcon, assets_collection, phalcon_assets_collection_method_entry, 0);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_local"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_resources"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_codes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_join"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_targetUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_targetPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_targetLocal"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_sourcePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_includedResources"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_assets_collection_ce->create_object = zephir_init_properties_Phalcon_Assets_Collection;

	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Assets_Collection, getPrefix) {

	

	RETURN_MEMBER(getThis(), "_prefix");

}

PHP_METHOD(Phalcon_Assets_Collection, getLocal) {

	

	RETURN_MEMBER(getThis(), "_local");

}

PHP_METHOD(Phalcon_Assets_Collection, getResources) {

	

	RETURN_MEMBER(getThis(), "_resources");

}

PHP_METHOD(Phalcon_Assets_Collection, getCodes) {

	

	RETURN_MEMBER(getThis(), "_codes");

}

PHP_METHOD(Phalcon_Assets_Collection, getPosition) {

	

	RETURN_MEMBER(getThis(), "_position");

}

PHP_METHOD(Phalcon_Assets_Collection, getFilters) {

	

	RETURN_MEMBER(getThis(), "_filters");

}

PHP_METHOD(Phalcon_Assets_Collection, getAttributes) {

	

	RETURN_MEMBER(getThis(), "_attributes");

}

PHP_METHOD(Phalcon_Assets_Collection, getJoin) {

	

	RETURN_MEMBER(getThis(), "_join");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetUri) {

	

	RETURN_MEMBER(getThis(), "_targetUri");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetPath) {

	

	RETURN_MEMBER(getThis(), "_targetPath");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal) {

	

	RETURN_MEMBER(getThis(), "_targetLocal");

}

PHP_METHOD(Phalcon_Assets_Collection, getSourcePath) {

	

	RETURN_MEMBER(getThis(), "_sourcePath");

}

/**
 * Phalcon\Assets\Collection constructor
 */
PHP_METHOD(Phalcon_Assets_Collection, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_includedResources"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a resource to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresource", NULL, 104, resource);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInline) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresource", NULL, 104, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Checks this the resource is added to the collection.
 *
 * <code>
 * use Phalcon\Assets\Resource;
 * use Phalcon\Assets\Collection;
 *
 * $collection = new Collection();
 * $resource = new Resource("js", "js/jquery.js");
 * $collection->add($resource);
 * $collection->has($resource); // true
 * </code>
 */
PHP_METHOD(Phalcon_Assets_Collection, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource, *key = NULL, *resources = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	ZEPHIR_CALL_METHOD(&key, resource, "getresourcekey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(resources);
	zephir_read_property_this(&resources, this_ptr, SL("_includedResources"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_fast_in_array(key, resources TSRMLS_CC));

}

/**
 * Adds a CSS resource to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local = NULL, *filter_param = NULL, *attributes = NULL, *collectionLocal = NULL, *collectionAttributes = NULL, *_0, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter_param, &attributes);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!local) {
		local = ZEPHIR_GLOBAL(global_null);
	}
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(local) == IS_BOOL) {
		ZEPHIR_CPY_WRT(collectionLocal, local);
	} else {
		ZEPHIR_OBS_NVAR(collectionLocal);
		zephir_read_property_this(&collectionLocal, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(collectionAttributes);
		zephir_read_property_this(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_resource_css_ce);
	ZEPHIR_INIT_VAR(_1);
	if (filter) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 105, path, collectionLocal, _1, collectionAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline CSS to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, *collectionAttributes = NULL, *_0, *_1;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes);

	zephir_get_strval(content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(collectionAttributes);
		zephir_read_property_this(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_inline_css_ce);
	ZEPHIR_INIT_VAR(_1);
	if (filter) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 106, content, _1, collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_codes"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a javascript resource to the collection
 *
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 * @return \Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local = NULL, *filter_param = NULL, *attributes = NULL, *collectionLocal = NULL, *collectionAttributes = NULL, *_0, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter_param, &attributes);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!local) {
		local = ZEPHIR_GLOBAL(global_null);
	}
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(local) == IS_BOOL) {
		ZEPHIR_CPY_WRT(collectionLocal, local);
	} else {
		ZEPHIR_OBS_NVAR(collectionLocal);
		zephir_read_property_this(&collectionLocal, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(collectionAttributes);
		zephir_read_property_this(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_resource_js_ce);
	ZEPHIR_INIT_VAR(_1);
	if (filter) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 107, path, collectionLocal, _1, collectionAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline javascript to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, *collectionAttributes = NULL, *_0, *_1;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes);

	zephir_get_strval(content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(collectionAttributes);
		zephir_read_property_this(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_inline_js_ce);
	ZEPHIR_INIT_VAR(_1);
	if (filter) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 108, content, _1, collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_codes"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Assets_Collection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, rewind) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_position"), _0 TSRMLS_CC);

}

/**
 * Returns the current resource in the iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, current) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, _2, PH_NOISY | PH_READONLY, "phalcon/assets/collection.zep", 225 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Assets_Collection, key) {

	

	RETURN_MEMBER(getThis(), "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Assets_Collection, next) {

	

	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position") TSRMLS_CC));

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Assets_Collection, valid) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, _1));

}

/**
 * Sets the target path of the file for the filtered/join output
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath) {

	zval *targetPath_param = NULL;
	zval *targetPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	if (UNEXPECTED(Z_TYPE_P(targetPath_param) != IS_STRING && Z_TYPE_P(targetPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(targetPath_param) == IS_STRING)) {
		zephir_get_strval(targetPath, targetPath_param);
	} else {
		ZEPHIR_INIT_VAR(targetPath);
		ZVAL_EMPTY_STRING(targetPath);
	}


	zephir_update_property_this(getThis(), SL("_targetPath"), targetPath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets a base source path for all the resources in this collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath) {

	zval *sourcePath_param = NULL;
	zval *sourcePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sourcePath_param);

	if (UNEXPECTED(Z_TYPE_P(sourcePath_param) != IS_STRING && Z_TYPE_P(sourcePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sourcePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sourcePath_param) == IS_STRING)) {
		zephir_get_strval(sourcePath, sourcePath_param);
	} else {
		ZEPHIR_INIT_VAR(sourcePath);
		ZVAL_EMPTY_STRING(sourcePath);
	}


	zephir_update_property_this(getThis(), SL("_sourcePath"), sourcePath TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri) {

	zval *targetUri_param = NULL;
	zval *targetUri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetUri_param);

	if (UNEXPECTED(Z_TYPE_P(targetUri_param) != IS_STRING && Z_TYPE_P(targetUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetUri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(targetUri_param) == IS_STRING)) {
		zephir_get_strval(targetUri, targetUri_param);
	} else {
		ZEPHIR_INIT_VAR(targetUri);
		ZVAL_EMPTY_STRING(targetUri);
	}


	zephir_update_property_this(getThis(), SL("_targetUri"), targetUri TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets a common prefix for all the resources
 */
PHP_METHOD(Phalcon_Assets_Collection, setPrefix) {

	zval *prefix_param = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	zephir_update_property_this(getThis(), SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets if the collection uses local resources by default
 */
PHP_METHOD(Phalcon_Assets_Collection, setLocal) {

	zval *local_param = NULL;
	zend_bool local;

	zephir_fetch_params(0, 1, 0, &local_param);

	if (UNEXPECTED(Z_TYPE_P(local_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'local' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	local = Z_BVAL_P(local_param);


	if (local) {
		zephir_update_property_this(getThis(), SL("_local"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_local"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, setAttributes) {

	zval *attributes_param = NULL;
	zval *attributes = NULL;

	zephir_fetch_params(0, 1, 0, &attributes_param);

	attributes = attributes_param;


	zephir_update_property_this(getThis(), SL("_attributes"), attributes TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets an array of filters in the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setFilters) {

	zval *filters_param = NULL;
	zval *filters = NULL;

	zephir_fetch_params(0, 1, 0, &filters_param);

	filters = filters_param;


	zephir_update_property_this(getThis(), SL("_filters"), filters TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the target local
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal) {

	zval *targetLocal_param = NULL;
	zend_bool targetLocal;

	zephir_fetch_params(0, 1, 0, &targetLocal_param);

	if (UNEXPECTED(Z_TYPE_P(targetLocal_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetLocal' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	targetLocal = Z_BVAL_P(targetLocal_param);


	if (targetLocal) {
		zephir_update_property_this(getThis(), SL("_targetLocal"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_targetLocal"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Sets if all filtered resources in the collection must be joined in a single result file
 */
PHP_METHOD(Phalcon_Assets_Collection, join) {

	zval *join_param = NULL;
	zend_bool join;

	zephir_fetch_params(0, 1, 0, &join_param);

	join = zephir_get_boolval(join_param);


	if (join) {
		zephir_update_property_this(getThis(), SL("_join"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_join"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns the complete location where the joined/filtered collection must be written
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, *targetPath = NULL, *completePath = NULL;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (UNEXPECTED(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(basePath_param) == IS_STRING)) {
		zephir_get_strval(basePath, basePath_param);
	} else {
		ZEPHIR_INIT_VAR(basePath);
		ZVAL_EMPTY_STRING(basePath);
	}


	ZEPHIR_OBS_VAR(targetPath);
	zephir_read_property_this(&targetPath, this_ptr, SL("_targetPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(completePath);
	ZEPHIR_CONCAT_VV(completePath, basePath, targetPath);
	if ((zephir_file_exists(completePath TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 67, completePath);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(completePath);

}

/**
 * Adds a filter to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter) {

	zval *filter;

	zephir_fetch_params(0, 1, 0, &filter);



	zephir_update_property_array_append(this_ptr, SL("_filters"), filter TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Adds a resource or inline-code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addResource) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource, *_0 = NULL, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, resource);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		if (zephir_instance_of_ev(resource, phalcon_assets_resource_ce TSRMLS_CC)) {
			zephir_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
		} else {
			zephir_update_property_array_append(this_ptr, SL("_codes"), resource TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_1$$3, resource, "getresourcekey", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("_includedResources"), _1$$3 TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

zend_object_value zephir_init_properties_Phalcon_Assets_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_1$$3, *_3$$4, *_5$$5, *_7$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_attributes"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_filters"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_codes"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("_codes"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(getThis(), SL("_resources"), _7$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

