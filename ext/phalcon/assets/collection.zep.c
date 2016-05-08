
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
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

	phalcon_assets_collection_ce->create_object = zephir_init_properties_Phalcon_Assets_Collection;

	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Assets_Collection, getPrefix) {

	

	RETURN_MEMBER(this_ptr, "_prefix");

}

PHP_METHOD(Phalcon_Assets_Collection, getLocal) {

	

	RETURN_MEMBER(this_ptr, "_local");

}

PHP_METHOD(Phalcon_Assets_Collection, getResources) {

	

	RETURN_MEMBER(this_ptr, "_resources");

}

PHP_METHOD(Phalcon_Assets_Collection, getCodes) {

	

	RETURN_MEMBER(this_ptr, "_codes");

}

PHP_METHOD(Phalcon_Assets_Collection, getPosition) {

	

	RETURN_MEMBER(this_ptr, "_position");

}

PHP_METHOD(Phalcon_Assets_Collection, getFilters) {

	

	RETURN_MEMBER(this_ptr, "_filters");

}

PHP_METHOD(Phalcon_Assets_Collection, getAttributes) {

	

	RETURN_MEMBER(this_ptr, "_attributes");

}

PHP_METHOD(Phalcon_Assets_Collection, getJoin) {

	

	RETURN_MEMBER(this_ptr, "_join");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetUri) {

	

	RETURN_MEMBER(this_ptr, "_targetUri");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetPath) {

	

	RETURN_MEMBER(this_ptr, "_targetPath");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal) {

	

	RETURN_MEMBER(this_ptr, "_targetLocal");

}

PHP_METHOD(Phalcon_Assets_Collection, getSourcePath) {

	

	RETURN_MEMBER(this_ptr, "_sourcePath");

}

/**
 * Adds a resource to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add) {

	zval *resource;

	zephir_fetch_params(0, 1, 0, &resource);



	zephir_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Adds a inline code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInline) {

	zval *code;

	zephir_fetch_params(0, 1, 0, &code);



	zephir_update_property_array_append(this_ptr, SL("_codes"), code TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Adds a CSS resource to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local = NULL, *filter_param = NULL, *attributes = NULL, *collectionLocal = NULL, *collectionAttributes = NULL, *_0, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter_param, &attributes);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 99, path, collectionLocal, _1, collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_resources"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a inline CSS to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss) {

	int ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 100, content, _1, collectionAttributes);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local = NULL, *filter_param = NULL, *attributes = NULL, *collectionLocal = NULL, *collectionAttributes = NULL, *_0, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter_param, &attributes);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 101, path, collectionLocal, _1, collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_resources"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a inline javascript to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs) {

	int ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 102, content, _1, collectionAttributes);
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
	zephir_update_property_this(this_ptr, SL("_position"), _0 TSRMLS_CC);

}

/**
 * Returns the current resource in the iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, current) {

	zval *resource = NULL, *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	zephir_array_isset_fetch(&resource, _0, _1, 1 TSRMLS_CC);
	RETURN_CTORW(resource);

}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Assets_Collection, key) {

	

	RETURN_MEMBER(this_ptr, "_position");

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

	if (unlikely(Z_TYPE_P(targetPath_param) != IS_STRING && Z_TYPE_P(targetPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(targetPath_param) == IS_STRING)) {
		zephir_get_strval(targetPath, targetPath_param);
	} else {
		ZEPHIR_INIT_VAR(targetPath);
		ZVAL_EMPTY_STRING(targetPath);
	}


	zephir_update_property_this(this_ptr, SL("_targetPath"), targetPath TSRMLS_CC);
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

	if (unlikely(Z_TYPE_P(sourcePath_param) != IS_STRING && Z_TYPE_P(sourcePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sourcePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(sourcePath_param) == IS_STRING)) {
		zephir_get_strval(sourcePath, sourcePath_param);
	} else {
		ZEPHIR_INIT_VAR(sourcePath);
		ZVAL_EMPTY_STRING(sourcePath);
	}


	zephir_update_property_this(this_ptr, SL("_sourcePath"), sourcePath TSRMLS_CC);
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

	if (unlikely(Z_TYPE_P(targetUri_param) != IS_STRING && Z_TYPE_P(targetUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetUri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(targetUri_param) == IS_STRING)) {
		zephir_get_strval(targetUri, targetUri_param);
	} else {
		ZEPHIR_INIT_VAR(targetUri);
		ZVAL_EMPTY_STRING(targetUri);
	}


	zephir_update_property_this(this_ptr, SL("_targetUri"), targetUri TSRMLS_CC);
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

	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets if the collection uses local resources by default
 */
PHP_METHOD(Phalcon_Assets_Collection, setLocal) {

	zval *local_param = NULL;
	zend_bool local;

	zephir_fetch_params(0, 1, 0, &local_param);

	if (unlikely(Z_TYPE_P(local_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'local' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	local = Z_BVAL_P(local_param);


	if (local) {
		zephir_update_property_this(this_ptr, SL("_local"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_local"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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


	zephir_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
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


	zephir_update_property_this(this_ptr, SL("_filters"), filters TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the target local
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal) {

	zval *targetLocal_param = NULL;
	zend_bool targetLocal;

	zephir_fetch_params(0, 1, 0, &targetLocal_param);

	if (unlikely(Z_TYPE_P(targetLocal_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetLocal' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	targetLocal = Z_BVAL_P(targetLocal_param);


	if (targetLocal) {
		zephir_update_property_this(this_ptr, SL("_targetLocal"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_targetLocal"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
		zephir_update_property_this(this_ptr, SL("_join"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_join"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns the complete location where the joined/filtered collection must be written
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, *targetPath = NULL, *completePath = NULL;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (unlikely(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(basePath_param) == IS_STRING)) {
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
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 64, completePath);
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

zend_object_value zephir_init_properties_Phalcon_Assets_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_1$$3, *_3$$4, *_5$$5, *_7$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_attributes"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("_filters"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_codes"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("_codes"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(this_ptr, SL("_resources"), _7$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

