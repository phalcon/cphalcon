
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
 *
 * @phpstan-import-type annotations_node_list from AnnotationsTypes
 * @phpstan-import-type annotations_reflection_data from AnnotationsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_ReaderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Annotations, ReaderInterface, phalcon, annotations_readerinterface, phalcon_annotations_readerinterface_method_entry);

	return SUCCESS;
}

/**
 * Reads annotations from the class docblocks, its constants, properties and methods
 *
 * @phpstan-param class-string $className
 *
 * @phpstan-return annotations_reflection_data
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_ReaderInterface, parse);
/**
 * Parses a raw docblock returning the annotations found
 *
 * @phpstan-param string|null $file
 * @phpstan-param int|null    $line
 *
 * @phpstan-return annotations_node_list
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_ReaderInterface, parseDocBlock);
