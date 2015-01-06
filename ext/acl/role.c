
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

#include "acl/role.h"
#include "acl/roleinterface.h"
#include "acl/exception.h"

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Acl\Role
 *
 * This class defines role entity and its description
 *
 */
zend_class_entry *phalcon_acl_role_ce;

PHP_METHOD(Phalcon_Acl_Role, __construct);
PHP_METHOD(Phalcon_Acl_Role, getName);
PHP_METHOD(Phalcon_Acl_Role, getDescription);
PHP_METHOD(Phalcon_Acl_Role, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_role___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_acl_role_method_entry[] = {
	PHP_ME(Phalcon_Acl_Role, __construct, arginfo_phalcon_acl_role___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Acl_Role, getName, arginfo_phalcon_acl_roleinterface_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Role, getDescription, arginfo_phalcon_acl_roleinterface_getdescription, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Role, __toString, arginfo___tostring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


/**
 * Phalcon\Acl\Role initializer
 */
PHALCON_INIT_CLASS(Phalcon_Acl_Role){

	PHALCON_REGISTER_CLASS(Phalcon\\Acl, Role, acl_role, phalcon_acl_role_method_entry, 0);

	zend_declare_property_null(phalcon_acl_role_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_acl_role_ce TSRMLS_CC, 1, phalcon_acl_roleinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Acl\Role description
 *
 * @param string $name
 * @param string $description
 */
PHP_METHOD(Phalcon_Acl_Role, __construct){

	zval *name, *description = NULL;

	phalcon_fetch_params(0, 1, 1, &name, &description);
	
	if (PHALCON_IS_STRING(name, "*")) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_acl_exception_ce, "Role name cannot be \"*\"");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if (description && Z_TYPE_P(description) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_description"), description TSRMLS_CC);
	}
}

/**
 * Returns the role name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, getName){


	RETURN_MEMBER(this_ptr, "_name");
}

/**
 * Returns role description
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, getDescription){


	RETURN_MEMBER(this_ptr, "_description");
}

/**
 * Magic method __toString
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, __toString){


	RETURN_MEMBER(this_ptr, "_name");
}

