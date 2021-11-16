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
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetPathsCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    /**
     * @dataProvider shortPathsProvider
     */
    public function testShortPaths(CliTester $I, Example $example)
    {
        Route::reset();

        $router = new Router(false);

        $route = $router->add(
            'route',
            $example['path']
        );

        $I->assertEquals(
            $example['expected'],
            $route->getPaths()
        );
    }

    protected function shortPathsProvider(): array
    {
        return [
            [
                'path'     => 'Feed',
                'expected' => [
                    'task' => 'feed',
                ],
            ],

            [
                'path'     => 'Feed::get',
                'expected' => [
                    'task'   => 'feed',
                    'action' => 'get',
                ],
            ],

            [
                'path'     => 'News::Posts::show',
                'expected' => [
                    'module' => 'News',
                    'task'   => 'posts',
                    'action' => 'show',
                ],
            ],

            [
                'path'     => 'MyApp\\Tasks\\Posts::show',
                'expected' => [
                    'namespace' => 'MyApp\\Tasks',
                    'task'      => 'posts',
                    'action'    => 'show',
                ],
            ],

            [
                'path'     => 'News::MyApp\\Tasks\\Posts::show',
                'expected' => [
                    'module'    => 'News',
                    'namespace' => 'MyApp\\Tasks',
                    'task'      => 'posts',
                    'action'    => 'show',
                ],
            ],

            [
                'path'     => '\\Posts::show',
                'expected' => [
                    'task'   => 'posts',
                    'action' => 'show',
                ],
            ],
        ];
    }
}
