
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

#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"

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

	return SUCCESS;
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
 * Prints the CSS resources added
 */
PHP_METHOD(Phalcon_Assets_Manager, outputCss){


	
}

