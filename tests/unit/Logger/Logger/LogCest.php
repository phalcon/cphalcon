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

namespace Phalcon\Tests\Unit\Logger\Logger;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Logger;
use UnitTester;

use function logsDir;
use function sprintf;
use function strtoupper;
use function uniqid;

class LogCest
{
    /**
     * Tests Phalcon\Logger :: log()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
            Enum::ALERT     => 'alert',
            Enum::CRITICAL  => 'critical',
            Enum::DEBUG     => 'debug',
            Enum::EMERGENCY => 'emergency',
            Enum::ERROR     => 'error',
            Enum::INFO      => 'info',
            Enum::NOTICE    => 'notice',
            Enum::WARNING   => 'warning',
            Enum::CUSTOM    => 'custom',
            'alert'         => 'alert',
            'critical'      => 'critical',
            'debug'         => 'debug',
            'emergency'     => 'emergency',
            'error'         => 'error',
            'info'          => 'info',
            'notice'        => 'notice',
            'warning'       => 'warning',
            'custom'        => 'custom',
        ];

        foreach ($levels as $level => $levelName) {
            $logger->log($level, 'Message ' . $levelName);
        }

        $I->amInPath($logPath);
        $I->openFile($fileName);

        foreach ($levels as $levelName) {
            $expected = sprintf(
                '[%s] Message %s',
                strtoupper($levelName),
                $levelName
            );

            $I->seeInThisFile($expected);
        }

        $adapter->close();
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests Phalcon\Logger :: log() - logLevel
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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

        $logger->setLogLevel(Enum::ALERT);

        $levelsYes = [
            Enum::ALERT     => 'alert',
            Enum::CRITICAL  => 'critical',
            Enum::EMERGENCY => 'emergency',
            'alert'         => 'alert',
            'critical'      => 'critical',
            'emergency'     => 'emergency',
        ];

        $levelsNo = [
            Enum::DEBUG   => 'debug',
            Enum::ERROR   => 'error',
            Enum::INFO    => 'info',
            Enum::NOTICE  => 'notice',
            Enum::WARNING => 'warning',
            Enum::CUSTOM  => 'custom',
            'debug'       => 'debug',
            'error'       => 'error',
            'info'        => 'info',
            'notice'      => 'notice',
            'warning'     => 'warning',
            'custom'      => 'custom',
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
                strtoupper($levelName),
                $levelName
            );
            $I->seeInThisFile($expected);
        }

        foreach ($levelsNo as $levelName) {
            $expected = sprintf(
                '[%s] Message %s',
                strtoupper($levelName),
                $levelName
            );
            $I->dontSeeInThisFile($expected);
        }

        $adapter->close();
        $I->safeDeleteFile($fileName);
    }

    /**
     * Tests Phalcon\Logger :: log() - interpolator
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-09-11
     */
    public function loggerLogLogInterpolator(UnitTester $I)
    {
        $I->wantToTest('Logger - log() - interpolator');

        $logPath   = logsDir();
        $fileName  = $I->getNewFileName('log', 'log');
        $formatter = new Line(
            '%message%-[%level%]-%server%:%user%',
            'U.u'
        );
        $context  = [
            'server' => uniqid('srv-'),
            'user'   => uniqid('usr-'),
        ];
        $adapter  = new Stream($logPath . $fileName);
        $adapter->setFormatter($formatter);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $logger->log(Enum::DEBUG, 'log message', $context);

        $I->amInPath($logPath);
        $I->openFile($fileName);

        $expected = sprintf(
            'log message-[DEBUG]-%s:%s',
            $context['server'],
            $context['user']
        );
        $I->seeInThisFile($expected);

        $adapter->close();
        $I->safeDeleteFile($fileName);
    }
}
