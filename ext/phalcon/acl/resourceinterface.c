
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "kernel/main.h"


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
 *
 * Phalcon\Acl\ResourceInterface
 *
 * Interface for Phalcon\Acl\Resource
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_ResourceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, ResourceInterface, phalcon, acl_resourceinterface, phalcon_acl_resourceinterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Acl\ResourceInterface constructor
 *
 * @param string name
 * @param string description
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceInterface, __construct);

/**
 * Returns the resource name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceInterface, getName);

/**
 * Returns resource description
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceInterface, getDescription);

/**
 * Magic method __toString
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceInterface, __toString);

