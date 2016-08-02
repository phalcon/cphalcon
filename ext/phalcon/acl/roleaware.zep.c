
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Acl\RoleAware
 *
 * Interface for classes which could be used in allow method as ROLE
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_RoleAware) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, RoleAware, phalcon, acl_roleaware, phalcon_acl_roleaware_method_entry);

	return SUCCESS;

}

/**
 * Returns role name
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_RoleAware, getRoleName);

