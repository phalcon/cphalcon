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

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use UnitTester;
use function outputDir;

/**
 * Class SetFormatterCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class SetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: setFormatter()
     *
     * @param UnitTester $I
     */
    public function loggerAdapterStreamSetFormatter(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - setFormatter()');

        $fileName = $I->getNewFileName('log', 'log');
        $fileName = logsDir($fileName);

        $adapter = new Stream($fileName);
        $adapter->setFormatter(new Line());

        $class  = FormatterInterface::class;
        $actual = $adapter->getFormatter();
        $I->assertInstanceOf($class, $actual);
        $I->safeDeleteFile($fileName);
    }
}
