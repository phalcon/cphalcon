
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Assets\Manager
 *
 * Manages collections of CSS/Javascript assets
 */


/**
 * Phalcon\Assets\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Assets, Manager, assets_manager, phalcon_assets_manager_method_entry, 0);

	zend_declare_property_null(phalcon_assets_manager_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_manager_ce, SL("_collections"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_assets_manager_ce, SL("_implicitOutput"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Assets\Manager constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Assets_Manager, __construct){

	zval *options = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the manager's options
 *
 * @param array $options
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, setOptions){

	zval *options;

	phalcon_fetch_params(0, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Options must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Sets if the HTML generated must be directly printed or returned
 *
 * @param boolean $implicitOutput
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput){

	zval *implicit_output;

	phalcon_fetch_params(0, 1, 0, &implicit_output);
	
	phalcon_update_property_this(this_ptr, SL("_implicitOutput"), implicit_output TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Adds a Css resource to the 'css' collection
 *
 * @param string $path
 * @param boolean $local
 * @param boolean $filter
 * @param array $attributes
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addCss){

	zval *path, *local = NULL, *filter = NULL, *attributes = NULL, *type, *resource;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	if (!filter) {
		PHALCON_INIT_VAR(filter);
	}
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "css", 1);
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_css_ce);
	phalcon_call_method_p4_noret(resource, "__construct", path, local, filter, attributes);
	
	phalcon_call_method_p2_noret(this_ptr, "addresourcebytype", type, resource);
	RETURN_THIS();
}

/**
 * Adds a javascript resource to the 'js' collection
 *
 * @param string $path
 * @param boolean $local
 * @param boolean $filter
 * @param array $attributes
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addJs){

	zval *path, *local = NULL, *filter = NULL, *attributes = NULL, *type, *resource;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	if (!filter) {
		PHALCON_INIT_VAR(filter);
	}
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "js", 1);
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_js_ce);
	phalcon_call_method_p4_noret(resource, "__construct", path, local, filter, attributes);
	
	phalcon_call_method_p2_noret(this_ptr, "addresourcebytype", type, resource);
	RETURN_THIS();
}

/**
 * Adds a resource by its type
 *
 *<code>
 *	$assets->addResourceByType('css', new Phalcon\Assets\Resource\Css('css/style.css'));
 *</code>
 *
 * @param string $type
 * @param Phalcon\Assets\Resource $resource
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addResourceByType){

	zval *type, *resource, *collections, *collection = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &resource);
	
	PHALCON_OBS_VAR(collections);
	phalcon_read_property_this(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
	if (phalcon_array_isset(collections, type)) {
		PHALCON_OBS_VAR(collection);
		phalcon_array_fetch(&collection, collections, type, PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		phalcon_update_property_array(this_ptr, SL("_collections"), type, collection TSRMLS_CC);
	}
	
	/** 
	 * Add the resource to the collection
	 */
	phalcon_call_method_p1_noret(collection, "add", resource);
	
	RETURN_THIS();
}

/**
 * Adds a raw resource to the manager
 *
 *<code>
 * $assets->addResource(new Phalcon\Assets\Resource('css', 'css/style.css'));
 *</code>
 *
 * @param Phalcon\Assets\Resource $resource
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addResource){

	zval *resource, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &resource);
	
	if (Z_TYPE_P(resource) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Resource must be an object");
		return;
	}
	
	PHALCON_INIT_VAR(type);
	phalcon_call_method(type, resource, "gettype");
	
	/** 
	 * Adds the resource by its type
	 */
	phalcon_call_method_p2_noret(this_ptr, "addresourcebytype", type, resource);
	
	RETURN_THIS();
}

