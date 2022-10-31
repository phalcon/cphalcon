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

        $router   = new Router(false);
        $callback = function () use (&$trace) {
            $trace++;

            return false;
        };

        /** @var Route $route1 */
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

        $actual = $router->wasMatched();
        $I->assertFalse($actual);


        $router->handle('static route');

        $actual = $router->wasMatched();
        $I->assertFalse($actual);


        $router->handle('static route2');

        $actual = $router->wasMatched();
        $I->assertTrue($actual);

        $expected = 2;
        $actual   = $trace;
        $I->assertSame($expected, $actual);

        $expected = $callback;
        $actual   = $route1->getBeforeMatch();
        $I->assertSame($expected, $actual);
    }
}
