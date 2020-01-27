
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate;

use Phalcon\Config;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;
use Phalcon\Translate\Adapter\AdapterInterface;

class TranslateFactory extends AbstractFactory
{
    /**
     * @var InterpolatorFactory
     */
    private interpolator;

    /**
     * AdapterFactory constructor.
     */
    public function __construct(<InterpolatorFactory> interpolator, array! services = [])
    {
        let this->interpolator = interpolator;

        this->init(services);
    }

    /**
     * Factory to create an instance from a Config object
     *
     * @param array|\Phalcon\Config = [
     *     'adapter' => 'ini,
     *     'options' => [
     *         'content' => '',
     *         'delimiter' => ';',
     *         'enclosure' => '"',
     *         'locale' => '',
     *         'defaultDomain' => '',
     *         'directory' => '',
     *         'category' => ''
     *         'triggerError' => false
     *     ]
     * ]
     */
    public function load(var config) -> var
    {
        var name, options;

        let config  = this->checkConfig(config),
            name    = config["adapter"],
            options = Arr::get(config, "options", []);

        return this->newInstance(name, options);
    }

    /**
     * Create a new instance of the adapter
     */
    public function newInstance(string! name, array! options = []) -> <AdapterInterface>
    {
        var definition;

        this->checkService(name);

        let definition = this->mapper[name];

        return create_instance_params(
            definition,
            [
                this->interpolator,
                options
            ]
        );
    }

    protected function getAdapters() -> array
    {
        return [
            "csv"     : "Phalcon\\Translate\\Adapter\\Csv",
            "gettext" : "Phalcon\\Translate\\Adapter\\Gettext",
            "array"   : "Phalcon\\Translate\\Adapter\\NativeArray"
        ];
    }
}
