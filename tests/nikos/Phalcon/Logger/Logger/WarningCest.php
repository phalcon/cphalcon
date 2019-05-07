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

class WarningCest
{
    /**
     * Tests Phalcon\Logger\Logger :: warning()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function loggerLoggerWarning(UnitTester $I)
    {
        $I->wantToTest('Logger\Logger - warning()');

        $I->skipTest('Need implementation');
    }
}
