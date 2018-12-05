<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Adapter;

use UnitTester;

class AlertCest
{
    /**
     * Tests Phalcon\Logger\Adapter :: alert()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterAlert(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter - alert()");
        $I->skipTest("Need implementation");
    }
}
