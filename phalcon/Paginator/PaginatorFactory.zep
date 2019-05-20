
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator;

use Phalcon\Paginator\Adapter\AbstractAdapter;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;

class PaginatorFactory extends AbstractFactory
{
    /**
     * AdapterFactory constructor.
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * Factory to create an instace from a Config object
     *
     *<code>
     * use Phalcon\Paginator\PaginatorFactory;
     *
     * $builder = $this
     *      ->modelsManager
     *      ->createBuilder()
     *      ->columns("id, name")
     *      ->from("Robots")
     *      ->orderBy("name");
     *
     * $options = [
     *     "builder" => $builder,
     *     "limit"   => 20,
     *     "page"    => 1,
     *     "adapter" => "queryBuilder",
     * ];
     *
     * $paginator = (new PaginatorFactory())->load($options);
     *</code>
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
                this->services[name] = new {definition}(options);
        }

        return this->services[name];
    }

    protected function getAdapters() -> array
    {
        return [
            "model"        : "\\Phalcon\\Paginator\\Adapter\\Model",
            "nativeArray"  : "\\Phalcon\\Paginator\\Adapter\\NativeArray",
            "queryBuilder" : "\\Phalcon\\Paginator\\Adapter\\QueryBuilder"
        ];
    }
}
