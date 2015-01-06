
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

#include "acl/resource.h"
#include "acl/resourceinterface.h"
#include "acl/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Acl\Resource
 *
 * This class defines resource entity and its description
 *
 */
zend_class_entry *phalcon_acl_resource_ce;

PHP_METHOD(Phalcon_Acl_Resource, __construct);
PHP_METHOD(Phalcon_Acl_Resource, getName);
PHP_METHOD(Phalcon_Acl_Resource, getDescription);
PHP_METHOD(Phalcon_Acl_Resource, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resource___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_acl_resource_method_entry[] = {
	PHP_ME(Phalcon_Acl_Resource, __construct, arginfo_phalcon_acl_resource___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Acl_Resource, getName, arginfo_phalcon_acl_resourceinterface_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Resource, getDescription, arginfo_phalcon_acl_resourceinterface_getdescription, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Resource, __toString, arginfo___tostring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


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

	phalcon_fetch_params(0, 1, 1, &name, &description);
	
	if (PHALCON_IS_STRING(name, "*")) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_acl_exception_ce, "Resource name cannot be \"*\"");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if (description && Z_TYPE_P(description) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_description"), description TSRMLS_CC);
	}
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

