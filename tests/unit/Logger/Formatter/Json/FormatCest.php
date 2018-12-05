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

namespace Phalcon\Test\Unit\Logger\Formatter\Json;

use UnitTester;

/**
 * Class FormatCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class FormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Json :: format()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonFormat(UnitTester $I)
    {
        $I->wantToTest("Logger\Formatter\Json - format()");
        $I->skipTest("Need implementation");
    }
}
