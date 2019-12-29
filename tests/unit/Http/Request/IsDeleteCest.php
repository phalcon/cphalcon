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

class IsDeleteCest
{
    /**
     * Tests Phalcon\Http\Request :: isDelete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestIsDelete(UnitTester $I)
    {
        $I->wantToTest('Http\Request - isDelete()');

        $I->skipTest('Need implementation');
    }
}
