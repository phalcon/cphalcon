
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

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\CriteriaInterface
 *
 * Interface for Phalcon\Mvc\Model\Criteria
 */
interface CriteriaInterface
{

	/**
	 * Set a model on which the query will be executed
	 *
	 * @param string modelName
	 * @return Phalcon\Mvc\Model\CriteriaInterface
	 */
	public function setModelName(modelName);

	/**
	 * Returns an internal model name on which the criteria will be applied
	 *
	 * @return string
	 */
	public function getModelName();

	/**
	 * Adds the bind parameter to the criteria
	 *
	 * @param string bindParams
	 * @return Phalcon\Mvc\Model\CriteriaInterface
	 */
	public function bind(bindParams);

	/**
	 * Sets the bind types in the criteria
	 * This method replaces all previously set bound parameters
	 *
	 * @param string bindTypes
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function bindTypes(bindTypes);

	/**
	 * Adds the conditions parameter to the criteria
	 *
	 * @param string conditions
	 * @return Phalcon\Mvc\Model\CriteriaInterface
	 */
	public function where(conditions);

	/**
	 * Adds the conditions parameter to the criteria
	 *
	 * @param string conditions
	 * @return Phalcon\Mvc\Model\CriteriaInterface
	 */
	public function conditions(conditions);

	/**
	 * Adds the order-by parameter to the criteria
	 *
	 * @param string orderColumns
	 * @return Phalcon\Mvc\Model\CriteriaInterface
	 */
	public function orderBy(orderColumns);

	/**
	 * Sets the limit parameter to the criteria
	 *
	 * @param int limit
	 * @param int offset
	 * @return Phalcon\Mvc\Model\CriteriaInterface
	 */
	public function limit(limit, offset=null);

	/**
	 * Sets the "for_update" parameter to the criteria
	 *
	 * @param boolean forUpdate
	 * @return Phalcon\Mvc\Model\CriteriaInterface
	 */
	public function forUpdate(forUpdate=true);

	/**
	 * Sets the "shared_lock" parameter to the criteria
	 *
	 * @param boolean sharedLock
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function sharedLock(sharedLock=true);

	/**
	 * Appends a condition to the current conditions using an AND operator
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function andWhere(conditions, bindParams=null, bindTypes=null);

	/**
	 * Appends a condition to the current conditions using an OR operator
	 *
	 * @param string conditions
	 * @param array bindParams
	 * @param array bindTypes
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function orWhere(conditions, bindParams=null, bindTypes=null);

	/**
	 * Appends a BETWEEN condition to the current conditions
	 *
	 *<code>
	 *	builder->betweenWhere('price', 100.25, 200.50);
	 *</code>
	 *
	 * @param string expr
	 * @param mixed minimum
	 * @param mixed maximum
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function betweenWhere(expr, minimum, maximum);

	/**
	 * Appends a NOT BETWEEN condition to the current conditions
	 *
	 *<code>
	 *	builder->notBetweenWhere('price', 100.25, 200.50);
	 *</code>
	 *
	 * @param string expr
	 * @param mixed minimum
	 * @param mixed maximum
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function notBetweenWhere(expr, minimum, maximum);

	/**
	 * Appends an IN condition to the current conditions
	 *
	 *<code>
	 *	builder->inWhere('id', [1, 2, 3]);
	 *</code>
	 *
	 * @param string expr
	 * @param array values
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function inWhere(expr, values);

	/**
	 * Appends a NOT IN condition to the current conditions
	 *
	 *<code>
	 *	builder->notInWhere('id', [1, 2, 3]);
	 *</code>
	 *
	 * @param string expr
	 * @param array values
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function notInWhere(expr, values);

	/**
	 * Returns the conditions parameter in the criteria
	 *
	 * @return string
	 */
	public function getWhere();

	/**
	 * Returns the conditions parameter in the criteria
	 *
	 * @return string
	 */
	public function getConditions();

	/**
	 * Returns the limit parameter in the criteria
	 *
	 * @return string
	 */
	public function getLimit();

	/**
	 * Returns the order parameter in the criteria
	 *
	 * @return string
	 */
	public function getOrder();

	/**
	 * Returns all the parameters defined in the criteria
	 *
	 * @return string
	 */
	public function getParams();

	/**
	 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like _POST
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @param string modelName
	 * @param array data
	 * @return static
	 */
	public static function fromInput(dependencyInjector, modelName, data);

	/**
	 * Executes a find using the parameters built with the criteria
	 *
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	public function execute();

}