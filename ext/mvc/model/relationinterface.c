
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
 * Phalcon\Mvc\Model\RelationInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, RelationInterface, mvc_model_relationinterface, phalcon_mvc_model_relationinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Relation constructor
 *
 * @param int $type
 * @param string $referencedModel
 * @param string|array $fields
 * @param string|array $referencedFields
 * @param array $options
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, __construct);

/**
 * Sets the intermediate model dat for has-*-through relations
 *
 * @param string|array $intermediateFields
 * @param string $intermediateModel
 * @param string $intermediateReferencedFields
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, setIntermediateRelation);

/**
 * Returns the relations type
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getType);

/**
 * Returns the referenced model
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getReferencedModel);

/**
 * Returns the fields
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getFields);

/**
 * Returns the referenced fields
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getReferencedFields);

/**
 * Returns the options
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getOptions);

/**
 * Check whether the relation act as a foreign key
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, isForeignKey);

/**
 * Returns the foreign key configuration
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getForeignKey);

/**
 * Check whether the relation is a 'many-to-many' relation or not
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, isThrough);

/**
 * Gets the intermediate fields for has-*-through relations
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateFields);

/**
 * Gets the intermediate model for has-*-through relations
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateModel);

/**
 * Gets the intermediate referenced fields for has-*-through relations
 *
 * @return string|array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateReferencedFields);

