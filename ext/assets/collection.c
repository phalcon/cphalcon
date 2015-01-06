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

#include "assets/collection.h"
#include "assets/exception.h"
#include "assets/resource/css.h"
#include "assets/resource/js.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"

/**
 * Phalcon\Assets\Collection
 *
 * Represents a collection of resources
 */
zend_class_entry *phalcon_assets_collection_ce;

PHP_METHOD(Phalcon_Assets_Collection, add);
PHP_METHOD(Phalcon_Assets_Collection, addCss);
PHP_METHOD(Phalcon_Assets_Collection, addJs);
PHP_METHOD(Phalcon_Assets_Collection, getResources);
PHP_METHOD(Phalcon_Assets_Collection, count);
PHP_METHOD(Phalcon_Assets_Collection, rewind);
PHP_METHOD(Phalcon_Assets_Collection, current);
PHP_METHOD(Phalcon_Assets_Collection, key);
PHP_METHOD(Phalcon_Assets_Collection, next);
PHP_METHOD(Phalcon_Assets_Collection, valid);
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath);
PHP_METHOD(Phalcon_Assets_Collection, getTargetPath);
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath);
PHP_METHOD(Phalcon_Assets_Collection, getSourcePath);
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri);
PHP_METHOD(Phalcon_Assets_Collection, getTargetUri);
PHP_METHOD(Phalcon_Assets_Collection, setPrefix);
PHP_METHOD(Phalcon_Assets_Collection, getPrefix);
PHP_METHOD(Phalcon_Assets_Collection, setLocal);
PHP_METHOD(Phalcon_Assets_Collection, getLocal);
PHP_METHOD(Phalcon_Assets_Collection, setAttributes);
PHP_METHOD(Phalcon_Assets_Collection, getAttributes);
PHP_METHOD(Phalcon_Assets_Collection, addFilter);
PHP_METHOD(Phalcon_Assets_Collection, setFilters);
PHP_METHOD(Phalcon_Assets_Collection, getFilters);
PHP_METHOD(Phalcon_Assets_Collection, join);
PHP_METHOD(Phalcon_Assets_Collection, getJoin);
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath);
PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal);
PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_add, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setsourcepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargeturi, 0, 0, 1)
	ZEND_ARG_INFO(0, targetUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_join, 0, 0, 1)
	ZEND_ARG_INFO(0, join)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_getrealtargetpath, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargetlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, targetLocal)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_assets_collection_method_entry[] = {
	PHP_ME(Phalcon_Assets_Collection, add, arginfo_phalcon_assets_collection_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addCss, arginfo_phalcon_assets_collection_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addJs, arginfo_phalcon_assets_collection_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetPath, arginfo_phalcon_assets_collection_settargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setSourcePath, arginfo_phalcon_assets_collection_setsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getSourcePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetUri, arginfo_phalcon_assets_collection_settargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setPrefix, arginfo_phalcon_assets_collection_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setLocal, arginfo_phalcon_assets_collection_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setAttributes, arginfo_phalcon_assets_collection_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addFilter, arginfo_phalcon_assets_collection_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setFilters, arginfo_phalcon_assets_collection_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, join, arginfo_phalcon_assets_collection_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getJoin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getRealTargetPath, arginfo_phalcon_assets_collection_getrealtargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetLocal, arginfo_phalcon_assets_collection_settargetlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Assets\Collection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Collection){

	PHALCON_REGISTER_CLASS(Phalcon\\Assets, Collection, assets_collection, phalcon_assets_collection_method_entry, 0);

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
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_targetLocal"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_assets_collection_ce TSRMLS_CC, 2, spl_ce_Countable, zend_ce_iterator);

	return SUCCESS;
}

/**
 * Adds a resource to the collection
 *
 * @param Phalcon\Assets\Resource $resource
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add){

	zval *resource;

	phalcon_fetch_params(0, 1, 0, &resource);
	
	if (Z_TYPE_P(resource) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Resource must be an object");
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	
	RETURN_THISW();
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
PHP_METHOD(Phalcon_Assets_Collection, addCss){

	zval *path, *local = NULL, *filter = NULL, *attributes = NULL, *collection_local = NULL;
	zval *collection_attributes = NULL, *resource;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);
	
	if (!local) {
		local = PHALCON_GLOBAL(z_null);
	}
	
	if (!filter) {
		filter = PHALCON_GLOBAL(z_true);
	}
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(local) == IS_BOOL) {
		collection_local = local;
	} else {
		collection_local = phalcon_fetch_nproperty_this(this_ptr, SL("_local"), PH_NOISY TSRMLS_CC);
	}

	if (Z_TYPE_P(attributes) == IS_ARRAY) { 
		collection_attributes = attributes;
	} else {
		collection_attributes = phalcon_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_css_ce);
	PHALCON_CALL_METHOD(NULL, resource, "__construct", path, collection_local, filter, collection_attributes);
	
	phalcon_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	
	RETURN_THIS();
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
PHP_METHOD(Phalcon_Assets_Collection, addJs){

	zval *path, *local = NULL, *filter = NULL, *attributes = NULL, *collection_local = NULL;
	zval *collection_attributes = NULL, *resource;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);
	
	if (!local) {
		local = PHALCON_GLOBAL(z_null);
	}
	
	if (!filter) {
		filter = PHALCON_GLOBAL(z_true);
	}
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(local) == IS_BOOL) {
		collection_local = local;
	} else {
		collection_local = phalcon_fetch_nproperty_this(this_ptr, SL("_local"), PH_NOISY TSRMLS_CC);
	}

	if (Z_TYPE_P(attributes) == IS_ARRAY) { 
		collection_attributes = attributes;
	} else {
		collection_attributes = phalcon_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_js_ce);
	PHALCON_CALL_METHOD(NULL, resource, "__construct", path, collection_local, filter, collection_attributes);
	
	phalcon_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns the resources as an array
 *
 * @return Phalcon\Assets\Resource[]
 */
PHP_METHOD(Phalcon_Assets_Collection, getResources){

	zval *resources;

	resources = phalcon_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(resources) != IS_ARRAY) { 
		array_init(return_value);
		return;
	}
	
	RETURN_ZVAL(resources, 1, 0);
}

