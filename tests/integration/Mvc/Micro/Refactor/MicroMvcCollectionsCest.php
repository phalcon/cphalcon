<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Micro\Refactor;

use IntegrationTester;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Test\Controllers\Micro\Collections\PersonasController;

class MicroMvcCollectionsCest
{
    public function testMicroCollections(IntegrationTester $I)
    {
        $app        = new Micro();
        $collection = new Collection();
        $controller = new PersonasController();

        $collection->setHandler($controller);

        $collection->map('/', 'index', 'index_route');
        $collection->map('/edit/{number}', 'edit', 'edit_route');

        $app->mount($collection);


        $app->handle('/');

        $I->assertEquals(
            1,
            $controller->getEntered()
        );

        $I->assertEquals(
            'index_route',
            $app->getRouter()->getMatchedRoute()->getName()
        );


        $app->handle('/edit/100');

        $I->assertEquals(
            101,
            $controller->getEntered()
        );

        $I->assertEquals(
            'edit_route',
            $app->getRouter()->getMatchedRoute()->getName()
        );
    }
}
