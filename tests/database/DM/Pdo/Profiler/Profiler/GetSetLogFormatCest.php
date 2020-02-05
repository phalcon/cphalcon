<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Profiler\Profiler;

use DatabaseTester;
use Phalcon\DM\Pdo\Profiler\Profiler;

class GetSetLogFormatCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Profiler\Profiler ::
     * getLogFormat()/setLogFormat()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerProfilerGetSetLogFormat(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Profiler\Profiler - getLogFormat()/setLogFormat()');


        $profiler = new Profiler();

        $I->assertEquals(
            "{method} ({duration} seconds): {statement} {backtrace}",
            $profiler->getLogFormat()
        );

        $format = "{method} ({duration} seconds): {statement}";
        $profiler->setLogFormat($format);
        $I->assertEquals(
            $format,
            $profiler->getLogFormat()
        );
    }
}
