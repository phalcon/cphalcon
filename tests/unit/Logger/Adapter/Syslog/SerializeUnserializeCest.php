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

namespace Phalcon\Test\Unit\Logger\Adapter\Syslog;

use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Logger\Exception;
use UnitTester;

use function serialize;

class SerializeUnserializeCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: serialize()/unserialize
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-09-03
     * @issue  15638
     */
    public function loggerAdapterSyslogSerializeUnserialize(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - serialize()/unserialize()');

        $I->expectThrowable(
            new Exception("This object cannot be serialized"),
            function () use ($I) {
                $streamName = $I->getNewFileName('log', 'log');
                $adapter    = new Syslog($streamName);

                $object = serialize($adapter);
            }
        );
    }
}
