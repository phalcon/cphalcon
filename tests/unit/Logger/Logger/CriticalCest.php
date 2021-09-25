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

namespace Phalcon\Tests\Unit\Logger\Logger;

use Phalcon\Tests\Fixtures\Traits\LoggerTrait;
use UnitTester;

class CriticalCest
{
    use LoggerTrait;

    /**
     * Tests Phalcon\Logger :: critical()
     */
    public function loggerCritical(UnitTester $I)
    {
        $I->wantToTest('Logger - critical()');
        $this->runLoggerFile($I, 'critical');
    }
}
