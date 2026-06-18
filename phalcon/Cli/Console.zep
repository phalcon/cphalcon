
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli;

use Closure;
use Phalcon\Application\AbstractApplication;
use Phalcon\Cli\Console\Exceptions\ContainerRequired;
use Phalcon\Cli\Console\Exceptions\InvalidModuleDefinition;
use Phalcon\Cli\Console\Exceptions\ModuleDefinitionPathNotFound;
use Phalcon\Cli\Router\Route;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\ModuleDefinitionInterface;

/**
 * This component allows to create CLI applications using Phalcon
 */
class Console extends AbstractApplication
{
    /**
     * @var array|string
     */
    protected arguments = [];

    /**
     * @var array
     */
    protected options = [];

    /**
     * Handle the whole command-line tasks
     */
    public function handle(array arguments = null)
    {
        var className, dispatcher, module, moduleName,
            moduleObject, path, router, task;

        if this->container === null {
            throw new ContainerRequired();
        }

        /**
         * Call boot event, this allows the developer to perform initialization
         * actions
         */
        if this->eventsManager !== null {
            if this->eventsManager->fire("console:boot", this) === false {
                return false;
            }
        }

        let router = <Router> this->container->getShared("router");

        if !count(arguments) && this->arguments {
            router->handle(this->arguments);
        } else {
            router->handle(arguments);
        }

        /**
         * If the router does not return a valid module we use the default module
         */
        let moduleName = router->getModuleName();

        if !moduleName {
            let moduleName = this->defaultModule;
        }

        if moduleName {
            if this->eventsManager !== null {
                if this->eventsManager->fire("console:beforeStartModule", this, moduleName) === false {
                    return false;
                }
            }

            /**
             * Gets the module definition
             */
            let module = this->getModule(moduleName);

            /**
             * A module definition must be an array or an object
             */
            if unlikely (typeof module !== "array" && typeof module !== "object") {
                throw new InvalidModuleDefinition(
                    moduleName,
                    "The module definition must be an array or an object"
                );
            }

            /**
             * An array module definition contains a path to a module
             * definition class
             */
            if typeof module === "array" {
                /**
                 * Class name used to load the module definition
                 */
                if !fetch className, module["className"] {
                    let className = "Module";
                }

                /**
                 * If developer specify a path try to include the file
                 */
                if fetch path, module["path"] {
                    if unlikely !file_exists(path) {
                        throw new ModuleDefinitionPathNotFound(path);
                    }

                    if !class_exists(className, false) {
                        require_once path;
                    }
                }

                let moduleObject = <ModuleDefinitionInterface> this->container->get(className);

                /**
                 * 'registerAutoloaders' and 'registerServices' are
                 * automatically called
                 */
                moduleObject->registerAutoloaders(this->container);
                moduleObject->registerServices(this->container);
            } else {
                /**
                 * A module definition object, can be a Closure instance
                 */
                if unlikely !(module instanceof Closure) {
                    throw new InvalidModuleDefinition(
                        moduleName,
                        "The module definition object must be a Closure"
                    );
                }

                let moduleObject = call_user_func_array(
                    module,
                    [
                        this->container
                    ]
                );
            }

            /**
             * The "afterStartModule" event is fired once the module has
             * started. Unlike Phalcon\Mvc\Application - where the return value
             * is a notification only - Console honors a `false` return and
             * aborts handling. This divergence is retained for backward
             * compatibility and is unified in the next major version.
             */
            if this->eventsManager !== null {
                if this->eventsManager->fire("console:afterStartModule", this, moduleObject) === false {
                    return false;
                }
            }

        }

        let dispatcher = <Dispatcher> this->container->getShared("dispatcher");

        dispatcher->setModuleName(moduleName);
        dispatcher->setTaskName(router->getTaskName());
        dispatcher->setActionName(router->getActionName());
        dispatcher->setParams(router->getParameters());
        dispatcher->setOptions(this->options);

        if this->eventsManager !== null {
            if this->eventsManager->fire("console:beforeHandleTask", this, dispatcher) === false {
                return false;
            }
        }

        let task = dispatcher->dispatch();

        if this->eventsManager !== null {
            this->eventsManager->fire("console:afterHandleTask", this, task);
        }

        return task;
    }

    /**
     * Set an specific argument
     */
    public function setArgument(array! arguments = null, bool! str = true, bool! shift = true) -> <static>
    {
        var arg, pos, args, opts, handleArgs;

        let args = [],
            opts = [],
            handleArgs = [];

        if shift && count(arguments) {
            array_shift(arguments);
        }

        for arg in arguments {
            if typeof arg === "string" {
                if strncmp(arg, "--", 2) == 0 {
                    let pos = strpos(arg, "=");

                    if pos {
                        let opts[trim(substr(arg, 2, pos - 2))] = trim(substr(arg, pos + 1));
                    } else {
                        let opts[trim(substr(arg, 2))] = true;
                    }
                } else {
                    if strncmp(arg, "-", 1) == 0 {
                        let opts[substr(arg, 1)] = true;
                    } else {
                        let args[] = arg;
                    }
                }
            } else {
                let args[] = arg;
            }
        }

        if str {
            let this->arguments = implode(
                Route::getDelimiter(),
                args
            );
        } else {
            if count(args) {
                let handleArgs["task"] = array_shift(args);
            }

            if count(args) {
                let handleArgs["action"] = array_shift(args);
            }

            if count(args) {
                let handleArgs = array_merge(handleArgs, args);
            }

            let this->arguments = handleArgs;
        }

        let this->options = opts;

        return this;
    }
}
