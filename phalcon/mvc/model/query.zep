
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
 |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\Query
 *
 * This class takes a PHQL intermediate representation and executes it.
 *
 *<code>
 *
 * $phql = "SELECT c.price*0.16 AS taxes, c.* FROM Cars AS c JOIN Brands AS b
 *          WHERE b.name = :name: ORDER BY c.name";
 *
 * $result = manager->executeQuery($phql, array(
 *   'name' => 'Lamborghini'
 * ));
 *
 * foreach ($result as $row) {
 *   echo "Name: ", $row->cars->name, "\n";
 *   echo "Price: ", $row->cars->price, "\n";
 *   echo "Taxes: ", $row->taxes, "\n";
 * }
 *
 *</code>
 */
class Query //implements Phalcon\Mvc\Model\QueryInterface, Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _manager;

	protected _metaData;

	protected _type;

	protected _phql;

	protected _ast;

	protected _intermediate;

	protected _models;

	protected _sqlAliases;

	protected _sqlAliasesModels;

	protected _sqlModelsAliases;

	protected _sqlAliasesModelsInstances;

	protected _sqlColumnAliases;

	protected _modelsInstances;

	protected _cache;

	protected _cacheOptions;

	protected _uniqueRow;

	protected _bindParams;

	protected _bindTypes;

	static protected _irPhqlCache;

	const TYPE_SELECT = 309;

	const TYPE_INSERT = 306;

	const TYPE_UPDATE = 300;

	const TYPE_DELETE = 303;

	/**
	 * Sets the cache parameters of the query
	 *
	 * @param array cacheOptions
	 * @return Phalcon\Mvc\Model\Query
	 */
	public function cache(cacheOptions) -> <Phalcon\Mvc\Model\Query>
	{
		let this->_cacheOptions = cacheOptions;
		return this;
	}

	/**
	 * Returns the current cache options
	 *
	 * @param array
	 */
	public function getCacheOptions()
	{
		return this->_cacheOptions;
	}

	/**
	 * Tells to the query if only the first row in the resultset must be returned
	 *
	 * @param boolean uniqueRow
	 * @return Phalcon\Mvc\Model\Query
	 */
	public function setUniqueRow(boolean uniqueRow) -> <Phalcon\Mvc\Model\Query>
	{
		let this->_uniqueRow = uniqueRow;
		return this;
	}

	/**
	 * Check if the query is programmed to get only the first row in the resultset
	 *
	 * @return boolean
	 */
	public function getUniqueRow() -> boolean
	{
		return this->_uniqueRow;
	}

}
