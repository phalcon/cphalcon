
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Firewall\Adapter;

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Events\Event;
use Phalcon\Events\ManagerInterface;
use Phalcon\Firewall\Adapter\AbstractAdapter;
use Phalcon\Firewall\Exception;
use Phalcon\Mvc\DispatcherInterface;
use ReflectionClass;

/**
 * Firewall which depends on annotations and dispatcher
 */
class Annotations extends AbstractAdapter
{
    /**
     * Number of active active arguments in active annotation
     * @var int
     */
    protected activeArgumentsNumber = 0;

    /**
     * Adapter for annotations
     * @var mixed
     */
    protected annotationsAdapter { get, set };

    /**
     * Dispatcher
     * @var mixed
     */
    protected dispatcher;

    /**
     * Role for which access was granted
     */
    protected resolvedRole;

    /**
     * Phalcon\Firewall\Adapter\Annotations constructor
     */
    public function __construct(<AdapterInterface> annotationsAdapter)
    {
        let this->annotationsAdapter = annotationsAdapter;
    }

    public function beforeExecuteRoute(<Event> event, <DispatcherInterface> dispatcher, var data)
    {
        var access, actionName, cacheKey, container, controllerClass,
            controllerName, defaultAccess, eventsManager, role, singleRole,
            value;

        let this->activeArgumentsNumber = 0;

        let this->dispatcher   = dispatcher,
            defaultAccess      = (bool) this->defaultAccess,
            eventsManager      = <ManagerInterface> this->eventsManager,
            controllerName     = dispatcher->getControllerName(),
            controllerClass    = dispatcher->getControllerClass(),
            actionName         = dispatcher->getActionName(),
            this->resolvedRole = null,
            container          = dispatcher->getDI();

        if this->activeRole == null || this->alwaysResolvingRole {
            let this->activeRole     = null,
                this->activeIdentity = null;

            this->callRoleCallback(container);
        }

        let role = this->activeRole;
        if typeof role == "array" {
            for singleRole in role {
                let cacheKey = singleRole . "!" . controllerName . "!" . actionName,
                    access   = this->getAccessFromCache(cacheKey);

                if typeof access == "boolean" {
                    break;
                }
            }
        } else {
            let cacheKey = role . "!" . controllerName . "!" . actionName,
                access   = this->getAccessFromCache(cacheKey);
        }

        if typeof role != "string" && typeof role != "array" {
            throw new Exception(
                "When using firewall based on annotations you must pass " .
                "role as string, array or object implementing 'RoleAware'."
            );
        }

        if this->annotationsAdapter == null {
            throw new Exception(
                "You need to set annotations adapter for firewall based " .
                "on annotations configurator to work"
            );
        }

        if typeof eventsManager == "object" {
            eventsManager->fire("firewall:beforeCheck", this);
        }

        if typeof access != "boolean" {
            let access = this->checkControllerAnnotationAccess(
                controllerClass,
                controllerName,
                role
            );

            if typeof access != "boolean" {
                let access = this->checkActionAnnotationAccess(
                    controllerClass,
                    controllerName,
                    actionName,
                    role
                );
            }

            if typeof access != "boolean" {
                let access = defaultAccess;

                if typeof role == "array" {
                    for singleRole in role {
                        this->saveAccessInCache(
                            singleRole . "!" . controllerName . "!" . actionName,
                            access
                        );
                    }
                } else {
                    this->saveAccessInCache(
                        role . "!" . controllerName . "!" . actionName,
                        access
                    );
                }
            }
        }

        let value = this->fireEventOrThrowException(
            role,
            actionName,
            controllerName,
            access
        );

        if value === false {
            return false;
        }
    }

    /**
     * Gets dispatcher
     */
    public function getDispatcher() -> <Dispatcher>
    {
        return this->dispatcher;
    }

    protected function checkControllerAnnotationAccess(string controllerClass, string controllerName, var role)
    {
        var annotationsAdapter, reflector, annotations, access, singleRole,
            resolvedRole;

        let annotationsAdapter = this->annotationsAdapter,
            reflector          = annotationsAdapter->get(controllerClass),
            annotations        = reflector->getClassAnnotations(),
            access             = this->checkAnnotations(annotations, role);

        if typeof access == "boolean" {
            if this->activeArgumentsNumber > 0 {
                let resolvedRole = this->resolvedRole;

                if typeof resolvedRole == "array" {
                    for singleRole in resolvedRole {
                        this->saveAccessInCache(
                            singleRole . "!" . controllerName . "!*",
                            access
                        );
                    }
                } else {
                    this->saveAccessInCache(
                        resolvedRole . "!" . controllerName . "!*",
                        access
                    );
                }
            } else {
                this->saveAccessInCache(
                    "*!" . controllerName . "!*",
                    access
                );
            }
        }

        return access;
    }

