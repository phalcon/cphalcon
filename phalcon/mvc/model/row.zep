
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\EntityInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\ResultInterface;

/**
 * Phalcon\Mvc\Model\Row
 *
 * This component allows Phalcon\Mvc\Model to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
class Row implements EntityInterface, ResultInterface, \ArrayAccess, \JsonSerializable
{

	/**
	 * Set the current object's state
	 */
	public function setDirtyState(int dirtyState) -> <ModelInterface> | bool
	{
		return false;
	}

	/**
	 * Checks whether offset exists in the row
	 *
	 * @param string|int $index
	 */
	public function offsetExists(var index) -> bool
	{
		return isset this->{index};
	}

	/**
	 * Gets a record in a specific position of the row
	 *
	 * @param string|int index
	 * @return string|Phalcon\Mvc\ModelInterface
	 */
	public function offsetGet(var index) -> var
	{
		var value;
		if fetch value, this->{index} {
			return value;
		}
		throw new Exception("The index does not exist in the row");
	}

	/**
	 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	 *
	 * @param string|int index
	 * @param \Phalcon\Mvc\ModelInterface value
	 */
	public function offsetSet(var index, var value) -> void
	{
		throw new Exception("Row is an immutable ArrayAccess object");
	}

	/**
	 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	 *
	 * @param string|int offset
	 */
	public function offsetUnset(var offset) -> void
	{
		throw new Exception("Row is an immutable ArrayAccess object");
	}

	/**
	 * Reads an attribute value by its name
	 *
	 *<code>
	 * echo $robot->readAttribute("name");
	 *</code>
	 *
	 * @return mixed
	 */
	public function readAttribute(string! attribute)
	{
		var value;
		if fetch value, this->{attribute} {
			return value;
		}
		return null;
	}

	/**
	 * Writes an attribute value by its name
	 *
	 *<code>
	 * $robot->writeAttribute("name", "Rosey");
	 *</code>
	 *
	 * @param mixed value
	 */
	public function writeAttribute(string! attribute, value) -> void
	{
		let this->{attribute} = value;
	}

	/**
	 * Returns the instance as an array representation
	 */
	public function toArray() -> array
	{
		return get_object_vars(this);
	}

    /**
    * Serializes the object for json_encode
    */
	public function jsonSerialize() -> array
	{
	    return this->toArray();
	}
}
