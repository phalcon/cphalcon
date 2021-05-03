
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
 * Phalcon\Mvc\Model\RelationInterface
 *
 * Interface for Phalcon\Mvc\Model\Relation
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, RelationInterface, phalcon, mvc_model_relationinterface, phalcon_mvc_model_relationinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the fields
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getFields);
/**
 * Returns the foreign key configuration
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getForeignKey);
/**
 * Gets the intermediate fields for has-*-through relations
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateFields);
/**
 * Gets the intermediate model for has-*-through relations
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateModel);
/**
 * Gets the intermediate referenced fields for has-*-through relations
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getIntermediateReferencedFields);
/**
 * Returns an option by the specified name
 * If the option doesn't exist null is returned
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getOption);
/**
 * Returns the options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getOptions);
/**
 * Returns parameters that must be always used when the related records are obtained
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getParams);
/**
 * Returns the referenced fields
 *
 * @return string|array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getReferencedFields);
/**
 * Returns the referenced model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getReferencedModel);
/**
 * Returns the relations type
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, getType);
/**
 * Check whether the relation act as a foreign key
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, isForeignKey);
/**
 * Check if records returned by getting belongs-to/has-many are implicitly cached during the current request
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, isReusable);
/**
 * Check whether the relation is a 'many-to-many' relation or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, isThrough);
/**
 * Sets the intermediate model data for has-*-through relations
 *
 * @param string|array intermediateFields
 * @param string|array intermediateReferencedFields
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_RelationInterface, setIntermediateRelation);
