
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

/**
 * Phalcon\Assets\Collection
 *
 * Represents a collection of resources // ArrayAccess,
 */


/**
 * Phalcon\Assets\Collection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Collection){

	PHALCON_REGISTER_CLASS(Phalcon\\Assets, Collection, assets_collection, phalcon_assets_collection_method_entry, 0);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_local"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_resources"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
		PHALCON_THROW_EXCEPTION_STR(phalcon_assets_exception_ce, "Resource must be an object");
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
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss){

	zval *path, *local = NULL, *collection_local = NULL, *resource;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &path, &local);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
	}
	
	if (Z_TYPE_P(local) == IS_BOOL) {
		PHALCON_CPY_WRT(collection_local, local);
	} else {
		PHALCON_OBS_VAR(collection_local);
		phalcon_read_property_this(&collection_local, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_css_ce);
	phalcon_call_method_p2_noret(resource, "__construct", path, collection_local);
	
	phalcon_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Adds a Js resource to the collection
 *
 * @param string $path
 * @param boolean $local
 * @return Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs){

	zval *path, *local = NULL, *collection_local = NULL, *resource;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &path, &local);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
	}
	
	if (Z_TYPE_P(local) == IS_BOOL) {
		PHALCON_CPY_WRT(collection_local, local);
	} else {
		PHALCON_OBS_VAR(collection_local);
		phalcon_read_property_this(&collection_local, this_ptr, SL("_local"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(resource);
	object_init_ex(resource, phalcon_assets_resource_js_ce);
	phalcon_call_method_p2_noret(resource, "__construct", path, collection_local);
	
	phalcon_update_property_array_append(this_ptr, SL("_resources"), resource TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns the resources as an array
 *
 * @return Phalcon\Assets\Resource[]
 */
PHP_METHOD(Phalcon_Assets_Collection, getResources){

	zval *resources, *empty_array;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(resources);
	phalcon_read_property_this(&resources, this_ptr, SL("_resources"), PH_NOISY_CC);
	if (Z_TYPE_P(resources) != IS_ARRAY) { 
		PHALCON_INIT_VAR(empty_array);
		array_init(empty_array);
		RETURN_CTOR(empty_array);
	}
	
	RETURN_CCTOR(resources);
}

/**
 * Returns the number of elements in the form
 *
 * @return int
 */
PHP_METHOD(Phalcon_Assets_Collection, count){

	zval *resources, *number;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(resources);
	phalcon_read_property_this(&resources, this_ptr, SL("_resources"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number);
	phalcon_fast_count(number, resources TSRMLS_CC);
	RETURN_NCTOR(number);
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

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(position);
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(resources);
	phalcon_read_property_this(&resources, this_ptr, SL("_resources"), PH_NOISY_CC);
	if (phalcon_array_isset(resources, position)) {
		PHALCON_OBS_VAR(resource);
		phalcon_array_fetch(&resource, resources, position, PH_NOISY_CC);
		RETURN_CCTOR(resource);
	}
	
	RETURN_MM_NULL();
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
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(resources);
	phalcon_read_property_this(&resources, this_ptr, SL("_resources"), PH_NOISY_CC);
	if (phalcon_array_isset(resources, position)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
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

