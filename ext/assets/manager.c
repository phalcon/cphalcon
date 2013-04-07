
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

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

	zend_declare_property_null(phalcon_assets_manager_ce, SL("_collections"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_assets_manager_ce, SL("_implicitOutput"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Sets if the html generated must be directly printed or returned
 *
 * @param boolean $implicitOutput
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput){

	zval *implicit_output;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &implicit_output) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_implicitOutput"), implicit_output TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Adds a Css resource to the 'css' collection
 *
 * @param string $path
 * @param boolean $local
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addCss){

	zval *path, *local = NULL, *type, *resource;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &path, &local) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "css", 1);
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_css_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(resource, "__construct", path, local);
	
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "addresourcebytype", type, resource);
	RETURN_THIS();
}

/**
 * Adds a javascript resource to the 'js' collection
 *
 * @param string $path
 * @param boolean $local
 * @return Phalcon\Assets\Manager
 */
PHP_METHOD(Phalcon_Assets_Manager, addJs){

	zval *path, *local = NULL, *type, *resource;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &path, &local) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "js", 1);
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_js_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(resource, "__construct", path, local);
	
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "addresourcebytype", type, resource);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &type, &resource) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(collections);
	phalcon_read_property(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
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
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(collection, "add", resource);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &resource) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(resource) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Resource must be an object");
		return;
	}
	
	PHALCON_INIT_VAR(type);
	PHALCON_CALL_METHOD(type, resource, "gettype");
	
	/** 
	 * Adds the resource by its type
	 */
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "addresourcebytype", type, resource);
	
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

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &id, &collection) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(id) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Collection-Id must be a string");
		return;
	}
	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Collection must be an object");
		return;
	}
	
	phalcon_update_property_array(this_ptr, SL("_collections"), id, collection TSRMLS_CC);
	
	RETURN_THIS();
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &id) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(id) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Collection-Id must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(collections);
	phalcon_read_property(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
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
	phalcon_read_property(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
	
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
	phalcon_read_property(&collections, this_ptr, SL("_collections"), PH_NOISY_CC);
	
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
 *
 */
PHP_METHOD(Phalcon_Assets_Manager, collection){


	
}

/**
 * Prints the HTML for CSS resources
 *
 * @param string $collectionName
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss){

	zval *collection_name = NULL, *collection = NULL, *output;
	zval *use_implicit_output, *resources, *resource = NULL;
	zval *path = NULL, *local = NULL, *html = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &collection_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!collection_name) {
		PHALCON_INIT_VAR(collection_name);
	}
	
	if (PHALCON_IS_EMPTY(collection_name)) {
		PHALCON_INIT_VAR(collection);
		PHALCON_CALL_METHOD(collection, this_ptr, "getcss");
	} else {
		PHALCON_INIT_NVAR(collection);
		PHALCON_CALL_METHOD_PARAMS_1(collection, this_ptr, "get", collection_name);
	}
	
	PHALCON_INIT_VAR(output);
	
	PHALCON_OBS_VAR(use_implicit_output);
	phalcon_read_property(&use_implicit_output, this_ptr, SL("_implicitOutput"), PH_NOISY_CC);
	
	/** 
	 * Get the resources as an array
	 */
	PHALCON_INIT_VAR(resources);
	PHALCON_CALL_METHOD(resources, collection, "getresources");
	
	if (!phalcon_is_iterable(resources, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(resource);
	
		PHALCON_INIT_NVAR(path);
		PHALCON_CALL_METHOD(path, resource, "getpath");
	
		PHALCON_INIT_NVAR(local);
		PHALCON_CALL_METHOD(local, resource, "getlocal");
	
		/** 
		 * Generate the html using Phalcon\Tag
		 */
		PHALCON_INIT_NVAR(html);
		PHALCON_CALL_STATIC_PARAMS_2(html, "phalcon\\tag", "stylesheetlink", path, local);
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
	zval *use_implicit_output, *resources, *resource = NULL;
	zval *path = NULL, *local = NULL, *html = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &collection_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!collection_name) {
		PHALCON_INIT_VAR(collection_name);
	}
	
	if (PHALCON_IS_EMPTY(collection_name)) {
		PHALCON_INIT_VAR(collection);
		PHALCON_CALL_METHOD(collection, this_ptr, "getjs");
	} else {
		PHALCON_INIT_NVAR(collection);
		PHALCON_CALL_METHOD_PARAMS_1(collection, this_ptr, "get", collection_name);
	}
	
	PHALCON_INIT_VAR(output);
	
	PHALCON_OBS_VAR(use_implicit_output);
	phalcon_read_property(&use_implicit_output, this_ptr, SL("_implicitOutput"), PH_NOISY_CC);
	
	/** 
	 * Get the resources as an array
	 */
	PHALCON_INIT_VAR(resources);
	PHALCON_CALL_METHOD(resources, collection, "getresources");
	
	if (!phalcon_is_iterable(resources, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(resource);
	
		PHALCON_INIT_NVAR(path);
		PHALCON_CALL_METHOD(path, resource, "getpath");
	
		PHALCON_INIT_NVAR(local);
		PHALCON_CALL_METHOD(local, resource, "getlocal");
	
		/** 
		 * Generate the html using Phalcon\Tag
		 */
		PHALCON_INIT_NVAR(html);
		PHALCON_CALL_STATIC_PARAMS_2(html, "phalcon\\tag", "javascriptinclude", path, local);
		if (zend_is_true(use_implicit_output)) {
			zend_print_zval(html, 0);
		} else {
			phalcon_concat_self(&output, html TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CCTOR(output);
}

