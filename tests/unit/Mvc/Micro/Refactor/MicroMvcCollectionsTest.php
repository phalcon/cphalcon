<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Unit\Mvc\Micro\Refactor;

use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Controllers\Micro\Collections\PersonasController;

class MicroMvcCollectionsTest extends AbstractUnitTestCase
{
    public function testMicroCollections(): void
    {
        $app        = new Micro();
        $collection = new Collection();
        $controller = new PersonasController();

        $collection->setHandler($controller);

        $collection->map('/', 'index', 'index_route');
        $collection->map('/edit/{number}', 'edit', 'edit_route');

        $app->mount($collection);


        $app->handle('/');

        $this->assertEquals(
            1,
            $controller->getEntered()
        );

        $this->assertEquals(
            'index_route',
            $app->getRouter()->getMatchedRoute()->getName()
        );


        $app->handle('/edit/100');

        $this->assertEquals(
            101,
            $controller->getEntered()
        );

        $this->assertEquals(
            'edit_route',
            $app->getRouter()->getMatchedRoute()->getName()
        );
    }
}
