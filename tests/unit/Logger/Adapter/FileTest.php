<?php

namespace Phalcon\Test\Unit\Logger\Adapter;

use Phalcon\Logger;
use Phalcon\Logger\Multiple;
use Phalcon\Logger\Adapter\File;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Formatter\Json;

/**
 * \Phalcon\Test\Unit\Logger\Adapter\FileTest
 * Tests the \Phalcon\Logger\Adapter\File component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Logger\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FileTest extends UnitTest
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
                $I = $this->tester;
                $fileName = $I->getNewFileName('log', 'log');

                $logger = new File($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->close();

                $I->amInPath($this->logPath);
                $I->seeFileFound($fileName);
                $I->deleteFile($fileName);
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
                $I = $this->tester;
                $fileName = $I->getNewFileName('log', 'log');
                $params   = ['mode' => 'w'];

                $logger = new File($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->close();

                $logger = new File($this->logPath . $fileName, $params);
                $logger->log('New Contents');
                $logger->close();

                $I->amInPath($this->logPath);
                $I->openFile($fileName);
                $I->seeInThisFile('New Contents');
                $I->deleteFile($fileName);
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
        $I = $this->tester;
        $fileName = $I->getNewFileName('log', 'log');

        $this->specify(
            "logging in a file with write mode does not create the file",
            function () use ($fileName) {
                $params   = array('mode' => 'r');

                $logger = new File($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->close();

                $logger = new File($this->logPath . $fileName, $params);
                $logger->log('New Contents');
                $logger->close();
            },
            ['throws' => ['Phalcon\Logger\Exception']]
        );

        $I->amInPath($this->logPath);
        $I->deleteFile($fileName);
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
                $I = $this->tester;
                $fileName = $I->getNewFileName('log', 'log');

                $logger = new File($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->log('Goodbye');
                $logger->close();

                $I->amInPath($this->logPath);
                $I->openFile($fileName);
                $expected = sprintf(
                    "[%s][DEBUG] Hello\n[%s][DEBUG] Goodbye",
                    date('D, d M y H:i:s O'),
                    date('D, d M y H:i:s O')
                );
                $I->seeInThisFile($expected);
                $I->deleteFile($fileName);
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
                $this->runLogging(Logger::ERROR, 'ERROR');
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
                $this->runLogging(Logger::DEBUG, 'DEBUG');
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
                $this->runLogging(Logger::NOTICE, 'NOTICE');
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
                $this->runLogging(Logger::INFO, 'INFO');
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
                $this->runLogging(Logger::WARNING, 'WARNING');
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
                $this->runLogging(Logger::ALERT, 'ALERT');
            }
        );
    }

    /**
     * Tests multiple loggers
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2798
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-28
     */
    public function testMultipleLoggers()
    {
        $this->specify(
            "Multiple logging does not works correctly",
            function () {
                $I = $this->tester;
                $file1 = $I->getNewFileName('log', 'log');
                $file2 = $I->getNewFileName('log', 'log');

                $logger = new Multiple();

                $logger->push(new File($this->logPath . $file1));
                $logger->push(new File($this->logPath . $file2));

                $logger->setFormatter(new Json());

                $expected = '{"type":"DEBUG","message":"This is a message","timestamp":' . time() . '}' . PHP_EOL;
                $logger->log('This is a message');

                $expected .= '{"type":"ERROR","message":"This is an error","timestamp":' . time() . '}' . PHP_EOL;
                $logger->log("This is an error", Logger::ERROR);

                $expected .= '{"type":"ERROR","message":"This is another error","timestamp":' . time() . '}' . PHP_EOL;
                $logger->error("This is another error");

                $I->amInPath($this->logPath);

                $I->openFile($file1);
                $I->seeFileContentsEqual($expected);
                $I->deleteFile($file1);

                $I->openFile($file2);
                $I->seeFileContentsEqual($expected);
                $I->deleteFile($file2);
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
        $I = $this->tester;
        $fileName = $I->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);
        $logger->log(Logger::DEBUG, 'Hello Debug');
        $logger->log(Logger::NOTICE, 'Hello Notice');
        $logger->log(Logger::ERROR, 'Hello Error');
        $logger->log(Logger::ALERT, 'Hello Alert');
        $logger->log(Logger::WARNING, 'Hello Warning');
        $logger->log(Logger::INFO, 'Hello Info');
        $logger->log('Hello Default');
        $logger->close();

        $I->amInPath($this->logPath);
        $I->openFile($fileName);

        $expected = sprintf(
            "[%s][DEBUG] Hello Debug\n[%s][NOTICE] Hello Notice\n[%s][ERROR] Hello Error\n" .
            "[%s][ALERT] Hello Alert\n[%s][WARNING] Hello Warning\n[%s][INFO] Hello Info\n" .
            "[%s][DEBUG] Hello Default\n",
            date('D, d M y H:i:s O'),
            date('D, d M y H:i:s O'),
            date('D, d M y H:i:s O'),
            date('D, d M y H:i:s O'),
            date('D, d M y H:i:s O'),
            date('D, d M y H:i:s O'),
            date('D, d M y H:i:s O')
        );
        $I->seeFileContentsEqual($expected);

        $I->deleteFile($fileName);
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
        $formatter = new Line();

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
        $fileName = $this->tester->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);

        $formatter = new Line('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $contents = \file($this->logPath . $fileName);
        $message  = explode('|', $contents[0]);
        $this->tester->cleanFile($this->logPath, $fileName);

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
     * Tests setting Json formatter
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2262
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-28
     */
    public function testLoggerAdapterFileSettingJsonFormatter()
    {
        $this->specify(
            "logging in a file does not create the file",
            function () {
                $I = $this->tester;
                $fileName = $I->getNewFileName('log', 'log');

                $logger = new File($this->logPath . $fileName);
                $logger->setFormatter(new Json());

                $logger->log('This is a message');
                $logger->log("This is an error", Logger::ERROR);
                $logger->error("This is another error");

                $I->amInPath($this->logPath);
                $I->openFile($fileName);

                $expected = sprintf(
                    '{"type":"DEBUG","message":"This is a message","timestamp":%s}' . PHP_EOL .
                    '{"type":"ERROR","message":"This is an error","timestamp":%s}' . PHP_EOL .
                    '{"type":"ERROR","message":"This is another error","timestamp":%s}',
                    time(),
                    time(),
                    time()
                );
                $I->seeInThisFile($expected);
                $I->deleteFile($fileName);
            }
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
        $fileName = $this->tester->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);

        $formatter = new Line('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $contents = \file($this->logPath . $fileName);
        $message  = explode('|', $contents[0]);
        $this->tester->cleanFile($this->logPath, $fileName);

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
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileCommit()
    {
        $this->specify(
            "Logging does not contain correct number of messages before commit",
            function () {
                $I = $this->tester;
                $fileName = $I->getNewFileName('log', 'log');

                $logger = new File($this->logPath . $fileName);
                $logger->begin();
                $logger->log('Hello');
                $logger->commit();

                $I->amInPath($this->logPath);
                $I->openFile($fileName);
                $I->seeNumberNewLines(2);

                $logger->close();
                $I->deleteFile($fileName);
            }
        );

        $this->specify(
            "Logging does not contain correct number of messages after commit",
            function () {
                $fileName = $this->tester->getNewFileName('log', 'log');

                $logger = new File($this->logPath . $fileName);
                $logger->log('Hello');

                $logger->begin();

                $logger->log('Message 1');
                $logger->log('Message 2');
                $logger->log('Message 3');

                $logger->commit();

                $logger->close();

                $contents = \file($this->logPath . $fileName);
                $this->tester->cleanFile($this->logPath, $fileName);

                $expected = 4;
                $actual   = count($contents);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the begin/rollback
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileRollback()
    {
        $this->specify(
            "Logging does not contain correct number of messages before rollback",
            function () {
                $I = $this->tester;
                $fileName = $I->getNewFileName('log', 'log');

                $logger = new File($this->logPath . $fileName);
                $logger->log('Hello');

                $logger->close();

                $I->amInPath($this->logPath);
                $I->openFile($fileName);
                $I->seeFileContentsEqual(sprintf("[%s][DEBUG] Hello\n", date('D, d M y H:i:s O')));
                $I->deleteFile($fileName);
            }
        );

        $this->specify(
            "Logging does not contain correct number of messages after rollback",
            function () {
                $I = $this->tester;
                $fileName = $this->tester->getNewFileName('log', 'log');

                $logger = new File($this->logPath . $fileName);
                $logger->log('Hello');

                $logger->begin();

                $logger->log('Message 1');
                $logger->log('Message 2');
                $logger->log('Message 3');

                $logger->rollback();

                $logger->close();

                $I->amInPath($this->logPath);
                $I->openFile($fileName);

                $I->seeFileContentsEqual(sprintf("[%s][DEBUG] Hello\n", date('D, d M y H:i:s O')));
                $I->deleteFile($fileName);
            }
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
        $I = $this->tester;
        $fileName = $I->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);
        if (is_null($name)) {
            $logger->log($level);
            $name = 'DEBUG';
        } else {
            $logger->log($level, 'Hello');
        }
        $logger->close();

        $I->amInPath($this->logPath);
        $I->openFile($fileName);
        $expected = sprintf(
            "[%s][%s] Hello",
            date('D, d M y H:i:s O'),
            $name
        );
        $I->seeInThisFile($expected);
        $I->deleteFile($fileName);
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
        $I = $this->tester;
        $fileName = $I->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->close();

        $I->amInPath($this->logPath);
        $I->seeFileFound($fileName);
        $I->deleteFile($fileName);
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
        $I = $this->tester;
        $fileName = $I->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->$function('Goodbye');
        $logger->close();

        $I->amInPath($this->logPath);
        $I->openFile($fileName);
        $I->seeNumberNewLines(3);
        $I->deleteFile($fileName);
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
        $I = $this->tester;
        $fileName = $I->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->close();

        $I->amInPath($this->logPath);
        $contents = \file($this->logPath . $fileName);
        $I->deleteFile($fileName);

        $position = strpos($contents[0], '[' . strtoupper($function) . ']');
        $actual   = ($position !== false);
        expect($actual)->true();

        $position = strpos($contents[0], 'Hello');
        $actual   = ($position !== false);
        expect($actual)->true();
    }
}
