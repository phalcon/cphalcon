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

namespace Phalcon\Test\Unit\Logger\Logger;

use Phalcon\Test\Fixtures\Traits\LoggerTrait;
use UnitTester;

class WarningCest
{
    use LoggerTrait;

    /**
     * Tests Phalcon\Logger :: warning()
     *
     * @param UnitTester $I
     */
    public function loggerWarning(UnitTester $I)
    {
        $I->wantToTest('Logger - warning()');
        $this->runLoggerFile($I, 'warning');
    }
}
