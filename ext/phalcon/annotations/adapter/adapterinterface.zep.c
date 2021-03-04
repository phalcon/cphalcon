
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * This interface must be implemented by adapters in Phalcon\Annotations
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Annotations\\Adapter, AdapterInterface, phalcon, annotations_adapter_adapterinterface, phalcon_annotations_adapter_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Parses or retrieves all the annotations found in a class
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_Adapter_AdapterInterface, get);
/**
 * Returns the annotations found in a specific method
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_Adapter_AdapterInterface, getMethod);
/**
 * Returns the annotations found in all the class' methods
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_Adapter_AdapterInterface, getMethods);
/**
 * Returns the annotations found in a specific property
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_Adapter_AdapterInterface, getProperty);
/**
 * Returns the annotations found in all the class' methods
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_Adapter_AdapterInterface, getProperties);
/**
 * Returns the annotation reader
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_Adapter_AdapterInterface, getReader);
/**
 * Sets the annotations parser
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_Adapter_AdapterInterface, setReader);
