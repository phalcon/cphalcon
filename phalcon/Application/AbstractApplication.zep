
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Application;

use Closure;
use Phalcon\Application\Exceptions\ModuleNotRegistered;
use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Events\Traits\EventsAwareTrait;

/**
 * Base class for Phalcon\Cli\Console and Phalcon\Mvc\Application.
 *
 * @phpstan-type TModule array{
 *     string: array{
 *          className: string,
 *          path: string,
 *     }
 * }
 */
abstract class AbstractApplication extends Injectable implements EventsAwareInterface
{
    use EventsAwareTrait;

    protected string defaultModule = "";

    /**
     * @var TModule[]
     */
    protected array modules = [];

    /**
     * AbstractApplication constructor.
     */
    public function __construct(<DiInterface> container = null)
    {
        if container !== null {
            let this->container = container;
        }
    }

    /**
     * Returns the default module name
     */
    public function getDefaultModule() -> string
    {
        return this->defaultModule;
    }

    /**
     * Gets the module definition registered in the application via module name
     *
     * @param string name
     *
     * @return TModule|Closure
     */
    public function getModule(string name) -> mixed
    {
        var module;

        if unlikely !fetch module, this->modules[name] {
            throw new ModuleNotRegistered(name);
        }

        return module;
    }

    /**
     * Return the modules registered in the application
     *
     * @return TModule[]
     */
    public function getModules() -> array
    {
        return this->modules;
    }

    /**
     * Register an array of modules present in the application
     *
     * ```php
     * $this->registerModules(
     *     [
     *         "frontend" => [
     *             "className" => \Multiple\Frontend\Module::class,
     *             "path"      => "../apps/frontend/Module.php",
     *         ],
     *         "backend" => [
     *             "className" => \Multiple\Backend\Module::class,
     *             "path"      => "../apps/backend/Module.php",
     *         ],
     *     ]
     * );
     * ```
     *
     * @param TModule[] $modules
     */
    public function registerModules(
        array modules,
        bool merge = false
    ) -> <static> {
        if merge {
            let this->modules = array_merge(this->modules, modules);
        } else {
            let this->modules = modules;
        }

        return this;
    }

    /**
     * Sets the module name to be used if the router does not return a valid
     * module
     */
    public function setDefaultModule( string defaultModule) -> <static>
    {
        let this->defaultModule = defaultModule;

        return this;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        this->getDI()->set("eventsManager", eventsManager);

        let this->eventsManager = eventsManager;
    }
}
