<?php
/**
 * UnitTest.php
 * \Phalcon\Logger\Adapter\File\UnitTest
 *
 * Tests the \Phalcon\Logger\Adapter\File component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
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

namespace Phalcon\Test\Logger\Adapter\File;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Logger as PhLogger;
use \Phalcon\Logger\Exception as PhLoggerException;
use \Phalcon\Logger\Adapter\File as PhLoggerAdapterFile;
use \Phalcon\Logger\Formatter\Line as PhLoggerFormatterLine;

class UnitTest extends PhTestUnitTestCase
{
    private $logPath = '';

    /**
     * Initialization of variables etc.
     *
     * @return Phalcon\DI|void
     */
    public function setUp()
    {
        parent::setUp();

        $this->logPath = PATH_LOGS;
    }

    /**
     * Tests the creation of the log file
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testLogCreationDefault()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello');
        $logger->close();

        $actual = file_exists($this->logPath . $fileName);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertTrue($actual, 'File was not correctly created');
    }

    /**
     * Tests the creation of the log file +w
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testLogCreationWrite()
    {
        $fileName = $this->getFileName('log', 'log');
        $params   = array('mode' => 'w');

        // First create one log entry
        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello');
        $logger->close();

        // Now open the logger with w and add something else
        $logger = new PhLoggerAdapterFile($this->logPath . $fileName, $params);
        $logger->log('New Contents');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $this->cleanFile($this->logPath, $fileName);

        $found = strpos($contents[0], 'New Contents');

        $this->assertTrue(
            $found !== FALSE,
            'Opening file with w does not clear the log'
        );
    }

    /**
     * Tests if opening the file with r and logging throws exception
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testLogOpenReadThrowsException()
    {
        $fileName = $this->getFileName('log', 'log');
        $params   = array('mode' => 'r');
        $run      = false;

        // First create one log entry
        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello');
        $logger->close();

        try {
            // Now open the logger with r and add something else
            $logger = new PhLoggerAdapterFile($this->logPath . $fileName, $params);
            $logger->log('New Contents');
            $logger->close();

            // If we are here something is wrong
            $run = false;
        } catch (PhLoggerException $e) {
            // This is where we need to be
        }

        // Just in case
        $this->cleanFile($this->logPath, $fileName);

        $this->assertFalse(
            $run,
            'Logger did not throw an exception'
        );
        $this->assertInstanceOf(
            '\Phalcon\Logger\Exception',
            $e,
            'Exception thrown not of correct type'
        );
    }

    /**
     * Tests how many lines the file has on creation
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testLogNumberOfMessagesLogged()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello');
        $logger->log('Goodbye');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 2;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages'
        );
    }

    /**
     * Tests default logging uses DEBUG
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testLogDefaultLoggingUsesDebug()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[DEBUG]');
        $this->assertTrue(
            $found !== FALSE,
            'Default logging is not set to DEBUG'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Default logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests ERROR logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLogErrorLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello', PhLogger::ERROR);
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[ERROR]');
        $this->assertTrue(
            $found !== FALSE,
            'Error logging is not set to ERROR'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Error logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests DEBUG logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLogDebugLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello', PhLogger::DEBUG);
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[DEBUG]');
        $this->assertTrue(
            $found !== FALSE,
            'Debug logging is not set to DEBUG'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Debug logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests NOTICE logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLogNoticeLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello', PhLogger::NOTICE);
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[NOTICE]');
        $this->assertTrue(
            $found !== FALSE,
            'Notice logging is not set to NOTICE'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Notice logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests INFO logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLogInfoLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello', PhLogger::INFO);
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[INFO]');
        $this->assertTrue(
            $found !== FALSE,
            'Info logging is not set to INFO'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Info logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests WARNING logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLogWarningLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello', PhLogger::WARNING);
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[WARNING]');
        $this->assertTrue(
            $found !== FALSE,
            'Warning logging is not set to WARNING'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Warning logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests ALERT logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLogAlertLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello', PhLogger::ALERT);
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[ALERT]');
        $this->assertTrue(
            $found !== FALSE,
            'Alert logging is not set to ALERT'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Alert logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests multiple log levels
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLogMultipleLogLevelsSetProperly()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello Debug', PhLogger::DEBUG);
        $logger->log('Hello Notice', PhLogger::NOTICE);
        $logger->log('Hello Error', PhLogger::ERROR);
        $logger->log('Hello Alert', PhLogger::ALERT);
        $logger->log('Hello Warning', PhLogger::WARNING);
        $logger->log('Hello Info', PhLogger::INFO);
        $logger->log('Hello Default');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        // First entry - Debug
        $found = strpos($contents[0], '[DEBUG]');
        $this->assertTrue($found !== FALSE);

        $found = strpos($contents[0], 'Hello Debug');
        $this->assertTrue($found !== FALSE);

        // Second entry - Notice
        $found = strpos($contents[1], '[NOTICE]');
        $this->assertTrue($found !== FALSE);

        $found = strpos($contents[1], 'Hello Notice');
        $this->assertTrue($found !== FALSE);

        // Third entry - Error
        $found = strpos($contents[2], '[ERROR]');
        $this->assertTrue($found !== FALSE);

        $found = strpos($contents[2], 'Hello Error');
        $this->assertTrue($found !== FALSE);

        // Fourth entry - Error
        $found = strpos($contents[3], '[ALERT]');
        $this->assertTrue($found !== FALSE);

        $found = strpos($contents[3], 'Hello Alert');
        $this->assertTrue($found !== FALSE);

        // Fifth entry - Error
        $found = strpos($contents[4], '[WARNING]');
        $this->assertTrue($found !== FALSE);

        $found = strpos($contents[4], 'Hello Warning');
        $this->assertTrue($found !== FALSE);

        // Sixth entry - Error
        $found = strpos($contents[5], '[INFO]');
        $this->assertTrue($found !== FALSE);

        $found = strpos($contents[5], 'Hello Info');
        $this->assertTrue($found !== FALSE);

        // Fourth entry - default (Debug)
        $found = strpos($contents[6], '[DEBUG]');
        $this->assertTrue($found !== FALSE);

        $found = strpos($contents[6], 'Hello Default');
        $this->assertTrue($found !== FALSE);

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests the creation of the log file with debug()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testDebugCreationOfLogFile()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->debug('Hello');
        $logger->close();

        $actual = file_exists($this->logPath . $fileName);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertTrue($actual, 'File was not correctly created');
    }

    /**
     * Tests how many lines the file has on creation with debug()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testDebugNumberOfMessagesLogged()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->debug('Hello');
        $logger->debug('Goodbye');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 2;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages'
        );
    }

    /**
     * Tests DEBUG logging with debug()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testDebugLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->debug('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[DEBUG]');
        $this->assertTrue(
            $found !== FALSE,
            'Debug logging is not set to DEBUG'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Debug logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests the creation of the log file with error()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorCreationOfLogFile()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->error('Hello');
        $logger->close();

        $actual = file_exists($this->logPath . $fileName);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertTrue($actual, 'File was not correctly created');
    }

    /**
     * Tests how many lines the file has on creation with error()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testErrorNumberOfMessagesLogged()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->error('Hello');
        $logger->error('Goodbye');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 2;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages'
        );
    }

    /**
     * Tests ERROR logging with error()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testErrorLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->error('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[ERROR]');
        $this->assertTrue(
            $found !== FALSE,
            'Error logging is not set to ERROR'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Error logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests the creation of the log file with info()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testInfoCreationOfLogFile()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->info('Hello');
        $logger->close();

        $actual = file_exists($this->logPath . $fileName);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertTrue($actual, 'File was not correctly created');
    }

    /**
     * Tests how many lines the file has on creation with info()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testInfoNumberOfMessagesLogged()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->info('Hello');
        $logger->info('Goodbye');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 2;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages'
        );
    }

    /**
     * Tests ERROR logging with info()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testInfoLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->info('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[INFO]');
        $this->assertTrue(
            $found !== FALSE,
            'Info logging is not set to INFO'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Info logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests the creation of the log file with notice()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeCreationOfLogFile()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->notice('Hello');
        $logger->close();

        $actual = file_exists($this->logPath . $fileName);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertTrue($actual, 'File was not correctly created');
    }

    /**
     * Tests how many lines the file has on creation with notice()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testNoticeNumberOfMessagesLogged()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->notice('Hello');
        $logger->notice('Goodbye');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 2;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages'
        );
    }

    /**
     * Tests NOTICE logging with notice()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testNoticeLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->notice('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[NOTICE]');
        $this->assertTrue(
            $found !== FALSE,
            'Notice logging is not set to NOTICE'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Notice logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests the creation of the log file with warning()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningCreationOfLogFile()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->warning('Hello');
        $logger->close();

        $actual = file_exists($this->logPath . $fileName);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertTrue($actual, 'File was not correctly created');
    }

    /**
     * Tests how many lines the file has on creation with warning()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testWarningNumberOfMessagesLogged()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->warning('Hello');
        $logger->warning('Goodbye');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 2;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages'
        );
    }

    /**
     * Tests WARNING logging with warning()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testWarningLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->warning('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[WARNING]');
        $this->assertTrue(
            $found !== FALSE,
            'Warning logging is not set to WARNING'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Warning logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests the creation of the log file with alert()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testAlertCreationOfLogFile()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->alert('Hello');
        $logger->close();

        $actual = file_exists($this->logPath . $fileName);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertTrue($actual, 'File was not correctly created');
    }

    /**
     * Tests how many lines the file has on creation with alert()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testAlertNumberOfMessagesLogged()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->alert('Hello');
        $logger->alert('Goodbye');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 2;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages'
        );
    }

    /**
     * Tests ALERT logging with alert()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testAlertLogging()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->alert('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        $found = strpos($contents[0], '[ALERT]');
        $this->assertTrue(
            $found !== FALSE,
            'Alert logging is not set to ALERT'
        );

        $found = strpos($contents[0], 'Hello');
        $this->assertTrue(
            $found !== FALSE,
            'Alert logging does not set correct message'
        );

        $this->cleanFile($this->logPath, $fileName);
    }

    /**
     * Tests set/getFormat
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testSetGetFormat()
    {
        $formatter = new PhLoggerFormatterLine();

        $format = '%type%|%date%|%message%';
        $formatter->setFormat($format);

        $actual = $formatter->getFormat();

        $expected = $format;

        $this->assertEquals(
            $expected,
            $actual,
            'set/getFormat does not correctly set/get the format'
        );
    }

    /**
     * Tests new format logs correctly
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testNewFormatLogsCorrectly()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);

        $formatter = new PhLoggerFormatterLine('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $message  = explode('|', $contents[0]);
        $this->cleanFile($this->logPath, $fileName);

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
    public function testNewFormatFormatsDateCorrectly()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);

        $formatter = new PhLoggerFormatterLine('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        $message  = explode('|', $contents[0]);
        $this->cleanFile($this->logPath, $fileName);

        $date = new \DateTime($message[1]);

        $expected = date('Y-m-d H');
        $actual   = $date->format('Y-m-d H');

        $this->assertEquals(
            $expected,
            $actual,
            'Date format not set properly'
        );
    }

    /**
     * Tests the begin/commit
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testCommit()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello');

        $contents = file($this->logPath . $fileName);
        $expected = 1;
        $actual   = count($contents);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages before commit'
        );

        $logger->begin();

        $logger->log('Message 1');
        $logger->log('Message 2');
        $logger->log('Message 3');

        $logger->commit();

        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 4;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages after commit'
        );
    }

    /**
     * Tests the begin/rollback
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testRollback()
    {
        $fileName = $this->getFileName('log', 'log');

        $logger = new PhLoggerAdapterFile($this->logPath . $fileName);
        $logger->log('Hello');

        $contents = file($this->logPath . $fileName);
        $expected = 1;
        $actual   = count($contents);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages before rollback'
        );

        $logger->begin();

        $logger->log('Message 1');
        $logger->log('Message 2');
        $logger->log('Message 3');

        $logger->rollback();

        $logger->close();

        $contents = file($this->logPath . $fileName);
        $expected = 1;
        $actual   = count($contents);

        $this->cleanFile($this->logPath, $fileName);

        $this->assertEquals(
            $expected,
            $actual,
            'Log does not contain correct number of messages after rollback'
        );
    }
}
