
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

/**
 * Allows to manipulate the annotations reflection in an OO manner
 *
 *```php
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
 *```
 */
class Reflection
{
    /**
     * @var Collection|null
     */
    protected classAnnotations = null;

    /**
     * @var array
     */
    protected constantAnnotations = [];

    /**
     * @var array
     */
    protected propertyAnnotations = [];

    /**
     * @var array
     */
    protected methodAnnotations = [];

    /**
     * @var array
     */
    protected reflectionData = [];

    public function __construct(array reflectionData = [])
    {
        let this->reflectionData = reflectionData;
    }

    /**
     * Returns the annotations found in the class docblock
     *
     * @return Collection|null
     */
    public function getClassAnnotations() -> <Collection> | null
    {
        var reflectionClass;

        if this->classAnnotations === null {
            if fetch reflectionClass, this->reflectionData["class"] {
                let this->classAnnotations = new Collection(reflectionClass);
            }
        }

        return this->classAnnotations;
    }

    /**
     * Returns the annotations found in the constants' docblocks
     *
     * @return Collection[]
     */
    public function getConstantsAnnotations() -> <Collection[]>
    {
        var reflectionConstants, constant, reflectionConstant;

        if fetch reflectionConstants, this->reflectionData["constants"] {
            if typeof reflectionConstants === "array" && count(reflectionConstants) > 0 {
                for constant, reflectionConstant in reflectionConstants {
                    let this->constantAnnotations[constant] = new Collection(
                        reflectionConstant
                    );
                }
            }
        }

        return this->constantAnnotations;
    }

    /**
     * Returns the annotations found in the properties' docblocks
     *
     * @return Collection[]
     */
    public function getPropertiesAnnotations() -> <Collection[]>
    {
        var reflectionProperties, property, reflectionProperty;

        if fetch reflectionProperties, this->reflectionData["properties"] {
            if typeof reflectionProperties === "array" && count(reflectionProperties) > 0 {
                for property, reflectionProperty in reflectionProperties {
                    let this->propertyAnnotations[property] = new Collection(
                        reflectionProperty
                    );
                }
            }
        }

        return this->propertyAnnotations;
    }

    /**
     * Returns the annotations found in the methods' docblocks
     *
     * @return Collection[]
     */
    public function getMethodsAnnotations() -> <Collection[]>
    {
        var reflectionMethods, methodName, reflectionMethod;

        if fetch reflectionMethods, this->reflectionData["methods"] {
            if typeof reflectionMethods === "array" && count(reflectionMethods) > 0 {
                for methodName, reflectionMethod in reflectionMethods {
                    let this->methodAnnotations[methodName] = new Collection(
                        reflectionMethod
                    );
                }
            }
        }

        return this->methodAnnotations;
    }

    /**
     * Returns the raw parsing intermediate definitions used to construct the
     * reflection
     *
     * @return array
     */
    public function getReflectionData() -> array
    {
        return this->reflectionData;
    }
}
