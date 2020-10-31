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

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Mvc\Micro\LazyLoader;
use Phalcon\Test\Fixtures\Micro\RestHandler;

use function is_array;

/**
 * Class GetActiveHandlerCest
 */
class GetActiveHandlerCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: getActiveHandler()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcMicroGetActiveHandler(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - getActiveHandler()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Mvc\Micro :: getActiveHandler() with lazy loader
     *
     * @author Jurigag <https://github.com/Jurigag>
     * @since  2020-01-21
     */
    public function mvcMicroGetActiveHandlerLazyLoader(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - getActiveHandler() with lazy loader');

        $app        = new Micro();
        $collection = new Collection();

        $collection->setHandler(RestHandler::class, true);

        $collection->map('/', 'find');
        $app->mount($collection);


        $app->handle('/');

        $result = $app->getActiveHandler();
        $I->assertTrue(is_array($result));

        $handler = $result[0];
        $I->assertInstanceOf(LazyLoader::class, $handler);
        $I->assertInstanceOf(RestHandler::class, $handler->getHandler());
    }
}
