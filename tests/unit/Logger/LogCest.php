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

namespace Phalcon\Test\Unit\Logger;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
use UnitTester;
use function outputFolder;

/**
 * Class LogCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class LogCest
{
    /**
     * Tests Phalcon\Logger :: log()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerLog(UnitTester $I)
    {
        $I->wantToTest('Logger - log()');
        $logPath  = outputFolder('tests/logs/');
        $fileName = $I->getNewFileName('log', 'log');
        $adapter  = new Stream($logPath . $fileName);

        $logger = new Logger('my-logger', ['one' => $adapter]);

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
        ];

        foreach ($levels as $level => $levelName) {
            $logger->log($level, 'Message ' . $levelName);
        }

        $I->amInPath($logPath);
        $I->openFile($fileName);

        foreach ($levels as $levelName) {
            $expected = sprintf(
                '[%s][%s] Message %s',
                date('D, d M y H:i:s O'),
                $levelName,
                $levelName
            );

            $I->seeInThisFile($expected);
        }
        $I->safeDeleteFile($fileName);
    }
}