/**
 * Returns the number of elements in the form
 *
 * @return int
 */
PHP_METHOD(Phalcon_Assets_Collection, count){

	zval *resources;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(resources);
	phalcon_read_property_this(&resources, this_ptr, SL("_resources"), PH_NOISY TSRMLS_CC);
	phalcon_fast_count(return_value, resources TSRMLS_CC);
	RETURN_MM();
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, rewind){


	phalcon_update_property_long(this_ptr, SL("_position"), 0 TSRMLS_CC);
	
}

/**
 * Returns the current resource in the iterator
 *
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Collection, current){

	zval *position, *resources, *resource;

	position  = phalcon_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY TSRMLS_CC);
	resources = phalcon_fetch_nproperty_this(this_ptr, SL("_resources"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&resource, resources, position)) {
		RETURN_ZVAL(resource, 1, 0);
	}
	
	RETURN_NULL();
}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Assets_Collection, key){


	RETURN_MEMBER(this_ptr, "_position");
}

/**
 * Moves the internal iteration pointer to the next position
 *
 */
PHP_METHOD(Phalcon_Assets_Collection, next){


	phalcon_property_incr(this_ptr, SL("_position") TSRMLS_CC);
	
}

/**
 * Check if the current element in the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Collection, valid){

	zval *position, *resources;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(position);
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(resources);
	phalcon_read_property_this(&resources, this_ptr, SL("_resources"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(resources, position)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Sets the target path of the file for the filtered/join output
 *
 * @param string $targetPath
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath){

	zval *target_path;

	phalcon_fetch_params(0, 1, 0, &target_path);
	
	phalcon_update_property_this(this_ptr, SL("_targetPath"), target_path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the target path of the file for the filtered/join output
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetPath){


	RETURN_MEMBER(this_ptr, "_targetPath");
}

/**
 * Sets a base source path for all the resources in this collection
 *
 * @param string $sourcePath
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath){

	zval *source_path;

	phalcon_fetch_params(0, 1, 0, &source_path);
	
	phalcon_update_property_this(this_ptr, SL("_sourcePath"), source_path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the base source path for all the resources in this collection
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getSourcePath){


	RETURN_MEMBER(this_ptr, "_sourcePath");
}

/**
 * Sets a target uri for the generated HTML
 *
 * @param string $targetUri
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri){

	zval *target_uri;

	phalcon_fetch_params(0, 1, 0, &target_uri);
	
	phalcon_update_property_this(this_ptr, SL("_targetUri"), target_uri TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the target uri for the generated HTML
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetUri){


	RETURN_MEMBER(this_ptr, "_targetUri");
}

/**
 * Sets a common prefix for all the resources
 *
 * @param string $prefix
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setPrefix){

	zval *prefix;

	phalcon_fetch_params(0, 1, 0, &prefix);
	
	phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the prefix
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getPrefix){


	RETURN_MEMBER(this_ptr, "_prefix");
}

/**
 * Sets if the collection uses local resources by default
 *
 * @param boolean $local
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setLocal){

	zval *local;

	phalcon_fetch_params(0, 1, 0, &local);
	
	phalcon_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns if the collection uses local resources by default
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Collection, getLocal){


	RETURN_MEMBER(this_ptr, "_local");
}

/**
 * Sets extra HTML attributes
 *
 * @param array $attributes
 * @return $this
 */
