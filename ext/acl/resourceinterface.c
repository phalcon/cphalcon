
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

#include "php_phalcon.h"

#include "acl/resourceinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_acl_resourceinterface_ce;

static const zend_function_entry phalcon_acl_resourceinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __construct, arginfo_phalcon_acl_resourceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getDescription, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Acl\ResourceInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Acl_ResourceInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Acl, ResourceInterface, acl_resourceinterface, phalcon_acl_resourceinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Acl\ResourceInterface constructor
 *
 * @param string $name
 * @param string $description
 */
PHALCON_DOC_METHOD(Phalcon_Acl_ResourceInterface, __construct);

/**
 * Returns the resource name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Acl_ResourceInterface, getName);

/**
 * Returns resource description
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Acl_ResourceInterface, getDescription);
