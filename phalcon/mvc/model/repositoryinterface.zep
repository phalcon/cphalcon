
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

use Phalcon\DiInterface;
use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\RepositoryInterface
 *
 * Interface for Phalcon\Mvc\Model\Repository
 */
interface RepositoryInterface
{
	/**
	 * Allows to query a set of records that match the specified conditions
	 */
	public function find(var parameters = null) -> <ResultsetInterface>;

	/**
	 * Allows to query the first record that match the specified conditions
	 *
	 * @param array parameters
	 */
	public function findFirst(parameters = null) -> <ModelInterface>;

	/**
	 * Counts how many records match the specified conditions
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function count(var parameters = null);


	/**
	 * Calculates the sum on a column for a result-set of rows that match the specified conditions
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function sum(var parameters = null);

	/**
	 * Returns the maximum value of a column for a result-set of rows that match the specified conditions
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function maximum(var parameters = null);

	/**
	 * Returns the minimum value of a column for a result-set of rows that match the specified conditions
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function minimum(parameters = null);

	/**
	 * Returns the average value on a column for a result-set of rows matching the specified conditions
	 *
	 * @param array parameters
	 * @return double
	 */
	public function average(var parameters = null);

	/**
	 * Create a criteria for a specific model
	 */
	public function query(<DiInterface> dependencyInjector = null) -> <Criteria>;

	/**
	 * Returns the table name mapped in the model
	 */
	public function getSource() -> string;

	/**
	 * Returns schema name where the mapped table is located
	 */
	public function getSchema() -> string;
}
