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

/**
 * Class SetFormatCest
 */
class SetFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: setFormat()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function loggerFormatterLineSetFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - setFormat()');
        $I->skipTest('Need implementation');
    }
}
