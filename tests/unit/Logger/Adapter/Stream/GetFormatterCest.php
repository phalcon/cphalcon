<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Adapter\Stream;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use UnitTester;
use function outputFolder;

/**
 * Class GetFormatterCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: getFormatter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterStreamGetFormatter(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - getFormatter()');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter = new Stream($streamName);
        $adapter->getFormatter(new Line());

        $class  = FormatterInterface::class;
        $actual = $adapter->getFormatter();
        $I->assertInstanceOf($class, $actual);
    }
}
