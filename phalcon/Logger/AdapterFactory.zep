
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
use Phalcon\Logger\Adapter\AdapterInterface;
use Phalcon\Logger\Exception;

/**
 * Factory used to create adapters used for Logging
 */
class AdapterFactory extends AbstractFactory
{
    /**
     * AdapterFactory constructor.
     *
     * @param array $services
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * Create a new instance of the adapter
     *
     * @param string $name
     * @param string $fileName
     * @param array  $options
     *
     * @return AdapterInterface
     * @throws Exception
     */
    public function newInstance(
        string! name,
        string! fileName,
        array options = []
    ) -> <AdapterInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance_params(
            definition,
            [
                fileName,
                options
            ]
        );
    }

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Logger\\Exception";
    }

    /**
     * @return array
     */
    protected function getServices() -> array
    {
        return [
            "noop"   : "Phalcon\\Logger\\Adapter\\Noop",
            "stream" : "Phalcon\\Logger\\Adapter\\Stream",
            "syslog" : "Phalcon\\Logger\\Adapter\\Syslog"
        ];
    }
}
