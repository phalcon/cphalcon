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

use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Exception;
use UnitTester;

use function serialize;

class SerializeUnserializeCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: serialize()/unserialize
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-09-03
     * @issue  15638
     */
    public function loggerAdapterNoopSerializeUnserialize(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - serialize()/unserialize()');

        $I->expectThrowable(
            new Exception("This object cannot be serialized"),
            function () {
                $adapter = new Noop();

                $object = serialize($adapter);
            }
        );
    }
}
