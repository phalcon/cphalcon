
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator;

use Phalcon\Paginator\Adapter\AdapterInterface;
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
     * Factory to create an instance from a Config object
     *
     *```php
     * use Phalcon\Paginator\PaginatorFactory;
     *
     * $builder = $this
     *      ->modelsManager
     *      ->createBuilder()
     *      ->columns("id, name")
     *      ->from(Robots::class)
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
     *```
     *
     * @param array|\Phalcon\Config = [
     *     'adapter' => 'queryBuilder',
     *     'limit' => 20,
     *     'page' => 1,
     *     'builder' => null
     * ]
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
     */
    public function newInstance(string! name, array! options = []) -> <AdapterInterface>
    {
        var definition;

        this->checkService(name);

        let definition = this->mapper[name];

        return create_instance_params(
            definition,
            [
                options
            ]
        );
    }

    protected function getAdapters() -> array
    {
        return [
            "model"        : "Phalcon\\Paginator\\Adapter\\Model",
            "nativeArray"  : "Phalcon\\Paginator\\Adapter\\NativeArray",
            "queryBuilder" : "Phalcon\\Paginator\\Adapter\\QueryBuilder"
        ];
    }
}
