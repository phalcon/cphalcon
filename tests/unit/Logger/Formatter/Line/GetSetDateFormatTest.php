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

namespace Phalcon\Tests\Unit\Logger\Formatter\Line;

use Phalcon\Logger\Formatter\Line;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDateFormatTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFormatterLineGetSetDateFormat(): void
    {
        $format    = '[%date%][%level%] %message%';
        $newFormat = 'YmdHis';

        /**
         * Default
         */
        $formatter = new Line();

        $expected = 'c';
        $actual   = $formatter->getDateFormat();
        $this->assertSame($expected, $actual);

        /**
         * Set in constructor
         */
        $formatter = new Line($format, $newFormat);

        $expected = $newFormat;
        $actual   = $formatter->getDateFormat();
        $this->assertSame($expected, $actual);

        /**
         * Set in setDateFormat
         */
        $formatter = new Line();
        $formatter->setDateFormat($newFormat);

        $expected = $newFormat;
        $actual   = $formatter->getDateFormat();
        $this->assertSame($expected, $actual);
    }
}
