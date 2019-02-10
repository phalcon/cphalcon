
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * Returns message metadata
	 */
	public function getMetaData() -> array;

	/**
	 * Sets code for the message
	 */
	public function setCode(int code) -> <MessageInterface>;

	/**
	 * Sets field name related to message
	 */
	public function setField(string! field) -> <MessageInterface>;

	/**
	 * Sets verbose message
	 */
	public function setMessage(string! message) -> <MessageInterface>;

	/**
	 * Sets message type
	 */
	public function setType(string! type) -> <MessageInterface>;

	/**
	 * Sets message metadata
	 */
	public function setMetaData(array! metaData) -> <MessageInterface>;

	/**
	 * Magic __toString method returns verbose message
	 */
	public function __toString() -> string;
}
