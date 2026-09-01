<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Modules\Frontend;

use Phalcon\Di\DiInterface;
use Phalcon\Mvc\ModuleDefinitionInterface;
use Phalcon\Mvc\View;

class Module implements ModuleDefinitionInterface
{
    public function registerAutoloaders(?DiInterface $di = null)
    {
    }

    public function registerServices(DiInterface $di)
    {
        $di->set(
            'view',
            function () {
                $view = new View();
                $view->setViewsDir(__DIR__ . '/views/');

                return $view;
            }
        );
    }
}
