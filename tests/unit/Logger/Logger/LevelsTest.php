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

use DateTime;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Logger;
use Phalcon\Tests\AbstractUnitTestCase;
use Psr\Log\LogLevel;

use function date;
use function end;
use function file_get_contents;
use function logsDir;
use function preg_match;
use function strtoupper;

final class LevelsTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getExamples(): array
    {
        return [
            [LogLevel::ALERT],
            [LogLevel::CRITICAL],
            [LogLevel::DEBUG],
            [LogLevel::EMERGENCY],
            [LogLevel::ERROR],
            [LogLevel::INFO],
            [LogLevel::NOTICE],
            [LogLevel::WARNING],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testLoggerAlert(
        string $level
    ): void {
        $fileName = $this->getNewFileName('log', 'log');
        $fileName = logsDir($fileName);
        $adapter  = new Stream($fileName);
        $logger   = new Logger('my-logger', ['one' => $adapter]);

        $logString = 'Hello';
        $logTime   = date('c');

        $logger->{$level}($logString);

        $logger->getAdapter('one')
               ->close()
        ;

        $content = file_get_contents($fileName);

        // Check if the $logString is in the log file
        $this->assertStringContainsString($logString, $content);

        // Check if the level is in the log file
        $this->assertStringContainsString(
            '[' . $level . ']',
            $content
        );

        // Check time content
        $content = file_get_contents($fileName);

        // Get time part
        $matches = [];
        preg_match(
            '/\[(.*)]\[' . $level . ']/',
            $content,
            $matches
        );
        $this->assertSame(2, count($matches));

        // Get Extract time
        $date             = end($matches);
        $logDateTime      = new DateTime($date);
        $dateTimeAfterLog = new DateTime($logTime);
        $nInterval        = $logDateTime->diff($dateTimeAfterLog)
                                        ->format('%s')
        ;
        $nSecondThreshold = 60;

        $this->assertLessThan($nSecondThreshold, $nInterval);

        $this->safeDeleteFile($fileName);
    }
}
