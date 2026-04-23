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
use Phalcon\Tests\AbstractUnitTestCase;
use Psr\Log\LogLevel;

use function file_get_contents;
use function logsDir;
use function sprintf;
use function strtoupper;
use function uniqid;

final class LogTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerLog(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir($fileName);
        $adapter    = new Stream($outputPath);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $levels = [
            Enum::ALERT     => LogLevel::ALERT,
            Enum::CRITICAL  => LogLevel::CRITICAL,
            Enum::DEBUG     => LogLevel::DEBUG,
            Enum::EMERGENCY => LogLevel::EMERGENCY,
            Enum::ERROR     => LogLevel::ERROR,
            Enum::INFO      => LogLevel::INFO,
            Enum::NOTICE    => LogLevel::NOTICE,
            Enum::WARNING   => LogLevel::WARNING,
            Enum::CUSTOM    => 'custom',
            'alert'         => LogLevel::ALERT,
            'critical'      => LogLevel::CRITICAL,
            'debug'         => LogLevel::DEBUG,
            'emergency'     => LogLevel::EMERGENCY,
            'error'         => LogLevel::ERROR,
            'info'          => LogLevel::INFO,
            'notice'        => LogLevel::NOTICE,
            'warning'       => LogLevel::WARNING,
            'custom'        => 'custom',
            99              => 'custom',
        ];

        foreach ($levels as $level => $levelName) {
            $logger->log($level, 'Message ' . $levelName);
        }

        $contents = file_get_contents($outputPath);
        foreach ($levels as $levelName) {
            $expected = sprintf(
                '[%s] Message %s',
                $levelName,
                $levelName
            );

            $this->assertStringContainsString($expected, $contents);
        }

        $adapter->close();
        $this->safeDeleteFile($outputPath);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-09-11
     */
    public function testLoggerLogLogInterpolator(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir($fileName);
        $formatter  = new Line(
            '%message%-[%level%]-%server%:%user%',
            'U.u'
        );
        $context   = [
            'server' => uniqid('srv-'),
            'user'   => uniqid('usr-'),
        ];
        $adapter   = new Stream($outputPath);
        $adapter->setFormatter($formatter);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $logger->log(Enum::DEBUG, 'log message', $context);

        $contents = file_get_contents($outputPath);
        $expected = sprintf(
            'log message-[debug]-%s:%s',
            $context['server'],
            $context['user']
        );
        $this->assertStringContainsString($expected, $contents);

        $adapter->close();
        $this->safeDeleteFile($outputPath);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerLogLogLevel(): void
    {
        $fileName   = $this->getNewFileName('log', 'log');
        $outputPath = logsDir($fileName);
        $adapter  = new Stream($outputPath);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $logger->setLogLevel(Enum::ALERT);

        $levelsYes = [
            Enum::ALERT     => LogLevel::ALERT,
            Enum::CRITICAL  => LogLevel::CRITICAL,
            Enum::EMERGENCY => LogLevel::EMERGENCY,
            'alert'         => LogLevel::ALERT,
            'critical'      => LogLevel::CRITICAL,
            'emergency'     => LogLevel::EMERGENCY,
        ];

        $levelsNo = [
            Enum::DEBUG   => LogLevel::DEBUG,
            Enum::ERROR   => LogLevel::ERROR,
            Enum::INFO    => LogLevel::INFO,
            Enum::NOTICE  => LogLevel::NOTICE,
            Enum::WARNING => LogLevel::WARNING,
            Enum::CUSTOM  => 'custom',
            'debug'       => LogLevel::DEBUG,
            'error'       => LogLevel::ERROR,
            'info'        => LogLevel::INFO,
            'notice'      => LogLevel::NOTICE,
            'warning'     => LogLevel::WARNING,
            'custom'      => 'custom',
        ];

        foreach ($levelsYes as $level => $levelName) {
            $logger->log($level, 'Message ' . $levelName);
        }

        foreach ($levelsNo as $level => $levelName) {
            $logger->log($level, 'Message ' . $levelName);
        }

        $contents = file_get_contents($outputPath);
        foreach ($levelsYes as $levelName) {
            $expected = sprintf(
                '[%s] Message %s',
                $levelName,
                $levelName
            );
            $this->assertStringContainsString($expected, $contents);
        }

        foreach ($levelsNo as $levelName) {
            $expected = sprintf(
                '[%s] Message %s',
                $levelName,
                $levelName
            );
            $this->assertStringNotContainsString($expected, $contents);
        }

        $adapter->close();
        $this->safeDeleteFile($outputPath);
    }
}
