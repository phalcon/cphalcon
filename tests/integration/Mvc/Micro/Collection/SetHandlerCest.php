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

namespace Phalcon\Test\Integration\Mvc\Micro\Collection;

use IntegrationTester;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Test\Controllers\Micro\Collections\PersonasLazyController;

/**
 * Class SetHandlerCest
 */
class SetHandlerCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: setHandler()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcMicroCollectionSetHandler(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - setHandler()');
        $I->skipTest('Need implementation');
    }

    public function testMicroCollectionsLazy(IntegrationTester $I)
    {
        $app        = new Micro();
        $collection = new Collection();

        $collection->setHandler(
            PersonasLazyController::class,
            true
        );


        $collection->map('/', 'index');
        $collection->map('/edit/{number}', 'edit');

        $app->mount($collection);


        $app->handle('/');

        $I->assertEquals(
            1,
            PersonasLazyController::getEntered()
        );


        $app->handle('/edit/100');

        $I->assertEquals(
            101,
            PersonasLazyController::getEntered()
        );
    }
}
