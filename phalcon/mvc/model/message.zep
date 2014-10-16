
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

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\MessageInterface;
use Phalcon\Mvc\Entity\Message as EntityMessage;

/**
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 *	use Phalcon\Mvc\Model\Message as Message;
 *
 *  class Robots extends \Phalcon\Mvc\Model
 *  {
 *
 *    public function beforeSave()
 *    {
 *      if (this->name == 'Peter') {
 *        text = "A robot cannot be named Peter";
 *        field = "name";
 *        type = "InvalidValue";
 *        message = new Message(text, field, type);
 *        this->appendMessage(message);
 *     }
 *   }
 *
 * }
 * </code>
 *
 */
class Message extends EntityMessage implements MessageInterface
{
	// leave this class for backward compatibility

	/**
	 * Set the model who generates the message
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return Phalcon\Mvc\Model\Message
	 */
	public function setModel(<ModelInterface> model) -> <MessageInterface>
	{
		this->setEntity(model);
		return this;
	}
	/**
	 * Returns the model that produced the message
	 *
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function getModel() -> <ModelInterface>
	{
		return this->getEntity();
	}
}
