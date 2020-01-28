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
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use UnitTester;

class GetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: getFormatter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopGetFormatter(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - getFormatter()');

        $adapter = new Noop();

        $adapter->getFormatter(
            new Line()
        );

        $I->assertInstanceOf(
            FormatterInterface::class,
            $adapter->getFormatter()
        );
    }
}
