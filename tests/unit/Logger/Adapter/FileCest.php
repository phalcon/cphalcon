<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Adapter;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\File;
use Phalcon\Logger\Exception;
use Phalcon\Logger\Formatter\Json;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Multiple;
use UnitTester;

class FileCest
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
     * Tests the creation of the log file
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileCreationDefault(UnitTester $I)
    {
        $fileName = $I->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);
        $logger->log('Hello');
        $logger->close();

        $I->amInPath($this->logPath);
        $I->seeFileFound($fileName);
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests the creation of the log file +w
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileCreationWrite(UnitTester $I)
    {
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
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests if opening the file with r and logging throws exception
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @expectedException \Phalcon\Logger\Exception
     */
    public function testLoggerAdapterFileOpenReadThrowsException(UnitTester $I)
    {
        $fileName = $I->getNewFileName('log', 'log');
        $I->expectThrowable(
            new Exception('Logger must be opened in append or write mode'),
            function () use ($fileName) {
                $params = ['mode' => 'r'];

                $logger = new File($this->logPath . $fileName);
                $logger->log('Hello');
                $logger->close();

                $logger = new File($this->logPath . $fileName, $params);
                $logger->log('New Contents');
                $logger->close();
            }
        );

        $I->amInPath($this->logPath);
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests how many lines the file has on creation
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileNumberOfMessagesLogged(UnitTester $I)
    {
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
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests default logging uses EMERGENCY
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileDefaultLoggingUsesDebug(UnitTester $I)
    {
        $this->runLogging($I, 'Hello', null);
    }

    /**
     * Runs the various logging function testLoggerAdapterFiles
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @param UnitTester $I
     * @param mixed      $level
     * @param null       $name
     */
    protected function runLogging(UnitTester $I, $level, $name = null)
    {
        $fileName = $I->getNewFileName('log', 'log');
        $logger   = new File($this->logPath . $fileName);
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
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests ERROR logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileErrorLogging(UnitTester $I)
    {
        $this->runLogging($I, Logger::ERROR, 'ERROR');
    }

    /**
     * Tests DEBUG logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileDebugLogging(UnitTester $I)
    {
        $this->runLogging($I, Logger::DEBUG, 'DEBUG');
    }

    /**
     * Tests NOTICE logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileNoticeLogging(UnitTester $I)
    {
        $this->runLogging($I, Logger::NOTICE, 'NOTICE');
    }

    /**
     * Tests INFO logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileInfoLogging(UnitTester $I)
    {
        $this->runLogging($I, Logger::INFO, 'INFO');
    }

    /**
     * Tests WARNING logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileWarningLogging(UnitTester $I)
    {
        $this->runLogging($I, Logger::WARNING, 'WARNING');
    }

    /**
     * Tests ALERT logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileAlertLogging(UnitTester $I)
    {
        $this->runLogging($I, Logger::ALERT, 'ALERT');
    }

    /**
     * Tests multiple loggers
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2798
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-28
     */
    public function testMultipleLoggers(UnitTester $I)
    {
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
        $I->safeDeleteFile($file1);

        $I->openFile($file2);
        $I->seeFileContentsEqual($expected);
        $I->safeDeleteFile($file2);
    }

    /**
     * Tests multiple log levels
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileMultipleLogLevelsSetProperly(UnitTester $I)
    {
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
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests the creation of the log file with debug()
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileCreationMessagesLog(UnitTester $I)
    {
        $levels = [
            'debug',
            'error',
            'info',
            'notice',
            'warning',
            'alert',
        ];

        foreach ($levels as $level) {
            $this->createOfLogFile($I, $level);
            $this->numberOfMessagesLogged($I, $level);
            $this->logging($I, $level);
        }
    }

    /**
     * Runs the test for the creation of a file with logging
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @param UnitTester $I
     * @param string     $function
     */
    protected function createOfLogFile(UnitTester $I, $function)
    {
        $fileName = $I->getNewFileName('log', 'log');
        $logger   = new File($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->close();

        $I->amInPath($this->logPath);
        $I->seeFileFound($fileName);
        $I->safeDeleteFile($fileName);
    }

    /**
     * Runs the test for how many lines the file has on creation
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-13
     *
     * @param UnitTester $I
     * @param string     $function
     */
    protected function numberOfMessagesLogged(UnitTester $I, $function)
    {
        $fileName = $I->getNewFileName('log', 'log');
        $logger   = new File($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->$function('Goodbye');
        $logger->close();

        $I->amInPath($this->logPath);
        $I->openFile($fileName);
        $I->seeNumberNewLines(3);
        $I->safeDeleteFile($fileName);
    }

    /**
     * Runs logging test
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     *
     * @param UnitTester $I
     * @param            $function
     */
    protected function logging(UnitTester $I, $function)
    {
        $fileName = $I->getNewFileName('log', 'log');
        $logger   = new File($this->logPath . $fileName);
        $logger->$function('Hello');
        $logger->close();

        $I->amInPath($this->logPath);
        $contents = \file($this->logPath . $fileName);
        $I->safeDeleteFile($fileName);

        $position = strpos($contents[0], '[' . strtoupper($function) . ']');
        $actual   = ($position !== false);
        $I->assertTrue($actual);

        $position = strpos($contents[0], 'Hello');
        $actual   = ($position !== false);
        $I->assertTrue($actual);
    }

    /**
     * Tests set/getFormat
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileSetGetFormat(UnitTester $I)
    {
        $formatter = new Line();

        $format = '%type%|%date%|%message%';
        $formatter->setFormat($format);

        $expected = $format;
        $actual   = $formatter->getFormat();

        $I->assertEquals(
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
    public function testLoggerAdapterFileNewFormatLogsCorrectly(UnitTester $I)
    {
        $fileName  = $I->getNewFileName('log', 'log');
        $logger    = new File($this->logPath . $fileName);
        $formatter = new Line('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $contents = \file($this->logPath . $fileName);
        $message  = explode('|', $contents[0]);
        $I->safeDeleteFile($this->logPath . $fileName);

        $I->assertEquals(
            'DEBUG',
            $message[0],
            'New format, type not set correctly'
        );
        $I->assertEquals(
            'Hello' . PHP_EOL,
            $message[2],
            'New format, message not set correctly'
        );
    }

    /**
     * Tests setting Json formatter
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2262
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-28
     */
    public function testLoggerAdapterFileSettingJsonFormatter(UnitTester $I)
    {
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
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests new format logs correctly
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-17
     */
    public function testLoggerAdapterFileNewFormatFormatsDateCorrectly(UnitTester $I)
    {
        $fileName  = $I->getNewFileName('log', 'log');
        $logger    = new File($this->logPath . $fileName);
        $formatter = new Line('%type%|%date%|%message%');

        $logger->setFormatter($formatter);
        $logger->log('Hello');
        $logger->close();

        $contents = \file($this->logPath . $fileName);
        $message  = explode('|', $contents[0]);
        $I->safeDeleteFile($this->logPath . $fileName);

        $date = new \DateTime($message[1]);

        $expected = date('Y-m-d H');
        $actual   = $date->format('Y-m-d H');

        $I->assertEquals(
            $expected,
            $actual,
            'Date format not set properly'
        );
    }

    /**
     * Tests the begin/commit
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileCommit(UnitTester $I)
    {
        $fileName = $I->getNewFileName('log', 'log');
        $logger   = new File($this->logPath . $fileName);
        $logger->begin();
        $logger->log('Hello');
        $logger->commit();

        $I->amInPath($this->logPath);
        $I->openFile($fileName);
        $I->seeNumberNewLines(2);

        $logger->close();
        $I->safeDeleteFile($fileName);

        $fileName = $I->getNewFileName('log', 'log');

        $logger = new File($this->logPath . $fileName);
        $logger->log('Hello');

        $logger->begin();

        $logger->log('Message 1');
        $logger->log('Message 2');
        $logger->log('Message 3');

        $logger->commit();

        $logger->close();

        $contents = \file($this->logPath . $fileName);
        $I->safeDeleteFile($this->logPath . $fileName);

        $expected = 4;
        $actual   = count($contents);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the begin/rollback
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-13
     */
    public function testLoggerAdapterFileRollback(UnitTester $I)
    {
        $fileName = $I->getNewFileName('log', 'log');
        $logger   = new File($this->logPath . $fileName);
        $logger->log('Hello');

        $logger->close();

        $I->amInPath($this->logPath);
        $I->openFile($fileName);
        $I->seeFileContentsEqual(sprintf("[%s][DEBUG] Hello\n", date('D, d M y H:i:s O')));
        $I->safeDeleteFile($fileName);

        $fileName = $I->getNewFileName('log', 'log');

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
        $I->safeDeleteFile($fileName);
    }
}
