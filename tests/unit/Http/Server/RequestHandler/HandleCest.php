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

namespace Phalcon\Test\Unit\Http\Server\RequestHandler;

use UnitTester;

class HandleCest
{
    /**
     * Tests Phalcon\Http\Server\RequestHandler :: handle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpServerRequestHandlerHandle(UnitTester $I)
    {
        $I->wantToTest('Http\Server\RequestHandler - handle()');
        $I->skipTest('Need implementation');
    }
}
