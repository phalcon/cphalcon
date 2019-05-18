
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate;

use Phalcon\Config;
use Phalcon\Helper\Arr;
use Phalcon\Translate\InterpolatorFactory;

class TranslateFactory
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
     * @var InterpolatorFactory
     */
    private interpolator;

    /**
     * AdapterFactory constructor.
     */
    public function __construct(<InterpolatorFactory> interpolator, array! services = [])
    {
        var adapters, name, service;

        let this->interpolator = interpolator;

        let adapters = [
            "csv"     : "\\Phalcon\\Translate\\Adapter\\Csv",
            "gettext" : "\\Phalcon\\Translate\\Adapter\\Gettext",
            "array"   : "\\Phalcon\\Translate\\Adapter\\NativeArray"
        ];

        let adapters = array_merge(adapters, services);

        for name, service in adapters {
            let this->mapper[name] = service;
            unset this->services[name];
        }
    }

    /**
     * Factory to create an instace from a Config object
     */
    public function load(var config) -> var
    {
        var name, options;

        if typeof config == "object" && config instanceof Config {
            let config = config->toArray();
        }

        if unlikely typeof config !== "array" {
            throw new Exception(
                "Config must be array or Phalcon\\Config object"
            );
        }

        if unlikely !isset config["adapter"] {
            throw new Exception(
                "You must provide 'adapter' option in factory config parameter."
            );
        }

        let name    = config["adapter"],
            options = Arr::get(config, "options", []);

        return this->newInstance(name, options);
    }

    /**
     * Create a new instance of the adapter
     */
    public function newInstance(string! name, array! options = []) -> <AbstractAdapter>
    {
        var definition;

        if !isset this->mapper[name] {
            throw new Exception("Service " . name . " is not registered");
        }

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}(this->interpolator, options);
        }

        return this->services[name];
    }
}
