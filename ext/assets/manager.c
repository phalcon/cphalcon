
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
 * Returns the manager's options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Manager, getOptions){


	RETURN_MEMBER(this_ptr, "_options");
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
 *<code>
 *	$assets->addCss('css/bootstrap.css');
 *	$assets->addCss('http://bootstrap.my-cdn.com/style.css', false);
 *</code>
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
 *<code>
 *	$assets->addJs('scripts/jquery.js');
 *	$assets->addJs('http://jquery.my-cdn.com/jquery.js', true);
 *</code>
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
	
	if (unlikely(Z_TYPE_P(id) != IS_STRING)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Collection-Id must be a string");
		return;
	}
	if (unlikely(Z_TYPE_P(collection) != IS_OBJECT)) {
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
	
	if (unlikely(Z_TYPE_P(id) != IS_STRING)) {
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
 * Traverses a collection calling the callback to generate its HTML
 *
 * @param Phalcon\Assets\Collection $collection
 * @param callback $callback
 */
PHP_METHOD(Phalcon_Assets_Manager, output){

	zval *collection, *callback, *output, *use_implicit_output;
	zval *resources, *filters, *prefix, *source_base_path = NULL;
	zval *target_base_path = NULL, *options, *collection_source_path;
	zval *complete_source_path = NULL, *collection_target_path;
	zval *complete_target_path = NULL, *filtered_joined_content = NULL;
	zval *join, *resource = NULL, *local = NULL, *path = NULL, *prefixed_path = NULL;
	zval *attributes = NULL, *parameters = NULL, *html = NULL, *content = NULL;
	zval *must_filter = NULL, *filter = NULL, *filtered_content = NULL;
	zval *source_path = NULL, *exception_message = NULL, *target_path = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &collection, &callback);
	
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
	
	/** 
	 * Prepare options if the collection must be filtered
	 */
	if (Z_TYPE_P(filters) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(source_base_path);
	
		PHALCON_INIT_VAR(target_base_path);
	
		PHALCON_OBS_VAR(options);
		phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
		/** 
		 * Check for global options in the assets manager
		 */
		if (Z_TYPE_P(options) == IS_ARRAY) { 
	
			/** 
			 * The source base path is a global location where all resources are located
			 */
			if (phalcon_array_isset_string(options, SS("sourceBasePath"))) {
				PHALCON_OBS_NVAR(source_base_path);
				phalcon_array_fetch_string(&source_base_path, options, SL("sourceBasePath"), PH_NOISY_CC);
			}
	
			/** 
			 * The target base path is a global location where all resources are written
			 */
			if (phalcon_array_isset_string(options, SS("targetBasePath"))) {
				PHALCON_OBS_NVAR(target_base_path);
				phalcon_array_fetch_string(&target_base_path, options, SL("targetBasePath"), PH_NOISY_CC);
			}
		}
	
		/** 
		 * Check if the collection have its own source base path
		 */
		PHALCON_INIT_VAR(collection_source_path);
		phalcon_call_method(collection_source_path, collection, "getsourcepath");
	
		/** 
		 * Concatenate the global base source path with the collection one
		 */
		if (PHALCON_IS_NOT_EMPTY(collection_source_path)) {
			PHALCON_INIT_VAR(complete_source_path);
			PHALCON_CONCAT_VV(complete_source_path, source_base_path, collection_source_path);
		} else {
			PHALCON_CPY_WRT(complete_source_path, source_base_path);
		}
	
		/** 
		 * Check if the collection have its own target base path
		 */
		PHALCON_INIT_VAR(collection_target_path);
		phalcon_call_method(collection_target_path, collection, "gettargetpath");
	
		/** 
		 * Concatenate the global base source path with the collection one
		 */
		if (PHALCON_IS_NOT_EMPTY(collection_target_path)) {
			PHALCON_INIT_VAR(complete_target_path);
			PHALCON_CONCAT_VV(complete_target_path, target_base_path, collection_target_path);
		} else {
			PHALCON_CPY_WRT(complete_target_path, target_base_path);
		}
	
		/** 
		 * Global filtered content
		 */
		PHALCON_INIT_VAR(filtered_joined_content);
	
		/** 
		 * Check if all the resources in the collection must be joined
		 */
		PHALCON_INIT_VAR(join);
		phalcon_call_method(join, collection, "getjoin");
	}
	
	
	if (!phalcon_is_iterable(resources, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(resource);
	
		PHALCON_INIT_NVAR(local);
		phalcon_call_method(local, resource, "getlocal");
	
		/** 
		 * If there are not filters, just print/buffer the HTML
		 */
		if (Z_TYPE_P(filters) != IS_ARRAY) { 
	
			PHALCON_INIT_NVAR(path);
			phalcon_call_method(path, resource, "getpath");
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
			 * Prepare the parameters for the callback
			 */
			if (Z_TYPE_P(attributes) == IS_ARRAY) { 
				phalcon_array_update_long(&attributes, 0, &prefixed_path, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
				PHALCON_INIT_NVAR(parameters);
				array_init_size(parameters, 2);
				phalcon_array_append(&parameters, attributes, PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&parameters, local, PH_SEPARATE TSRMLS_CC);
			} else {
				PHALCON_INIT_NVAR(parameters);
				array_init_size(parameters, 2);
				phalcon_array_append(&parameters, prefixed_path, PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&parameters, local, PH_SEPARATE TSRMLS_CC);
			}
	
			/** 
			 * Call the callback to generate the HTML
			 */
			PHALCON_INIT_NVAR(html);
			PHALCON_CALL_USER_FUNC_ARRAY(html, callback, parameters);
	
			/** 
			 * Implicit output prints the content directly
			 */
			if (zend_is_true(use_implicit_output)) {
				zend_print_zval(html, 0);
			} else {
				phalcon_concat_self(&output, html TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		/** 
		 * Gets the resource's content
		 */
		PHALCON_INIT_NVAR(content);
		phalcon_call_method_p1(content, resource, "getcontent", complete_source_path);
	
		/** 
		 * Check if the resource must be filtered
		 */
		PHALCON_INIT_NVAR(must_filter);
		phalcon_call_method(must_filter, resource, "getfilter");
	
		/** 
		 * Only filter the resource if it's marked as 'filterable'
		 */
		if (!zend_is_true(must_filter)) {
	
			if (!phalcon_is_iterable(filters, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_HVALUE(filter);
	
				/** 
				 * Filters must be valid objects
				 */
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Filter is invalid");
					return;
				}
	
				/** 
				 * Calls the method 'filter' which must return a filtered version of the content
				 */
				PHALCON_INIT_NVAR(filtered_content);
				phalcon_call_method_p1(filtered_content, filter, "filter", content);
	
				/** 
				 * Update the joined filtered content
				 */
				if (zend_is_true(join)) {
					if (Z_TYPE_P(filtered_joined_content) == IS_NULL) {
						PHALCON_CPY_WRT(filtered_joined_content, filtered_content);
					} else {
						phalcon_concat_self(&filtered_joined_content, filtered_content TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		} else {
			/** 
			 * Update the joined filtered content
			 */
			if (zend_is_true(join)) {
				if (Z_TYPE_P(filtered_joined_content) == IS_NULL) {
					PHALCON_CPY_WRT(filtered_joined_content, content);
				} else {
					phalcon_concat_self(&filtered_joined_content, content TSRMLS_CC);
				}
			}
		}
	
		/** 
		 * If the collection must not be joined we must print a HTML for each one
		 */
		if (!zend_is_true(join)) {
	
			/** 
			 * Get the complete path
			 */
			PHALCON_INIT_NVAR(source_path);
			phalcon_call_method_p1(source_path, resource, "getrealsourcepath", complete_source_path);
	
			/** 
			 * We need a valid source path
			 */
			if (!zend_is_true(source_path)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Resource '", source_path, "' does not have a valid source path");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Get the target path, we need to write the filtered content to a file
			 */
			PHALCON_INIT_NVAR(target_path);
			phalcon_call_method_p1(target_path, resource, "getrealtargetpath", complete_target_path);
	
			/** 
			 * We need a valid final target path
			 */
			if (PHALCON_IS_EMPTY(target_path)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Resource '", source_path, "' does not have a valid target path");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Make sure the target path is not the same source path
			 */
			if (PHALCON_IS_EQUAL(target_path, source_path)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Resource '", source_path, "' have the same source and target paths");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * Write the file using file_put_contents. This respects the openbase-dir also
			 * writes to streams
			 */
			phalcon_call_func_p2_noret("file_put_contents", target_path, filtered_content);
	
			/** 
			 * Generate the HTML using the original path in the resource
			 */
			PHALCON_INIT_NVAR(path);
			phalcon_call_method(path, resource, "getpath");
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
			 * Prepare the parameters for the callback
			 */
			if (Z_TYPE_P(attributes) == IS_ARRAY) { 
				phalcon_array_update_long(&attributes, 0, &prefixed_path, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
				PHALCON_INIT_NVAR(parameters);
				array_init_size(parameters, 2);
				phalcon_array_append(&parameters, attributes, PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&parameters, local, PH_SEPARATE TSRMLS_CC);
			} else {
				PHALCON_INIT_NVAR(parameters);
				array_init_size(parameters, 2);
				phalcon_array_append(&parameters, prefixed_path, PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&parameters, local, PH_SEPARATE TSRMLS_CC);
			}
	
			/** 
			 * Call the callback to generate the HTML
			 */
			PHALCON_INIT_NVAR(html);
			PHALCON_CALL_USER_FUNC_ARRAY(html, callback, parameters);
	
			/** 
			 * Implicit output prints the content directly
			 */
			if (zend_is_true(use_implicit_output)) {
				zend_print_zval(html, 0);
			} else {
				phalcon_concat_self(&output, html TSRMLS_CC);
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CCTOR(output);
}

/**
 * Prints the HTML for CSS resources
 *
 * @param string $collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss){

	zval *collection_name = NULL, *collection = NULL, *callback;
	zval *output;

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
	
	PHALCON_INIT_VAR(callback);
	array_init_size(callback, 2);
	add_next_index_stringl(callback, SL("Phalcon\\Tag"), 1);
	add_next_index_stringl(callback, SL("stylesheetLink"), 1);
	
	PHALCON_INIT_VAR(output);
	phalcon_call_method_p2(output, this_ptr, "output", collection, callback);
	
	RETURN_CCTOR(output);
}

/**
 * Prints the HTML for JS resources
 *
 * @param string $collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputJs){

	zval *collection_name = NULL, *collection = NULL, *callback;
	zval *output;

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
	
	PHALCON_INIT_VAR(callback);
	array_init_size(callback, 2);
	add_next_index_stringl(callback, SL("Phalcon\\Tag"), 1);
	add_next_index_stringl(callback, SL("javascriptInclude"), 1);
	
	PHALCON_INIT_VAR(output);
	phalcon_call_method_p2(output, this_ptr, "output", collection, callback);
	
	RETURN_CCTOR(output);
}

