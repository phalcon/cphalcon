
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

#include "assets/manager.h"
#include "assets/collection.h"
#include "assets/exception.h"
#include "assets/resource.h"
#include "assets/resource/css.h"
#include "assets/resource/js.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"

/**
 * Phalcon\Assets\Manager
 *
 * Manages collections of CSS/Javascript assets
 */
zend_class_entry *phalcon_assets_manager_ce;

PHP_METHOD(Phalcon_Assets_Manager, __construct);
PHP_METHOD(Phalcon_Assets_Manager, setOptions);
PHP_METHOD(Phalcon_Assets_Manager, getOptions);
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput);
PHP_METHOD(Phalcon_Assets_Manager, addCss);
PHP_METHOD(Phalcon_Assets_Manager, addJs);
PHP_METHOD(Phalcon_Assets_Manager, addResourceByType);
PHP_METHOD(Phalcon_Assets_Manager, addResource);
PHP_METHOD(Phalcon_Assets_Manager, set);
PHP_METHOD(Phalcon_Assets_Manager, get);
PHP_METHOD(Phalcon_Assets_Manager, getCss);
PHP_METHOD(Phalcon_Assets_Manager, getJs);
PHP_METHOD(Phalcon_Assets_Manager, collection);
PHP_METHOD(Phalcon_Assets_Manager, output);
PHP_METHOD(Phalcon_Assets_Manager, outputCss);
PHP_METHOD(Phalcon_Assets_Manager, outputJs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_useimplicitoutput, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitOutput)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addresourcebytype, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_collection, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_output, 0, 0, 2)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputcss, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputjs, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_assets_manager_method_entry[] = {
	PHP_ME(Phalcon_Assets_Manager, __construct, arginfo_phalcon_assets_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Manager, setOptions, arginfo_phalcon_assets_manager_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, useImplicitOutput, arginfo_phalcon_assets_manager_useimplicitoutput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addCss, arginfo_phalcon_assets_manager_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addJs, arginfo_phalcon_assets_manager_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addResourceByType, arginfo_phalcon_assets_manager_addresourcebytype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addResource, arginfo_phalcon_assets_manager_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, set, arginfo_phalcon_assets_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, get, arginfo_phalcon_assets_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getCss, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getJs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, collection, arginfo_phalcon_assets_manager_collection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, output, arginfo_phalcon_assets_manager_output, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputCss, arginfo_phalcon_assets_manager_outputcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputJs, arginfo_phalcon_assets_manager_outputjs, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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

	phalcon_fetch_params(0, 0, 1, &options);
	
	if (options && Z_TYPE_P(options) == IS_ARRAY) {
		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
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
		PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Options must be an array");
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
		local = PHALCON_GLOBAL(z_true);
	}
	
	if (!filter) {
		filter = PHALCON_GLOBAL(z_true);
	}
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "css", 1);
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_css_ce);
	PHALCON_CALL_METHOD(NULL, resource, "__construct", path, local, filter, attributes);
	
	PHALCON_CALL_METHOD(NULL, this_ptr, "addresourcebytype", type, resource);
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
		local = PHALCON_GLOBAL(z_true);
	}
	
	if (!filter) {
		filter = PHALCON_GLOBAL(z_true);
	}
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "js", 1);
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_js_ce);
	PHALCON_CALL_METHOD(NULL, resource, "__construct", path, local, filter, attributes);
	
	PHALCON_CALL_METHOD(NULL, this_ptr, "addresourcebytype", type, resource);
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
	phalcon_read_property_this(&collections, this_ptr, SL("_collections"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(collections, type)) {
		PHALCON_OBS_VAR(collection);
		phalcon_array_fetch(&collection, collections, type, PH_NOISY);
	} else {
		PHALCON_INIT_NVAR(collection);
		object_init_ex(collection, phalcon_assets_collection_ce);
		phalcon_update_property_array(this_ptr, SL("_collections"), type, collection TSRMLS_CC);
	}
	
	/** 
	 * Add the resource to the collection
	 */
	PHALCON_CALL_METHOD(NULL, collection, "add", resource);
	
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

	zval *resource, *type = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &resource);
	
	PHALCON_VERIFY_CLASS_EX(resource, phalcon_assets_resource_ce, phalcon_assets_exception_ce, 1);
	PHALCON_CALL_METHOD(&type, resource, "gettype");
	
	/** 
	 * Adds the resource by its type
	 */
	PHALCON_CALL_METHOD(NULL, this_ptr, "addresourcebytype", type, resource);
	
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
		PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Collection-Id must be a string");
		return;
	}
	if (unlikely(Z_TYPE_P(collection) != IS_OBJECT)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Collection must be an object");
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

	phalcon_fetch_params(0, 1, 0, &id);
	
	if (unlikely(Z_TYPE_P(id) != IS_STRING)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Collection-Id must be a string");
		return;
	}
	
	collections = phalcon_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&collection, collections, id)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "The collection does not exist in the manager");
		return;
	}
	
	RETURN_ZVAL(collection, 1, 0);
}

