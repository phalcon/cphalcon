
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

#include "acl/roleinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_acl_roleinterface_ce;

static const zend_function_entry phalcon_acl_roleinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getName, arginfo_phalcon_acl_roleinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getDescription, arginfo_phalcon_acl_roleinterface_getdescription)
	PHP_FE_END
};

/**
 * Phalcon\Acl\RoleInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Acl_RoleInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Acl, RoleInterface, acl_roleinterface, phalcon_acl_roleinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the role name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Acl_RoleInterface, getName);

/**
 * Returns role description
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Acl_RoleInterface, getDescription);
