
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
use Phalcon\Helper\Arr;
use Phalcon\Translate\Adapter\AdapterInterface;

/**
 * Class TranslateFactory
 *
 * @package Phalcon\Translate
 *
 * @property InterpolatorFactory $interpolator
 */
class TranslateFactory extends AbstractFactory
{
    protected exception = "Phalcon\\Translate\\Exception";

    /**
     * @var InterpolatorFactory
     */
    private interpolator;

    /**
     * AdapterFactory constructor.
     *
     * @param InterpolatorFactory $interpolator
     * @param array               $services
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
     * @param array|ConfigInterface $config = [
     *     'adapter' => 'ini,
     *     'options' => [
     *         'content'       => '',
     *         'delimiter'     => ';',
     *         'enclosure'     => '"',
     *         'locale'        => '',
     *         'defaultDomain' => '',
     *         'directory'     => '',
     *         'category'      => ''
     *         'triggerError'  => false
     *     ]
     * ]
     *
     * @return AdapterInterface
     * @throws Exception
     */
    public function load(var config) -> <AdapterInterface>
    {
        var name, options;

        let config  = this->checkConfig(config),
            name    = config["adapter"],
            options = Arr::get(config, "options", []);

        return this->newInstance(name, options);
    }

    /**
     * Create a new instance of the adapter
     *
     * @param string $name
     * @param array  $options
     *
     * @return AdapterInterface
     * @throws Exception
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