/**
 * Returns the CSS collection of assets
 *
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, getCss){

	zval *collections, *collection;

	collections = phalcon_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Check if the collection does not exist and create an implicit collection
	 */
	if (!phalcon_array_isset_string_fetch(&collection, collections, SS("css"))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		return;
	}
	
	RETURN_ZVAL(collection, 1, 0);
}

/**
 * Returns the CSS collection of assets
 *
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, getJs){

	zval *collections, *collection;

	collections = phalcon_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Check if the collection does not exist and create an implicit collection
	 */
	if (!phalcon_array_isset_string_fetch(&collection, collections, SS("js"))) {
		object_init_ex(return_value, phalcon_assets_collection_ce);
		return;
	}
	
	RETURN_ZVAL(collection, 1, 0);
}

/**
 * Creates/Returns a collection of resources
 *
 * @param string $name
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Manager, collection){

	zval *name, *collections, *collection = NULL;

	phalcon_fetch_params(0, 1, 0, &name);
	
	collections = phalcon_fetch_nproperty_this(this_ptr, SL("_collections"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&collection, collections, name)) {
		RETURN_ZVAL(collection, 1, 0);
	}

	object_init_ex(return_value, phalcon_assets_collection_ce);
	phalcon_update_property_array(this_ptr, SL("_collections"), name, return_value TSRMLS_CC);
}

/**
 * Traverses a collection calling the callback to generate its HTML
 *
 * @param Phalcon\Assets\Collection $collection
 * @param callback $callback
 * @param string $type
 */
