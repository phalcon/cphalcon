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

use Phalcon\Logger\Adapter\Noop;
use UnitTester;

class CloseCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: close()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopClose(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - close()');

        $adapter = new Noop();

        $I->assertTrue(
            $adapter->close()
        );
    }
}
