
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Annotations\Collection;

/**
 * Phalcon\Annotations\Reflection
 *
 * Allows to manipulate the annotations reflection in an OO manner
 *
 *<code>
 * use Phalcon\Annotations\Reader;
 * use Phalcon\Annotations\Reflection;
 *
 * // Parse the annotations in a class
 * $reader = new Reader();
 * $parsing = $reader->parse("MyComponent");
 *
 * // Create the reflection
 * $reflection = new Reflection($parsing);
 *
 * // Get the annotations in the class docblock
 * $classAnnotations = $reflection->getClassAnnotations();
 *</code>
 */
class Reflection
{
    protected classAnnotations;

    protected methodAnnotations;

    protected propertyAnnotations;

    protected reflectionData;

    /**
     * Phalcon\Annotations\Reflection constructor
     */
    public function __construct(array reflectionData = []) -> void
    {
        let this->reflectionData = reflectionData;
    }

    /**
     * Restores the state of a Phalcon\Annotations\Reflection variable export
     */
    public static function __set_state(array! data) -> <Reflection>
    {
        var reflectionData;

        /**
         * Check for a 'reflectionData' in the array to build the Reflection
         */
        if fetch reflectionData, data["reflectionData"] {
            return new self(reflectionData);
        }

        return new self();
    }

    /**
     * Returns the annotations found in the class docblock
     */
    public function getClassAnnotations() -> <Collection> | bool
    {
        var annotations, reflectionClass, collection;

        let annotations = this->classAnnotations;
        if typeof annotations != "object" {
            if fetch reflectionClass, this->reflectionData["class"] {
                let collection = new Collection(reflectionClass),
                    this->classAnnotations = collection;
                return collection;
            }
            let this->classAnnotations = false;
            return false;
        }
        return annotations;
    }

    /**
     * Returns the annotations found in the methods' docblocks
     */
    public function getMethodsAnnotations() -> <Collection[]> | bool
    {
        var annotations, reflectionMethods,
            collections, methodName, reflectionMethod;

        let annotations = this->methodAnnotations;
        if typeof annotations != "object" {

            if fetch reflectionMethods, this->reflectionData["methods"] {
                if count(reflectionMethods) {
                    let collections = [];
                    for methodName, reflectionMethod in reflectionMethods {
                        let collections[methodName] = new Collection(
                            reflectionMethod
                        );
                    }
                    let this->methodAnnotations = collections;
                    return collections;
                }
            }

            let this->methodAnnotations = false;
            return false;
        }
        return annotations;
    }

    /**
     * Returns the annotations found in the properties' docblocks
     */
    public function getPropertiesAnnotations() -> <Collection[]> | bool
    {
        var annotations, reflectionProperties,
            collections, property, reflectionProperty;

        let annotations = this->propertyAnnotations;
        if typeof annotations != "object" {
            if fetch reflectionProperties, this->reflectionData["properties"] {
                if count(reflectionProperties) {
                    let collections = [];
                    for property, reflectionProperty in reflectionProperties {
                        let collections[property] = new Collection(
                            reflectionProperty
                        );
                    }
                    let this->propertyAnnotations = collections;
                    return collections;
                }
            }
            let this->propertyAnnotations = false;
            return false;
        }

        return annotations;
    }

    /**
     * Returns the raw parsing intermediate definitions used to construct the
     * reflection
     */
    public function getReflectionData() -> array
    {
        return this->reflectionData;
    }
}
