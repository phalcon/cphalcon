
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Hydration;

use ReflectionClass;
use ReflectionProperty;

class GetPrivateProperties
{
    /**
     * Per-process cache of declared private model properties as
     * [class name => [property name => ReflectionProperty]], used during
     * hydration - see getPrivateProperties()
     *
     * @var array
     *
     * @phpstan-var array<class-string, array<string, \ReflectionProperty>>
     */
    private static privatePropertiesCache = [];

    /**
     * Returns the declared private properties of a class (including inherited
     * ones) as [property name => ReflectionProperty], cached per class.
     *
     * Hydration (cloneResult/cloneResultMap) cannot write private properties
     * directly: the engine write from Model scope falls back to __set(),
     * which invokes a possible setter - or throws for a non-public property
     * without one. Writing through ReflectionProperty stores the raw
     * database value instead.
     *
     * @see https://github.com/phalcon/cphalcon/issues/16454
     *
     * @phpstan-param class-string $className
     */
    public static function getPrivateProperties(string className) -> array
    {
        var cache, privateProperties, propertyName, reflection,
            reflectionProperties, reflectionProperty;

        let cache = self::privatePropertiesCache;

        if !isset cache[className] {
            let privateProperties = [];
            let reflection        = new ReflectionClass(className);

            while typeof reflection === "object" {
                let reflectionProperties = reflection->getProperties(ReflectionProperty::IS_PRIVATE);

                for reflectionProperty in reflectionProperties {
                    if reflectionProperty->isStatic() {
                        continue;
                    }

                    let propertyName = reflectionProperty->getName();

                    if !isset privateProperties[propertyName] {
                        let privateProperties[propertyName] = reflectionProperty;
                    }
                }

                let reflection = reflection->getParentClass();
            }

            let cache[className]             = privateProperties,
                self::privatePropertiesCache = cache;
        }

        return cache[className];
    }
}
