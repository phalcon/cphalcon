
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

namespace Phalcon\Messages;

use Phalcon\Messages\Message;

/**
 * Phalcon\Messages\MessageInterface
 *
 * Interface for Phalcon\Messages\MessageInterface
 */
interface MessageInterface
{
	/**
	 * Returns the message code related to this message
	 *
	 * @return int
	 */
	public function getCode();

	/**
	 * Returns field name related to message
	 *
	 * @return string
	 */
	public function getField();

	/**
	 * Returns verbose message
	 */
	public function getMessage() -> string;

	/**
	 * Returns message type
	 */
	public function getType() -> string;

	/**
	 * Sets code for the message
	 */
	public function setCode(int code) -> <Message>;

	/**
	 * Sets field name related to message
	 */
	public function setField(string! field) -> <Message>;

	/**
	 * Sets verbose message
	 */
	public function setMessage(string! message) -> <Message>;

	/**
	 * Sets message type
	 */
	public function setType(string! type) -> <Message>;

	/**
	 * Magic __toString method returns verbose message
	 */
	public function __toString() -> string;

	/**
	 * Magic __set_state helps to recover messages from serialization
	 */
	public static function __set_state(array! message) -> <MessageInterface>;

}
