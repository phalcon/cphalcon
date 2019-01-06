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

/**
 * @todo Until I figure this approach, this stays here and can be used for other
 *       tests in this namespace
 */

namespace Phalcon\Test\Unit\Logger\Adapter\Syslog {
    function syslog($level, $message)
    {
    }

    function closelog()
    {
        return true;
    }

    use Phalcon\Logger;
    use Phalcon\Logger\Adapter\Syslog;
    use Phalcon\Logger\Item;
    use UnitTester;

    /**
     * Class AddCest
     *
     * @package Phalcon\Test\Unit\Logger
     */
    class AddCest
    {
        /**
         * Tests Phalcon\Logger\Adapter\Syslog :: add()
         *
         * @param UnitTester $I
         *
         * @author Phalcon Team <team@phalconphp.com>
         * @since  2018-11-13
         */
        public function loggerAdapterSyslogAdd(UnitTester $I)
        {
            $I->wantToTest('Logger\Adapter\Syslog - add()');
            $streamName = $I->getNewFileName('log', 'log');
            $adapter    = new Syslog($streamName);

            $adapter->begin();
            $item1 = new Item('Message 1', 'debug', Logger::DEBUG);
            $item2 = new Item('Message 2', 'debug', Logger::DEBUG);
            $item3 = new Item('Message 3', 'debug', Logger::DEBUG);

            $adapter
                ->add($item1)
                ->add($item2)
                ->add($item3)
            ;

            $adapter->commit();

            $actual = $adapter->close();
            $I->assertTrue($actual);
        }
    }
}
