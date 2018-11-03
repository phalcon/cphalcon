<?php

namespace Phalcon\Test\Unit\Logger\Formatter;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\File;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Logger\Formatter\Line;

/**
 * \Phalcon\Test\Unit\Logger\Formatter\Line
 * Tests the \Phalcon\Logger\Formatter\Line component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Logger\Formatter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class LineTest extends UnitTest
{
    protected $logPath = '';

    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        $this->logPath = PATH_OUTPUT . 'tests/logs/';
    }

    /**
     * Tests new format logs correctly
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerFormatterLineNewFormatLogsCorrectly()
    {
        $this->specify(
            "Line formatted does not set format correctly",
            function () {
                $I = $this->tester;
                $fileName = $I->getNewFileName('log', 'log');

                $logger = new File($this->logPath . $fileName);

                $formatter = new Line('%type%|%date%|%message%');

                $logger->setFormatter($formatter);
                $logger->log('Hello');
                $logger->close();

                $I->amInPath($this->logPath);
                $I->openFile($fileName);
                $I->seeInThisFile(sprintf('DEBUG|%s|Hello', date('D, d M y H:i:s O')));
                $I->deleteFile($fileName);
            }
        );
    }

    /**
     * Tests adding newline at end of message
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10631
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-28
     */
    public function testLoggerFormatterLineNewLines()
    {
        $this->specify(
            "Line formatter does not add new line at end of message",
            function () {
                $formatter = new Line();
                expect($formatter->format('msg', Logger::INFO, 0))->equals('[Thu, 01 Jan 70 00:00:00 +0000][INFO] msg'.PHP_EOL);
            }
        );
    }
}
