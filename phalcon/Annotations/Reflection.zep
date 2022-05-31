
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
     * @var array
     * TODO: Make always array
     */
    protected classAnnotations;

    /**
     * @var array
     * TODO: Make always array
     */
    protected constantAnnotations;

    /**
     * @var array
     * TODO: Make always array
     */
    protected propertyAnnotations;

    /**
     * @var array
     * TODO: Make always array
     */
    protected methodAnnotations;

    /**
     * @var array
     */
    protected reflectionData = [];

    /**
     * Phalcon\Annotations\Reflection constructor
     */
    public function __construct(array reflectionData = [])
    {
        let this->reflectionData = reflectionData;
    }

    /**
     * Returns the annotations found in the class docblock
     */
    public function getClassAnnotations() -> <Collection> | bool
    {
        var reflectionClass;

        if this->classAnnotations === null {
            if fetch reflectionClass, this->reflectionData["class"] {
                let this->classAnnotations = new Collection(reflectionClass);
            } else {
                let this->classAnnotations = false;
            }
        }

        return this->classAnnotations;
    }

    /**
     * Returns the annotations found in the constants' docblocks
     */
    public function getConstantsAnnotations() -> <Collection[]> | bool
    {
        var reflectionConstants, constant, reflectionConstant;

        if this->constantAnnotations === null {
            if fetch reflectionConstants, this->reflectionData["constants"] {
                if count(reflectionConstants) {
                    let this->constantAnnotations = [];

                    for constant, reflectionConstant in reflectionConstants {
                        let this->constantAnnotations[constant] = new Collection(
                            reflectionConstant
                        );
                    }

                    return this->constantAnnotations;
                }
            }

            let this->constantAnnotations = false;
        }

        return this->constantAnnotations;
    }

    /**
     * Returns the annotations found in the properties' docblocks
     */
    public function getPropertiesAnnotations() -> <Collection[]> | bool
    {
        var reflectionProperties, property, reflectionProperty;

        if this->propertyAnnotations === null {
            if fetch reflectionProperties, this->reflectionData["properties"] {
                if count(reflectionProperties) {
                    let this->propertyAnnotations = [];

                    for property, reflectionProperty in reflectionProperties {
                        let this->propertyAnnotations[property] = new Collection(
                            reflectionProperty
                        );
                    }

                    return this->propertyAnnotations;
                }
            }

            let this->propertyAnnotations = false;
        }

        return this->propertyAnnotations;
    }

    /**
     * Returns the annotations found in the methods' docblocks
     */
    public function getMethodsAnnotations() -> <Collection[]> | bool
    {
        var reflectionMethods, methodName, reflectionMethod;

        if this->methodAnnotations === null {
            if fetch reflectionMethods, this->reflectionData["methods"] {
                if count(reflectionMethods) {
                    let this->methodAnnotations = [];

                    for methodName, reflectionMethod in reflectionMethods {
                        let this->methodAnnotations[methodName] = new Collection(
                            reflectionMethod
                        );
                    }

                    return this->methodAnnotations;
                }
            }

            let this->methodAnnotations = false;
        }

        return this->methodAnnotations;
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
