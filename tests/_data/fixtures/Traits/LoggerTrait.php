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
use DateTime;
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
        
        //Check if the $logString is in the log file
        $I->seeInThisFile($logString);

        //Check if the level is in the log file
        $I->seeInThisFile('['.$level.']');

        //Check time content
        $sContent = file_get_contents($fileName);

        //Get time part
        $aDate = [];
        preg_match('/\[(.*)\]\['.$level.'\]/', $sContent, $aDate);
        $I->assertEquals(count($aDate), 2);

        //Get Extract time
        $sDate              = end($aDate);
        $sLogDateTime       = new DateTime($sDate);
        $sDateTimeAfterLog  = new DateTime($logTime);

        $nInterval          = $sLogDateTime->diff($sDateTimeAfterLog)->format('%s');
        $nSecondThreshold   = 60;

        $I->assertLessThan($nSecondThreshold,$nInterval);

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
