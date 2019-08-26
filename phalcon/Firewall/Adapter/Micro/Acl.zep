
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Firewall\Adapter\Micro;

use Phalcon\Acl\Adapter\AdapterInterface as AclAdapterInterface;
use Phalcon\Di;
use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Di\DiInterface;
use Phalcon\Events\Event;
use Phalcon\Events\ManagerInterface;
use Phalcon\Firewall\Adapter\AbstractAdapter;
use Phalcon\Firewall\Exception;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Model\BinderInterface;
use Phalcon\Mvc\Router;

/**
 * Firewall for Phalcon\Mvc\Micro which depends on ACL
 */
class Acl extends AbstractAdapter
{
    /**
     * Acl service name
     * @var string
     */
    protected aclServiceName { get, set };

    /**
     * Bound models
     * @var array
     */
    protected boundModels;

    /**
     * Property used for setting different key names in associated ACL function
     * than got from Binder
     */
    protected boundModelsKeyMap { get, set };

    /**
     * Component name used to acquire access, be default it's Micro
     * @var string
     */
    protected componentName = "Micro" { get, set };

    /**
     * Micro object
     * @var mixed
     */
    protected micro;

    /**
     * Function returning string for role cache key
     * @var mixed
     */
    protected roleCacheCallback { get, set };

    /**
     * Router object
     * @var mixed
     */
    protected router;

    /**
     * By default using route names which are required, you can change it to
     * false to use route patterns
     * @var bool
     */
    protected routeNameConfiguration = true { set };

    public function __construct(string! aclServiceName, array! boundModelsKeyMap = null)
    {
        let this->aclServiceName    = aclServiceName,
            this->boundModelsKeyMap = boundModelsKeyMap;
    }

    public function afterBinding(<Event> event, <Micro> micro, var data)
    {
        let this->boundModels = micro->getBoundModels(),
            this->router      = micro->getRouter(),
            this->micro       = micro;

        return this->handleRouter(micro);
    }

    public function beforeExecuteRoute(<Event> event, <Micro> micro, var data)
    {
        let this->router = micro->getRouter(),
            this->micro  = micro;

        return this->handleRouter(micro);
    }

    /**
     * Gets micro
     */
    public function getMicro() -> <Micro>
    {
        return this->micro;
    }

    /**
     * Gets route name configuration
     */
    public function isRouteNameConfiguration() -> bool
    {
        return this->routeNameConfiguration;
    }

    /**
     * Fires event or throwing exception
     */
    protected function fireEventOrThrowException(
        var role,
        string actionName,
        string controllerName,
        bool access
    )
    {
        var eventsManager, roleName;

        if access {
            if typeof eventsManager == "object" {
                eventsManager->fire("firewall:afterCheck",this);
            }
        } else {
            if typeof role == "array" {
                let roleName = implode(", ",role);
            } else {
                let roleName = role;
            }

            if this->routeNameConfiguration {
                return this->throwFirewallException(
                    "Role name " . roleName . " doesn't have access to route called " . actionName,
                    403
                );
            } else {
                return this->throwFirewallException(
                    "Role name " . roleName . " doesn't have access to route with pattern " . actionName,
                    403
                );
            }
        }
    }

    protected function getAccessFromCache(
        string! key,
        array originalValues = null,
        string roleCacheKey = null
    ) -> bool | null
    {
        var explodedKey, access, keyWithValues, originalKeysJoin;

        if roleCacheKey != null {
            let roleCacheKey = "!" . roleCacheKey;
        }

        let explodedKey = explode("!", key);

        /**
         * If this is inherited role we change it to our active role to keep things simpler
         */
        if explodedKey[0] != this->activeRole {
            let explodedKey[0] = this->activeRole,
                key            = join("!", explodedKey);
        }

        /**
         * If there is original values from binding then use it first
         */
        if !empty originalValues {
            let originalKeysJoin = join("!", originalValues),
                keyWithValues    = key . "!" . originalKeysJoin . roleCacheKey,
                access           = parent::getAccessFromCache(keyWithValues);

            if access !== null {
                return access;
            }

            let access = parent::getAccessFromCache(
                explodedKey[0] . "!" . explodedKey[1] . "!*!" . originalKeysJoin . roleCacheKey
            );

            if access !== null {
                return access;
            }

            let access = parent::getAccessFromCache(
                explodedKey[0] . "!*!*!" . originalKeysJoin . roleCacheKey
            );

            if access !== null {
                return access;
            }
        }

        let access = parent::getAccessFromCache(
            key . roleCacheKey
        );

        if access !== null {
            return access;
        }

        /**
         * Try role-component-*
         */

        let access = parent::getAccessFromCache(
            explodedKey[0] . "!" . explodedKey[1] . "!*" . roleCacheKey
        );

        if access !== null {
            return access;
        }

        /**
         * Try role-*-*
         */

        let access = parent::getAccessFromCache(
            explodedKey[0] . "!*!*" . roleCacheKey
        );

        return access;
    }

