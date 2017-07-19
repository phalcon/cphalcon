
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

namespace Phalcon\Flash;

use Phalcon\Flash as FlashBase;
use Phalcon\DiInterface;
use Phalcon\Flash\Exception;
use Phalcon\Session\AdapterInterface as SessionInterface;

/**
 * Phalcon\Flash\Session
 *
 * Temporarily stores the messages in session, then messages can be printed in the next request
 */
class Session extends FlashBase
{
	/**
	 * Returns the messages stored in session
	 */
	protected function _getSessionMessages(boolean remove, type = null) -> array
	{
		var dependencyInjector, session, messages, returnMessages;

		let dependencyInjector = <DiInterface> this->getDI();

		let session = <SessionInterface> dependencyInjector->getShared("session"),
			messages = session->get("_flashMessages");

		if typeof type == "string" {
			if fetch returnMessages, messages[type] {
				if remove === true {
					unset(messages[type]);
					session->set("_flashMessages", messages);
				}

				return returnMessages;
			}

			return [];
		}

		if remove === true {
			session->remove("_flashMessages");
		}

		return messages;
	}

	/**
	 * Stores the messages in session
	 */
	protected function _setSessionMessages(array! messages) -> array
	{
		var dependencyInjector, session;

		let dependencyInjector = <DiInterface> this->getDI(),
			session = <SessionInterface> dependencyInjector->getShared("session");

		session->set("_flashMessages", messages);
		return messages;
	}

	/**
	 * Adds a message to the session flasher
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
	 */
	public function getMessages(type = null, boolean remove = true) -> array
	{
		return this->_getSessionMessages(remove, type);
	}

	/**
	 * Prints the messages in the session flasher
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

		parent::clear();
	}

	/**
	 * Clear messages in the session messenger
	 */
	public function clear() -> void
	{
		this->_getSessionMessages(true);
		parent::clear();
	}
}
