
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\ManagerInterface
 *
 * Interface for Phalcon\Mvc\Model\Manager
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, ManagerInterface, phalcon, mvc_model_managerinterface, phalcon_mvc_model_managerinterface_method_entry);

	return SUCCESS;

}

/**
 * Initializes a model in the model manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, initialize);

/**
 * Sets the mapped source for a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, setModelSource);

/**
 * Returns the mapped source for a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getModelSource);

/**
 * Sets the mapped schema for a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, setModelSchema);

/**
 * Returns the mapped schema for a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getModelSchema);

/**
 * Sets both write and read connection service for a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, setConnectionService);

/**
 * Sets read connection service for a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, setReadConnectionService);

/**
 * Returns the connection service name used to read data related to a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getReadConnectionService);

/**
 * Sets write connection service for a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, setWriteConnectionService);

/**
 * Returns the connection service name used to write data related to a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getWriteConnectionService);

/**
 * Returns the connection to read data related to a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getReadConnection);

/**
 * Returns the connection to write data related to a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getWriteConnection);

/**
 * Check of a model is already initialized
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, isInitialized);

/**
 * Get last initialized model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getLastInitialized);

/**
 * Loads a model throwing an exception if it doesn't exist
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, load);

/**
 * Setup a 1-1 relation between two models
 *
 * @param	mixed  fields
 * @param	mixed  referencedFields
 * @param	array  options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addHasOne);

/**
 * Setup a relation reverse 1-1  between two models
 *
 * @param	mixed  fields
 * @param	mixed  referencedFields
 * @param	array  options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addBelongsTo);

/**
 * Setup a relation 1-n between two models
 *
 * @param	mixed  fields
 * @param	mixed  referencedFields
 * @param	array  options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addHasMany);

/**
 * Checks whether a model has a belongsTo relation with another model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsBelongsTo);

/**
 * Checks whether a model has a hasMany relation with another model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsHasMany);

/**
 * Checks whether a model has a hasOne relation with another model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsHasOne);

/**
 * Gets belongsTo related records from a model
 *
 * @param string modelRelation
 * @param array  parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getBelongsToRecords);

/**
 * Gets hasMany related records from a model
 *
 * @param string modelRelation
 * @param array  parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasManyRecords);

/**
 * Gets belongsTo related records from a model
 *
 * @param string modelRelation
 * @param array  parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOneRecords);

/**
 * Gets belongsTo relations defined on a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getBelongsTo);

/**
 * Gets hasMany relations defined on a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasMany);

/**
 * Gets hasOne relations defined on a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOne);

/**
 * Gets hasOne relations defined on a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOneAndHasMany);

/**
 * Query all the relationships defined on a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelations);

/**
 * Query the relations between two models
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelationsBetween);

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, createQuery);

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 *
 * @param array $placeholders
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, executeQuery);

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 *
 * @param string $params
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, createBuilder);

/**
 * Binds a behavior to a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addBehavior);

/**
 * Receives events generated in the models and dispatches them to an events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string $eventName
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, notifyEvent);

/**
 * Dispatch an event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that a least one is implemented
 *
 * @param array data
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, missingMethod);

/**
 * Returns the last query created or executed in the models manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getLastQuery);

/**
 * Returns a relation by its alias
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelationByAlias);

/**
 * Check whether a model property is declared as public.
 *
 * <code>
 * $isPublic = $manager->isVisibleModelProperty(
 *     new Robots(),
 *     "name"
 * );
 * </code>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, isVisibleModelProperty);

/**
 * Sets if a model must keep snapshots
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, keepSnapshots);

/**
 * Checks if a model is keeping snapshots for the queried records
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, isKeepingSnapshots);

/**
 * Sets if a model must use dynamic update instead of the all-field update
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, useDynamicUpdate);

/**
 * Checks if a model is using dynamic update instead of all-field update
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, isUsingDynamicUpdate);

/**
 * Setups a relation n-m between two models
 *
 * @param	string fields
 * @param	string intermediateFields
 * @param	string intermediateReferencedFields
 * @param	string referencedFields
 * @param   array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addHasManyToMany);

/**
 * Checks whether a model has a hasManyToMany relation with another model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsHasManyToMany);

/**
 * Helper method to query records based on a relation definition
 *
 * @return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|int|false
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelationRecords);

/**
 * Gets hasManyToMany relations defined on a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasManyToMany);

/**
 * Registers shorter aliases for namespaces in PHQL statements
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, registerNamespaceAlias);

/**
 * Returns a real namespace from its alias
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getNamespaceAlias);

