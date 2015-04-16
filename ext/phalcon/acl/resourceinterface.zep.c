
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceInterface, __construct);

/**
 * Returns the resource name
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceInterface, getName);

/**
 * Returns resource description
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceInterface, getDescription);

/**
 * Magic method __toString
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceInterface, __toString);

