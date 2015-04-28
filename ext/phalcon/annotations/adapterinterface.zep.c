
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Annotations\AdapterInterface
 *
 * This interface must be implemented by adapters in Phalcon\Annotations
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Annotations, AdapterInterface, phalcon, annotations_adapterinterface, phalcon_annotations_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the annotations parser
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_AdapterInterface, setReader);

/**
 * Returns the annotation reader
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getReader);

/**
 * Parses or retrieves all the annotations found in a class
 *
 * @param string|object className
 * @return Phalcon\Annotations\Reflection
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_AdapterInterface, get);

/**
 * Returns the annotations found in all the class' methods
 *
 * @param string className
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getMethods);

/**
 * Returns the annotations found in a specific method
 *
 * @param string className
 * @param string methodName
 * @return Phalcon\Annotations\Collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getMethod);

/**
 * Returns the annotations found in all the class' methods
 *
 * @param string className
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getProperties);

/**
 * Returns the annotations found in a specific property
 *
 * @param string className
 * @param string propertyName
 * @return Phalcon\Annotations\Collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getProperty);

