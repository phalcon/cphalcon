
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Collection;

use Phalcon\Mvc\EntityInterface;
use Phalcon\Mvc\Collection\Exception;

/**
 * Phalcon\Mvc\Collection\Document
 *
 * This component allows Phalcon\Mvc\Collection to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
class Document implements EntityInterface, \ArrayAccess
{
	/**
	 * Checks whether an offset exists in the document
	 */
	public function offsetExists(var index) -> bool
	{
		return isset this->{index};
	}

	/**
	 * Returns the value of a field using the ArrayAccess interfase
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
	 * Change a value using the ArrayAccess interface
	 */
	public function offsetSet(var index, value) -> void
	{
		let this->{index} = value;
	}

	/**
	 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	 */
	public function offsetUnset(var index) -> void
	{
		throw new Exception("The index does not exist in the row");
	}

	/**
	 * Reads an attribute value by its name
	 *
	 *<code>
	 *  echo $robot->readAttribute("name");
	 *</code>
	 */
	public function readAttribute(string! attribute) -> var | null
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
	 *  $robot->writeAttribute("name", "Rosey");
	 *</code>
	 */
	public function writeAttribute(string! attribute, var value) -> void
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
}
