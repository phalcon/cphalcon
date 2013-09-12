
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"


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
/**
 * Phalcon\Acl\Role
 *
 * This class defines role entity and its description
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Role) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Role, phalcon, acl_role, phalcon_acl_role_method_entry, 0);

/**
 * Role's name
 * @var string
 */
	zend_declare_property_null(phalcon_acl_role_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Role's description
 * @var string
 */
	zend_declare_property_null(phalcon_acl_role_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Acl\Role constructor
 *
 * @param string name
 * @param string description
 */
PHP_METHOD(Phalcon_Acl_Role, __construct) {

	zval *name, *description = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &description);

	if (!description) {
		ZEPHIR_CPY_WRT(description, ZEPHIR_GLOBAL(global_null));
	}


	if (ZEPHIR_IS_STRING(name, "*")) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_acl_exception_ce, "Role name cannot be '*'");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if (zend_is_true(description)) {
		zephir_update_property_this(this_ptr, SL("_description"), description TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the role name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Returns role description
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, getDescription) {


	RETURN_MEMBER(this_ptr, "_description");

}

/**
 * Magic method __toString
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, __toString) {


	RETURN_MEMBER(this_ptr, "_name");

}

