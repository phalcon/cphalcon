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

namespace Phalcon\Test\Unit\Logger\Adapter\Stream;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use UnitTester;

class SetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: setFormatter()
     */
    public function loggerAdapterStreamSetFormatter(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - setFormatter()');

        $fileName = $I->getNewFileName('log', 'log');
        $fileName = logsDir($fileName);

        $adapter = new Stream($fileName);

        $adapter->setFormatter(
            new Line()
        );

        $actual = $adapter->getFormatter();

        $I->assertInstanceOf(
            FormatterInterface::class,
            $actual
        );

        $I->safeDeleteFile($fileName);
    }
}
