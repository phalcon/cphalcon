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

class GetDateFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: getDateFormat()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function loggerFormatterLineGetDateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - getDateFormat()');

        $I->skipTest('Need implementation');
    }
}