PHP_METHOD(Phalcon_Assets_Manager, output){

	zval *collection, *callback, *type = NULL, *output, *use_implicit_output;
	zval *resources = NULL, *filters = NULL, *prefix = NULL, *source_base_path = NULL;
	zval *target_base_path = NULL, *options, *collection_source_path = NULL;
	zval *complete_source_path = NULL, *collection_target_path = NULL;
	zval *complete_target_path = NULL, *filtered_joined_content = NULL;
	zval *join = NULL, *exception_message = NULL, *is_directory;
	zval *resource = NULL, *filter_needed = NULL, *local = NULL, *source_path = NULL;
	zval *target_path = NULL, *path = NULL, *prefixed_path = NULL, *attributes = NULL;
	zval *parameters = NULL, *html = NULL, *content = NULL, *must_filter = NULL;
	zval *filter = NULL, *filtered_content = NULL, *target_uri = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	zval *type_css;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &collection, &callback, &type);
	
	PHALCON_INIT_VAR(output);
	
	PHALCON_OBS_VAR(use_implicit_output);
	phalcon_read_property_this(&use_implicit_output, this_ptr, SL("_implicitOutput"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Get the resources as an array
	 */
	PHALCON_CALL_METHOD(&resources, collection, "getresources");
	
	/** 
	 * Get filters in the collection
	 */
	PHALCON_CALL_METHOD(&filters, collection, "getfilters");
	
	/** 
	 * Get the collection's prefix
	 */
	PHALCON_CALL_METHOD(&prefix, collection, "getprefix");

	PHALCON_INIT_VAR(type_css);
	ZVAL_STRING(type_css, "css", 1);
	
	/** 
	 * Prepare options if the collection must be filtered
	 */
	if (Z_TYPE_P(filters) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(source_base_path);
	
		PHALCON_INIT_VAR(target_base_path);
	
		PHALCON_OBS_VAR(options);
		phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	
		/** 
		 * Check for global options in the assets manager
		 */
		if (Z_TYPE_P(options) == IS_ARRAY) { 
	
			/** 
			 * The source base path is a global location where all resources are located
			 */
			if (phalcon_array_isset_string(options, SS("sourceBasePath"))) {
				PHALCON_OBS_NVAR(source_base_path);
				phalcon_array_fetch_string(&source_base_path, options, SL("sourceBasePath"), PH_NOISY);
			}
	
			/** 
			 * The target base path is a global location where all resources are written
			 */
			if (phalcon_array_isset_string(options, SS("targetBasePath"))) {
				PHALCON_OBS_NVAR(target_base_path);
				phalcon_array_fetch_string(&target_base_path, options, SL("targetBasePath"), PH_NOISY);
			}
		}
	
		/** 
		 * Check if the collection have its own source base path
		 */
		PHALCON_CALL_METHOD(&collection_source_path, collection, "getsourcepath");
	
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
		PHALCON_CALL_METHOD(&collection_target_path, collection, "gettargetpath");
	
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
		PHALCON_CALL_METHOD(&join, collection, "getjoin");
	
		/** 
		 * Check for valid target paths if the collection must be joined
		 */
		if (zend_is_true(join)) {
	
			/** 
			 * We need a valid final target path
			 */
			if (PHALCON_IS_EMPTY(complete_target_path)) {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Path '", complete_target_path, "' is not a valid target path (1)");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
				return;
			}
	
			PHALCON_INIT_VAR(is_directory);
			phalcon_is_dir(is_directory, complete_target_path TSRMLS_CC);
	
			/** 
			 * The targetpath needs to be a valid file
			 */
			if (PHALCON_IS_TRUE(is_directory)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Path '", complete_target_path, "' is not a valid target path (2)");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
				return;
			}
		}
	}
	
	phalcon_is_iterable(resources, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(resource);
	
		PHALCON_INIT_NVAR(filter_needed);
		ZVAL_FALSE(filter_needed);

		if (!type) {
			PHALCON_CALL_METHOD(&type, resource, "gettype");
		}

		/** 
		 * Is the resource local?
		 */
		PHALCON_CALL_METHOD(&local, resource, "getlocal");
	
		/** 
		 * If the collection must not be joined we must print a HTML for each one
		 */
		if (Z_TYPE_P(filters) == IS_ARRAY) { 
			if (zend_is_true(local)) {

				/** 
				 * Get the complete path
				 */
				PHALCON_CALL_METHOD(&source_path, resource, "getrealsourcepath", complete_source_path);

				/** 
				 * We need a valid source path
				 */
				if (!zend_is_true(source_path)) {
					PHALCON_CALL_METHOD(&source_path, resource, "getpath");

					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Resource '", source_path, "' does not have a valid source path");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
					return;
				}
			} else {
				/** 
				 * Get the complete source path
				 */
				PHALCON_CALL_METHOD(&source_path, resource, "getpath");

				/** 
				 * resources paths are always filtered
				 */
				PHALCON_INIT_NVAR(filter_needed);
				ZVAL_TRUE(filter_needed);
			}

			/** 
			 * Get the target path, we need to write the filtered content to a file
			 */
			PHALCON_CALL_METHOD(&target_path, resource, "getrealtargetpath", complete_target_path);

			/** 
			 * We need a valid final target path
			 */
			if (PHALCON_IS_EMPTY(target_path)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Resource '", source_path, "' does not have a valid target path");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
				return;
			}

			if (zend_is_true(local)) {

				/** 
				 * Make sure the target path is not the same source path
				 */
				if (PHALCON_IS_EQUAL(target_path, source_path)) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Resource '", target_path, "' have the same source and target paths");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_assets_exception_ce, exception_message);
					return;
				}
				if (phalcon_file_exists(target_path TSRMLS_CC) == SUCCESS) {
					if (phalcon_compare_mtime(target_path, source_path TSRMLS_CC)) {
						PHALCON_INIT_NVAR(filter_needed);
						ZVAL_TRUE(filter_needed);
					}
				} else {
					PHALCON_INIT_NVAR(filter_needed);
					ZVAL_TRUE(filter_needed);
				}
			}
		}
	
		/** 
		 * If there are no filters, just print/buffer the HTML
		 */
		if (Z_TYPE_P(filters) != IS_ARRAY) { 
			PHALCON_CALL_METHOD(&path, resource, "getrealtargeturi");
			if (Z_TYPE_P(prefix) != IS_NULL) {
				PHALCON_INIT_NVAR(prefixed_path);
				PHALCON_CONCAT_VV(prefixed_path, prefix, path);
			} else {
				PHALCON_CPY_WRT(prefixed_path, path);
			}
	
			/** 
			 * Gets extra HTML attributes in the resource
			 */
			PHALCON_CALL_METHOD(&attributes, resource, "getattributes");
	
			/** 
			 * Prepare the parameters for the callback
			 */
			PHALCON_INIT_NVAR(parameters);
			array_init_size(parameters, 2);
			if (Z_TYPE_P(attributes) == IS_ARRAY) { 
				phalcon_array_update_long(&attributes, 0, prefixed_path, PH_COPY | PH_SEPARATE);
	
				phalcon_array_append(&parameters, attributes, 0);
			} else {
				phalcon_array_append(&parameters, prefixed_path, 0);
			}

			phalcon_array_append(&parameters, local, 0);
	
			/** 
			 * Call the callback to generate the HTML
			 */
			PHALCON_INIT_NVAR(html);/**/
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
	
		if (zend_is_true(filter_needed)) {
	
			/** 
			 * Get the resource's content
			 */
			PHALCON_CALL_METHOD(&content, resource, "getcontent", complete_source_path);
	
			/** 
			 * Check if the resource must be filtered
			 */
			PHALCON_CALL_METHOD(&must_filter, resource, "getfilter");
	
			/** 
			 * Only filter the resource if it's marked as 'filterable'
			 */
			if (zend_is_true(must_filter)) {
	
				phalcon_is_iterable(filters, &ah1, &hp1, 0, 0);
	
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
					PHALCON_CALL_METHOD(&filtered_content, filter, "filter", content);
					PHALCON_CPY_WRT_CTOR(content, filtered_content);

					zend_hash_move_forward_ex(ah1, &hp1);
				}

				/**
				 * Update the joined filtered content
				 */
				if (zend_is_true(join)) {
					if (PHALCON_IS_EQUAL(type, type_css)) {
						if (Z_TYPE_P(filtered_joined_content) == IS_NULL) {
							PHALCON_INIT_NVAR(filtered_joined_content);
							PHALCON_CONCAT_VS(filtered_joined_content, content, "");
						} else {
							PHALCON_SCONCAT_VS(filtered_joined_content, content, "");
						}
					} else {
						if (Z_TYPE_P(filtered_joined_content) == IS_NULL) {
							PHALCON_INIT_NVAR(filtered_joined_content);
							PHALCON_CONCAT_VS(filtered_joined_content, content, ";");
						} else {
							PHALCON_SCONCAT_VS(filtered_joined_content, content, ";");
						}
					}
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
				} else {
					PHALCON_CPY_WRT(filtered_content, content);
				}
			}
	
			if (!zend_is_true(join)) {
				/** 
				 * Write the file using file-put-contents. This respects the openbase-dir also
				 * writes to streams
				 */
				phalcon_file_put_contents(NULL, target_path, filtered_content TSRMLS_CC);
			}
		}
	
		if (!zend_is_true(join)) {
	
			/** 
			 * Generate the HTML using the original path in the resource
			 */
			PHALCON_CALL_METHOD(&path, resource, "getrealtargeturi");
			if (Z_TYPE_P(prefix) != IS_NULL) {
				PHALCON_INIT_NVAR(prefixed_path);
				PHALCON_CONCAT_VV(prefixed_path, prefix, path);
			} else {
				PHALCON_CPY_WRT(prefixed_path, path);
			}
	
			/** 
			 * Gets extra HTML attributes in the resource
			 */
			PHALCON_CALL_METHOD(&attributes, resource, "getattributes");
	
			/** 
			 * Filtered resources are always local
			 */
			PHALCON_INIT_NVAR(local);
			ZVAL_TRUE(local);
	
			/** 
			 * Prepare the parameters for the callback
			 */
			PHALCON_INIT_NVAR(parameters);
			array_init_size(parameters, 2);
			if (Z_TYPE_P(attributes) == IS_ARRAY) { 
				phalcon_array_update_long(&attributes, 0, prefixed_path, PH_COPY | PH_SEPARATE);
	
				phalcon_array_append(&parameters, attributes, 0);
			} else {
				phalcon_array_append(&parameters, prefixed_path, 0);
			}

			phalcon_array_append(&parameters, local, 0);

			/** 
			 * Call the callback to generate the HTML
			 */
			PHALCON_INIT_NVAR(html);/**/
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
	
	if (Z_TYPE_P(filters) == IS_ARRAY) { 
		if (zend_is_true(join)) {
	
			/** 
			 * Write the file using file_put_contents. This respects the openbase-dir also
			 * writes to streams
			 */
			phalcon_file_put_contents(NULL, complete_target_path, filtered_joined_content TSRMLS_CC);
	
			/** 
			 * Generate the HTML using the original path in the resource
			 */
			PHALCON_CALL_METHOD(&target_uri, collection, "gettargeturi");
			if (Z_TYPE_P(prefix) != IS_NULL) {
				PHALCON_INIT_NVAR(prefixed_path);
				PHALCON_CONCAT_VV(prefixed_path, prefix, target_uri);
			} else {
				PHALCON_CPY_WRT(prefixed_path, target_uri);
			}
	
			/** 
			 * Gets extra HTML attributes in the resource
			 */
			PHALCON_CALL_METHOD(&attributes, collection, "getattributes");
			PHALCON_CALL_METHOD(&local, collection, "gettargetlocal");
	
			/** 
			 * Prepare the parameters for the callback
			 */
			PHALCON_INIT_NVAR(parameters);
			array_init_size(parameters, 2);
			if (Z_TYPE_P(attributes) == IS_ARRAY) { 
				phalcon_array_update_long(&attributes, 0, prefixed_path, PH_COPY | PH_SEPARATE);
	
				phalcon_array_append(&parameters, attributes, 0);
			} else {
				phalcon_array_append(&parameters, prefixed_path, 0);
			}

			phalcon_array_append(&parameters, local, 0);

			/** 
			 * Call the callback to generate the HTML
			 */
			PHALCON_INIT_NVAR(html);/**/
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
	}
	
	RETURN_CCTOR(output);
}

/**
 * Prints the HTML for CSS resources
 *
 * @param string $collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss){

	zval *collection_name = NULL, *collection = NULL, *callback, *type = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &collection_name);
	
	if (!collection_name || PHALCON_IS_EMPTY(collection_name)) {
		PHALCON_CALL_METHOD(&collection, this_ptr, "getcss");
	} else {
		PHALCON_CALL_METHOD(&collection, this_ptr, "get", collection_name);
	}
	
	PHALCON_INIT_VAR(callback);
	array_init_size(callback, 2);
	add_next_index_stringl(callback, SL("Phalcon\\Tag"), 1);
	add_next_index_stringl(callback, SL("stylesheetLink"), 1);

	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "css", 1);
	
	PHALCON_RETURN_CALL_METHOD(this_ptr, "output", collection, callback, type);
	
	PHALCON_MM_RESTORE();
}

/**
 * Prints the HTML for JS resources
 *
 * @param string $collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputJs){

	zval *collection_name = NULL, *collection = NULL, *callback, *type = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &collection_name);
	
	if (!collection_name) {
		collection_name = PHALCON_GLOBAL(z_null);
	}

	if (PHALCON_IS_EMPTY(collection_name)) {
		PHALCON_CALL_METHOD(&collection, this_ptr, "getjs");
	} else {
		PHALCON_CALL_METHOD(&collection, this_ptr, "get", collection_name);
	}
	
	PHALCON_INIT_VAR(callback);
	array_init_size(callback, 2);
	add_next_index_stringl(callback, SL("Phalcon\\Tag"), 1);
	add_next_index_stringl(callback, SL("javascriptInclude"), 1);
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "js", 1);

	PHALCON_RETURN_CALL_METHOD(this_ptr, "output", collection, callback, type);

	PHALCON_MM_RESTORE();
}
