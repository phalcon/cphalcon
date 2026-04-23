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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Mvc\Micro\LazyLoader;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Micro\RestHandler;

class GetActiveHandlerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroGetActiveHandler(): void
    {
        $micro = new Micro();
        $this->assertNull($micro->getActiveHandler());
    }

    /**
     * @author Jurigag <https://github.com/Jurigag>
     * @since  2020-01-21
     */
    public function testMvcMicroGetActiveHandlerLazyLoader(): void
    {
        $app        = new Micro();
        $collection = new Collection();

        $collection->setHandler(RestHandler::class, true);

        $collection->map('/', 'find');
        $app->mount($collection);

        $app->handle('/');

        $result = $app->getActiveHandler();
        $this->assertIsArray($result);

        $handler = $result[0];
        $this->assertInstanceOf(LazyLoader::class, $handler);
        $this->assertInstanceOf(RestHandler::class, $handler->getHandler());
    }
}
