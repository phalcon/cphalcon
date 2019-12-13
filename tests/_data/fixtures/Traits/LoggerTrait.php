<?php

/**
* This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Exception;
use Phalcon\Logger;
use UnitTester;

use function logsDir;

trait LoggerTrait
{
    /**
     * @param UnitTester $I
     * @param string     $level
     *
     * @throws Exception
     */
    protected function runLoggerFile(UnitTester $I, string $level)
    {
        $fileName = $I->getNewFileName('log', 'log');
        $fileName = logsDir($fileName);
        $logger   = $this->getLogger($fileName);

        $logString = 'Hello';
        $logTime   = date('c');

        $logger->{$level}($logString);

        $logger->getAdapter('one')->close();

        $I->amInPath(logsDir());
        $I->openFile($fileName);

        $I->seeInThisFile(
            sprintf(
                '[%s][%s] ' . $logString,
                $logTime,
                $level
            )
        );

        $I->safeDeleteFile($fileName);
    }

    /**
     * @param string $fileName
     *
     * @return Logger
     * @throws Exception
     */
    protected function getLogger(string $fileName): Logger
    {
        $adapter = new Stream($fileName);

        return new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );
    }
}
