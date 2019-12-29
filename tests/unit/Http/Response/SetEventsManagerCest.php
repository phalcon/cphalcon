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

class SetEventsManagerCest
{
    /**
     * Unit Tests Phalcon\Http\Response :: setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function httpResponseSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setEventsManager()');

        $I->skipTest('Need implementation');
    }
}
