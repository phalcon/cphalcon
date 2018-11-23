<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Formatter;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\File;
use Phalcon\Logger\Formatter\Line;
use UnitTester;

class LineCest
{
    protected $logPath = '';

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->logPath = PATH_OUTPUT . 'tests/logs/';
    }

    /**
     * Tests new format logs correctly
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerFormatterLineNewFormatLogsCorrectly(UnitTester $I)
    {
        $fileName = $I->getNewFileName('log', 'log');

        $logger    = new File($this->logPath . $fileName);
        $formatter = new Line('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $I->amInPath($this->logPath);
        $I->openFile($fileName);
        $I->seeInThisFile(sprintf('DEBUG|%s|Hello', date('D, d M y H:i:s O')));
        $I->deleteFile($fileName);
    }

    /**
     * Tests adding newline at end of message
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10631
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-28
     */
    public function testLoggerFormatterLineNewLines(UnitTester $I)
    {
        $formatter = new Line();

        $expected = '[Thu, 01 Jan 70 00:00:00 +0000][INFO] msg' . PHP_EOL;
        $actual   = $formatter->format('msg', Logger::INFO, 0);
        $I->assertEquals($expected, $actual);
    }
}
