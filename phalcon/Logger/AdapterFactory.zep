
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use Phalcon\Factory\AbstractFactory;

class AdapterFactory extends AbstractFactory
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
    public function newInstance(
        string! name,
        string! fileName,
        array options = []
    ) -> <AdapterInterface>
    {
        var definition;

        this->checkService(name);

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}(fileName, options);
        }

        return this->services[name];
    }

    protected function getAdapters() -> array
    {
        return [
            "noop"   : "\\Phalcon\\Logger\\Adapter\\Noop",
            "stream" : "\\Phalcon\\Logger\\Adapter\\Stream",
            "syslog" : "\\Phalcon\\Logger\\Adapter\\Syslog"
        ];
    }
}
