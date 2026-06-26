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
use DateTimeZone;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Item;
use Phalcon\Tests\AbstractUnitTestCase;

use function date_default_timezone_get;

final class ProcessTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerAdapterNoopProcess(): void
    {
        $timezone = date_default_timezone_get();
        $datetime = new DateTimeImmutable('now', new DateTimeZone($timezone));
        $adapter  = new Noop();

        $item = new Item(
            'Message 1',
            'debug',
            Enum::DEBUG,
            $datetime
        );

        $adapter->process($item);

        $actual = $adapter->close();
        $this->assertTrue($actual);
    }
}
