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

namespace Phalcon\Test\Unit\Http\Response;

use UnitTester;

class GetEventsManagerCest
{
    /**
     * Tests Phalcon\Http\Response :: getEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseGetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getEventsManager()');
        $I->skipTest('Need implementation');
    }
}
