
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use ArrayAccess;
use JsonSerializable;
use Phalcon\Mvc\EntityInterface;
use Phalcon\Mvc\ModelInterface;

/**
 * This component allows Phalcon\Mvc\Model to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
class Row implements EntityInterface, ResultInterface, ArrayAccess, JsonSerializable
{
    /**
    * Serializes the object for json_encode
    */
    public function jsonSerialize() -> array
    {
        return this->toArray();
    }

    /**
     * Gets a record in a specific position of the row
     *
     * @param string|int index
     *
     * @return string|ModelInterface
     */
    public function offsetGet(mixed index) -> mixed
    {
        if !this->offsetExists(index) {
            throw new Exception("The index does not exist in the row");
        }

        return this->{index};
    }

    /**
     * Checks whether offset exists in the row
     *
     * @param string|int $index
     */
    public function offsetExists(mixed index) -> bool
    {
        return isset this->{index};
    }

    /**
     * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     *
     * @param string|int index
     * @param ModelInterface value
     */
    public function offsetSet(mixed index, mixed value) -> void
    {
        throw new Exception("Row is an immutable ArrayAccess object");
    }

    /**
     * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     *
     * @param string|int offset
     */
    public function offsetUnset(mixed offset) -> void
    {
        throw new Exception("Row is an immutable ArrayAccess object");
    }

    /**
     * Reads an attribute value by its name
     *
     *```php
     * echo $robot->readAttribute("name");
     *```
     *
     * @return mixed
     */
    public function readAttribute(string! attribute)
    {
        var value;

        if !fetch value, this->{attribute} {
            return null;
        }

        return value;
    }

    /**
     * Set the current object's state
     */
    public function setDirtyState(int dirtyState) -> <ModelInterface> | bool
    {
        return false;
    }

    /**
     * Returns the instance as an array representation
     */
    public function toArray() -> array
    {
        return get_object_vars(this);
    }

    /**
     * Writes an attribute value by its name
     *
     *```php
     * $robot->writeAttribute("name", "Rosey");
     *```
     *
     * @param mixed value
     */
    public function writeAttribute(string! attribute, value) -> void
    {
        let this->{attribute} = value;
    }
}
