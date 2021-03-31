
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\EntityInterface
 *
 * Interface for Phalcon\Mvc\Collection and Phalcon\Mvc\Model
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_EntityInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, EntityInterface, phalcon, mvc_entityinterface, phalcon_mvc_entityinterface_method_entry);

	return SUCCESS;

}

/**
 * Reads an attribute value by its name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_EntityInterface, readAttribute);
/**
 * Writes an attribute value by its name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_EntityInterface, writeAttribute);
