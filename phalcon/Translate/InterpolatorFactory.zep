
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
use Phalcon\Translate\Interpolator\InterpolatorInterface;

class InterpolatorFactory extends AbstractFactory
{
    /**
     * AdapterFactory constructor.
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * Create a new instance of the adapter
     */
    public function newInstance(string! name) -> <InterpolatorInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance(definition);
    }

    protected function getAdapters() -> array
    {
        return [
            "associativeArray" : "Phalcon\\Translate\\Interpolator\\AssociativeArray",
            "indexedArray"     : "Phalcon\\Translate\\Interpolator\\IndexedArray"
        ];
    }
}
