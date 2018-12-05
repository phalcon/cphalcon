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

namespace Phalcon\Test\Unit\Logger\Formatter\AbstractFormatter;

use UnitTester;

/**
 * Class FormatCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class FormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\AbstractFormatter :: format()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterAbstractformatterFormat(UnitTester $I)
    {
        $I->wantToTest("Logger\Formatter\AbstractFormatter - format()");
        $I->skipTest("Need implementation");
    }
}
