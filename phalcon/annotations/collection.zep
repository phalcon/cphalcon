
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

namespace Phalcon\Annotations;

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
	public function __construct(reflectionData=null)
	{
		var annotations, annotationData;

		if typeof reflectionData != "null" {
			if typeof reflectionData != "array" {
				throw new Phalcon\Annotations\Exception("Reflection data must be an array");
			}
		}
		if typeof reflectionData == "array" {
			let annotations = [];
			for annotationData in reflectionData {
				let annotations[] = new Phalcon\Annotations\Annotation(annotationData);
			}
			let this->_annotations = annotations;
		}
	}

	/**
	 * Returns the number of annotations in the collection
	 *
	 * @return int
	 */
	public function count()
	{
		return count(this->_annotations);
	}

	/**
	 * Rewinds the internal iterator
	 */
	public function rewind()
	{
		let this->_position = 0;
	}

	/**
	 * Returns the current annotation in the iterator
	 *
	 * @return Phalcon\Annotations\Annotation
	 */
	public function current()
	{
		var annotation, annotations;
		let annotations = this->_annotations;
		if fetch annotation, annotations[this->_position] {
			return annotation;
		}
		return null;
	}

	/**
	 * Returns the current position/key in the iterator
	 *
	 * @return int
	 */
	public function key()
	{
		return this->_position;
	}

	/**
	 * Moves the internal iteration pointer to the next position
	 *
	 */
	public function next()
	{
		let this->_position++;
	}

	/**
	 * Check if the current annotation in the iterator is valid
	 *
	 * @return boolean
	 */
	public function valid()
	{
		var annotations;
		let annotations = this->_annotations;
		return annotations[this->_position];
	}

	/**
	 * Returns the internal annotations as an array
	 *
	 * @return Phalcon\Annotations\Annotation[]
	 */
	public function getAnnotations()
	{
		return this->_annotations;
	}

	/**
	 * Returns the first annotation that match a name
	 *
	 * @param string name
	 * @return Phalcon\Annotations\Annotation
	 */
	public function get(name)
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

		throw new Phalcon\Annotations\Exception("The collection doesn't have an annotation called '" . name . "'");
	}

	/**
	 * Returns all the annotations that match a name
	 *
	 * @param string name
	 * @return Phalcon\Annotations\Annotation[]
	 */
	public function getAll(name)
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
	 *
	 * @param string name
	 * @return boolean
	 */
	public function has(name)
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