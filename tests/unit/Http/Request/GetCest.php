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

class GetCest
{
    /**
     * Tests Phalcon\Http\Request :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestGet(UnitTester $I)
    {
        $I->wantToTest('Http\Request - get()');

        $I->skipTest('Need implementation');
    }
}
