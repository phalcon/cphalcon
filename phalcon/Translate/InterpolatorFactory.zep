
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Translate;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Translate\Exceptions\InterpolatorNotRegistered;
use Phalcon\Translate\Interpolator\AssociativeArray;
use Phalcon\Translate\Interpolator\IndexedArray;
use Phalcon\Translate\Interpolator\InterpolatorInterface;

class InterpolatorFactory extends AbstractFactory
{
    /**
     * @phpstan-param array<string, string> $services
     */
    public function __construct( array services = [])
    {
        this->init(services);
    }

    /**
     * Create a new instance of the adapter
     */
    public function newInstance( string name) -> <InterpolatorInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance(definition);
    }

    /**
     * @return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return InterpolatorNotRegistered::class;
    }

    /**
     * Returns the available adapters
     *
     * @return array<string, string>
     */
    protected function getServices() -> array
    {
        return [
            "associativeArray" : AssociativeArray::class,
            "indexedArray"     : IndexedArray::class
        ];
    }
}
