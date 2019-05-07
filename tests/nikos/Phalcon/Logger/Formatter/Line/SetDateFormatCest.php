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

namespace Phalcon\Test\Unit\Logger\Formatter\Line;

use UnitTester;

class SetDateFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: setDateFormat()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function loggerFormatterLineSetDateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - setDateFormat()');

        $I->skipTest('Need implementation');
    }
}
