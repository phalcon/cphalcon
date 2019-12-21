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

namespace Phalcon\Test\Unit\Http\Request;

use UnitTester;

class GetRawBodyCest
{
    /**
     * Tests Phalcon\Http\Request :: getRawBody()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestGetRawBody(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getRawBody()');

        $I->skipTest('Need implementation');
    }
}
