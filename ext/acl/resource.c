
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

#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"

/**
 * Phalcon\Acl\Resource
 *
 * This class defines resource entity and its description
 *
 */


/**
 * Phalcon\Acl\Resource initializer
 */
PHALCON_INIT_CLASS(Phalcon_Acl_Resource){

	PHALCON_REGISTER_CLASS(Phalcon\\Acl, Resource, acl_resource, phalcon_acl_resource_method_entry, 0);

	zend_declare_property_null(phalcon_acl_resource_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_acl_resource_ce TSRMLS_CC, 1, phalcon_acl_resourceinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Acl\Resource constructor
 *
 * @param string $name
 * @param string $description
 */
PHP_METHOD(Phalcon_Acl_Resource, __construct){

	zval *name, *description = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &name, &description);
	
	if (!description) {
		PHALCON_INIT_VAR(description);
	}
	
	if (PHALCON_IS_STRING(name, "*")) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_acl_exception_ce, "Resource name cannot be \"*\"");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if (Z_TYPE_P(description) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_description"), description TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the resource name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Resource, getName){


	RETURN_MEMBER(this_ptr, "_name");
}

/**
 * Returns resource description
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Resource, getDescription){


	RETURN_MEMBER(this_ptr, "_description");
}

/**
 * Magic method __toString
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Resource, __toString){


	RETURN_MEMBER(this_ptr, "_name");
}

