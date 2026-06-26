
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth;

use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Auth\Adapter\AdapterLocator;
use Phalcon\Auth\Exceptions\UnknownAdapter;
use Phalcon\Auth\Exceptions\UnknownGuard;
use Phalcon\Auth\Guard\GuardLocator;
use Phalcon\Auth\Internal\ContainerResolver;
use Phalcon\Auth\Internal\Options;
use Phalcon\Config\ConfigInterface;
use Phalcon\Contracts\Auth\Access\Access;
use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\Guard\Guard;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Di\DiInterface;
use Phalcon\Encryption\Security;

/**
 * Single entry-point factory that builds a fully wired Phalcon\Auth\Manager
 * from a config tree. Framework-shared services (RequestInterface,
 * CookiesInterface, SessionManagerInterface) are resolved from the injected
 * container so the manager wires against the real application singletons,
 * not separately constructed copies.
 *
 *  [
 *      'guards' => [
 *          'web' => [
 *              'type'    => 'session',
 *              'default' => true,
 *              'adapter' => [
 *                  'name'    => 'model',
 *                  'options' => [
 *                      'model' => User::class
 *                  ],
 *              ],
 *              'options' => [],
 *          ],
 *          'api' => [
 *              'type'    => 'token',
 *              'adapter' => [
 *                  'name'    => 'model',
 *                  'options' => [
 *                      'model' => User::class
 *                  ]
 *              ],
 *              'options' => [
 *                  'inputKey'   => 'api_token',
 *                  'storageKey' => 'api_token'
 *              ],
 *          ],
 *      ],
 *      'access' => [
 *          'auth'  => \Phalcon\Auth\Access\Auth::class,
 *          'guest' => \Phalcon\Auth\Access\Guest::class,
 *      ],
 *  ]
 *
 * @phpstan-type GuardConfig array{
 *     type: string,
 *     default?: bool,
 *     adapter: array{name: string, options?: array<string, mixed>},
 *     options?: array<string, mixed>,
 * }
 *
 * @phpstan-type AuthConfig array{
 *     guards?: array<string, GuardConfig>,
 *     access?: array<string, class-string<Access>>,
 * }
 */
class ManagerFactory
{
    /**
     * @var AccessLocator
     */
    protected accessLocator;
    /**
     * @var AdapterLocator
     */
    protected adapterLocator;
    /**
     * @var Collection|DiInterface
     */
    protected container;
    /**
     * @var GuardLocator
     */
    protected guardLocator;
    /**
     * @var Security
     */
    protected hasher;

    public function __construct(
        <Security> hasher,
        var container,
        <AdapterLocator> adapterLocator = null,
        <GuardLocator> guardLocator = null,
        <AccessLocator> accessLocator = null
    ) {
        ContainerResolver::ensureContainer(container);

        let this->container      = container;
        let this->hasher         = hasher;
        let this->adapterLocator = adapterLocator !== null ? adapterLocator : new AdapterLocator(container);
        let this->guardLocator   = guardLocator !== null   ? guardLocator   : new GuardLocator(container);
        let this->accessLocator  = accessLocator !== null  ? accessLocator  : new AccessLocator(container);
    }

    /**
     * @phpstan-param AuthConfig|ConfigInterface $config
     *
     * @throws Exception
     */
    public function load(var config) -> <Manager>
    {
        if (typeof config !== "array" && !(config instanceof ConfigInterface)) {
            throw new \TypeError("The parameter must be an array or instance of ConfigInterface");
        }

        var accessList, adapter, gconf, guard, guards, manager, name;

        if (typeof config === "object" && config instanceof ConfigInterface) {
            /** @var AuthConfig $config */
            let config = config->toArray();
        }

        let manager = new Manager(this->accessLocator);

        /** @var array<string, GuardConfig> $guards */
        let guards = isset(config["guards"]) ? config["guards"] : [];

        for name, gconf in guards {
            let adapter = this->buildAdapter(
                this->adapterLocator,
                Options::requireArray(gconf, "adapter", "guard '" . name . "'")
            );
            let guard   = this->buildGuard(
                this->guardLocator,
                Options::requireString(gconf, "type", "guard '" . name . "'"),
                adapter,
                isset(gconf["options"]) ? gconf["options"] : []
            );

            manager->addGuard(
                (string) name,
                guard,
                (bool) (isset(gconf["default"]) ? gconf["default"] : false)
            );
        }

        let accessList = isset(config["access"]) ? config["access"] : [];
        if (!empty(accessList)) {
            manager->addAccessList(accessList);
        }

        return manager;
    }

    /**
     * @param array{name: string, options?: array<string, mixed>} $cfg
     *
     * @throws Exception
     */
    protected function buildAdapter(<AdapterLocator> locator, array cfg) -> <Adapter>
    {
        var className, name;

        let name = Options::requireString(cfg, "name", "adapter");

        if (!locator->has(name)) {
            throw new UnknownAdapter(name);
        }

        let className = locator->getClass(name);

        return {className}::fromOptions(
            this->hasher,
            isset(cfg["options"]) ? cfg["options"] : []
        );
    }

    /**
     * @param array<string, mixed> $options
     *
     * @throws Exception
     */
    protected function buildGuard(
        <GuardLocator> locator,
        string type,
        <Adapter> adapter,
        array options
    ) -> <Guard> {
        var className;

        if (!locator->has(type)) {
            throw new UnknownGuard(type);
        }

        let className = locator->getClass(type);

        return {className}::fromOptions(
            adapter,
            this-> container,
            options
        );
    }
}
