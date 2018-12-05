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

class EmergencyCest
{
    /**
     * Tests Phalcon\Logger\Adapter :: emergency()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterEmergency(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter - emergency()");
        $I->skipTest("Need implementation");
    }
}
