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

namespace Phalcon\Test\Unit\Storage\SerializerLocatorFactory;

use Codeception\Example;
use Phalcon\Html\TagLocatorFactory;
use Phalcon\Service\LocatorInterface;
use Phalcon\Storage\SerializerLocatorFactory;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Storage\SerializerLocatorFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageSerializerLocatorFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerLocatorFactory - newInstance()');

        $factory  = new SerializerLocatorFactory();
        $instance = $factory->newInstance();

        $class = LocatorInterface::class;
        $I->assertInstanceOf($class, $instance);
    }

    /**
     * Tests Phalcon\Storage\SerializerLocatorFactory :: newInstance() - services
     *
     * @dataProvider getData
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageSerializerLocatorFactoryNewInstanceServices(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\SerializerLocatorFactory - newInstance() - services ' . $example[0]);

        $factory  = new SerializerLocatorFactory();
        $instance = $factory->newInstance();

        $class = LocatorInterface::class;
        $I->assertInstanceOf($class, $instance);

        $actual = $instance->has($example[0]);
        $I->assertTrue($actual);
    }

    /**
     * Returns the example data
     */
    private function getData(): array
    {
        return [
            ["base64"],
            ["igbinary"],
            ["json"],
            ["msgpack"],
            ["none"],
            ["php"]
        ];
    }
}
