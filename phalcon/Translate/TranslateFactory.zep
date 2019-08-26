
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
use Phalcon\Translate\InterpolatorFactory;

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
     * Factory to create an instace from a Config object
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
    public function newInstance(string! name, array! options = []) -> <AbstractAdapter>
    {
        var definition;

        this->checkService(name);

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}(this->interpolator, options);
        }

        return this->services[name];
    }

    protected function getAdapters() -> array
    {
        return [
            "csv"     : "\\Phalcon\\Translate\\Adapter\\Csv",
            "gettext" : "\\Phalcon\\Translate\\Adapter\\Gettext",
            "array"   : "\\Phalcon\\Translate\\Adapter\\NativeArray"
        ];
    }
}
