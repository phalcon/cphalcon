
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Application;

use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;

/**
 * Base class for Phalcon\Cli\Console and Phalcon\Mvc\Application.
 */
abstract class AbstractApplication extends Injectable implements EventsAwareInterface
{
    /**
     * @var DiInterface|null
     */
    protected container = null;

    /**
     * @var string|null
     */
    protected defaultModule = null;

    /**
     * @var ManagerInterface|null
     */
    protected eventsManager = null;

    /**
     * @var array
     */
    protected modules = [];

    /**
     * Phalcon\AbstractApplication constructor
     */
    public function __construct(<DiInterface> container = null)
    {
        if typeof container == "object" {
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
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Gets the module definition registered in the application via module name
     *
     * @param string name
     *
     * @return array|mixed
     */
    public function getModule(string! name) -> array | object
    {
        var module;

        if unlikely !fetch module, this->modules[name] {
            throw new Exception(
                "Module '" . name . "' is not registered in the application container"
            );
        }

        return module;
    }

    /**
     * Return the modules registered in the application
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
     */
    public function registerModules(array modules, bool merge = false) -> <AbstractApplication>
    {
        if merge {
            let this->modules = array_merge(this->modules, modules);
        } else {
            let this->modules = modules;
        }

        return this;
    }

    /**
     * Sets the module name to be used if the router doesn't return a valid module
     */
    public function setDefaultModule(string! defaultModule) -> <AbstractApplication>
    {
        let this->defaultModule = defaultModule;

        return this;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }
}
