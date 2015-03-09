
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

namespace Phalcon\Validation;

use Phalcon\Validation\Message;

/**
 * Phalcon\Validation\Message
 *
 * Interface for Phalcon\Validation\Message
 */
interface MessageInterface
{

	/**
	 * Phalcon\Validation\Message constructor
	 *
	 * @param string message
	 * @param string field
	 * @param string type
	 */
	public function __construct(string! message, field = null, type = null);

	/**
	 * Sets message type
	 *
	 * @param string type
	 * @return Phalcon\Validation\Message
	 */
	public function setType(string! type) -> <Message>;

	/**
	 * Returns message type
	 *
	 * @return string
	 */
	public function getType() -> string;

	/**
	 * Sets verbose message
	 *
	 * @param string message
	 * @return Phalcon\Validation\Message
	 */
	public function setMessage(string! message) -> <Message>;

	/**
	 * Returns verbose message
	 *
	 * @return string
	 */
	public function getMessage() -> string;

	/**
	 * Sets field name related to message
	 *
	 * @param string field
	 * @return Phalcon\Validation\Message
	 */
	public function setField(string! field) -> <Message>;

	/**
	 * Returns field name related to message
	 *
	 * @return string
	 */
	public function getField();

	/**
	 * Magic __toString method returns verbose message
	 *
	 * @return string
	 */
	public function __toString();

	/**
	 * Magic __set_state helps to recover messsages from serialization
	 *
	 * @param array message
	 * @return Phalcon\Validation\Message
	 */
	public static function __set_state(array! message) -> <MessageInterface>;

}