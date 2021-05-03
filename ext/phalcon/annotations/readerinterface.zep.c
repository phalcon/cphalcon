
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
 * Parses docblocks returning an array with the found annotations
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_ReaderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Annotations, ReaderInterface, phalcon, annotations_readerinterface, phalcon_annotations_readerinterface_method_entry);

	return SUCCESS;
}

/**
 * Reads annotations from the class docblocks, its methods and/or properties
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_ReaderInterface, parse);
/**
 * Parses a raw docblock returning the annotations found
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_ReaderInterface, parseDocBlock);
