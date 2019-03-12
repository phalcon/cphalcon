<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Server\RequestHandler;

use UnitTester;

/**
 * Class HandleCest
 */
class HandleCest
{
    /**
     * Tests Phalcon\Http\Server\RequestHandler :: handle()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpServerRequestHandlerHandle(UnitTester $I)
    {
        $I->wantToTest('Http\Server\RequestHandler - handle()');
        $I->skipTest('Need implementation');
    }
}
