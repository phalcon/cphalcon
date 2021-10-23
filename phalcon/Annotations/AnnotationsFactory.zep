
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;

/**
 * Factory to create annotations components
 */
class AnnotationsFactory extends AbstractFactory
{
    protected exception = "Phalcon\\Annotations\\Exception";

    /**
     * AdapterFactory constructor.
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * @param array|\Phalcon\Config\Config config = [
     *     'adapter' => 'apcu',
     *     'options' => [
     *         'prefix' => 'phalcon',
     *         'lifetime' => 3600,
     *         'annotationsDir' => 'phalconDir'
     *     ]
     * ]
     *
     * Factory to create an instance from a Config object
     */
    public function load(var config) -> var
    {
        var name, options;

        let config = this->checkConfig(config),
            name   = config["adapter"];

        unset config["adapter"];

        let options = Arr::get(config, "options", []);

        return this->newInstance(name, options);
    }

    /**
     * Create a new instance of the adapter
     *
     * @param array options = [
     *     'prefix' => 'phalcon',
     *     'lifetime' => 3600,
     *     'annotationsDir' => 'phalconDir'
     * ]
     */
    public function newInstance(string! name, array! options = []) -> <AdapterInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance_params(
            definition,
            [
                options
            ]
        );
    }

    /**
     * The available adapters
     */
    protected function getServices() -> array
    {
        return [
            "apcu"   : "Phalcon\\Annotations\\Adapter\\Apcu",
            "memory" : "Phalcon\\Annotations\\Adapter\\Memory",
            "stream" : "Phalcon\\Annotations\\Adapter\\Stream"
        ];
    }
}
