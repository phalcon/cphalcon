
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

namespace Phalcon\Flash;

use Phalcon\DiInterface;
use Phalcon\FlashInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Flash\Exception;
use Phalcon\Session\AdapterInterface as SessionInterface;

/**
 * Phalcon\Flash\Session
 *
 * Temporarily stores the messages in session, then messages can be printed in the next request
 */
class Session extends \Phalcon\Flash implements FlashInterface, InjectionAwareInterface
{

	protected _dependencyInjector;

	/**
	 * Sets the dependency injector
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Returns the messages stored in session
	 *
	 * @param boolean remove
	 * @return array
	 */
	protected function _getSessionMessages(boolean remove)
	{
		var dependencyInjector, session, messages;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection container is required to access the 'session' service");
		}

		let session = <SessionInterface> dependencyInjector->getShared("session");
		let messages = session->get("_flashMessages");

		if remove === true {
			session->remove("_flashMessages");
		}

		return messages;
	}

	/**
	 * Stores the messages in session
	 *
	 * @param array messages
	 */
	protected function _setSessionMessages(array! messages) -> array
	{
		var dependencyInjector, session;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection container is required to access the 'session' service");
		}

		let session = <SessionInterface> dependencyInjector->getShared("session");
		session->set("_flashMessages", messages);
		return messages;
	}

	/**
	 * Adds a message to the session flasher
	 *
	 * @param string type
	 * @param string message
	 */
	public function message(string type, string message) -> void
	{
		var messages;

		let messages = this->_getSessionMessages(false);
		if typeof messages != "array" {
			let messages = [];
		}
		if !isset messages[type] {
			let messages[type] = [];
		}
		let messages[type][] = message;

		this->_setSessionMessages(messages);
	}

	/**
	 * Checks whether there are messages
	 *
	 * @param string type
	 * @return boolean
	 */
	public function has(type = null) -> boolean
	{
		var messages;

		let messages = this->_getSessionMessages(false);
		if typeof messages == "array" {
			if typeof type == "string" {
				return isset messages[type];
			}
			return true;
		}
		return false;
	}

	/**
	 * Returns the messages in the session flasher
	 *
	 * @param string type
	 * @param boolean remove
	 * @return array
	 */
	public function getMessages(type = null, remove = true) -> array
	{
		var messages, returnMessages;

		let messages = this->_getSessionMessages(remove);
		if typeof messages == "array" {
			if typeof type == "string" {
				if fetch returnMessages, messages[type] {
					return returnMessages;
				}
			}
			return messages;
		}

		return [];
	}

	/**
	 * Prints the messages in the session flasher
	 *
	 * @param boolean remove
	 */
	public function output(boolean remove = true) -> void
	{
		var type, message, messages;

		let messages = this->_getSessionMessages(remove);
		if typeof messages == "array" {
			for type, message in messages {
				this->outputMessage(type, message);
			}
		}
	}

	public function clear() -> void
	{
		this->_getSessionMessages(true);
	}
}
