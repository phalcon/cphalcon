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

namespace Phalcon\Test\Unit\Http\Server\AbstractRequestHandler;

use UnitTester;

class HandleCest
{
    /**
     * Tests Phalcon\Http\Server\AbstractRequestHandler :: handle()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpServerAbstractRequestHandlerHandle(UnitTester $I)
    {
        $I->wantToTest('Http\Server\AbstractRequestHandler - handle()');

        $I->skipTest('Need implementation');
    }
}
