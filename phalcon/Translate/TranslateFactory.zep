
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate;

use Phalcon\Config\ConfigInterface;
use Phalcon\Contracts\Translate\TranslateTypes;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Exceptions\TranslatorNotRegistered;

/**
 * @property InterpolatorFactory $interpolator
 *
 * @phpstan-import-type translate_factory_config from TranslateTypes
 */
class TranslateFactory extends AbstractFactory
{
    private <InterpolatorFactory> interpolator;

    /**
     * @phpstan-param array<string, string> $services
     */
    public function __construct(
        <InterpolatorFactory> interpolator,
         array services = []
    ) {
        let this->interpolator = interpolator;

        this->init(services);
    }

    /**
     * Factory to create an instance from a Config object
     *
     * @phpstan-param ConfigInterface|translate_factory_config $config
     *
     * @return AdapterInterface
     * @throws Exception
     */
    public function load(var config) -> <AdapterInterface>
    {
        var name, options;

        let config  = this->checkConfig(config),
            config  = this->checkConfigElement(config, "adapter"),
            name    = config["adapter"];

        if !fetch options, config["options"] {
            let options = [];
        }

        return this->newInstance(name, options);
    }

    /**
     * Create a new instance of the adapter
     *
     * @phpstan-param array<string, mixed> $options
     *
     * @return AdapterInterface
     */
    public function newInstance(string name,  array options = []) -> <AdapterInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance_params(
            definition,
            [
                this->interpolator,
                options
            ]
        );
    }

    /**
     * @return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return TranslatorNotRegistered::class;
    }

    /**
     * Returns the available adapters
     *
     * @return array<string, string>
     */
    protected function getServices() -> array
    {
        return [
            "csv"     : Csv::class,
            "gettext" : Gettext::class,
            "array"   : NativeArray::class
        ];
    }
}
