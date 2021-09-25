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

namespace Phalcon\Tests\Integration\Mvc\Micro\Collection;

use IntegrationTester;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Tests\Controllers\MicroController;

/**
 * Class MapViaCest
 */
class MapViaCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: mapVia()
     */
    public function testMicroCollectionVia(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - mapVia()');

        $app        = new Micro();
        $collection = new Collection();

        $collection->setHandler(new MicroController());

        $collection->mapVia(
            '/test',
            'indexAction',
            ['POST', 'GET'],
            'test'
        );

        $app->mount($collection);

        $expected = ['POST', 'GET'];
        $actual   = $app->getRouter()->getRouteByName('test')->getHttpMethods();

        $I->assertEquals($expected, $actual);
    }
}
