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
use Codeception\Example;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Tests\Fixtures\Traits\CliTrait;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function array_flip;

class GetReversedPathsCest
{
    use CliTrait;
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    /**
     * @dataProvider getExamplesShortPaths
     *
     * @param CliTester $I
     * @param Example   $example
     *
     * @return void
     */
    public function cliRouterRouteGetReversedPathsShortPaths(CliTester $I, Example $example)
    {
        Route::reset();

        $router = new Router(false);

        $path     = $example['path'];
        $expected = array_flip($example['expected']);

        $route  = $router->add('route', $path);
        $actual = $route->getReversedPaths();
        $I->assertSame($expected, $actual);
    }
}
