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

namespace Phalcon\Tests\Unit\Cli\Router\Route;

use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Di\Fake\CliTrait;

use function array_flip;

final class GetReversedPathsTest extends AbstractUnitTestCase
{
    use CliTrait;
    use DiTrait;

    /**
     * @dataProvider getExamplesShortPaths
     *
     */
    public function testCliRouterRouteGetReversedPathsShortPaths(
        string $path,
        array $expected
    ): void {
        $this->setNewCliFactoryDefault();

        Route::reset();

        $router = new Router(false);

        $expected = array_flip($expected);

        $route  = $router->add('route', $path);
        $actual = $route->getReversedPaths();
        $this->assertSame($expected, $actual);
    }
}
