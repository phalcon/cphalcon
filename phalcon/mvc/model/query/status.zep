
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
 * Phalcon\Mvc\Model\Query\Status
 *
 * This class represents the status returned by a PHQL
 * statement like INSERT, UPDATE or DELETE. It offers context
 * information and the related messages produced by the
 * model which finally executes the operations when it fails
 *
 *<code>
 *$phql = "UPDATE Robots SET name = :name:, type = :type:, year = :year: WHERE id = :id:";
 *$status = $app->modelsManager->executeQuery($phql, array(
 *   'id' => 100,
 *   'name' => 'Astroy Boy',
 *   'type' => 'mechanical',
 *   'year' => 1959
 *));
 *
 *\//Check if the update was successful
 *if ($status->success() == true) {
 *   echo 'OK';
 *}
 *</code>
 */
class Status implements Phalcon\Mvc\Model\Query\StatusInterface
{

	protected _success;

	protected _model;

	/**
	 * Phalcon\Mvc\Model\Query\Status
	 *
	 * @param boolean success
	 * @param Phalcon\Mvc\ModelInterface model
	 */
	public function __construct(boolean success, <Phalcon\Mvc\ModelInterface> model)
	{
		let this->_success = success,
			this->_model = model;
	}

	/**
	 * Returns the model that executed the action
	 *
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function getModel() -> <Phalcon\Mvc\ModelInterface>
	{
		return this->_model;
	}

	/**
	 * Returns the messages produced because of a failed operation
	 *
	 * @return Phalcon\Mvc\Model\MessageInterface[]
	 */
	public function getMessages()
	{
		var model;
		let model = this->_model;
		if typeof model == "object" {
			return model->getMessages();
		}
		return [];
	}

	/**
	 * Allows to check if the executed operation was successful
	 *
	 * @return boolean
	 */
	public function success() -> boolean
	{
		return this->_success;
	}

}
