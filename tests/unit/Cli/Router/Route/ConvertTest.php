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

final class ConvertTest extends AbstractUnitTestCase
{
    use DiTrait;

    public static function getExamplesConverters(): array
    {
        return [
            [
                'some-controller my-action-name this-is-a-country',
                [
                    'task'   => 'somecontroller',
                    'action' => 'myactionname',
                    'params' => ['this-is-a-country'],
                ],
            ],
            [
                'BINARY 1101',
                [
                    'task'   => 'binary',
                    'action' => 'index',
                    'params' => [1011],
                ],
            ],
        ];
    }

    /**
     * @dataProvider getExamplesConverters
     *
     */
    public function testCliRouterRouteConverters(
        string $route,
        array $paths
    ): void {
        $this->setNewCliFactoryDefault();

        Route::reset();

        $router = new Router();

        $route1 = $router
            ->add('{task:[a-z\-]+} {action:[a-z\-]+} this-is-a-country')
        ;

        $taskConverter   = function ($task) {
            return str_replace('-', '', $task);
        };
        $actionConverter = function ($action) {
            return str_replace('-', '', $action);
        };

        $route1
            ->convert('task', $taskConverter)
            ->convert('action', $actionConverter)
        ;

        $router
            ->add(
                '([A-Z]+) ([0-9]+)',
                [
                    'task'   => 1,
                    'action' => 'default',
                    'id'     => 2,
                ]
            )
            ->convert(
                'task',
                function ($task) {
                    return strtolower($task);
                }
            )
            ->convert(
                'action',
                function ($action) {
                    if ($action == 'default') {
                        return 'index';
                    }

                    return $action;
                }
            )
            ->convert(
                'id',
                function ($id) {
                    return strrev($id);
                }
            )
        ;

        $router->handle($route);

        $actual = $router->wasMatched();
        $this->assertTrue($actual);

        $expected = $paths['task'];
        $actual   = $router->getTaskName();
        $this->assertSame($expected, $actual);

        $expected = $paths['action'];
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $expected = [
            'task'   => $taskConverter,
            'action' => $actionConverter,
        ];
        $actual   = $route1->getConverters();
        $this->assertSame($expected, $actual);
    }
}
