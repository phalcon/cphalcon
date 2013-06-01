
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

/**
 * Phalcon\Assets\Resource
 *
 * Represents an asset resource
 */


/**
 * Phalcon\Assets\Resource initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Resource){

	PHALCON_REGISTER_CLASS(Phalcon\\Assets, Resource, assets_resource, phalcon_assets_resource_method_entry, 0);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_local"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Assets\Resource constructor
 *
 * @param string $type
 * @param string $path
 * @param boolean $local
 * @param boolean $filter
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Assets_Resource, __construct){

	zval *type, *path, *local = NULL, *filter = NULL, *attributes = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 3, &type, &path, &local, &filter, &attributes);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	if (!filter) {
		PHALCON_INIT_VAR(filter);
		ZVAL_BOOL(filter, 1);
	}
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
	if (Z_TYPE_P(attributes) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the resource's type
 *
 * @param string $type
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setType){

	zval *type;

	phalcon_fetch_params(0, 1, 0, &type);
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the type of resource
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Sets the resource's path
 *
 * @param string $path
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setPath){

	zval *path;

	phalcon_fetch_params(0, 1, 0, &path);
	
	phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the URI/URL path to the resource
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getPath){


	RETURN_MEMBER(this_ptr, "_path");
}

/**
 * Sets if the resource is local or external
 *
 * @param boolean $local
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setLocal){

	zval *local;

	phalcon_fetch_params(0, 1, 0, &local);
	
	phalcon_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns whether the resource is local or external
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Resource, getLocal){


	RETURN_MEMBER(this_ptr, "_local");
}

/**
 * Sets if the resource must be filtered or not
 *
 * @param boolean $filter
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setFilter){

	zval *filter;

	phalcon_fetch_params(0, 1, 0, &filter);
	
	phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns whether the resource must be filtered or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Resource, getFilter){


	RETURN_MEMBER(this_ptr, "_filter");
}

/**
 * Sets extra HTML attributes
 *
 * @param array $attributes
 * @return Phalcon\Assets\Resource
 */
PHP_METHOD(Phalcon_Assets_Resource, setAttributes){

	zval *attributes;

	phalcon_fetch_params(0, 1, 0, &attributes);
	
	phalcon_update_property_this(this_ptr, SL("_attributes"), attributes TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns extra HTML attributes set in the resource
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Resource, getAttributes){


	RETURN_MEMBER(this_ptr, "_attributes");
}

/**
 * Returns the content of the resource as an string
 * Optionally a path where the resource is located can be set
 *
 * @param string $path
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getContent){


	
}

