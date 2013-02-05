
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Annotations\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Annotations, AdapterInterface, annotations_adapterinterface, phalcon_annotations_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the annotations parser
 *
 * @param Phalcon\Annotations\ReaderInterface $reader
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_AdapterInterface, setReader);

/**
 * Returns the annotation reader
 *
 * @return Phalcon\Annotations\ReaderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getReader);

/**
 * Parses or retrieves all the annotations found in a class
 *
 * @param string|object $className
 * @return Phalcon\Annotations\Reflection
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_AdapterInterface, get);

/**
 * Returns the annotations found in all the class' methods
 *
 * @param string $className
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getMethods);

/**
 * Returns the annotations found in a specific method
 *
 * @param string $className
 * @param string $methodName
 * @return Phalcon\Annotations\Collection
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getMethod);

/**
 * Returns the annotations found in all the class' methods
 *
 * @param string $className
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getProperties);

/**
 * Returns the annotations found in a specific property
 *
 * @param string $className
 * @param string $propertyName
 * @return Phalcon\Annotations\Collection
 */
PHALCON_DOC_METHOD(Phalcon_Annotations_AdapterInterface, getProperty);

