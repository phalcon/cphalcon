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

namespace Phalcon\Test\Unit\Logger\Logger;

use Phalcon\Logger;
use UnitTester;

class GetNameCest
{
    /**
     * Tests Phalcon\Logger :: getName()
     */
    public function loggerGetName(UnitTester $I)
    {
        $I->wantToTest('Logger - getName()');
        $logger = new Logger('my-name');

        $expected = 'my-name';
        $actual   = $logger->getName();
        $I->assertEquals($expected, $actual);
    }
}