PHP_METHOD(Phalcon_Assets_Collection, setAttributes){

	zval *attributes;

	phalcon_fetch_params(0, 1, 0, &attributes);
	
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Attributes must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns extra HTML attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Collection, getAttributes){


	RETURN_MEMBER(this_ptr, "_attributes");
}

/**
 * Adds a filter to the collection
 *
 * @param Phalcon\Assets\FilterInterface $filter
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter){

	zval *filter;

	phalcon_fetch_params(0, 1, 0, &filter);
	
	phalcon_update_property_array_append(this_ptr, SL("_filters"), filter TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets an array of filters in the collection
 *
 * @param array $filters
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setFilters){

	zval *filters;

	phalcon_fetch_params(0, 1, 0, &filters);
	
	if (Z_TYPE_P(filters) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Filters must be an array of filters");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_filters"), filters TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns the filters set in the collection
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Collection, getFilters){


	RETURN_MEMBER(this_ptr, "_filters");
}

/**
 * Sets if all filtered resources in the collection must be joined in a single result file
 *
 * @param boolean $join
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, join){

	zval *join;

	phalcon_fetch_params(0, 1, 0, &join);
	
	phalcon_update_property_this(this_ptr, SL("_join"), join TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns if all the filtered resources must be joined
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Collection, getJoin){


	RETURN_MEMBER(this_ptr, "_join");
}

/**
 * Returns the complete location where the joined/filtered collection must be written
 *
 * @param string $basePath
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath){

	zval *base_path = NULL, *target_path, *complete_path;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &base_path);
	
	if (!base_path) {
		base_path = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(target_path);
	phalcon_read_property_this(&target_path, this_ptr, SL("_targetPath"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * A base path for resources can be set in the assets manager
	 */
	PHALCON_INIT_VAR(complete_path);
	PHALCON_CONCAT_VV(complete_path, base_path, target_path);
	
	/** 
	 * Get the real template path, the target path can optionally don't exist
	 */
	if (phalcon_file_exists(complete_path TSRMLS_CC) == SUCCESS) {
		phalcon_realpath(return_value, complete_path TSRMLS_CC);
		RETURN_MM();
	}
	
	RETURN_CTOR(complete_path);
}

/**
 * Sets the target local
 *
 * @param boolean $targetLocal
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal){

	zval *target_local;

	phalcon_fetch_params(0, 1, 0, &target_local);
	
	phalcon_update_property_this(this_ptr, SL("_targetLocal"), target_local TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the target local
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal){


	RETURN_MEMBER(this_ptr, "_targetLocal");
}

