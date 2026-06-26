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

/**
 * @todo Until I figure this approach, this stays here and can be used for other
 *       tests in this namespace
 */

namespace Phalcon\Tests\Unit\Logger\Adapter\Syslog;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Item;
use Phalcon\Tests\AbstractUnitTestCase;

use function date_default_timezone_get;

final class AddTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterSyslogAdd(): void
    {
        $streamName = $this->getNewFileName('log', 'log');
        $timezone   = date_default_timezone_get();
        $datetime   = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter    = new Syslog($streamName);

        $adapter->begin();

        $item1 = new Item(
            'Message 1',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $item2 = new Item(
            'Message 2',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $item3 = new Item(
            'Message 3',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $adapter
            ->add($item1)
            ->add($item2)
            ->add($item3)
        ;

        $adapter->commit();

        $this->assertTrue(
            $adapter->close()
        );
    }
}
