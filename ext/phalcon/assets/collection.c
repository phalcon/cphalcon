
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_sourcePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Assets_Collection, getPrefix) {



}

PHP_METHOD(Phalcon_Assets_Collection, setPrefix) {

	zval *prefix;

	zephir_fetch_params(0, 1, 0, &prefix);




}

PHP_METHOD(Phalcon_Assets_Collection, getLocal) {



}

PHP_METHOD(Phalcon_Assets_Collection, setLocal) {

	zval *local;

	zephir_fetch_params(0, 1, 0, &local);




}

PHP_METHOD(Phalcon_Assets_Collection, getResources) {



}

PHP_METHOD(Phalcon_Assets_Collection, setResources) {

	zval *resources;

	zephir_fetch_params(0, 1, 0, &resources);




}

PHP_METHOD(Phalcon_Assets_Collection, getPosition) {



}

PHP_METHOD(Phalcon_Assets_Collection, setPosition) {

	zval *position;

	zephir_fetch_params(0, 1, 0, &position);




}

PHP_METHOD(Phalcon_Assets_Collection, getFilters) {



}

PHP_METHOD(Phalcon_Assets_Collection, setFilters) {

	zval *filters;

	zephir_fetch_params(0, 1, 0, &filters);




}

PHP_METHOD(Phalcon_Assets_Collection, getAttributes) {



}

PHP_METHOD(Phalcon_Assets_Collection, setAttributes) {

	zval *attributes;

	zephir_fetch_params(0, 1, 0, &attributes);




}

PHP_METHOD(Phalcon_Assets_Collection, getJoin) {



}

PHP_METHOD(Phalcon_Assets_Collection, setJoin) {

	zval *join;

	zephir_fetch_params(0, 1, 0, &join);




}

PHP_METHOD(Phalcon_Assets_Collection, getTargetUri) {



}

PHP_METHOD(Phalcon_Assets_Collection, setTargetUri) {

	zval *targetUri;

	zephir_fetch_params(0, 1, 0, &targetUri);




}

PHP_METHOD(Phalcon_Assets_Collection, getTargetPath) {



}

PHP_METHOD(Phalcon_Assets_Collection, setTargetPath) {

	zval *targetPath;

	zephir_fetch_params(0, 1, 0, &targetPath);




}

PHP_METHOD(Phalcon_Assets_Collection, getSourcePath) {



}

PHP_METHOD(Phalcon_Assets_Collection, setSourcePath) {

	zval *sourcePath;

	zephir_fetch_params(0, 1, 0, &sourcePath);




}

/**
 * Adds a resource to the collection
 *
 * @param Phalcon\Assets\Resource $resource
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add) {

	zval *resource;

	zephir_fetch_params(0, 1, 0, &resource);



	if ((Z_TYPE_P(resource) == IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Resource must be an object");
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);

}

/**
 * Adds a CSS resource to the collection
 *
 * @param string $path
 * @param boolean $local
 * @param boolean $filter
 * @param array $attributes
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss) {

	zval *path, *local, *filter = NULL, *attributes, *resource, *collectionLocal = NULL, *collectionAttributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &path, &local, &filter, &attributes);

	ZEPHIR_SEPARATE_PARAM(filter);


	if (!(zephir_is_true(filter))) {
		ZEPHIR_INIT_NVAR(filter);
		ZVAL_BOOL(filter, 1);
	}
	if ((Z_TYPE_P(local) == IS_BOOL)) {
		ZEPHIR_CPY_WRT(collectionLocal, local);
	} else {
		ZEPHIR_OBS_VAR(collectionLocal);
		zephir_read_property_this(&collectionLocal, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	if ((Z_TYPE_P(attributes) == IS_ARRAY)) {
		ZEPHIR_CPY_WRT(collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_VAR(collectionAttributes);
		zephir_read_property_this(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_css_ce);
	zephir_call_method_p3_noret(resource, "__construct", collectionLocal, filter, collectionAttributes);
	zephir_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a javascript resource to the collection
 *
 * @param string $path
 * @param boolean $local
 * @param boolean $filter
 * @param array $attributes
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs) {

	zval *path, *local, *filter = NULL, *attributes, *resource, *collectionLocal = NULL, *collectionAttributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &path, &local, &filter, &attributes);

	ZEPHIR_SEPARATE_PARAM(filter);


	if (!(zephir_is_true(filter))) {
		ZEPHIR_INIT_NVAR(filter);
		ZVAL_BOOL(filter, 1);
	}
	if ((Z_TYPE_P(local) == IS_BOOL)) {
		ZEPHIR_CPY_WRT(collectionLocal, local);
	} else {
		ZEPHIR_OBS_VAR(collectionLocal);
		zephir_read_property_this(&collectionLocal, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	if ((Z_TYPE_P(attributes) == IS_ARRAY)) {
		ZEPHIR_CPY_WRT(collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_VAR(collectionAttributes);
		zephir_read_property_this(&collectionAttributes, this_ptr, SL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_js_ce);
	zephir_call_method_p3_noret(resource, "__construct", collectionLocal, filter, collectionAttributes);
	zephir_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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

	zval *position, *resource = NULL, *resources;

	ZEPHIR_MM_GROW();

	position = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	resources = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(resource);
	ZVAL_NULL(resource);
	if (zephir_array_isset(resources, position)) {
		ZEPHIR_OBS_NVAR(resource);
		zephir_array_fetch(&resource, resources, position, PH_NOISY TSRMLS_CC);
	}
	RETURN_CCTOR(resource);

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

	zval *position, *_0;


	position = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, (zephir_get_numberval(position) + 1));
	zephir_update_property_this(this_ptr, SL("_position"), _0 TSRMLS_CC);

}

/**
 * Check if the current element in the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Collection, valid) {

	zval *resources, *_0;


	resources = zephir_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	if (zephir_array_isset(resources, _0)) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);

}

/**
 * Sets if all filtered resources in the collection must be joined in a single result file
 *
 * @param boolean $join
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, join) {

	zval *join;

	zephir_fetch_params(0, 1, 0, &join);



	zephir_update_property_this(this_ptr, SL("_join"), join TSRMLS_CC);

}

/**
 * Returns the complete location where the joined/filtered collection must be written
 *
 * @param string $basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath) {

	zval *basePath, *targetPath, *completePath, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath);



	targetPath = zephir_fetch_nproperty_this(this_ptr, SL("_targetPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(completePath);
	concat_function(completePath, basePath, targetPath TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "file_exists", completePath);
	if (zephir_is_true(_0)) {
		zephir_call_func_p1(return_value, "realpath", completePath);
		RETURN_MM();
	}
	RETURN_CCTOR(completePath);

}

