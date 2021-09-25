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
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use UnitTester;

class GetSetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Noop :: getFormatter()/setFormatter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerAdapterNoopGetSetFormatter(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Noop - getFormatter()/setFormatter()');

        $adapter = new Noop();

        $adapter->setFormatter(new Line());

        $I->assertInstanceOf(FormatterInterface::class, $adapter->getFormatter());
    }
}
