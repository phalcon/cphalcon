
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 *
 * @param string attribute
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_EntityInterface, readAttribute);

/**
 * Writes an attribute value by its name
 *
 * @param string attribute
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_EntityInterface, writeAttribute);

