<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;

trait FirewallTrait
{
    /**
     * @param Dispatcher $dispatcher
     */
    private function getReturnedValueFor(
        DiInterface $di,
        $dispatcher,
        string $controllerName,
        string $actionName,
        $role,
        array $params = null,
        string $moduleName = null
    ) {
        $dispatcher->setReturnedValue(null);

        $this->changeRole($di, $role);

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

    private function changeRole(DiInterface $di, $role)
    {
        $di->set(
            'myrole',
            function () use ($role) {
                return $role;
            }
        );

        Di::setDefault($di);
    }

    private function getMicroValueFor(DiInterface $di, Micro $micro, $url, $role)
    {
        $this->changeRole($di, $role);

        $di->remove('response');

        $di->setShared(
            'response',
            new Response()
        );

        $micro->setDI($di);

        return $micro->handle($url);
    }
}
