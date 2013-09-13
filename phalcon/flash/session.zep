
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

namespace Phalcon\Flash;

/**
 * Phalcon\Flash\Session
 *
 * Temporarily stores the messages in session, then messages can be printed in the next request
 */
class Session extends Phalcon\Flash implements Phalcon\FlashInterface, Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	/**
	 * Sets the dependency injector
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI()
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

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Flash\Exception("A dependency injection container is required to access the 'session' service");
		}

		let session = dependencyInjector->getShared("session");
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
	protected function _setSessionMessages(messages)
	{
		var dependencyInjector, session;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Flash\Exception("A dependency injection container is required to access the 'session' service");
		}

		let session = dependencyInjector->getShared("session");
		session->set("_flashMessages", messages);
		return messages;
	}

	/**
	 * Adds a message to the session flasher
	 *
	 * @param string type
	 * @param string message
	 */
	public function message(type, message)
	{
		var messages;

		let messages = this->_getSessionMessages(false);
		if typeof messages != "array" {
			let messages = [];
		}
		if !isset messages[type] {
			let messages[type] = [];
		}
		//let messages[type][] = message;

		this->_setSessionMessages(messages);
	}

	/**
	 * Returns the messages in the session flasher
	 *
	 * @param string type
	 * @param boolean remove
	 * @return array
	 */
	public function getMessages(type=null, remove=true)
	{
		var messages, returnMessages;

		let messages = this->_getSessionMessages(remove);
		if typeof messages == "array" {
			if typeof type == "string" {
				if fetch returnMessages, messages[type] {
					return messages[type];
				}
			}
			return messages;
		}

		return [];
	}

	/**
	 * Prints the messages in the session flasher
	 *
	 * @param string type
	 * @param boolean remove
	 */
	public function output(remove=true)
	{
		var type, message, messages;

		let messages = this->_getSessionMessages(remove);
		if typeof messages == "array" {
			for type, message in messages {
				this->outputMessage(type, message);
			}
		}
	}

}
