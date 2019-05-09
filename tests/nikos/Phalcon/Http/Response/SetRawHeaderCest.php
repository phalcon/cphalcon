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

namespace Phalcon\Test\Unit\Http\Response;

use UnitTester;

class SetRawHeaderCest
{
    /**
     * Tests Phalcon\Http\Response :: setRawHeader()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpResponseSetRawHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setRawHeader()');

        $I->skipTest('Need implementation');
    }
}
