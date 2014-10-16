
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

namespace Phalcon\Mvc;

use Phalcon\DiInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\TransactionInterface;
use Phalcon\Mvc\Model\MessageInterface;
use Phalcon\Mvc\Entity\StaticFinderInterface;

/**
 * Phalcon\Mvc\ModelInterface
 *
 * Interface for Phalcon\Mvc\Model
 */
interface ModelInterface extends EntityInterface, StaticFinderInterface
{

	/**
	 * Sets a transaction related to the Model instance
	 *
	 * @param Phalcon\Mvc\Model\TransactionInterface transaction
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function setTransaction(<TransactionInterface> transaction) -> <ModelInterface>;

	/**
	 * Returns table name mapped in the model
	 *
	 * @return string
	 */
	public function getSource();

	/**
	 * Returns schema name where table mapped is located
	 *
	 * @return string
	 */
	public function getSchema();

	/**
	 * Sets both read/write connection services
	 *
	 * @param string connectionService
	 */
	public function setConnectionService(string connectionService) -> void;

	/**
	 * Sets the DependencyInjection connection service used to write data
	 *
	 * @param string connectionService
	 */
	public function setWriteConnectionService(string connectionService) -> void;

	/**
	 * Sets the DependencyInjection connection service used to read data
	 *
	 * @param string connectionService
	 */
	public function setReadConnectionService(string connectionService) -> void;

	/**
	 * Returns DependencyInjection connection service used to read data
	 *
	 * @return string
	 */
	public function getReadConnectionService() -> string;

	/**
	 * Returns DependencyInjection connection service used to write data
	 *
	 * @return string
	 */
	public function getWriteConnectionService() -> string;

	/**
	 * Gets internal database connection
	 *
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getReadConnection() -> <\Phalcon\Db\AdapterInterface>;

	/**
	 * Gets internal database connection
	 *
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getWriteConnection() -> <\Phalcon\Db\AdapterInterface>;

	/**
	 * Assigns values to a model from an array returning a new model
	 *
	 * @param Phalcon\Mvc\Model base
	 * @param array data
	 * @param array columnMap
	 * @param int dirtyState
	 * @param boolean keepSnapshots
	 * @return Phalcon\Mvc\Model result
	 */
	public static function cloneResultMap(base, array! data, var columnMap, dirtyState = 0, keepSnapshots = null);

	/**
	 * Assigns values to a model from an array returning a new model
	 *
	 * @param Phalcon\Mvc\ModelInterface base
	 * @param array data
	 * @param int dirtyState
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public static function cloneResult(<ModelInterface> base, data, dirtyState = 0);

	/**
	 * Returns an hydrated result based on the data and the column map
	 *
	 * @param array data
	 * @param array columnMap
	 * @param int hydrationMode
	 */
	public static function cloneResultMapHydrate(array! data, var columnMap, int hydrationMode);

	/**
	 * Create a criteria for a especific model
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return Phalcon\Mvc\Model\CriteriaInterface
	 */
	public static function query(<DiInterface> dependencyInjector = null);

	/**
	 * Allows to count how many records match the specified conditions
	 *
	 * @param array parameters
	 * @return int
	 */
	public static function count(parameters = null);

	/**
	 * Allows to calculate a summatory on a column that match the specified conditions
	 *
	 * @param array parameters
	 * @return double
	 */
	public static function sum(parameters = null);

	/**
	 * Allows to get the maximum value of a column that match the specified conditions
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public static function maximum(parameters = null);

	/**
	 * Allows to get the minimum value of a column that match the specified conditions
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public static function minimum(parameters = null);

	/**
	 * Allows to calculate the average value on a column matching the specified conditions
	 *
	 * @param array parameters
	 * @return double
	 */
	public static function average(parameters = null);

	/**
	 * Refreshes the model attributes re-querying the record from the database
	 */
	public function refresh();

	/**
	 * Returns related records based on defined relations
	 *
	 * @param string alias
	 * @param array arguments
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	public function getRelated(alias, arguments = null);

}
