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

namespace Phalcon\Tests\Unit\Mvc\Router\Route;

use Phalcon\Mvc\Router\Route;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

use function uniqid;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: array<int, string>|string|null}>
     */
    public static function getHttpMethods(): array
    {
        return [
            'no methods' => [null],
            'one method' => ['GET'],
            'a list'     => [['GET', 'POST']],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-01-27
     */
    public function testMvcRouterRouteConstruct(): void
    {
        $pattern = uniqid();
        $route   = new Route($pattern);

        $expected = $pattern;
        $actual   = $route->getPattern();
        $this->assertSame($expected, $actual);
    }

    /**
     * The constructor stores the HTTP methods as given.
     *
     * @param array<int, string>|string|null $httpMethods
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    #[DataProvider('getHttpMethods')]
    public function testMvcRouterRouteConstructHttpMethods(array | string | null $httpMethods): void
    {
        $route = new Route('/test', [], $httpMethods);

        $this->assertSame($httpMethods, $route->getHttpMethods());
    }
}
