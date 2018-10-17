
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (http://www.phalconphp.com)    |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Phalcon Team <team@phalconphp.com>                            |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 * use Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $text  = "A robot cannot be named Peter";
 *             $field = "name";
 *             $type  = "InvalidValue";
 *
 *             $message = new Message($text, $field, $type);
 *
 *             $this->appendMessage($message);
 *         }
 *     }
 * }
 * </code>
 *
 */
class Message extends Phalcon\Messages\Message
{

	protected _model;

	/**
	 * Phalcon\Mvc\Model\Message constructor
	 *
	 * @param string|array field
	 */
	public function __construct(string! message, var field = null, string type = null, int code = null, <ModelInterface> model = null)
	{
		parent::__construct(message, field, type, code);
		if typeof model == "object" {
			let this->_model = model;
		}
	}

	/**
	 * Returns the model that produced the message
	 */
	public function getModel() -> <ModelInterface>
	{
		return this->_model;
	}

	/**
	 * Set the model who generates the message
	 */
	public function setModel(<ModelInterface> model) -> <Message>
	{
		let this->_model = model;
		return this;
	}

}
