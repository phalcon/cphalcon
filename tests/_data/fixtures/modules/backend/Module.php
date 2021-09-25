<?php

namespace Phalcon\Tests\Modules\Backend;

use Phalcon\Di\DiInterface;
use Phalcon\Loader;
use Phalcon\Mvc\ModuleDefinitionInterface;
use Phalcon\Mvc\View;
use function dataDir;

/**
 * \Phalcon\Tests\Modules\Backend\Module
 * Backend Module
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalcon.io
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
 * so that we can send you a copy immediately.
 */
class Module implements ModuleDefinitionInterface
{
    public function registerAutoloaders(DiInterface $di = null)
    {
    }

    public function registerServices(DiInterface $di)
    {
        $di->set(
            'view',
            function () {
                $view = new View();

                $view->setViewsDir(
                    dataDir('fixtures/modules/backend/views/')
                );

                return $view;
            }
        );

        /**
         * @var Loader $loader
         */
        $loader = new Loader();
        $loader->registerNamespaces([
                'Phalcon\Tests\Modules\Backend\Tasks' =>
                    dataDir('fixtures/modules/backend/tasks/')
            ]
        );
        $loader->register();

        $di->set('loader', $loader);
    }
}
