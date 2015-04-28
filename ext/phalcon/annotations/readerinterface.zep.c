
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Annotations\Reader
 *
 * Parses docblocks returning an array with the found annotations
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_ReaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Annotations, ReaderInterface, phalcon, annotations_readerinterface, phalcon_annotations_readerinterface_method_entry);

	return SUCCESS;

}

/**
 * Reads annotations from the class dockblocks, its methods and/or properties
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_ReaderInterface, parse);

/**
 * Parses a raw doc block returning the annotations found
 *
 * @param string docBlock
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_ReaderInterface, parseDocBlock);

