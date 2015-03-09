<?php
/**
 * FileTest.php
 * \Phalcon\Logger\FileTest
 *
 * Tests the Phalcon\Logger\Adapter\File component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Logger\Adapter;

use Phalcon\Logger as PhLogger;
use Phalcon\Logger\Exception as PhLoggerException;
use Phalcon\Logger\Formatter\Line as PhLoggerFormatterLine;
use \Phalcon\Logger\Adapter\File as PhTLoggerAdapterFile;

use Phalcon\Tests\unit\Phalcon\Logger\Helper\FileBase as FBase;

class FormatterTest extends FBase
{
    /**
     * Tests new format logs correctly
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerFormatterNewFormatLogsCorrectly()
    {
        $fileName = newFileName('log', 'log');

        $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);

        $formatter = new PhLoggerFormatterLine('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $message  = explode('|', $contents[0]);
        cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            'DEBUG',
            $message[0],
            'New format, type not set correctly'
        );
        $this->assertEquals(
            'Hello' . PHP_EOL,
            $message[2],
            'New format, message not set correctly'
        );
    }

    /**
     * Tests new format logs correctly
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerFormatterNewFormatFormatsDateCorrectly()
    {
        $fileName = newFileName('log', 'log');

        $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);

        $formatter = new PhLoggerFormatterLine('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $message  = explode('|', $contents[0]);
        cleanFile($this->logPath, $fileName);

        $date = new \DateTime($message[1]);

        $expected = date('Y-m-d H');
        $actual   = $date->format('Y-m-d H');

        $this->assertEquals(
            $expected,
            $actual,
            'Date format not set properly'
        );
    }
}
