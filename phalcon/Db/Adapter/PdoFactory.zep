
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Adapter;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;

class PdoFactory extends AbstractFactory
{
    /**
     * Constructor
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * Factory to create an instace from a Config object
     */
    public function load(var config) ->  <AdapterInterface>
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
     */
    public function newInstance(string! name, array! options = []) ->  <AdapterInterface>
    {
        var definition;

        this->checkService(name);

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = create_instance_params(
                    definition,
                    [
                        options
                    ]
                );
        }

        return this->services[name];
    }

    /**
     * Returns the available adapters
     */
    protected function getAdapters() -> array
    {
        return [
            "mysql"      : "Phalcon\\Db\\Adapter\\Pdo\\Mysql",
            "postgresql" : "Phalcon\\Db\\Adapter\\Pdo\\Postgresql",
            "sqlite"     : "Phalcon\\Db\\Adapter\\Pdo\\Sqlite"
        ];
    }
}
