<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Support\Modules\Backend;

use Phalcon\Di\DiInterface;
use Phalcon\Autoload\Loader;
use Phalcon\Mvc\ModuleDefinitionInterface;
use Phalcon\Mvc\View;
use Phalcon\Talon\Talon;

/**
 * \Phalcon\Tests\Support\Modules\Backend\Module
 * Backend Module
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          https://www.phalcon.io
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 */
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

                $view->setViewsDir(
                    Talon::settings()->supportPath('assets/modules/backend/views/')
                );

                return $view;
            }
        );

        /**
         * @var Loader $loader
         */
        $loader = new Loader();
        $loader->setNamespaces(
            [
                'Phalcon\Tests\Support\Modules\Backend\Tasks' =>
                    Talon::settings()->supportPath('assets/modules/backend/tasks/')
            ]
        );
        $loader->register();

        $di->set('loader', $loader);
    }
}
