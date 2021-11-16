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

namespace Phalcon\Tests\Cli\Cli\Router\Route;

use CliTester;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class BeforeMatchCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function testBeforeMatch(CliTester $I)
    {
        Route::reset();

        $trace = 0;

        $router = new Router(false);

        $callback = function () use (&$trace) {
            $trace++;

            return false;
        };

        $route1 = $router->add('static route');
        $route1->beforeMatch($callback);

        $router
            ->add('static route2')
            ->beforeMatch(
                function () use (&$trace) {
                    $trace++;

                    return true;
                }
            )
        ;


        $router->handle();

        $I->assertFalse(
            $router->wasMatched()
        );


        $router->handle('static route');

        $I->assertFalse(
            $router->wasMatched()
        );


        $router->handle('static route2');

        $I->assertTrue(
            $router->wasMatched()
        );

        $I->assertEquals(2, $trace);

        $I->assertEquals($callback, $route1->getBeforeMatch());
    }
}
