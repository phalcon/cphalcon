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

use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Exception;
use UnitTester;
use function outputFolder;

/**
 * Trait LoggerTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait LoggerTrait
{
    /**
     * @param UnitTester $I
     * @param string     $level
     */
    protected function runLoggerFile(UnitTester $I, string $level)
    {
        $logPath  = outputFolder('tests/logs/');
        $fileName = $I->getNewFileName('log', 'log');
        $adapter  = new Stream($logPath . $fileName);

        $logger = new Logger('my-logger', ['one' => $adapter]);
        $logger->{$level}('Hello');

        $logger->getAdapter('one')->close();

        $I->amInPath($logPath);
        $I->openFile($fileName);
        $expected = sprintf(
            "[%s][%s] Hello",
            date('D, d M y H:i:s O'),
            $level
        );

        $I->seeInThisFile($expected);
        $I->safeDeleteFile($fileName);
    }
}
