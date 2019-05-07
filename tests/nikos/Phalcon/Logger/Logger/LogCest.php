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

namespace Phalcon\Test\Unit\Logger\Logger;

use UnitTester;

class LogCest
{
    /**
     * Tests Phalcon\Logger\Logger :: log()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function loggerLoggerLog(UnitTester $I)
    {
        $I->wantToTest('Logger\Logger - log()');

        $I->skipTest('Need implementation');
    }
}
