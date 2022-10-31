<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Traits;

use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Router;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Filter\Filter;
use Phalcon\Html\Escaper;
use Phalcon\Support\HelperFactory;

trait CliTrait
{
    /**
     * @return array[]
     */
    protected function getExamplesShortPaths(): array
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

    private function getServices(): array
    {
        return [
            [
                'service' => 'dispatcher',
                'class'   => Dispatcher::class,
            ],
            [
                'service' => 'escaper',
                'class'   => Escaper::class,
            ],
            [
                'service' => 'eventsManager',
                'class'   => EventsManager::class,
            ],
            [
                'service' => 'filter',
                'class'   => Filter::class,
            ],
            [
                'service' => 'helper',
                'class'   => HelperFactory::class,
            ],
            [
                'service' => 'router',
                'class'   => Router::class,
            ],
            [
                'service' => 'security',
                'class'   => Security::class,
            ],
        ];
    }
}
