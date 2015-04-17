
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Mvc\Model\Message
 *
 * Interface for Phalcon\Mvc\Model\Message
 */
interface MessageInterface
{

	/**
	 * Phalcon\Mvc\Model\Message constructor
	 *
	 * @param string message
	 * @param string field
	 * @param string type
	 */
	public function __construct(message, field = null, type = null);

	/**
	 * Sets message type
	 *
	 * @param string type
	 */
	public function setType(type);

	/**
	 * Returns message type
	 *
	 * @return string
	 */
	public function getType();

	/**
	 * Sets verbose message
	 *
	 * @param string message
	 */
	public function setMessage(message);

	/**
	 * Returns verbose message
	 *
	 * @return string
	 */
	public function getMessage();

	/**
	 * Sets field name related to message
	 *
	 * @param string field
	 */
	public function setField(field);

	/**
	 * Returns field name related to message
	 *
	 * @return string
	 */
	public function getField();

	/**
	 * Magic __toString method returns verbose message
	 */
	public function __toString() -> string;

	/**
	 * Magic __set_state helps to recover messsages from serialization
	 */
	public static function __set_state(array! message) -> <MessageInterface>;

}