/**
 * Sets a collection in the Assets Manager
 *
 *<code>
 * $assets->get('js', $collection);
 *</code>
 *
 * @param string $id
 * @param Phalcon\Assets\Collection $collection
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, set){

	zval *id, *collection;

	phalcon_fetch_params(0, 2, 0, &id, &collection);
	
	if (Z_TYPE_P(id) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Collection-Id must be a string");
		return;
	}
	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Collection must be an object");
		return;
	}
	
	phalcon_update_property_array(this_ptr, SL("_collections"), id, collection TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns a collection by its id
 *
 *<code>
 * $scripts = $assets->get('js');
 *</code>
 *
 * @param string $id
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, get){

	zval *id, *collections, *collection;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &id);
	
	if (Z_TYPE_P(id) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Collection-Id must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(collections);
	phalcon_read_property_this(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
	if (!phalcon_array_isset(collections, id)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "The collection does not exist in the manager");
		return;
	}
	
	PHALCON_OBS_VAR(collection);
	phalcon_array_fetch(&collection, collections, id, PH_NOISY_CC);
	
	RETURN_CCTOR(collection);
}

/**
 * Returns the CSS collection of assets
 *
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, getCss){

	zval *collections, *collection = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(collections);
	phalcon_read_property_this(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
	
	/** 
	 * Check if the collection does not exist and create an implicit collection
	 */
	if (!phalcon_array_isset_string(collections, SS("css"))) {
		PHALCON_INIT_VAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		RETURN_CTOR(collection);
	}
	
	PHALCON_OBS_NVAR(collection);
	phalcon_array_fetch_string(&collection, collections, SL("css"), PH_NOISY_CC);
	
	RETURN_CCTOR(collection);
}

/**
 * Returns the CSS collection of assets
 *
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, getJs){

	zval *collections, *collection = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(collections);
	phalcon_read_property_this(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
	
	/** 
	 * Check if the collection does not exist and create an implicit collection
	 */
	if (!phalcon_array_isset_string(collections, SS("js"))) {
		PHALCON_INIT_VAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		RETURN_CTOR(collection);
	}
	
	PHALCON_OBS_NVAR(collection);
	phalcon_array_fetch_string(&collection, collections, SL("js"), PH_NOISY_CC);
	
	RETURN_CCTOR(collection);
}

