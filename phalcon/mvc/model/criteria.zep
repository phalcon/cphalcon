
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
 * Phalcon\Mvc\Model\Criteria
 *
 * This class allows to build the array parameter required by Phalcon\Mvc\Model::find
 * and Phalcon\Mvc\Model::findFirst using an object-oriented interface
 *
 *<code>
 *$robots = Robots::query()
 *    ->where("type = :type:")
 *    ->andWhere("year < 2000")
 *    ->bind(array("type" => "mechanical"))
 *    ->order("name")
 *    ->execute();
 *</code>
 */
class Criteria
//implements Phalcon_Mvc_Model_CriteriaInterface, Phalcon_DI_InjectionAwareInterface
{

	protected _model;

	protected _params;

	protected _bindParams;

	protected _bindTypes;

	protected _hiddenParamNumber = 0;

	/**
	 * Sets the DependencyInjector container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_params["di"] = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		var params, dependencyInjector;
		let params = this->_params;
		if fetch dependencyInjector, params["di"] {
			return dependencyInjector;
		}
		return null;
	}

	/**
	 * Set a model on which the query will be executed
	 *
	 * @param string modelName
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public function setModelName(string modelName) -> <Phalcon\Mvc\Model\Criteria>
	{
		let this->_model = modelName;
		return this;
	}

	/**
	 * Returns an internal model name on which the criteria will be applied
	 *
	 * @return string
	 */
	public function getModelName() -> string
	{
		return this->_model;
	}

}
