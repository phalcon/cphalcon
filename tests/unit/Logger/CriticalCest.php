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

namespace Phalcon\Test\Unit\Logger;

use Phalcon\Test\Fixtures\Traits\LoggerTrait;
use UnitTester;

/**
 * Class CriticalCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class CriticalCest
{
    use LoggerTrait;

    /**
     * Tests Phalcon\Logger :: critical()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerCritical(UnitTester $I)
    {
        $I->wantToTest('Logger - critical()');
        $this->runLoggerFile($I, 'critical');
    }
}
