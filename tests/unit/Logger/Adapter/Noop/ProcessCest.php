<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Logger\Adapter\Noop;

use DateTimeImmutable;
use Phalcon\Logger;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Item;
use UnitTester;

class ProcessCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: process()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopProcess(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - process()');

        $adapter = new Noop();
        $time    = new DateTimeImmutable('now');
        $item    = new Item('Message 1', 'debug', Logger::DEBUG, $time);

        $adapter->process($item);
    }
}
