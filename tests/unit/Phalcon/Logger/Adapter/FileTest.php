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
use \Phalcon\Logger\Formatter\Line as PhLoggerFormatterLine;
use \Phalcon\Logger\Adapter\File as PhTLoggerAdapterFile;

use Phalcon\Tests\unit\Phalcon\Logger\Helper\FileBase as FBase;

class FileTest extends FBase
{
    public function _before()
    {
        parent::_before();

        $this->logPath = PATH_LOGS;
    }

    /**
     * Tests the creation of the log file
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileCreationDefault()
    {
        $this->specify(
            "logging in a file does not create the file",
            function () {

                $fileName = newFileName('log', 'log');

                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->close();

                $actual = file_exists($this->logPath . $fileName);

                cleanFile($this->logPath, $fileName);

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the creation of the log file +w
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileCreationWrite()
    {
        $this->specify(
            "logging in a file with write mode does not create the file",
            function () {

                $fileName = newFileName('log', 'log');
                $params   = ['mode' => 'w'];

                // First create one log entry
                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->close();

                // Now open the logger with w and add something else
                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName, $params);
                $logger->log('New Contents');
                $logger->close();

                $contents = file($this->logPath . $fileName);

                cleanFile($this->logPath, $fileName);

                $position = strpos($contents[0], 'New Contents');
                $actual   = ($position !== false);

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests if opening the file with r and logging throws exception
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileOpenReadThrowsException()
    {
        $this->specify(
            "logging in a file with write mode does not create the file",
            function () {

                $fileName = newFileName('log', 'log');
                $params   = array('mode' => 'r');

                // First create one log entry
                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->close();

                // Now open the logger with r and add something else
                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName, $params);
                $logger->log('New Contents');
                $logger->close();
            },
            [
                'throws' => new PhLoggerException()
            ]
        );
    }

    /**
     * Tests how many lines the file has on creation
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileNumberOfMessagesLogged()
    {
        $this->specify(
            "Log does not contain correct number of messages",
            function () {

                $fileName = newFileName('log', 'log');

                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->log('Goodbye');
                $logger->close();

                $contents = file($this->logPath . $fileName);
                $expected = 2;
                $actual   = count($contents);

                cleanFile($this->logPath, $fileName);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests default logging uses EMERGENCY
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileDefaultLoggingUsesDebug()
    {
        $this->specify(
            "default logging does not use debug",
            function () {
                $this->runLogging('Hello', null);
            }
        );
    }

    /**
     * Tests ERROR logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileErrorLogging()
    {
        $this->specify(
            "ERROR logging not correct",
            function () {
                $this->runLogging(PhLogger::ERROR, 'ERROR');
            }
        );
    }

    /**
     * Tests DEBUG logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileDebugLogging()
    {
        $this->specify(
            "DEBUG logging not correct",
            function () {
                $this->runLogging(PhLogger::DEBUG, 'DEBUG');
            }
        );
    }

    /**
     * Tests NOTICE logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileNoticeLogging()
    {
        $this->specify(
            "NOTICE logging not correct",
            function () {
                $this->runLogging(PhLogger::NOTICE, 'NOTICE');
            }
        );
    }

    /**
     * Tests INFO logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileInfoLogging()
    {
        $this->specify(
            "INFO logging not correct",
            function () {
                $this->runLogging(PhLogger::INFO, 'INFO');
            }
        );
    }

    /**
     * Tests WARNING logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileWarningLogging()
    {
        $this->specify(
            "WARNING logging not correct",
            function () {
                $this->runLogging(PhLogger::WARNING, 'WARNING');
            }
        );
    }

    /**
     * Tests ALERT logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileAlertLogging()
    {
        $this->specify(
            "ALERT logging not correct",
            function () {
                $this->runLogging(PhLogger::ALERT, 'ALERT');
            }
        );
    }

    /**
     * Tests multiple log levels
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileMultipleLogLevelsSetProperly()
    {
        $fileName = newFileName('log', 'log');

        $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
        $logger->log(PhLogger::DEBUG, 'Hello Debug');
        $logger->log(PhLogger::NOTICE, 'Hello Notice');
        $logger->log(PhLogger::ERROR, 'Hello Error');
        $logger->log(PhLogger::ALERT, 'Hello Alert');
        $logger->log(PhLogger::WARNING, 'Hello Warning');
        $logger->log(PhLogger::INFO, 'Hello Info');
        $logger->log('Hello Default');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        cleanFile($this->logPath, $fileName);

        // First entry - Debug
        $position = strpos($contents[0], '[DEBUG]');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[0], 'Hello Debug');
        $actual   = ($position !== false);
        expect($actual)->true();

        // Second entry - Notice
        $position = strpos($contents[1], '[NOTICE]');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[1], 'Hello Notice');
        $actual   = ($position !== false);
        expect($actual)->true();

        // Third entry - Error
        $position = strpos($contents[2], '[ERROR]');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[2], 'Hello Error');
        $actual   = ($position !== false);
        expect($actual)->true();

        // Fourth entry - Error
        $position = strpos($contents[3], '[ALERT]');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[3], 'Hello Alert');
        $actual   = ($position !== false);
        expect($actual)->true();

        // Fifth entry - Error
        $position = strpos($contents[4], '[WARNING]');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[4], 'Hello Warning');
        $actual   = ($position !== false);
        expect($actual)->true();

        // Sixth entry - Error
        $position = strpos($contents[5], '[INFO]');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[5], 'Hello Info');
        $actual   = ($position !== false);
        expect($actual)->true();

        // Fourth entry - default (Debug)
        $position = strpos($contents[6], '[DEBUG]');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[6], 'Hello Default');
        $actual   = ($position !== false);
        expect($actual)->true();
    }

    /**
     * Tests the creation of the log file with debug()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileDebugCreationOfLogFile()
    {
        $this->specify(
            "Debug file was not correctly created",
            function () {
                $this->createOfLogFile('debug');
            }
        );
    }

    /**
     * Tests how many lines the file has on creation with debug()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileDebugNumberOfMessagesLogged()
    {
        $this->specify(
            "Debug log does not contain correct number of messages",
            function () {
                $this->numberOfMessagesLogged('debug');
            }
        );
    }

    /**
     * Tests DEBUG logging with debug()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileDebugLogLogging()
    {
        $this->specify(
            "Logging with debug not correct",
            function () {
                $this->logging('debug');
            }
        );
    }

    /**
     * Tests the creation of the log file with error()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileErrorCreationOfLogFile()
    {
        $this->specify(
            "Error file was not correctly created",
            function () {
                $this->createOfLogFile('error');
            }
        );
    }

    /**
     * Tests how many lines the file has on creation with error()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileErrorNumberOfMessagesLogged()
    {
        $this->specify(
            "Error log does not contain correct number of messages",
            function () {
                $this->numberOfMessagesLogged('error');
            }
        );
    }

    /**
     * Tests ERROR logging with error()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileErrorLogLogging()
    {
        $this->specify(
            "Logging with error not correct",
            function () {
                $this->logging('error');
            }
        );
    }

    /**
     * Tests the creation of the log file with info()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileInfoCreationOfLogFile()
    {
        $this->specify(
            "Info file was not correctly created",
            function () {
                $this->createOfLogFile('info');
            }
        );
    }

    /**
     * Tests how many lines the file has on creation with info()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileInfoNumberOfMessagesLogged()
    {
        $this->specify(
            "Info log does not contain correct number of messages",
            function () {
                $this->numberOfMessagesLogged('info');
            }
        );
    }

    /**
     * Tests ERROR logging with info()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileInfoLogLogging()
    {
        $this->specify(
            "Logging with info not correct",
            function () {
                $this->logging('info');
            }
        );
    }

    /**
     * Tests the creation of the log file with notice()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileNoticeCreationOfLogFile()
    {
        $this->specify(
            "Notice file was not correctly created",
            function () {
                $this->createOfLogFile('notice');
            }
        );
    }

    /**
     * Tests how many lines the file has on creation with notice()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileNoticeNumberOfMessagesLogged()
    {
        $this->specify(
            "Notice log does not contain correct number of messages",
            function () {
                $this->numberOfMessagesLogged('notice');
            }
        );
    }

    /**
     * Tests NOTICE logging with notice()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileNoticeLogLogging()
    {
        $this->specify(
            "Logging with notice not correct",
            function () {
                $this->logging('notice');
            }
        );
    }

    /**
     * Tests the creation of the log file with warning()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileWarningCreationOfLogFile()
    {
        $this->specify(
            "Warning file was not correctly created",
            function () {
                $this->createOfLogFile('warning');
            }
        );
    }

    /**
     * Tests how many lines the file has on creation with warning()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileWarningNumberOfMessagesLogged()
    {
        $this->specify(
            "Warning log does not contain correct number of messages",
            function () {
                $this->numberOfMessagesLogged('warning');
            }
        );
    }

    /**
     * Tests WARNING logging with warning()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileWarningLogLogging()
    {
        $this->specify(
            "Logging with warning not correct",
            function () {
                $this->logging('warning');
            }
        );
    }

    /**
     * Tests the creation of the log file with alert()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileAlertCreationOfLogFile()
    {
        $this->specify(
            "Alert file was not correctly created",
            function () {
                $this->createOfLogFile('alert');
            }
        );
    }

    /**
     * Tests how many lines the file has on creation with alert()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileAlertNumberOfMessagesLogged()
    {
        $this->specify(
            "Alert log does not contain correct number of messages",
            function () {
                $this->numberOfMessagesLogged('alert');
            }
        );
    }

    /**
     * Tests ALERT logging with alert()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileAlertLogLogging()
    {
        $this->specify(
            "Logging with alert not correct",
            function () {
                $this->logging('alert');
            }
        );
    }

    /**
     * Tests set/getFormat
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileSetGetFormat()
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
    public function testLoggerAdapterFileNewFormatLogsCorrectly()
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
    public function testLoggerAdapterFileNewFormatFormatsDateCorrectly()
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

    /**
     * Runs the various logging function testLoggerAdapterFiles
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @param mixed $level
     * @param null  $name
     */
    protected function runLogging($level, $name = null)
    {
        $fileName = newFileName('log', 'log');

        $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
        if (is_null($name)) {
            $logger->log($level);
            $name = 'DEBUG';
        } else {
            $logger->log($level, 'Hello');
        }
        $logger->close();

        $contents = file($this->logPath . $fileName);
        cleanFile($this->logPath, $fileName);

        $position = strpos($contents[0], '[' . $name . ']');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[0], 'Hello');
        $actual   = ($position !== false);
        expect($actual)->true();
    }


    /**
     * Runs the test for the creation of a file with logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @param string $function
     */
    protected function createOfLogFile($function)
    {
        $fileName = newFileName('log', 'log');

        $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->close();

        $found = file_exists($this->logPath . $fileName);

        cleanFile($this->logPath, $fileName);

        expect($found)->true();
    }

    /**
     * Runs the test for how many lines the file has on creation
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @param string $function
     */
    protected function numberOfMessagesLogged($function)
    {
        $fileName = newFileName('log', 'log');

        $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->$function('Goodbye');
        $logger->close();

        $contents = file($this->logPath . $fileName);

        cleanFile($this->logPath, $fileName);

        $expected = 2;
        $actual   = count($contents);

        expect($actual)->equals($expected);
    }

    /**
     * Runs logging test
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     *
     * @param $function
     */
    protected function logging($function)
    {
        $fileName = newFileName('log', 'log');

        $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->close();

        $contents = file($this->logPath . $fileName);
        cleanFile($this->logPath, $fileName);

        $position = strpos($contents[0], '[' . strtoupper($function) . ']');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[0], 'Hello');
        $actual   = ($position !== false);
        expect($actual)->true();
    }
}
