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
use Phalcon\Logger\Exception;
use UnitTester;

/**
 * Class GetAdapterCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetAdapterCest
{
    /**
     * Tests Phalcon\Logger :: getAdapter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Logger - getAdapter()');
        $fileName1  = $I->getNewFileName('log', 'log');
        $outputPath = outputFolder('tests/logs/');
        $adapter1   = new Stream($outputPath . $fileName1);

        $logger = new Logger(
            'my-logger',
            [
                'one' => $adapter1,
            ]
        );


        $class  = Stream::class;
        $actual = $logger->getAdapter('one');
        $I->assertInstanceOf($class, $actual);

        $I->safeDeleteFile($outputPath . $fileName1);
    }

    /**
     * Tests Phalcon\Logger :: getAdapter() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerGetAdapterUnknown(UnitTester $I)
    {
        $I->wantToTest('Logger - getAdapter() - unknown');

        $I->expectThrowable(
            new Exception('Adapter does not exist for this logger'),
            function () {
                $logger = new Logger('my-logger');
                $logger->getAdapter('unknown');
            }
        );
    }
}
