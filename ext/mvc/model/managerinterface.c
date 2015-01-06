
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/managerinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_model_managerinterface_ce;

static const zend_function_entry phalcon_mvc_model_managerinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, initialize, arginfo_phalcon_mvc_model_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, isInitialized, arginfo_phalcon_mvc_model_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastInitialized, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, load, arginfo_phalcon_mvc_model_managerinterface_load)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasOne, arginfo_phalcon_mvc_model_managerinterface_addhasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBelongsTo, arginfo_phalcon_mvc_model_managerinterface_addbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasMany, arginfo_phalcon_mvc_model_managerinterface_addhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsBelongsTo, arginfo_phalcon_mvc_model_managerinterface_existsbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsHasMany, arginfo_phalcon_mvc_model_managerinterface_existshasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsHasOne, arginfo_phalcon_mvc_model_managerinterface_existshasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsToRecords, arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasManyRecords, arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneRecords, arginfo_phalcon_mvc_model_managerinterface_gethasonerecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsTo, arginfo_phalcon_mvc_model_managerinterface_getbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOne, arginfo_phalcon_mvc_model_managerinterface_gethasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneAndHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelations, arginfo_phalcon_mvc_model_managerinterface_getrelations)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelationsBetween, arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createQuery, arginfo_phalcon_mvc_model_managerinterface_createquery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, executeQuery, arginfo_phalcon_mvc_model_managerinterface_executequery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createBuilder, arginfo_phalcon_mvc_model_managerinterface_createbuilder)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBehavior, arginfo_phalcon_mvc_model_managerinterface_addbehavior)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_model_managerinterface_notifyevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, missingMethod, arginfo_phalcon_mvc_model_managerinterface_missingmethod)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastQuery, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\ManagerInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ManagerInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, ManagerInterface, mvc_model_managerinterface, phalcon_mvc_model_managerinterface_method_entry);

	return SUCCESS;
}

/**
 * Initializes a model in the model manager
 *
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, initialize);

/**
 * Check of a model is already initialized
 *
 * @param string $modelName
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, isInitialized);

/**
 * Get last initialized model
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getLastInitialized);

/**
 * Loads a model throwing an exception if it doesn't exist
 *
 * @param string $modelName
 * @param boolean $newInstance
 * @return Phalcon\Mvc\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, load);

/**
 * Setup a 1-1 relation between two models
 *
 * @param   Phalcon\Mvc\ModelInterface $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 * @return  Phalcon\Mvc\Model\RelationInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addHasOne);

/**
 * Setup a relation reverse 1-1  between two models
 *
 * @param 	Phalcon\Mvc\ModelInterface $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 * @return 	Phalcon\Mvc\Model\RelationInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addBelongsTo);

/**
 * Setup a relation 1-n between two models
 *
 * @param 	Phalcon\Mvc\ModelInterface $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 * @return 	Phalcon\Mvc\Model\RelationInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addHasMany);

/**
 * Checks whether a model has a belongsTo relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsBelongsTo);

/**
 * Checks whether a model has a hasMany relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsHasMany);

/**
 * Checks whether a model has a hasOne relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, existsHasOne);

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getBelongsToRecords);

/**
 * Gets hasMany related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasManyRecords);

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOneRecords);

/**
 * Gets belongsTo relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getBelongsTo);

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasMany);

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOne);

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getHasOneAndHasMany);

/**
 * Query all the relationships defined on a model
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelations);

/**
 * Query the relations between two models
 *
 * @param string $first
 * @param string $second
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getRelationsBetween);

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 *
 * @param string $phql
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, createQuery);

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 *
 * @param string $phql
 * @param array $placeholders
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, executeQuery);

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 *
 * @param string $params
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, createBuilder);

/**
 * Binds a behavior to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\Mvc\Model\BehaviorInterface $behavior
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, addBehavior);

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string $eventName
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, notifyEvent);

/**
 * Dispatch a event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that a least one is implemented
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $eventName
 * @param array $data
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, missingMethod);

/**
 * Returns the last query created or executed in the
 *
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ManagerInterface, getLastQuery);
