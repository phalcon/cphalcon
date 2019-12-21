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

namespace Phalcon\Test\Cli\Cli\Router\Route;

use CliTester;
use Codeception\Example;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetReversedPathsCest
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
            $route->getReversedPaths()
        );
    }

    protected function shortPathsProvider(): array
    {
        return [
            [
                'path'     => 'Feed',
                'expected' => [
                    'feed' => 'task',
                ],
            ],

            [
                'path'     => 'Feed::get',
                'expected' => [
                    'feed' => 'task',
                    'get'  => 'action',
                ],
            ],

            [
                'path'     => 'News::Posts::show',
                'expected' => [
                    'News'  => 'module',
                    'posts' => 'task',
                    'show'  => 'action',
                ],
            ],

            [

                'path'     => 'MyApp\\Tasks\\Posts::show',
                'expected' => [
                    'MyApp\\Tasks' => 'namespace',
                    'posts'        => 'task',
                    'show'         => 'action',
                ],
            ],

            [
                'path'     => 'News::MyApp\\Tasks\\Posts::show',
                'expected' => [
                    'News'         => 'module',
                    'MyApp\\Tasks' => 'namespace',
                    'posts'        => 'task',
                    'show'         => 'action',
                ],
            ],

            [
                'path'     => '\\Posts::show',
                'expected' => [
                    'posts' => 'task',
                    'show'  => 'action',
                ],
            ],
        ];
    }
}
