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
use Phalcon\Logger\Formatter\Json;
use Phalcon\Test\Fixtures\Traits\LoggerTrait;
use Psr\Log\LoggerInterface;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class ConstructCest
{
    use LoggerTrait;

    /**
     * Tests Phalcon\Logger :: __construct() - implement PSR
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerConstructImplementPsr(UnitTester $I)
    {
        $I->wantToTest('Logger - __construct() - implement PSR');
        $logger = new Logger('my-logger');
        $I->assertInstanceOf(LoggerInterface::class, $logger);
    }

    /**
     * Tests Phalcon\Logger :: __construct() - constants
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerConstructConstants(UnitTester $I)
    {
        $I->wantToTest('Logger - __construct() - constants');
        $I->assertEquals(2, Logger::ALERT);
        $I->assertEquals(1, Logger::CRITICAL);
        $I->assertEquals(7, Logger::DEBUG);
        $I->assertEquals(0, Logger::EMERGENCY);
        $I->assertEquals(3, Logger::ERROR);
        $I->assertEquals(6, Logger::INFO);
        $I->assertEquals(5, Logger::NOTICE);
        $I->assertEquals(4, Logger::WARNING);
        $I->assertEquals(8, Logger::CUSTOM);
    }

    /**
     * Tests Phalcon\Logger :: __construct() - file with json formatter
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2262
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-28
     */
    public function loggerConstructStreamWithJsonConstants(UnitTester $I)
    {
        $I->wantToTest('Logger - __construct() - file with json formatter');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = outputFolder('tests/logs/');
        $adapter    = new Stream($outputPath . $fileName);
        $adapter->setFormatter(new Json());

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter,
            ]
        );

        $time = time();
        $logger->debug('This is a message');
        $logger->log(Logger::ERROR, "This is an error");
        $logger->error("This is another error");

        $I->amInPath($outputPath);
        $I->openFile($fileName);

        $expected = sprintf(
            '{"type":"debug","message":"This is a message","timestamp":"%s"}' . PHP_EOL .
            '{"type":"error","message":"This is an error","timestamp":"%s"}' . PHP_EOL .
            '{"type":"error","message":"This is another error","timestamp":"%s"}',
            date('D, d M y H:i:s O', $time),
            date('D, d M y H:i:s O', $time),
            date('D, d M y H:i:s O', $time)
        );

        $I->seeInThisFile($expected);
        $I->safeDeleteFile($outputPath . $fileName);
    }
}
