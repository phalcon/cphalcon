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

class GetMethodCest
{
    /**
     * Tests Phalcon\Http\Request :: getMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestGetMethod(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getMethod()');

        $I->skipTest('Need implementation');
    }
}
