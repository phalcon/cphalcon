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
use UnitTester;

/**
 * Class GetNameCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetNameCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: getName()
     *
     * @param UnitTester $I
     */
    public function loggerAdapterStreamGetName(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Stream - getName()');
        $fileName   = $I->getNewFileName('log', 'log');
        $outputPath = outputDir();
        $adapter    = new Stream($outputPath . $fileName);

        $expected = $outputPath . $fileName;
        $actual   = $adapter->getName();
        $I->assertEquals($expected, $actual);

        $I->safeDeleteFile($outputPath . $fileName);
    }
}
