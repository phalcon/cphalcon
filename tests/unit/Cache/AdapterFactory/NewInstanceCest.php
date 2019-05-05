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

namespace Phalcon\Test\Unit\Cache\AdapterFactory;

use Phalcon\Service\Exception;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Php;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Cache\AdapterFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageAdapterFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Cache\AdapterFactory - newInstance()');

        $factory = new SerializerFactory();
        $service = new AdapterFactory($factory);

        $service = $service->newInstance('apcu');
        $class   = Apcu::class;
        $I->assertInstanceOf($class, $service);
    }

    /**
     * Tests Phalcon\Cache\AdapterFactory :: newInstance() - exception
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageAdapterFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Cache\AdapterFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception('The service unknown has not been found in the locator'),
            function () {
                $factory = new SerializerFactory();
                $service = new AdapterFactory($factory);
                $service = $service->newInstance('unknown');
            }
        );
    }
}
