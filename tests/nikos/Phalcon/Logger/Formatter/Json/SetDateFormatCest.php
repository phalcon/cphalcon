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

class SetDateFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Json :: setDateFormat()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function loggerFormatterJsonSetDateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - setDateFormat()');

        $I->skipTest('Need implementation');
    }
}
