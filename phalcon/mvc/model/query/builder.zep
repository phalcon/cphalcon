
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

namespace Phalcon\Mvc\Model\Query;

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *<code>
 *$resultset = $this->modelsManager->createBuilder()
 *   ->from('Robots')
 *   ->join('RobotsParts')
 *   ->limit(20)
 *   ->orderBy('Robots.name')
 *   ->getQuery()
 *   ->execute();
 *</code>
 */
class Builder
//implements Phalcon_Mvc_Model_Query_BuilderInterface, Phalcon_DI_InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _columns;

	protected _models;

	protected _joins;

	protected _conditions;

	protected _group;

	protected _having;

	protected _order;

	protected _limit;

	protected _offset;

	protected _forUpdate;

	protected _sharedLock;

	protected _bindParams;

	protected _bindTypes;

	protected _hiddenParamNumber = 0;

	/**
	 * Sets the models who makes part of the query
	 *
	 *<code>
	 *	$builder->from('Robots');
	 *	$builder->from(array('Robots', 'RobotsParts'));
	 *</code>
	 *
	 * @param string|array models
	 * @return Phalcon\Mvc\Model\Query\Builder
	 */
	public function from(var models) -> <Phalcon\Mvc\Model\Query\Builder>
	{
		let this->_models = models;
		return this;
	}

	/**
	 * Returns the query built
	 *
	 * @return Phalcon\Mvc\Model\Query
	 */
	public function getQuery() -> <Phalcon\Mvc\Model\QueryInterface>
	{

	}

}