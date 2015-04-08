
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Mvc\Model\RelationInterface
 *
 * Interface for Phalcon\Mvc\Model\Relation
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, RelationInterface, phalcon, mvc_model_relationinterface, phalcon_mvc_model_relationinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Relation constructor
 *
 * @param int type
 * @param string referencedModel
 * @param string|array fields
 * @param string|array referencedFields
 * @param array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, __construct);

/**
 * Sets the intermediate model dat for has-*-through relations
 *
 * @param string|array intermediateFields
 * @param string intermediateModel
 * @param string|array intermediateReferencedFields
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, setIntermediateRelation);

/**
 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, isReusable);

/**
 * Returns the relations type
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getType);

/**
 * Returns the referenced model
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getReferencedModel);

/**
 * Returns the fields
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getFields);

/**
 * Returns the referenced fields
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getReferencedFields);

/**
 * Returns the options
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getOptions);

/**
 * Check whether the relation act as a foreign key
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, isForeignKey);

/**
 * Returns the foreign key configuration
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getForeignKey);

/**
 * Check whether the relation is a 'many-to-many' relation or not
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, isThrough);

/**
 * Gets the intermediate fields for has-*-through relations
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateFields);

/**
 * Gets the intermediate model for has-*-through relations
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateModel);

/**
 * Gets the intermediate referenced fields for has-*-through relations
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateReferencedFields);

