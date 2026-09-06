
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
use Phalcon\Annotations\Exceptions\AnnotationNotFound;
use Phalcon\Contracts\Annotations\AnnotationsTypes;

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
 *
 * The class cannot carry an `@implements Iterator<int, Annotation>` tag.
 * `current()` returns `false` past the end of the collection, while Psalm's
 * `Iterator` stub requires `TValue|null` there. Narrowing the iteration would
 * mean changing that return to null, which is a v7 signature change.
 *
 * @phpstan-import-type annotations_list from AnnotationsTypes
 * @phpstan-import-type annotations_node_list from AnnotationsTypes
 */
class Collection implements Iterator, Countable
{
    /**
     * @var array
     *
     * @phpstan-var annotations_list
     */
    protected annotations;

    /**
     * @var int
     */
    protected position = 0;

    /**
     * Phalcon\Annotations\Collection constructor
     *
     * @phpstan-param annotations_node_list $reflectionData
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
     *
     * @phpstan-return Annotation|false
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

        throw new AnnotationNotFound(name);
    }

    /**
     * Returns all the annotations that match a name
     *
     * @phpstan-return annotations_list
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
     *
     * @phpstan-return annotations_list
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