    protected function handleRouter(<Micro> micro)
    {
        var acl, aclAccess, aclRole, aclServiceName, actionName, boundModel,
            boundModelKey, boundModelKeyMap, boundModels, boundModelsKeyMap,
            cacheKey, componentName, container, defaultAccess, modelBinder,
            originalValues, parameters, role, roleCacheKey, roleCacheCallback,
            route, value;

        let container = micro->getDI();
        if typeof container != "object" {
            throw new Exception(
                "A dependency injector container is required to obtain ACL service"
            );
        }

        let defaultAccess     = (bool) this->defaultAccess,
            parameters        = [],
            route             = this->router->getMatchedRoute(),
            boundModels       = this->boundModels,
            boundModelsKeyMap = this->boundModelsKeyMap;

        if this->routeNameConfiguration {
            let actionName = route->getName();
        } else {
            let actionName = route->getPattern();
        }

        if this->activeRole == null || this->alwaysResolvingRole {
            let this->activeRole     = null,
                this->activeIdentity = null;

            this->callRoleCallback(container);
        }

        let aclRole       = this->activeRole,
            componentName = this->componentName;

        if typeof aclRole != "string" {
            throw new Exception(
                "When using ACL service as firewall configuration you can pass role only as string or object implementing 'Phalcon\\Acl\\RoleAware'."
            );
        }

        // handle role as object
        if typeof this->activeIdentity == "object" {
            let role = this->activeIdentity;
        } else {
            let role = aclRole;
        }

        let cacheKey    = aclRole . "!" . componentName . "!" . actionName,
            modelBinder = micro->getModelBinder();

        if modelBinder != null {
            let originalValues = modelBinder->getOriginalValues();
        }

        let roleCacheCallback = this->roleCacheCallback;

        if typeof role == "object" && roleCacheCallback != null {
            let roleCacheKey = {roleCacheCallback}(role);
        }

        let aclAccess = this->getAccessFromCache(cacheKey, originalValues, roleCacheKey);

        if aclAccess === null {
            let aclServiceName = this->aclServiceName,
                acl            = container->get(aclServiceName);

            if typeof acl != "object" || !(acl instanceof AclAdapterInterface) {
                throw new Exception(
                    "You need to add acl service to dependency injector " .
                    "container which is implementing 'Phalcon\\Acl\\Adapter\\AdapterInterface'"
                );
            }

            // check if role exist
            if !acl->isRole(aclRole) {
                throw new Exception(
                    "Role " . aclRole . " doesn't exist in ACL"
                );
            }

            // if component doesn't exist check against firewall defaultAccess
            if !acl->isComponent(componentName) {
                let value = this->fireEventOrThrowException(
                    aclRole,
                    actionName,
                    componentName,
                    defaultAccess
                );

                if roleCacheKey != null {
                    this->saveAccessInCache(
                        cacheKey . "!" . roleCacheKey,
                        defaultAccess
                    );
                } else {
                    this->saveAccessInCache(cacheKey, defaultAccess);
                }

                if value === false {
                    return false;
                }
            }

            if !empty boundModels {
                for boundModelKey, boundModel in boundModels {
                    if fetch boundModelKeyMap, boundModelsKeyMap[boundModelKey] {
                        let parameters[boundModelKeyMap] = boundModel;
                    } else {
                        let parameters[boundModelKey] = boundModel;
                    }
                }
            }

            if empty parameters {
                let aclAccess = acl->isAllowed(role, componentName, actionName);
            } else {
                let aclAccess = acl->isAllowed(role, componentName, actionName, parameters);
            }

            let cacheKey = acl->getActiveKey();

            if acl->getActiveFunction() != null {
                if !empty parameters && acl->getActiveFunctionCustomArgumentsCount() > 0 {
                    let cacheKey .= "!" . join("!", originalValues);
                }

                if roleCacheKey != null && typeof role == "object" {
                    let cacheKey .= "!" . roleCacheKey;
                }
            }

            this->saveAccessInCache(cacheKey, aclAccess);
        }

        let value = this->fireEventOrThrowException(
            aclRole,
            actionName,
            componentName,
            aclAccess
        );

        if value === false {
            return false;
        }
    }

    protected function saveAccessInCache(string! key, bool access) -> void
    {
        var explodedKey, activeRole;

        let explodedKey = explode("!", key),
            activeRole  = this->activeRole;

        /**
         * We are not saving info about inherited role, if access was got
         * from inherited role, save it as an actual role to keep things simple
         */
        if explodedKey[0] != activeRole {
            let explodedKey[0] = activeRole,
                key            = join("!", explodedKey);
        }

        parent::saveAccessInCache(key, access);
    }
}
