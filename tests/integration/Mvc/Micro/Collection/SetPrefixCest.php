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

namespace Phalcon\Test\Integration\Mvc\Micro\Collection;

use IntegrationTester;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Test\Controllers\Micro\Collections\PersonasController;

/**
 * Class SetPrefixCest
 */
class SetPrefixCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: setPrefix()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testMicroCollectionsPrefixed(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - setPrefix()');

        $app        = new Micro();
        $collection = new Collection();

        $collection->setPrefix('/personas');

        $controller = new PersonasController();

        $collection->setHandler($controller);

        $collection->map('/', 'index');
        $collection->map('/edit/{number}', 'edit');

        $app->mount($collection);


        $app->handle('/personas');

        $I->assertEquals(
            1,
            $controller->getEntered()
        );


        $app->handle('/personas/edit/100');

        $I->assertEquals(
            101,
            $controller->getEntered()
        );
    }
}
