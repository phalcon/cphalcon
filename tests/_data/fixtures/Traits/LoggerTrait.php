<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Logger\Logger;
use Phalcon\Logger\Adapter\Stream;
use UnitTester;
use function outputDir;

/**
 * @package Phalcon\Test\Fixtures\Traits
 */
trait LoggerTrait
{
    protected function runLoggerFile(UnitTester $I, string $level)
    {
        $logPath  = outputDir('tests/logs/');
        $fileName = $I->getNewFileName('log', 'log');
        $adapter  = new Stream($logPath . $fileName);

        $logString = "Hello";

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $logTime = date('D, d M y H:i:s O');

        $logger->{$level}($logString);

        $logger->getAdapter('one')->close();

        $I->amInPath($logPath);
        $I->openFile($fileName);

        $I->seeInThisFile(
            sprintf(
                "[%s][%s] " . $logString,
                $logTime,
                $level
            )
        );

        $I->safeDeleteFile($fileName);
    }
}
