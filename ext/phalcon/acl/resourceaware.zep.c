
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Acl\ResourceAware
 *
 * Interface for classes which could be used in allow method as RESOURCE
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_ResourceAware) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, ResourceAware, phalcon, acl_resourceaware, phalcon_acl_resourceaware_method_entry);

	return SUCCESS;

}

/**
 * Returns resource name
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ResourceAware, getResourceName);

