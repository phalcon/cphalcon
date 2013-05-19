
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

	return SUCCESS;
}

/**
 * Phalcon\Assets\Resource
 *
 * @param string $type
 * @param string $path
 * @param boolean $local
 */
PHP_METHOD(Phalcon_Assets_Resource, __construct){

	zval *type, *path, *local = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &type, &path, &local);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_local"), local TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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
 * Returns the URI/URL path to the resource
 *
 * @return string
 */
PHP_METHOD(Phalcon_Assets_Resource, getPath){


	RETURN_MEMBER(this_ptr, "_path");
}

/**
 * Returns whether the resource is local or external
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Assets_Resource, getLocal){


	RETURN_MEMBER(this_ptr, "_local");
}

