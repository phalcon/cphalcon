
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Repository
 */
class Repository implements RepositoryInterface
{
	/**
	 * @var string
	 */
	protected _modelClass;

	/**
	 * @var ManagerInterface
	 */
	protected _modelsManager;

	public function __construct(string! modelClass, <ManagerInterface> modelsManager)
	{
		let this->_modelClass    = modelClass;
		let this->_modelsManager = modelsManager;
	}

	/**
	 * Query for a set of records that match the specified conditions
	 *
	 * <code>
	 * // How many robots are there?
	 * $robots = Robots::find();
	 *
	 * echo "There are ", count($robots), "\n";
	 *
	 * // How many mechanical robots are there?
	 * $robots = Robots::find(
	 *     "type = 'mechanical'"
	 * );
	 *
	 * echo "There are ", count($robots), "\n";
	 *
	 * // Get and print virtual robots ordered by name
	 * $robots = Robots::find(
	 *     [
	 *         "type = 'virtual'",
	 *         "order" => "name",
	 *     ]
	 * );
	 *
	 * foreach ($robots as $robot) {
	 *	 echo $robot->name, "\n";
	 * }
	 *
	 * // Get first 100 virtual robots ordered by name
	 * $robots = Robots::find(
	 *     [
	 *         "type = 'virtual'",
	 *         "order" => "name",
	 *         "limit" => 100,
	 *     ]
	 * );
	 *
	 * foreach ($robots as $robot) {
	 *	 echo $robot->name, "\n";
	 * }
	 * </code>
	 */
	public function find(var parameters = null) -> <ResultsetInterface>
	{
		var params, builder, query, bindParams, bindTypes, cache, resultset, hydration;

		if typeof parameters != "array" {
			let params = [];
			if parameters !== null {
				let params[] = parameters;
			}
		} else {
			let params = parameters;
		}

		/**
		 * Builds a query with the passed parameters
		 */
		let builder = this->_modelsManager->createBuilder(params);

		builder->from(this->_modelClass);

		let query = builder->getQuery();

		/**
		 * Check for bind parameters
		 */
		if fetch bindParams, params["bind"] {

			if typeof bindParams == "array" {
				query->setBindParams(bindParams, true);
			}

			if fetch bindTypes, params["bindTypes"] {
				if typeof bindTypes == "array" {
					query->setBindTypes(bindTypes, true);
				}
			}
		}

		/**
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Execute the query passing the bind-params and casting-types
		 */
		let resultset = query->execute();

		/**
		 * Define an hydration mode
		 */
		if typeof resultset == "object" {
			if fetch hydration, params["hydration"] {
				resultset->setHydrateMode(hydration);
			}
		}

		return resultset;
	}

	/**
	 * Query the first record that matches the specified conditions
	 *
	 * <code>
	 * // What's the first robot in robots table?
	 * $robot = Robots::findFirst();
	 *
	 * echo "The robot name is ", $robot->name;
	 *
	 * // What's the first mechanical robot in robots table?
	 * $robot = Robots::findFirst(
	 *     "type = 'mechanical'"
	 * );
	 *
	 * echo "The first mechanical robot name is ", $robot->name;
	 *
	 * // Get first virtual robot ordered by name
	 * $robot = Robots::findFirst(
	 *     [
	 *         "type = 'virtual'",
	 *         "order" => "name",
	 *     ]
	 * );
	 *
	 * echo "The first virtual robot name is ", $robot->name;
	 * </code>
	 *
	 * @param string|array parameters
	 */
	public function findFirst(var parameters = null) -> <ModelInterface>
	{
		var params, builder, query, bindParams, bindTypes, cache;

		if typeof parameters != "array" {
			let params = [];
			if parameters !== null {
				let params[] = parameters;
			}
		} else {
			let params = parameters;
		}

		/**
		 * Builds a query with the passed parameters
		 */
		let builder = this->_modelsManager->createBuilder(params);

		builder->from(this->_modelClass);

		/**
		 * We only want the first record
		 */
		builder->limit(1);

		let query = builder->getQuery();

		/**
		 * Check for bind parameters
		 */
		if fetch bindParams, params["bind"] {

			if typeof bindParams == "array" {
				query->setBindParams(bindParams, true);
			}

			if fetch bindTypes, params["bindTypes"] {
				if typeof bindTypes == "array" {
					query->setBindTypes(bindTypes, true);
				}
			}
		}

		/**
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Return only the first row
		 */
		query->setUniqueRow(true);

		/**
		 * Execute the query passing the bind-params and casting-types
		 */
		return query->execute();
	}
}
