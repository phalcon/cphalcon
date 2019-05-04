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

namespace Phalcon\Test\Unit\Storage\SerializerFactory;

use Phalcon\Service\Exception;
use Phalcon\Storage\Serializer\Php;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageSerializerFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance()');

        $service = new SerializerFactory();

        $service = $service->newInstance('php');
        $class   = Php::class;
        $I->assertInstanceOf($class, $service);
    }

    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance() - exception
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageSerializerFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception('The service unknown has not been found in the locator'),
            function () {
                $service = new SerializerFactory();
                $service = $service->newInstance('unknown');

            }
        );
    }
}
