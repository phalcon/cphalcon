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

namespace Phalcon\Tests\Unit\Logger\AdapterFactory;

use Phalcon\Logger\Exception;
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

    /**
     * Tests Phalcon\Logger\AdapterFactory :: newInstance() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-20
     */
    public function loggerAdapterFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Logger\AdapterFactory - newInstance() - exception');

        $factory = new AdapterFactory();
        $I->expectThrowable(
            new Exception('Service unknown is not registered'),
            function () use ($factory) {
                $logger = $factory->newInstance('unknown', '123.log');
            }
        );
    }
}
