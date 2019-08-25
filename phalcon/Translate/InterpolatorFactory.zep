
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Translate\Adapter\AdapterInterface;

class InterpolatorFactory extends AbstractFactory
{
    /**
     * @var array
     */
    private mapper   = [];

    /**
     * @var array
     */
    private services = [];

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
    public function newInstance(string! name) -> <AdapterInterface>
    {
        var definition;

        this->checkService(name);

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}();
        }

        return this->services[name];
    }

    protected function getAdapters() -> array
    {
        return [
            "associativeArray" : "\\Phalcon\\Translate\\Interpolator\\AssociativeArray",
            "indexedArray"     : "\\Phalcon\\Translate\\Interpolator\\IndexedArray"
        ];
    }
}
