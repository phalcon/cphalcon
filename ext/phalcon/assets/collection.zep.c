
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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_prefix");

}

PHP_METHOD(Phalcon_Assets_Collection, getLocal) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_local");

}

PHP_METHOD(Phalcon_Assets_Collection, getResources) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_resources");

}

PHP_METHOD(Phalcon_Assets_Collection, getCodes) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_codes");

}

PHP_METHOD(Phalcon_Assets_Collection, getPosition) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_position");

}

PHP_METHOD(Phalcon_Assets_Collection, getFilters) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_filters");

}

PHP_METHOD(Phalcon_Assets_Collection, getAttributes) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_attributes");

}

PHP_METHOD(Phalcon_Assets_Collection, getJoin) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_join");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetUri) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_targetUri");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetPath) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_targetPath");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_targetLocal");

}

PHP_METHOD(Phalcon_Assets_Collection, getSourcePath) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_sourcePath");

}

/**
 * Adds a resource to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add) {

	zval *resource, resource_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&resource_sub);

	zephir_fetch_params(0, 1, 0, &resource);



	zephir_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Adds an inline code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInline) {

	zval *code, code_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&code_sub);

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
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionLocal, collectionAttributes, _0, _1;
	zval path;
	ZEPHIR_INIT_THIS();

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

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
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
		zephir_read_property(&collectionLocal, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_resource_css_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 100, &path, &collectionLocal, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_resources"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds an inline CSS to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionAttributes, _0, _1;
	zval content;
	ZEPHIR_INIT_THIS();

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
		zephir_read_property(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_css_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 101, &content, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_codes"), &_0 TSRMLS_CC);
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
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionLocal, collectionAttributes, _0, _1;
	zval path;
	ZEPHIR_INIT_THIS();

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

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
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
		zephir_read_property(&collectionLocal, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_resource_js_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 102, &path, &collectionLocal, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_resources"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds an inline javascript to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionAttributes, _0, _1;
	zval content;
	ZEPHIR_INIT_THIS();

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
		zephir_read_property(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_js_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 103, &content, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_codes"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Assets_Collection, count) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_resources"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, rewind) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_position"), &_0);

}

/**
 * Returns the current resource in the iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, current) {

	zval _0, _1, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_resources"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("_position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalcon/assets/collection.zep", 190 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Assets_Collection, key) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Assets_Collection, next) {

	ZEPHIR_INIT_THIS();


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position") TSRMLS_CC));

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Assets_Collection, valid) {

	zval _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("_resources"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Sets the target path of the file for the filtered/join output
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath) {

	zval *targetPath_param = NULL;
	zval targetPath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&targetPath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	if (unlikely(Z_TYPE_P(targetPath_param) != IS_STRING && Z_TYPE_P(targetPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(targetPath_param) == IS_STRING)) {
		zephir_get_strval(&targetPath, targetPath_param);
	} else {
		ZEPHIR_INIT_VAR(&targetPath);
		ZVAL_EMPTY_STRING(&targetPath);
	}


	zephir_update_property_zval(this_ptr, SL("_targetPath"), &targetPath);
	RETURN_THIS();

}

/**
 * Sets a base source path for all the resources in this collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath) {

	zval *sourcePath_param = NULL;
	zval sourcePath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sourcePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sourcePath_param);

	if (unlikely(Z_TYPE_P(sourcePath_param) != IS_STRING && Z_TYPE_P(sourcePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sourcePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(sourcePath_param) == IS_STRING)) {
		zephir_get_strval(&sourcePath, sourcePath_param);
	} else {
		ZEPHIR_INIT_VAR(&sourcePath);
		ZVAL_EMPTY_STRING(&sourcePath);
	}


	zephir_update_property_zval(this_ptr, SL("_sourcePath"), &sourcePath);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri) {

	zval *targetUri_param = NULL;
	zval targetUri;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&targetUri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetUri_param);

	if (unlikely(Z_TYPE_P(targetUri_param) != IS_STRING && Z_TYPE_P(targetUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetUri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(targetUri_param) == IS_STRING)) {
		zephir_get_strval(&targetUri, targetUri_param);
	} else {
		ZEPHIR_INIT_VAR(&targetUri);
		ZVAL_EMPTY_STRING(&targetUri);
	}


	zephir_update_property_zval(this_ptr, SL("_targetUri"), &targetUri);
	RETURN_THIS();

}

/**
 * Sets a common prefix for all the resources
 */
PHP_METHOD(Phalcon_Assets_Collection, setPrefix) {

	zval *prefix_param = NULL;
	zval prefix;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}


	zephir_update_property_zval(this_ptr, SL("_prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Sets if the collection uses local resources by default
 */
PHP_METHOD(Phalcon_Assets_Collection, setLocal) {

	zval *local_param = NULL, __$true, __$false;
	zend_bool local;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &local_param);

	if (unlikely(Z_TYPE_P(local_param) != IS_TRUE && Z_TYPE_P(local_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'local' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	local = (Z_TYPE_P(local_param) == IS_TRUE);


	if (local) {
		zephir_update_property_zval(this_ptr, SL("_local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_local"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, setAttributes) {

	zval *attributes_param = NULL;
	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, SL("_attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Sets an array of filters in the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setFilters) {

	zval *filters_param = NULL;
	zval filters;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filters_param);

	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);


	zephir_update_property_zval(this_ptr, SL("_filters"), &filters);
	RETURN_THIS();

}

/**
 * Sets the target local
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal) {

	zval *targetLocal_param = NULL, __$true, __$false;
	zend_bool targetLocal;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &targetLocal_param);

	if (unlikely(Z_TYPE_P(targetLocal_param) != IS_TRUE && Z_TYPE_P(targetLocal_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetLocal' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	targetLocal = (Z_TYPE_P(targetLocal_param) == IS_TRUE);


	if (targetLocal) {
		zephir_update_property_zval(this_ptr, SL("_targetLocal"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_targetLocal"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if all filtered resources in the collection must be joined in a single result file
 */
PHP_METHOD(Phalcon_Assets_Collection, join) {

	zval *join_param = NULL, __$true, __$false;
	zend_bool join;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &join_param);

	join = zephir_get_boolval(join_param);


	if (join) {
		zephir_update_property_zval(this_ptr, SL("_join"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_join"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Returns the complete location where the joined/filtered collection must be written
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, targetPath, completePath;
	zval basePath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&completePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (unlikely(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(basePath_param) == IS_STRING)) {
		zephir_get_strval(&basePath, basePath_param);
	} else {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_EMPTY_STRING(&basePath);
	}


	ZEPHIR_OBS_VAR(&targetPath);
	zephir_read_property(&targetPath, this_ptr, SL("_targetPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &targetPath);
	if ((zephir_file_exists(&completePath TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 64, &completePath);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(completePath);

}

/**
 * Adds a filter to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter) {

	zval *filter, filter_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filter_sub);

	zephir_fetch_params(0, 1, 0, &filter);



	zephir_update_property_array_append(this_ptr, SL("_filters"), filter TSRMLS_CC);
	RETURN_THISW();

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
		zephir_read_property(&_0, this_ptr, SL("_attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_attributes"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_filters"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_codes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_codes"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_resources"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_resources"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

