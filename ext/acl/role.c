
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
 *
 * Phalcon\Acl\Role
 *
 * This class defines role entity and its description
 *
 */


/**
 * Phalcon\Acl\Role description
 *
 * @param string $name
 * @param string $description
 */
PHP_METHOD(Phalcon_Acl_Role, __construct){

	zval *name, *description = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &description) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!description) {
		PHALCON_INIT_NVAR(description);
		ZVAL_STRING(description, "", 1);
	}
	
	if (PHALCON_COMPARE_STRING(name, "*")) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_acl_exception_ce, "Role name cannot be \"*\"");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_description"), description TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the role name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, getName){

	zval *name;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(name);
	phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	RETURN_CCTOR(name);
}

/**
 * Returns role description
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Role, getDescription){

	zval *description;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(description);
	phalcon_read_property(&description, this_ptr, SL("_description"), PH_NOISY_CC);
	
	RETURN_CCTOR(description);
}

