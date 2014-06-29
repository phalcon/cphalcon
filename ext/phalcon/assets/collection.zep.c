
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_join"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_targetUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_targetPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_targetLocal"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_sourcePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Assets_Collection, getPrefix) {


	RETURN_MEMBER(this_ptr, "_prefix");

}

PHP_METHOD(Phalcon_Assets_Collection, setPrefix) {

	zval *prefix;

	zephir_fetch_params(0, 1, 0, &prefix);



	zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getLocal) {


	RETURN_MEMBER(this_ptr, "_local");

}

PHP_METHOD(Phalcon_Assets_Collection, setLocal) {

	zval *local;

	zephir_fetch_params(0, 1, 0, &local);



	zephir_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getResources) {


	RETURN_MEMBER(this_ptr, "_resources");

}

PHP_METHOD(Phalcon_Assets_Collection, setResources) {

	zval *resources;

	zephir_fetch_params(0, 1, 0, &resources);



	zephir_update_property_this(this_ptr, SL("_resources"), resources TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getPosition) {


	RETURN_MEMBER(this_ptr, "_position");

}

PHP_METHOD(Phalcon_Assets_Collection, setPosition) {

	zval *position;

	zephir_fetch_params(0, 1, 0, &position);



	zephir_update_property_this(this_ptr, SL("_position"), position TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getFilters) {


	RETURN_MEMBER(this_ptr, "_filters");

}

PHP_METHOD(Phalcon_Assets_Collection, setFilters) {

	zval *filters;

	zephir_fetch_params(0, 1, 0, &filters);



	zephir_update_property_this(this_ptr, SL("_filters"), filters TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getAttributes) {


	RETURN_MEMBER(this_ptr, "_attributes");

}

PHP_METHOD(Phalcon_Assets_Collection, setAttributes) {

	zval *attributes;

	zephir_fetch_params(0, 1, 0, &attributes);



	zephir_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getJoin) {


	RETURN_MEMBER(this_ptr, "_join");

}

PHP_METHOD(Phalcon_Assets_Collection, setJoin) {

	zval *join;

	zephir_fetch_params(0, 1, 0, &join);



	zephir_update_property_this(this_ptr, SL("_join"), join TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetUri) {


	RETURN_MEMBER(this_ptr, "_targetUri");

}

PHP_METHOD(Phalcon_Assets_Collection, setTargetUri) {

	zval *targetUri;

	zephir_fetch_params(0, 1, 0, &targetUri);



	zephir_update_property_this(this_ptr, SL("_targetUri"), targetUri TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetPath) {


	RETURN_MEMBER(this_ptr, "_targetPath");

}

PHP_METHOD(Phalcon_Assets_Collection, setTargetPath) {

	zval *targetPath;

	zephir_fetch_params(0, 1, 0, &targetPath);



	zephir_update_property_this(this_ptr, SL("_targetPath"), targetPath TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal) {


	RETURN_MEMBER(this_ptr, "_targetLocal");

}

PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal) {

	zval *targetLocal;

	zephir_fetch_params(0, 1, 0, &targetLocal);



	zephir_update_property_this(this_ptr, SL("_targetLocal"), targetLocal TSRMLS_CC);

}

PHP_METHOD(Phalcon_Assets_Collection, getSourcePath) {


	RETURN_MEMBER(this_ptr, "_sourcePath");

}

PHP_METHOD(Phalcon_Assets_Collection, setSourcePath) {

	zval *sourcePath;

	zephir_fetch_params(0, 1, 0, &sourcePath);



	zephir_update_property_this(this_ptr, SL("_sourcePath"), sourcePath TSRMLS_CC);

}

/**
 * Adds a resource to the collection
 *
 * @param Phalcon\Assets\Resource resource
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add) {

	zval *resource;

	zephir_fetch_params(0, 1, 0, &resource);



	if (!(zephir_instance_of_ev(resource, phalcon_assets_resource_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'resource' must be an instance of 'Phalcon\\Assets\\Resource'", "", 0);
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Adds a CSS resource to the collection
 *
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local, *filter_param = NULL, *attributes = NULL, *collectionLocal = NULL, *collectionAttributes = NULL, *_0;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &path_param, &local, &filter_param, &attributes);

	zephir_get_strval(path, path_param);
	filter = zephir_get_boolval(filter_param);
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	if (!(filter)) {
		filter = 1;
	}
	if (Z_TYPE_P(local) == IS_BOOL) {
		ZEPHIR_CPY_WRT(collectionLocal, local);
	} else {
		ZEPHIR_OBS_VAR(collectionLocal);
		zephir_read_property_this(&collectionLocal, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_VAR(collectionAttributes);
		zephir_read_property_this(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_resource_css_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, collectionLocal, (filter ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_resources"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a javascript resource to the collection
 *
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local, *filter_param = NULL, *attributes = NULL, *collectionLocal = NULL, *collectionAttributes = NULL, *_0;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &path_param, &local, &filter_param, &attributes);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(path_param) == IS_STRING)) {
		path = path_param;
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	filter = zephir_get_boolval(filter_param);
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	if (!(filter)) {
		filter = 1;
	}
	if (Z_TYPE_P(local) == IS_BOOL) {
		ZEPHIR_CPY_WRT(collectionLocal, local);
	} else {
		ZEPHIR_OBS_VAR(collectionLocal);
		zephir_read_property_this(&collectionLocal, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_VAR(collectionAttributes);
		zephir_read_property_this(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_assets_resource_js_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, collectionLocal, (filter ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_resources"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 *
 * @return int
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
 *
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Collection, current) {

	zval *resource, *_0, *_1;


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
 *
 */
PHP_METHOD(Phalcon_Assets_Collection, next) {


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position") TSRMLS_CC));

}

/**
 * Check if the current element in the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Collection, valid) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, _1));

}

/**
 * Sets if all filtered resources in the collection must be joined in a single result file
 *
 * @param boolean join
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, join) {

	zval *join_param = NULL;
	zend_bool join;

	zephir_fetch_params(0, 1, 0, &join_param);

	join = zephir_get_boolval(join_param);


	zephir_update_property_this(this_ptr, SL("_join"), join ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the complete location where the joined/filtered collection must be written
 *
 * @param string basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *basePath_param = NULL, *targetPath, *completePath;
	zval *basePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (unlikely(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(basePath_param) == IS_STRING)) {
		basePath = basePath_param;
	} else {
		ZEPHIR_INIT_VAR(basePath);
		ZVAL_EMPTY_STRING(basePath);
	}


	ZEPHIR_OBS_VAR(targetPath);
	zephir_read_property_this(&targetPath, this_ptr, SL("_targetPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(completePath);
	ZEPHIR_CONCAT_VV(completePath, basePath, targetPath);
	if ((zephir_file_exists(completePath TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", &_0, completePath);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(completePath);

}

/**
 * Adds a filter to the collection
 *
 * @param Phalcon\Assets\FilterInterface $filter
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter) {

	zval *filter;

	zephir_fetch_params(0, 1, 0, &filter);



	if (!(zephir_instance_of_ev(filter, phalcon_assets_filterinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'filter' must be an instance of 'Phalcon\\Assets\\FilterInterface'", "", 0);
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("_filters"), filter TSRMLS_CC);
	RETURN_THISW();

}

