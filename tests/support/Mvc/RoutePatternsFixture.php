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

namespace Phalcon\Tests\Support\Mvc;

use Phalcon\Mvc\Router\Route;

/**
 * Route patterns for each branch of Route::extractNamedParams()
 */
final class RoutePatternsFixture
{
    /**
     * Returns a list of [pattern, result] pairs.
     *
     * @return array<int, array{0: string, 1: array<int, mixed>|bool}>
     */
    public static function extract(): array
    {
        $route  = new Route('/');
        $result = [];

        foreach (self::patterns() as $pattern) {
            $result[] = [$pattern, $route->extractNamedParams($pattern)];
        }

        return $result;
    }

    /**
     * @return array<int, string>
     */
    private static function patterns(): array
    {
        return [
            '',
            '/',
            '/products/show',
            '/products/{id}',
            '/products/{id:[0-9]+}',
            '/products/{id:([0-9]+)}',
            '/products/{slug:[a-z\-]+}/{id:[0-9]+}',
            '/files/{name}.{ext}',
            '/a+b/c|d/e#f',
            '/a\.b',
            '/(foo|bar)/{id}',
            '/({lang})/x',
            '/{1abc}',
            '/{a b}',
            '/{}',
            '/{a{b}c}',
            '/{year:[0-9]{4}}',
            '/}',
            '/{',
            '/x/{a}/y/{b:[a-z]+}/z',
            '/:controller/:action',
            '#^/manual$#',
            '/über/{name}',
            '/a.b.c/{x}.json',
            '/{lang:[a-z]{2}}/{page:[a-z\.]+}',
            '/((a|b)+)/{id}',
            '/a\+b',
            '/very/long/static/path/with/many/segments/and/no/params/at/all',
            '/{id:[0-9]+}/',
            '/{controller}/{action}/{params}',
        ];
    }
}
