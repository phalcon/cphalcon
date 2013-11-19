
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

namespace Phalcon\Mvc\Collection;

/**
 * Phalcon\Mvc\Collection\Document
 *
 * This component allows Phalcon\Mvc\Collection to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
class Document implements ArrayAccess
{
	/**
	* Checks whether an offset exists in the document
	*
	* @param int index
	* @return boolean
	*/
	public function offsetExists(index) -> boolean
	{
		if isset this->{index} {
			return true;
		}
		return false;
	}

	/**
	* Returns the value of a field using the ArrayAccess interfase
	*
	* @param string index
	* @return mixed
	*/
	public function offsetGet(index)
	{
		if isset this->{index} {
			return this->{index};
		}
		throw new Phalcon\Mvc\Collection\Exception("The index does not exist in the row");
	}

	/**
	* Change a value using the ArrayAccess interface
	*
	* @param string index
	* @param mixed value
	* @param Phalcon\Mvc\ModelInterface value
	*/
	public function offsetSet(index, value) -> void
	{
		let this->{index} = value;
	}

	/**
	* Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	*
	* @param string offset
	*/
	public function offsetUnset(offset)
	{
		throw new Phalcon\Mvc\Collection\Exception("The index does not exist in the row");
	}

	/**
	* Reads an attribute value by its name
	*
	*<code>
	*        echo robot->readAttribute('name');
	*</code>
	*
	* @param string attribute
	* @return mixed
	*/
	public function readAttribute(attribute)
	{
		if isset this->{attribute} {
			return this->{attribute};
		}
		return null;
	}

	/**
	* Writes an attribute value by its name
	*
	*<code>
	*        robot->writeAttribute('name', 'Rosey');
	*</code>
	*
	* @param string attribute
	* @param mixed value
	*/
	public function writeAttribute(attribute, value) -> void
	{
		let this->{attribute} = value;
	}
}