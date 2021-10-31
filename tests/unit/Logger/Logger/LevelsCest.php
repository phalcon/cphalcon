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

use Codeception\Example;
use DateTime;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Logger;
use UnitTester;

use function date;
use function end;
use function file_get_contents;
use function logsDir;
use function preg_match;
use function strtoupper;

class LevelsCest
{
    /**
     * Tests Phalcon\Logger :: alert()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAlert(UnitTester $I, Example $example)
    {
        $I->wantToTest('Logger - ' . $example[0] . '()');

        $level    = $example[0];
        $fileName = $I->getNewFileName('log', 'log');
        $fileName = logsDir($fileName);
        $adapter = new Stream($fileName);
        $logger  = new Logger('my-logger', ['one' => $adapter]);

        $logString = 'Hello';
        $logTime   = date('c');

        $logger->{$level}($logString);

        $logger->getAdapter('one')->close();

        $I->amInPath(logsDir());
        $I->openFile($fileName);

        // Check if the $logString is in the log file
        $I->seeInThisFile($logString);

        // Check if the level is in the log file
        $I->seeInThisFile('[' . strtoupper($level) . ']');

        // Check time content
        $content = file_get_contents($fileName);

        // Get time part
        $matches = [];
        preg_match(
            '/\[(.*)\]\[' . strtoupper($level) . '\]/',
            $content,
            $matches
        );
        $I->assertEquals(count($matches), 2);

        // Get Extract time
        $date             = end($matches);
        $logDateTime      = new DateTime($date);
        $dateTimeAfterLog = new DateTime($logTime);
        $nInterval        = $logDateTime->diff($dateTimeAfterLog)->format('%s');
        $nSecondThreshold = 60;

        $I->assertLessThan($nSecondThreshold, $nInterval);

        $I->safeDeleteFile($fileName);
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
            ['alert'],
            ['critical'],
            ['debug'],
            ['emergency'],
            ['error'],
            ['info'],
            ['notice'],
            ['warning'],
        ];
    }
}
