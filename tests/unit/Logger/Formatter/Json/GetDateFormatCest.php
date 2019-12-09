<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Logger\Formatter\Json;

use Phalcon\Logger\Formatter\Json;
use UnitTester;

class GetDateFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Json :: getDateFormat()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonGetDateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - getDateFormat()');

        $formatter = new Json();

        $I->assertEquals(
            'D, d M y H:i:s O',
            $formatter->getDateFormat()
        );
    }
}
