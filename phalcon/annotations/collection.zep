
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

namespace Phalcon\Annotations;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Exception;

/**
 * Phalcon\Annotations\Collection
 *
 * Represents a collection of annotations. This class allows to traverse a group of annotations easily
 *
 *<code>
 * //Traverse annotations
 * foreach ($classAnnotations as $annotation) {
 *     echo 'Name=', $annotation->getName(), PHP_EOL;
 * }
 *
 * //Check if the annotations has a specific
 * var_dump($classAnnotations->has('Cacheable'));
 *
 * //Get an specific annotation in the collection
 * $annotation = $classAnnotations->get('Cacheable');
 *</code>
 */
class Collection implements \Iterator, \Countable
{

	protected _position = 0;

	protected _annotations;

	/**
	 * Phalcon\Annotations\Collection constructor
	 *
	 * @param array reflectionData
	 */
	public function __construct(var reflectionData = null)
	{
		var annotations, annotationData;

		if typeof reflectionData != "null" && typeof reflectionData != "array" {
			throw new Exception("Reflection data must be an array");
		}

		let annotations = [];
		if typeof reflectionData == "array" {
			for annotationData in reflectionData {
				let annotations[] = new Annotation(annotationData);
			}
		}
		let this->_annotations = annotations;
	}

	/**
	 * Returns the number of annotations in the collection
	 */
	public function count() -> int
	{
		return count(this->_annotations);
	}

	/**
	 * Rewinds the internal iterator
	 */
	public function rewind() -> void
	{
		let this->_position = 0;
	}

	/**
	 * Returns the current annotation in the iterator
	 *
	 * @return Phalcon\Annotations\Annotation
	 */
	public function current() -> <Annotation> | boolean
	{
		var annotation;
		if fetch annotation, this->_annotations[this->_position] {
			return annotation;
		}
		return false;
	}

	/**
	 * Returns the current position/key in the iterator
	 */
	public function key() -> int
	{
		return this->_position;
	}

	/**
	 * Moves the internal iteration pointer to the next position
	 */
	public function next() -> void
	{
		let this->_position++;
	}

	/**
	 * Check if the current annotation in the iterator is valid
	 */
	public function valid() -> boolean
	{
		return isset this->_annotations[this->_position];
	}

	/**
	 * Returns the internal annotations as an array
	 */
	public function getAnnotations() -> <Annotation[]>
	{
		return this->_annotations;
	}

	/**
	 * Returns the first annotation that match a name
	 */
	public function get(string name) -> <Annotation>
	{
		var annotation, annotations;
		let annotations = this->_annotations;
		if typeof annotations == "array" {
			for annotation in annotations {
				if name == annotation->getName() {
					return annotation;
				}
			}
		}

		throw new Exception("Collection doesn't have an annotation called '" . name . "'");
	}

	/**
	 * Returns all the annotations that match a name
	 */
	public function getAll(string name) -> <Annotation[]>
	{
		var annotations, found, annotation;

		let found = [],
			annotations = this->_annotations;
		if typeof annotations == "array" {
			for annotation in annotations {
				if name == annotation->getName() {
					let found[] = annotation;
				}
			}
		}

		return found;
	}

	/**
	 * Check if an annotation exists in a collection
	 */
	public function has(string name) -> boolean
	{
		var annotations, annotation;

		let annotations = this->_annotations;
		if typeof annotations == "array" {
			for annotation in annotations {
				if name == annotation->getName() {
					return true;
				}
			}
		}
		return false;
	}

}
