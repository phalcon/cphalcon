<?php

namespace Phalcon\Test\Unit\Logger;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\File;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Logger\Formatter\Json;
use Phalcon\Test\Proxy\Logger\Multiple;

/**
 * \Phalcon\Test\Unit\Logger\MultipleTest
 * Tests the \Phalcon\Logger\Multiple component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Logger
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MultipleTest extends UnitTest
{
    protected  $logPath = '';

    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        $this->logPath = PATH_OUTPUT . 'tests/logs/';
    }

    /**
     * Tests setLogLevel method with Multiple Logger
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-02-16
     */
    public function testSetLogLevel()
    {
        $this->specify(
            "setLogLevel does not work correctly",
            function () {
                $I = $this->tester;
                $fileName1 = $I->getNewFileName('log', 'log');
                $fileName2 = $I->getNewFileName('log', 'log');

                $logger = new Multiple();

                $logger->push(new File($this->logPath . $fileName1));
                $logger->push(new File($this->logPath . $fileName2));
                $logger->setFormatter(new Json());

                $logger->setLogLevel(Logger::WARNING);
                $logger->log('This is an ignored debug');
                $logger->log("This is a warning", Logger::WARNING);
                $logger->error("This is an error");
                $logger->setLogLevel(Logger::DEBUG);
                $logger->log('This is a debug');

                $content =<<<LOG
{"type":"WARNING","message":"This is a warning","timestamp":%s}
{"type":"ERROR","message":"This is an error","timestamp":%s}
{"type":"DEBUG","message":"This is a debug","timestamp":%s}
LOG;

                $content = sprintf($content, time(), time(), time());

                $I->amInPath($this->logPath);

                $I->seeFileFound($fileName1);
                $I->openFile($fileName1);
                $I->seeInThisFile($content);
                $I->seeNumberNewLines(4);
                $I->deleteFile($fileName1);

                $I->seeFileFound($fileName2);
                $I->openFile($fileName2);
                $I->seeNumberNewLines(4);
                $I->seeInThisFile($content);
                $I->deleteFile($fileName2);
            }
        );
    }
}
