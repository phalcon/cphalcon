<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Di;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;

trait FirewallTrait
{
    /**
     * @param Di          $di
     * @param Dispatcher  $dispatcher
     * @param string      $controllerName
     * @param string      $actionName
     * @param string      $roleName
     * @param array|null  $params
     * @param string|null $moduleName
     */
    private function getReturnedValueFor(
        $di,
        $dispatcher,
        $controllerName,
        $actionName,
        $roleName,
        $params = null,
        $moduleName = null
    ) {
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
