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

use \Phalcon\Logger\Adapter\File as PhTLoggerAdapterFile;

use Phalcon\Tests\unit\Phalcon\Logger\Helper\FileBase as FBase;

class TransactionTest extends FBase
{
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

                $fileName = newFileName('log', 'log');

                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
                $logger->log('Hello');

                $logger->close();

                $contents = file($this->logPath . $fileName);
                cleanFile($this->logPath, $fileName);

                $expected = 1;
                $actual   = count($contents);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "Logging does not contain correct number of messages after commit",
            function () {

                $fileName = newFileName('log', 'log');

                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
                $logger->log('Hello');

                $logger->begin();

                $logger->log('Message 1');
                $logger->log('Message 2');
                $logger->log('Message 3');

                $logger->commit();

                $logger->close();

                $contents = file($this->logPath . $fileName);
                cleanFile($this->logPath, $fileName);

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

                $fileName = newFileName('log', 'log');

                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
                $logger->log('Hello');

                $logger->close();

                $contents = file($this->logPath . $fileName);
                cleanFile($this->logPath, $fileName);

                $expected = 1;
                $actual   = count($contents);

                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            "Logging does not contain correct number of messages after rollback",
            function () {

                $fileName = newFileName('log', 'log');

                $logger = new PhTLoggerAdapterFile($this->logPath . $fileName);
                $logger->log('Hello');

                $logger->begin();

                $logger->log('Message 1');
                $logger->log('Message 2');
                $logger->log('Message 3');

                $logger->rollback();

                $logger->close();

                $contents = file($this->logPath . $fileName);
                cleanFile($this->logPath, $fileName);

                $expected = 1;
                $actual   = count($contents);

                expect($actual)->equals($expected);
            }
        );
    }
}
