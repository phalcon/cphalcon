
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Countable;
use Iterator;

/**
 * Represents a collection of annotations. This class allows to traverse a group
 * of annotations easily
 *
 *```php
 * // Traverse annotations
 * foreach ($classAnnotations as $annotation) {
 *     echo "Name=", $annotation->getName(), PHP_EOL;
 * }
 *
 * // Check if the annotations has a specific
 * var_dump($classAnnotations->has("Cacheable"));
 *
 * // Get an specific annotation in the collection
 * $annotation = $classAnnotations->get("Cacheable");
 *```
 */
class Collection implements Iterator, Countable
{
    /**
     * @var array
     */
    protected annotations;

    /**
     * @var int
     */
    protected position = 0;

    /**
     * Phalcon\Annotations\Collection constructor
     */
    public function __construct(array reflectionData = [])
    {
        var annotations, annotationData;

        let annotations = [];

        for annotationData in reflectionData {
            let annotations[] = new Annotation(annotationData);
        }

        let this->annotations = annotations;
    }

    /**
     * Returns the number of annotations in the collection
     */
    public function count() -> int
    {
        return count(this->annotations);
    }

    /**
     * Returns the current annotation in the iterator
     */
    public function current() -> mixed
    {
        var annotation;

        if !fetch annotation, this->annotations[this->position] {
            return false;
        }

        return annotation;
    }

    /**
     * Returns the first annotation that match a name
     */
    public function get(string name) -> <Annotation>
    {
        var annotation, annotations;

        let annotations = this->annotations;

        for annotation in annotations {
            if name == annotation->getName() {
                return annotation;
            }
        }

        throw new Exception(
            "Collection doesn't have an annotation called '" . name . "'"
        );
    }

    /**
     * Returns all the annotations that match a name
     */
    public function getAll(string name) -> <Annotation[]>
    {
        var annotations, annotation;
        array found;

        let found = [],
            annotations = this->annotations;

        for annotation in annotations {
            if name == annotation->getName() {
                let found[] = annotation;
            }
        }

        return found;
    }

    /**
     * Returns the internal annotations as an array
     */
    public function getAnnotations() -> <Annotation[]>
    {
        return this->annotations;
    }

    /**
     * Check if an annotation exists in a collection
     */
    public function has(string name) -> bool
    {
        var annotations, annotation;

        let annotations = this->annotations;

        for annotation in annotations {
            if name == annotation->getName() {
                return true;
            }
        }

        return false;
    }

    /**
     * Returns the current position/key in the iterator
     */
    public function key() -> int
    {
        return this->position;
    }

    /**
     * Moves the internal iteration pointer to the next position
     */
    public function next() -> void
    {
        let this->position++;
    }

    /**
     * Rewinds the internal iterator
     */
    public function rewind() -> void
    {
        let this->position = 0;
    }

    /**
     * Check if the current annotation in the iterator is valid
     */
    public function valid() -> bool
    {
        return isset this->annotations[this->position];
    }
}
