
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Hydration;

use Phalcon\Mvc\Model\Exceptions\InvalidDumpResultKey;
use Phalcon\Mvc\ModelInterface;

class CloneResult
{
    /**
     * Assigns values to a model from an array returning a new model
     *
     *```php
     * $invoice = Phalcon\Mvc\Model::cloneResult(
     *     new Invoices(),
     *     [
     *         "type" => "mechanical",
     *         "name" => "Test Invoice",
     *         "year" => 1952,
     *     ]
     * );
     *```
     *
     * @phpstan-param mvc_model_data $data
     */
    public static function cloneResult(<ModelInterface> base, array data, int dirtyState = 0) -> <ModelInterface>
    {
        var instance, key, privateProperties, reflectionProperty, value;

        /**
         * Clone the base record
         */
        let instance = clone base;

        /**
         * Declared private properties must be written via reflection during
         * hydration - see Hydration\GetPrivateProperties
         */
        let privateProperties = GetPrivateProperties::getPrivateProperties(get_class(instance));

        /**
         * Mark the object as persistent
         */
        instance->setDirtyState(dirtyState);

        for key, value in data {
            if unlikely typeof key !== "string" {
                throw new InvalidDumpResultKey(get_class(base));
            }

            if unlikely isset privateProperties[key] {
                let reflectionProperty = privateProperties[key];
                reflectionProperty->setValue(instance, value);
            } else {
                let instance->{key} = value;
            }
        }

        /**
         * Call afterFetch, this allows the developer to execute actions after a
         * record is fetched from the database
         */
        (<ModelInterface> instance)->fireEvent("afterFetch");

        return instance;
    }
}
