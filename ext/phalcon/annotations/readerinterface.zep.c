
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
 * Reads the annotations of a class and returns them as an array
 *
 * Phalcon\Annotations\Reader reads the docblocks and Phalcon\Annotations\AttributesReader
 * reads the PHP attributes. The two give the same array shape, so the adapter
 * and the classes after it do not know which reader made it.
 *
 * @phpstan-import-type annotations_reflection_data from AnnotationsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_ReaderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Annotations, ReaderInterface, phalcon, annotations_readerinterface, phalcon_annotations_readerinterface_method_entry);

	return SUCCESS;
}

/**
 * Reads annotations from the class, its constants, properties and methods
 *
 * @phpstan-param class-string $className
 *
 * @phpstan-return annotations_reflection_data
 */
ZEPHIR_DOC_METHOD(Phalcon_Annotations_ReaderInterface, parse);
