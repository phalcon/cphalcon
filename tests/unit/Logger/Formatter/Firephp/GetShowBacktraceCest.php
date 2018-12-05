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

class GetShowBacktraceCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Firephp :: getShowBacktrace()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterFirephpGetShowBacktrace(UnitTester $I)
    {
        $I->wantToTest("Logger\Formatter\Firephp - getShowBacktrace()");
        $I->skipTest("Need implementation");
    }
}
