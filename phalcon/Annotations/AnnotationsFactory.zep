
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
use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Contracts\Annotations\AnnotationsTypes;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Traits\Support\Helper\Arr\GetTrait;

/**
 * Factory to create annotations components
 *
 * @phpstan-import-type annotations_options from AnnotationsTypes
 */
class AnnotationsFactory extends AbstractFactory
{
    use GetTrait;

    /**
     * AdapterFactory constructor.
     *
     * @phpstan-param array<string, class-string<AdapterInterface>> $services
     */
    public function __construct(array services = [])
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
     *
     * @phpstan-return AdapterInterface
     */
    public function load(var config) -> var
    {
        var name, options;

        let config = this->checkConfig(config),
            config = this->checkConfigElement(config, "adapter"),
            name   = config["adapter"];

        unset config["adapter"];

        let options = this->getArrVal(config, "options", []);

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
     *
     * @phpstan-param annotations_options $options
     */
    public function newInstance(string name,  array options = []) -> <AdapterInterface>
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
     * @return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * Returns the available adapters
     *
     * @return array<string, string>
     */
    protected function getServices() -> array
    {
        return [
            "apcu"   : Apcu::class,
            "memory" : Memory::class,
            "stream" : Stream::class
        ];
    }
}
