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

use Phalcon\Logger\Formatter\Line;
use UnitTester;

class GetFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: getFormat()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterLineGetFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - getFormat()');

        $formatter = new Line();

        $I->assertEquals(
            '[%date%][%type%] %message%',
            $formatter->getFormat()
        );
    }
}
