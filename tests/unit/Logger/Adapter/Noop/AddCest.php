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

namespace Phalcon\Test\Unit\Logger\Adapter\Noop;

use DateTimeImmutable;
use Phalcon\Logger;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Item;
use UnitTester;

class AddCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: add()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopAdd(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - add()');

        $adapter = new Noop();

        $adapter->begin();

        $item1 = new Item(
            'Message 1',
            'debug',
            Logger::DEBUG,
            new DateTimeImmutable('now')
        );

        $item2 = new Item(
            'Message 2',
            'debug',
            Logger::DEBUG,
            new DateTimeImmutable('now')
        );

        $item3 = new Item(
            'Message 3',
            'debug',
            Logger::DEBUG,
            new DateTimeImmutable('now')
        );

        $adapter
            ->add($item1)
            ->add($item2)
            ->add($item3)
        ;

        $adapter->commit();
    }
}
