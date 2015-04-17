
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * @param   Phalcon\Mvc\ModelInterface model
 * @param	mixed fields
 * @param	string referencedModel
 * @param	mixed referencedFields
 * @param	array options
 * @return  Phalcon\Mvc\Model\RelationInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addHasOne);

/**
 * Setup a relation reverse 1-1  between two models
 *
 * @param 	Phalcon\Mvc\ModelInterface model
 * @param	mixed fields
 * @param	string referencedModel
 * @param	mixed referencedFields
 * @param	array options
 * @return 	Phalcon\Mvc\Model\RelationInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addBelongsTo);

/**
 * Setup a relation 1-n between two models
 *
 * @param 	Phalcon\Mvc\ModelInterface model
 * @param	mixed fields
 * @param	string referencedModel
 * @param	mixed referencedFields
 * @param	array options
 * @return 	Phalcon\Mvc\Model\RelationInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addHasMany);

/**
 * Checks whether a model has a belongsTo relation with another model
 *
 * @param 	string modelName
 * @param 	string modelRelation
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsBelongsTo);

/**
 * Checks whether a model has a hasMany relation with another model
 *
 * @param 	string modelName
 * @param 	string modelRelation
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsHasMany);

/**
 * Checks whether a model has a hasOne relation with another model
 *
 * @param 	string modelName
 * @param 	string modelRelation
 * @return 	boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsHasOne);

/**
 * Gets belongsTo related records from a model
 *
 * @param string method
 * @param string modelName
 * @param string modelRelation
 * @param Phalcon\Mvc\Model record
 * @param array parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getBelongsToRecords);

/**
 * Gets hasMany related records from a model
 *
 * @param string method
 * @param string modelName
 * @param string modelRelation
 * @param Phalcon\Mvc\Model record
 * @param array parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasManyRecords);

/**
 * Gets belongsTo related records from a model
 *
 * @param string method
 * @param string modelName
 * @param string modelRelation
 * @param Phalcon\Mvc\Model record
 * @param array parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOneRecords);

/**
 * Gets belongsTo relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getBelongsTo);

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasMany);

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOne);

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface model
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOneAndHasMany);

/**
 * Query all the relationships defined on a model
 *
 * @param string modelName
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelations);

/**
 * Query the relations between two models
 *
 * @param string first
 * @param string second
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelationsBetween);

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 *
 * @param string phql
 * @return Phalcon\Mvc\Model\QueryInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, createQuery);

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 *
 * @param string phql
 * @param array placeholders
 * @return Phalcon\Mvc\Model\QueryInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, executeQuery);

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 *
 * @param string params
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, createBuilder);

/**
 * Binds a behavior to a model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addBehavior);

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string eventName
 * @param Phalcon\Mvc\ModelInterface model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, notifyEvent);

/**
 * Dispatch a event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that a least one is implemented
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string eventName
 * @param array data
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, missingMethod);

/**
 * Returns the last query created or executed in the
 *
 * @return Phalcon\Mvc\Model\QueryInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getLastQuery);

/**
 * Returns a relation by its alias
 *
 * @param string modelName
 * @param string alias
 * @return Phalcon\Mvc\Model\Relation
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelationByAlias);