/**
 * Creates/Returns a collection of resources
 *
 * @param string $name
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, collection){

	zval *name, *collections, *collection = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(collections);
	phalcon_read_property_this(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
	if (phalcon_array_isset(collections, name)) {
		PHALCON_OBS_VAR(collection);
		phalcon_array_fetch(&collection, collections, name, PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		phalcon_update_property_array(this_ptr, SL("_collections"), name, collection TSRMLS_CC);
	}
	
	RETURN_CCTOR(collection);
}

/**
 * Prints the HTML for CSS resources
 *
 * @param string $collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss){

	zval *collection_name = NULL, *collection = NULL, *output;
	zval *use_implicit_output, *prefix, *resources;
	zval *resource = NULL, *path = NULL, *local = NULL, *prefixed_path = NULL, *attributes = NULL;
	zval *html = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &collection_name);
	
	if (!collection_name) {
		PHALCON_INIT_VAR(collection_name);
	}
	
	if (PHALCON_IS_EMPTY(collection_name)) {
		PHALCON_INIT_VAR(collection);
		phalcon_call_method(collection, this_ptr, "getcss");
	} else {
		PHALCON_INIT_NVAR(collection);
		phalcon_call_method_p1(collection, this_ptr, "get", collection_name);
	}
	
	PHALCON_INIT_VAR(output);
	
	PHALCON_OBS_VAR(use_implicit_output);
	phalcon_read_property_this(&use_implicit_output, this_ptr, SL("_implicitOutput"), PH_NOISY_CC);
	
	/** 
	 * Get the collection's prefix
	 */
	PHALCON_INIT_VAR(prefix);
	phalcon_call_method(prefix, collection, "getprefix");
	
	/** 
	 * Get the resources as an array
	 */
	PHALCON_INIT_VAR(resources);
	phalcon_call_method(resources, collection, "getresources");
	
	if (!phalcon_is_iterable(resources, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(resource);
	
		PHALCON_INIT_NVAR(path);
		phalcon_call_method(path, resource, "getpath");
	
		PHALCON_INIT_NVAR(local);
		phalcon_call_method(local, resource, "getlocal");
		if (Z_TYPE_P(prefix) != IS_NULL) {
			PHALCON_INIT_NVAR(prefixed_path);
			PHALCON_CONCAT_VV(prefixed_path, prefix, path);
		} else {
			PHALCON_CPY_WRT(prefixed_path, path);
		}
	
		/** 
		 * Gets extra HTML attributes in the resource
		 */
		PHALCON_INIT_NVAR(attributes);
		phalcon_call_method(attributes, resource, "getattributes");
	
		/** 
		 * Generate the html using Phalcon\Tag
		 */
		if (Z_TYPE_P(attributes) == IS_ARRAY) { 
			phalcon_array_update_long(&attributes, 0, &prefixed_path, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_NVAR(html);
			PHALCON_CALL_STATIC_PARAMS_2(html, "phalcon\\tag", "stylesheetlink", attributes, local);
		} else {
			PHALCON_INIT_NVAR(html);
			PHALCON_CALL_STATIC_PARAMS_2(html, "phalcon\\tag", "stylesheetlink", path, local);
		}
	
		if (zend_is_true(use_implicit_output)) {
			zend_print_zval(html, 0);
		} else {
			phalcon_concat_self(&output, html TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CCTOR(output);
}

/**
 * Prints the HTML for JS resources
 *
 * @param string $collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputJs){

	zval *collection_name = NULL, *collection = NULL, *output;
	zval *use_implicit_output, *resources, *filters;
	zval *prefix, *resource = NULL, *path = NULL, *local = NULL, *prefixed_path = NULL;
	zval *attributes = NULL, *html = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &collection_name);
	
	if (!collection_name) {
		PHALCON_INIT_VAR(collection_name);
	}
	
	if (PHALCON_IS_EMPTY(collection_name)) {
		PHALCON_INIT_VAR(collection);
		phalcon_call_method(collection, this_ptr, "getjs");
	} else {
		PHALCON_INIT_NVAR(collection);
		phalcon_call_method_p1(collection, this_ptr, "get", collection_name);
	}
	
	PHALCON_INIT_VAR(output);
	
	PHALCON_OBS_VAR(use_implicit_output);
	phalcon_read_property_this(&use_implicit_output, this_ptr, SL("_implicitOutput"), PH_NOISY_CC);
	
	/** 
	 * Get the resources as an array
	 */
	PHALCON_INIT_VAR(resources);
	phalcon_call_method(resources, collection, "getresources");
	
	/** 
	 * Get filters in the collection
	 */
	PHALCON_INIT_VAR(filters);
	phalcon_call_method(filters, collection, "getfilters");
	
	/** 
	 * Get the collection's prefix
	 */
	PHALCON_INIT_VAR(prefix);
	phalcon_call_method(prefix, collection, "getprefix");
	
	if (!phalcon_is_iterable(resources, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(resource);
	
		PHALCON_INIT_NVAR(path);
		phalcon_call_method(path, resource, "getpath");
	
		PHALCON_INIT_NVAR(local);
		phalcon_call_method(local, resource, "getlocal");
		if (Z_TYPE_P(prefix) != IS_NULL) {
			PHALCON_INIT_NVAR(prefixed_path);
			PHALCON_CONCAT_VV(prefixed_path, prefix, path);
		} else {
			PHALCON_CPY_WRT(prefixed_path, path);
		}
	
		/** 
		 * If there are not filters, just print/buffer the HTML
		 */
		if (Z_TYPE_P(filters) != IS_ARRAY) { 
	
			/** 
			 * Gets extra HTML attributes in the resource
			 */
			PHALCON_INIT_NVAR(attributes);
			phalcon_call_method(attributes, resource, "getattributes");
	
			/** 
			 * Generate the html using Phalcon\Tag
			 */
			if (Z_TYPE_P(attributes) == IS_ARRAY) { 
				phalcon_array_update_long(&attributes, 0, &prefixed_path, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
				PHALCON_INIT_NVAR(html);
				PHALCON_CALL_STATIC_PARAMS_2(html, "phalcon\\tag", "javascriptinclude", attributes, local);
			} else {
				PHALCON_INIT_NVAR(html);
				PHALCON_CALL_STATIC_PARAMS_2(html, "phalcon\\tag", "javascriptinclude", prefixed_path, local);
			}
	
			if (zend_is_true(use_implicit_output)) {
				zend_print_zval(html, 0);
			} else {
				phalcon_concat_self(&output, html TSRMLS_CC);
			}
		} else {
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CCTOR(output);
}

/**
 * Filters
 *
 * @param array $resources
 * @param array $filters
 */
PHP_METHOD(Phalcon_Assets_Manager, filter){


	
}

/**
 * Checks if a group of resources
 */
PHP_METHOD(Phalcon_Assets_Manager, hasChanged){

	zval *resources, *options;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &resources);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Assets_Manager, getResourceContent){

	zval *resource;

	phalcon_fetch_params(0, 1, 0, &resource);
	
	if (Z_TYPE_P(resource) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Resource must be an object");
		return;
	}
	
}

