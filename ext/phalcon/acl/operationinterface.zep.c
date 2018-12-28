
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Acl\OperationInterface
 *
 * Interface for Phalcon\Acl\Operation
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_OperationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, OperationInterface, phalcon, acl_operationinterface, phalcon_acl_operationinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the operation name
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_OperationInterface, getName);

/**
 * Returns operation description
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_OperationInterface, getDescription);

/**
 * Magic method __toString
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_OperationInterface, __toString);

