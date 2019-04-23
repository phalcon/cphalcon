
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Application\Exception;
use Phalcon\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;

/**
 * Phalcon\Application
 *
 * Base class for Phalcon\Cli\Console and Phalcon\Mvc\Application.
 */
abstract class Application extends Injectable implements EventsAwareInterface
{
    protected container;
    
    /**
     * @var string
     */
    protected defaultModule;

    protected eventsManager;

    /**
     * @var array
     */
    protected modules = [];

    /**
     * Phalcon\Application
     */
    public function __construct(<DiInterface> container = null) -> void
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
    public function getEventsManager() -> <ManagerInterface>
    {
        return this->eventsManager;
    }

    /**
     * Gets the module definition registered in the application via module name
     */
    public function getModule(string! name) -> array | object
    {
        var module;

        if !fetch module, this->modules[name] {
            throw new Exception(
                "Module '" . name . "' isn't registered in the application container"
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
     * Handles a request
     */
    abstract public function handle();

    /**
     * Register an array of modules present in the application
     *
     * <code>
     * $this->registerModules(
     *     [
     *         "frontend" => [
     *             "className" => "Multiple\\Frontend\\Module",
     *             "path"      => "../apps/frontend/Module.php",
     *         ],
     *         "backend" => [
     *             "className" => "Multiple\\Backend\\Module",
     *             "path"      => "../apps/backend/Module.php",
     *         ],
     *     ]
     * );
     * </code>
     */
    public function registerModules(array modules, bool merge = false) -> <Application>
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
    public function setDefaultModule(string! defaultModule) -> <Application>
    {
        let this->defaultModule = defaultModule;

        return this;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> <Application>
    {
        let this->eventsManager = eventsManager;

        return this;
    }
}
