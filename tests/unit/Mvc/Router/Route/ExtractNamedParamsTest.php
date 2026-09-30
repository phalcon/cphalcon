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
use Phalcon\Talon\Talon;
use Phalcon\Tests\Support\Mvc\RoutePatternsFixture;

use function file_get_contents;
use function json_decode;

use const JSON_THROW_ON_ERROR;

final class ExtractNamedParamsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterRouteExtractNamedParams(): void
    {
        $route  = new Route('/test');
        $result = $route->extractNamedParams('/users/{id:[0-9]+}');
        $this->assertIsArray($result);
        $this->assertCount(2, $result);
        $this->assertIsString($result[0]);
        $this->assertIsArray($result[1]);
        $this->assertArrayHasKey('id', $result[1]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-30
     */
    public function testMvcRouterRouteExtractNamedParamsFixture(): void
    {
        $file     = Talon::settings()->supportPath('assets/Mvc/route-named-params.json');
        $expected = json_decode(
            (string) file_get_contents($file),
            true,
            512,
            JSON_THROW_ON_ERROR
        );

        $this->assertSame($expected, RoutePatternsFixture::extract());
    }
}
