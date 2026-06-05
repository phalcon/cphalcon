
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
use Phalcon\Factory\AbstractFactory;
use Phalcon\Translate\Adapter\AdapterInterface;

/**
 * @property InterpolatorFactory $interpolator
 *
 * @psalm-type TConfig array{
 *      adapter: string,
 *      options?: array{
 *          content: string,
 *          delimiter: string,
 *          enclosure: string,
 *          locale: string,
 *          defaultDomain: string,
 *          directory: string,
 *          category: string,
 *          triggerError: bool,
 *      }
 *  }
 */
class TranslateFactory extends AbstractFactory
{
    /**
     * @var InterpolatorFactory
     */
    private interpolator;

    /**
     * @phpstan-param array<string, string> $services
     */
    public function __construct(
        <InterpolatorFactory> interpolator,
        array! services = []
    ) {
        let this->interpolator = interpolator;

        this->init(services);
    }

    /**
     * Factory to create an instance from a Config object
     *
     * @param ConfigInterface|TConfig $config
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
    public function newInstance(string! name, array! options = []) -> <AdapterInterface>
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
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Translate\\Exceptions\\TranslatorNotRegistered";
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "csv"     : "Phalcon\\Translate\\Adapter\\Csv",
            "gettext" : "Phalcon\\Translate\\Adapter\\Gettext",
            "array"   : "Phalcon\\Translate\\Adapter\\NativeArray"
        ];
    }
}
