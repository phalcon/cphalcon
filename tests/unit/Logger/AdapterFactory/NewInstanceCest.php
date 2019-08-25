<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\AdapterFactory;

use Phalcon\Logger\Adapter\AdapterInterface;
use Phalcon\Logger\AdapterFactory;
use UnitTester;
use function outputDir;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Logger\AdapterFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-20
     */
    public function loggerAdapterFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Logger\AdapterFactory - newInstance()');

        $fileName = $I->getNewFileName();
        $fileName = outputDir('tests/logs/' . $fileName);
        $factory  = new AdapterFactory();

        $logger = $factory->newInstance('stream', $fileName);
        $I->assertInstanceOf(AdapterInterface::class, $logger);
    }
}
