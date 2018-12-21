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
 * Class DebugCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class DebugCest
{
    use LoggerTrait;

    /**
     * Tests Phalcon\Logger :: debug()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerDebug(UnitTester $I)
    {
        $I->wantToTest('Logger - debug()');
        $this->runLoggerFile($I, 'debug');
    }
}
