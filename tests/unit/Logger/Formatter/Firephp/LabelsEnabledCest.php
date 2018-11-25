<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Formatter\Firephp;

use UnitTester;

class LabelsEnabledCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Firephp :: labelsEnabled()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterFirephpLabelsEnabled(UnitTester $I)
    {
        $I->wantToTest("Logger\Formatter\Firephp - labelsEnabled()");
        $I->skipTest("Need implementation");
    }
}
