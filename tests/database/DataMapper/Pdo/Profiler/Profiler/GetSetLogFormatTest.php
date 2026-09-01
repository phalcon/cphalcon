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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Profiler\Profiler;

use Phalcon\DataMapper\Pdo\Profiler\Profiler;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetSetLogFormatTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoProfilerProfilerGetSetLogFormat(): void
    {
        $profiler = new Profiler();

        $this->assertEquals(
            "{method} ({duration}s): {statement} {backtrace}",
            $profiler->getLogFormat()
        );

        $format = "{method} ({duration}s): {statement}";
        $profiler->setLogFormat($format);
        $this->assertEquals(
            $format,
            $profiler->getLogFormat()
        );
    }
}
