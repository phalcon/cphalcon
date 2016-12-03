<?php
/**
 * Created by PhpStorm.
 * User: User
 * Date: 2017-01-19
 * Time: 13:50
 */

namespace Phalcon\Test\Unit\Firewall\Helper;


use Phalcon\Di;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;

trait FirewallTrait
{
    /**
     * @param $di
     * @param Dispatcher $dispatcher
     * @param $controllerName
     * @param $actionName
     * @param $roleName
     * @param array $params
     * @param string $moduleName
     *
     * @return mixed
     */
    private function getReturnedValueFor($di, $dispatcher, $controllerName, $actionName, $roleName, $params = null, $moduleName = null)
    {
        $dispatcher->setReturnedValue(null);
        $this->changeRole($di, $roleName);
        $dispatcher->setControllerName($controllerName);
        $dispatcher->setActionName($actionName);
        if (!empty($moduleName)) {
            $dispatcher->setModuleName($moduleName);
        }
        if (!empty($params)) {
            $dispatcher->setParams($params);
        }
        $dispatcher->setDI($di);
        $dispatcher->dispatch();
        return $dispatcher->getReturnedValue();
    }

    /**
     * @param Di $di
     * @param $role
     */
    private function changeRole($di, $role)
    {
        $di->set('myrole', function () use ($role) {
            return $role;
        });
        Di::setDefault($di);
    }

    /**
     * @param Di $di
     * @param Micro $micro
     * @param string $url
     * @param string $role
     * @return mixed
     */
    private function getMicroValueFor($di, $micro, $url, $role)
    {
        $this->changeRole($di, $role);
        $di->remove('response');
        $di->setShared('response', new Response());
        $micro->setDI($di);
        return $micro->handle($url);
    }
}
