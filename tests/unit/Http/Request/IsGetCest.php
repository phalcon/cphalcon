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

class IsGetCest
{
    /**
     * Tests Phalcon\Http\Request :: isGet()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestIsGet(UnitTester $I)
    {
        $I->wantToTest('Http\Request - isGet()');

        $I->skipTest('Need implementation');
    }
}
