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

namespace Phalcon\Test\Unit\Logger\Logger;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Adapter\Syslog;
use UnitTester;

use function logsDir;
use function sprintf;

class LogCest
{
    /**
     * Tests Phalcon\Logger :: log()
     */
    public function loggerLog(UnitTester $I)
    {
        $I->wantToTest('Logger - log()');

        $logPath  = logsDir();
        $fileName = $I->getNewFileName('log', 'log');
        $adapter  = new Stream($logPath . $fileName);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $levels = [
            Logger::ALERT     => 'alert',
            Logger::CRITICAL  => 'critical',
            Logger::DEBUG     => 'debug',
            Logger::EMERGENCY => 'emergency',
            Logger::ERROR     => 'error',
            Logger::INFO      => 'info',
            Logger::NOTICE    => 'notice',
            Logger::WARNING   => 'warning',
            Logger::CUSTOM    => 'custom',
            'alert'           => 'alert',
            'critical'        => 'critical',
            'debug'           => 'debug',
            'emergency'       => 'emergency',
            'error'           => 'error',
            'info'            => 'info',
            'notice'          => 'notice',
            'warning'         => 'warning',
            'custom'          => 'custom',
            'unknown'         => 'custom',
        ];

        foreach ($levels as $level => $levelName) {
            $logger->log($level, 'Message ' . $levelName);
        }

        $I->amInPath($logPath);
        $I->openFile($fileName);

        foreach ($levels as $levelName) {
            $expected = sprintf(
                '[%s] Message %s',
                $levelName,
                $levelName
            );

            $I->seeInThisFile($expected);
        }

        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests Phalcon\Logger :: log() - logLevel
     */
    public function loggerLogLogLevel(UnitTester $I)
    {
        $I->wantToTest('Logger - log() - logLevel');

        $logPath  = logsDir();
        $fileName = $I->getNewFileName('log', 'log');
        $adapter  = new Stream($logPath . $fileName);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $logger->setLogLevel(Logger::ALERT);

        $levelsYes = [
            Logger::ALERT     => 'alert',
            Logger::CRITICAL  => 'critical',
            Logger::EMERGENCY => 'emergency',
            'alert'           => 'alert',
            'critical'        => 'critical',
            'emergency'       => 'emergency',
        ];

        $levelsNo = [
            Logger::DEBUG   => 'debug',
            Logger::ERROR   => 'error',
            Logger::INFO    => 'info',
            Logger::NOTICE  => 'notice',
            Logger::WARNING => 'warning',
            Logger::CUSTOM  => 'custom',
            'debug'         => 'debug',
            'error'         => 'error',
            'info'          => 'info',
            'notice'        => 'notice',
            'warning'       => 'warning',
            'custom'        => 'custom',
            'unknown'       => 'custom',
        ];

        foreach ($levelsYes as $level => $levelName) {
            $logger->log($level, 'Message ' . $levelName);
        }

        foreach ($levelsNo as $level => $levelName) {
            $logger->log($level, 'Message ' . $levelName);
        }

        $I->amInPath($logPath);
        $I->openFile($fileName);

        foreach ($levelsYes as $levelName) {
            $expected = sprintf(
                '[%s] Message %s',
                $levelName,
                $levelName
            );
            $I->seeInThisFile($expected);
        }

        foreach ($levelsNo as $levelName) {
            $expected = sprintf(
                '[%s] Message %s',
                $levelName,
                $levelName
            );
            $I->dontSeeInThisFile($expected);
        }

        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests Phalcon\Logger :: log()
     */
    public function loggerLogSyslog(UnitTester $I)
    {
        $I->wantToTest('Logger - log() - syslog');

        $adapter = new Syslog("php:://memory");

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $logger->log(Logger::ERROR, 'Message Error');
    }
}
