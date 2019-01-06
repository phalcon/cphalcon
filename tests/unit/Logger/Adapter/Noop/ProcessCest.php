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

namespace Phalcon\Test\Unit\Logger\Adapter\Noop;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Item;
use UnitTester;

/**
 * Class ProcessCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class ProcessCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: process()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopProcess(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - process()');
        $adapter = new Noop();

        $item = new Item('Message 1', 'debug', Logger::DEBUG);
        $adapter->process($item);
    }
}
