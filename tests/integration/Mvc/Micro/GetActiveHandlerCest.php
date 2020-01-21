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
use Phalcon\Test\Fixtures\Micro\RestHandler;

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

    public function lazyLoaderActiveHandler(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - getActiveHandler() with lazy loader');
        $app = new Micro();
        $microCollection = new Micro\Collection();
        $microCollection->setHandler(RestHandler::class, true);
        $microCollection->get('/api/site', 'find');
        $app->mount($microCollection);
        $app->handle('/api/site');
        $I->assertInstanceOf(Micro\LazyLoader::class, $app->getActiveHandler());
        $I->assertInstanceOf(RestHandler::class, $app->getActiveHandler()->getHandler());
    }
}
