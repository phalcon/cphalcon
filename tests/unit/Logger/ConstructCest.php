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

//    /**
//     * Tests Phalcon\Logger :: __construct()
//     *
//     * @param UnitTester $I
//     *
//     * @author Phalcon Team <team@phalconphp.com>
//     * @since  2018-11-13
//     */
//    public function loggerConstruct(UnitTester $I)
//    {
//        $I->wantToTest('Logger - __construct()');
//        $I->skipTest('Need implementation');
//    }
//
//    public function checkSetAdaptersInConstructor(\UnitTester $I)
//    {
//        $fileName1  = $I->getNewFileName('log', 'log');
//        $fileName2  = $I->getNewFileName('log', 'log');
//
//        $adapter1 = new File($this->logPath . $fileName1);
//        $adapter2 = new File($this->logPath . $fileName2);
//        $adapter1->setFormatter(new Line('%type%|%date%|%message%'));
//        $adapter2->setFormatter(new Line('%type%|%date%|%message%'));
//
//        $logger = new Logger(
//            'my-logger',
//            [
//                'one' => $adapter1,
//                'two' => $adapter2,
//            ]
//        );
//
//        $adapters = $logger->getAdapters();
//        $I->assertEquals(2, count($adapters));
//        $I->assertTrue($adapters['one'] instanceof File);
//        $I->assertTrue($adapters['two'] instanceof File);
//        unset($logger, $adapter1, $adapter2);
//    }
//
//    public function checkAddGetRemoveAdapter(\UnitTester $I)
//    {
//        $fileName1  = $I->getNewFileName('log', 'log');
//        $fileName2  = $I->getNewFileName('log', 'log');
//
//        $adapter1 = new File($this->logPath . $fileName1);
//        $adapter2 = new File($this->logPath . $fileName2);
//        $adapter1->setFormatter(new Line('%type%|%date%|%message%'));
//        $adapter2->setFormatter(new Line('%type%|%date%|%message%'));
//
//        $logger = new Logger('my-logger');
//        $logger
//            ->addAdapter('one', $adapter1)
//            ->addAdapter('two', $adapter2);
//
//        $adapters = $logger->getAdapters();
//        $I->assertEquals(2, count($adapters));
//        $I->assertTrue($adapters['one'] instanceof File);
//        $I->assertTrue($adapters['two'] instanceof File);
//
//        $logger->removeAdapter('one');
//        $adapter = $logger->getAdapter('two');
//        $I->assertTrue($adapter instanceof File);
//
//        $adapters = $logger->getAdapters();
//        $I->assertEquals(1, count($adapters));
//        unset($logger, $adapter);
//    }
}
