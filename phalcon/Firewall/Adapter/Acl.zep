
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Firewall\Adapter;

use Phalcon\Acl\Adapter\AdapterInterface as AclAdapterInterface;
use Phalcon\Di;
use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Events\Event;
use Phalcon\Events\ManagerInterface;
use Phalcon\Firewall\Adapter\AbstractAdapter;
use Phalcon\Firewall\Exception;
use Phalcon\Mvc\DispatcherInterface;

/**
 * FirewallZ for Phalcon\Application which depends on acl and dispatcher
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
     * Property used for setting different key names in associated acl function than got from Binder
     */
    protected boundModelsKeyMap { get, set };

    /**
     * Dispatcher
     * @var mixed
     */
    protected dispatcher;

    /**
     * Parameter for using with multi module application
     * @var bool
     */
    protected multiModuleConfiguration = false;

    /**
     * Separator between module name and controller prefix
     * @var string
     */
    protected moduleSeparator = ":" { get, set };

    /**
     * Function returning string for role cache key
     * @var mixed
     */
    protected roleCacheCallback { get, set };


    /**
     * Phalcon\Firewall\Adapter\Acl constructor
     */
    public function __construct(string aclServiceName, array boundModelsKeyMap = null)
    {
        let this->aclServiceName    = aclServiceName,
            this->boundModelsKeyMap = boundModelsKeyMap;
    }

    public function afterBinding(<Event> event, <DispatcherInterface> dispatcher, var data)
    {
        let this->boundModels = dispatcher->getBoundModels(),
            this->dispatcher  = dispatcher;

        return this->handleDispatcher(dispatcher);
    }

    public function beforeExecuteRoute(<Event> event, <DispatcherInterface> dispatcher, var data)
    {
        let this->dispatcher = dispatcher;

        return this->handleDispatcher(dispatcher);
    }

    /**
     * Gets dispatcher
     */
    public function getDispatcher() -> <Dispatcher>
    {
        return this->dispatcher;
    }

    /**
     * Returns multiModuleConfiguration
     * @return bool
     */
    public function isMultiModuleConfiguration() -> bool
    {
        return this->multiModuleConfiguration;
    }

    /**
     * Sets multiModuleConfiguration
     */
    public function useMultiModuleConfiguration(bool multiModuleConfiguration)
    {
        let this->multiModuleConfiguration = multiModuleConfiguration;

        return this;
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
            let explodedKey[0] = this->activeRole;
            let key = join("!", explodedKey);
        }

        /**
         * If there is original values from binding then use it first
         */
        if !empty originalValues {
            let originalKeysJoin = join("!", originalValues),
                keyWithValues    = key . "!" . originalKeysJoin . roleCacheKey,
                access           = parent::getAccessFromCache(keyWithValues);

            if access !== null {
                return null;
            }

            /**
             * Try role-component-*
             */

            let access = parent::getAccessFromCache(
                explodedKey[0] . "!" . explodedKey[1] . "!*!" . originalKeysJoin . roleCacheKey
            );

            if access !== null {
                return access;
            }

            /**
             * Try role-*-*
             */

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
            return null;
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

    protected function handleDispatcher(<DispatcherInterface> dispatcher)
    {
        var acl, aclAccess, aclRole, aclServiceName, actionName, boundModel,
            boundModelKey, boundModelKeyMap, boundModels, boundModelsKeyMap,
            cacheKey, componentName, container, controllerName, defaultAccess,
            modelBinder, moduleName, moduleSeparator, originalValues, parameters,
            roleCacheKey, roleCacheCallback, role,value;

        let container = dispatcher->getDI();
        if typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound("the ACL service")
            );
        }

        let defaultAccess     = (bool) this->defaultAccess,
            parameters        = [],
            controllerName    = get_class(dispatcher->getActiveController()),
            boundModels       = this->boundModels,
            boundModelsKeyMap = this->boundModelsKeyMap;

        if !this->multiModuleConfiguration {
            let componentName = ucfirst(
                dispatcher->getControllerName()
            );
        } else {
            let moduleSeparator = this->moduleSeparator,
                moduleName      = dispatcher->getModuleName(),
                componentName   = moduleName . moduleSeparator . ucfirst(dispatcher->getControllerName());
        }

        let actionName = dispatcher->getActionName();

        if this->activeRole == null || this->alwaysResolvingRole {
            let this->activeRole     = null,
                this->activeIdentity = null;

            this->callRoleCallback(container);
        }

        let aclRole = this->activeRole;

        // handle role as object
        if typeof this->activeIdentity == "object" {
            let role = this->activeIdentity;
        } else {
            let role = aclRole;
        }

        if typeof aclRole != "string" {
            throw new Exception(
                "When using ACL service as firewall configuration you can " .
                "pass role only as string or object implementing 'Phalcon\\Acl\\RoleAware'."
            );
        }

        let cacheKey    = aclRole . "!" . componentName . "!" . actionName,
            modelBinder = dispatcher->getModelBinder();
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
                throw new Exception("Role " . aclRole . " doesn't exist in ACL");
            }

            // if component doesn't exist check against firewall defaultAccess
            if !acl->isComponent(componentName) {
                let value = this->fireEventOrThrowException(
                    aclRole,
                    actionName,
                    controllerName,
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

        let value = this->fireEventOrThrowException(aclRole, actionName, controllerName, aclAccess);

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
         * We are not saving info about inherited role, if access was got from inherited role, save it as an actual role to keep things simple
         */
        if explodedKey[0] != activeRole {
            let explodedKey[0] = activeRole,
                key            = join("!", explodedKey);
        }

        parent::saveAccessInCache(key, access);
    }
}