    protected function checkAnnotations(var annotations, var role)
    {
        var returnAllow;

        if !empty annotations {
            if annotations->has("Allow") {
                let returnAllow = this->handleAnnotation(
                    annotations->get("Allow"),
                    true,
                    role
                );

                if typeof returnAllow == "boolean" {
                    return returnAllow;
                }
            }

            if annotations->has("Deny") {
                let returnAllow = this->handleAnnotation(
                    annotations->get("Deny"),
                    false,
                    role
                );

                if typeof returnAllow == "boolean" {
                    return returnAllow;
                }
            }
        }

        return null;
    }

    protected function checkActionAnnotationAccess(
        string controllerClass,
        string controllerName,
        string actionName,
        var role
    )
    {
        var annotationsAdapter, annotations, access, singleRole, resolvedRole;

        let annotationsAdapter = this->annotationsAdapter,
            annotations        = annotationsAdapter->getMethod(controllerClass, actionName . "Action");

        let access = this->checkAnnotations(annotations, role);

        if typeof access == "boolean" {
            if this->activeArgumentsNumber > 0 {
                let resolvedRole = this->resolvedRole;

                if typeof resolvedRole == "array" {
                    for singleRole in resolvedRole {
                        this->saveAccessInCache(
                            singleRole . "!" . controllerName . "!" . actionName,
                            access
                        );
                    }
                } else {
                    this->saveAccessInCache(
                        resolvedRole . "!" . controllerName . "!" . actionName,
                        access
                    );
                }
            } else {
                this->saveAccessInCache(
                    "*!" . controllerName . "!" . actionName,
                    access
                );
            }
        }

        return access;
    }

    protected function getAccessFromCache(
        string! key,
        array originalValues = null,
        string roleCacheKey = null
    ) -> bool | null
    {
        var explodedKey, access;

        let access = parent::getAccessFromCache(key);

        if access !== null {
            return access;
        }

        let explodedKey = explode("!", key);

        /**
         * Try role-component-*
         */
        let access = parent::getAccessFromCache(
            explodedKey[0] . "!" . explodedKey[1] . "!*"
        );

        if access !== null {
            return access;
        }

        /**
         * Try *-component-action
         */

        let access = parent::getAccessFromCache(
            "*!" . explodedKey[1] . "!" . explodedKey[2]
        );

        if access !== null {
            return access;
        }

        /**
         * Try *-component-*
         */

        let access = parent::getAccessFromCache(
            "*!" . explodedKey[1] . "!*"
        );

        return access;
    }

    protected function handleAnnotation(var annotation, bool access, var role)
    {
        var numberArguments, annotationRoles, roleIntersect;

        let numberArguments             = annotation->numberArguments(),
            this->activeArgumentsNumber = numberArguments;

        if numberArguments === 1 {
            let annotationRoles = annotation->getArguments()[0];

            if typeof annotationRoles == "array" {
                if typeof role == "string" && in_array(role, annotationRoles) {
                    let this->resolvedRole = role;

                    return access;
                } elseif typeof role == "array" {
                    let roleIntersect = array_intersect(role, annotationRoles);

                    if (bool) roleIntersect {
                        let this->resolvedRole = roleIntersect;

                        return access;
                    }
                } elseif access == false {
                    let this->resolvedRole = role;

                    return true;
                }

                return null;
            } elseif typeof annotationRoles == "string" {
                if typeof role == "string" && annotationRoles == role {
                    let this->resolvedRole = role;

                    return access;
                } elseif typeof role == "array" && in_array(annotationRoles, role) {
                    let this->resolvedRole = annotationRoles;

                    return access;
                } elseif access == false {
                    let this->resolvedRole = role;

                    return true;
                }

                return null;
            } else {
                throw new Exception(
                    "Allowed or denied role must be provided as string or array of roles."
                );
            }
        } elseif numberArguments === 0 {
            let this->resolvedRole = role;

            return access;
        } else {
            throw new Exception(
                "Allow or deny annotation expect one or none arguments"
            );
        }
    }
}
