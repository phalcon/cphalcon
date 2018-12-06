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

namespace Phalcon\Test\Unit\Logger\Adapter\File;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\File;
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
     * Tests Phalcon\Logger\Adapter\File :: getFormatter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterFileGetFormatter(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\File - getFormatter()');

        $fileName = $I->getNewFileName('log', 'log');
        $fileName = outputFolder('tests/logs/' . $fileName);

        $adapter = new File($fileName);
        $adapter->getFormatter(new Line());

        $class  = FormatterInterface::class;
        $actual = $adapter->getFormatter();
        $I->assertInstanceOf($class, $actual);
        $I->safeDeleteFile($fileName);
    }
}
