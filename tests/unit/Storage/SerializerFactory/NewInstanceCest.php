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

use Codeception\Example;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Exception;
use Phalcon\Storage\Serializer\Base64;
use Phalcon\Storage\Serializer\Igbinary;
use Phalcon\Storage\Serializer\Json;
use Phalcon\Storage\Serializer\Msgpack;
use Phalcon\Storage\Serializer\None;
use Phalcon\Storage\Serializer\Php;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

/**
 * Class NewInstanceCest
 */
class NewInstanceCest
{
    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since        2019-05-04
     *
     * @author       Phalcon Team <team@phalconphp.com>
     */
    public function storageSerializerFactoryNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - ' . $example[0]);

        $factory = new SerializerFactory();
        $service = $factory->newInstance($example[0]);

        $class = $example[1];
        $I->assertInstanceOf($class, $service);
    }

    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance() - exception
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2019-05-04
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function storageSerializerFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception('Service unknown is not registered'),
            function () {
                $factory = new SerializerFactory();
                $service = $factory->newInstance('unknown');
            }
        );
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            ['base64', Base64::class],
            ['igbinary', Igbinary::class],
            ['json', Json::class],
            ['msgpack', Msgpack::class],
            ['none', None::class],
            ['php', Php::class],
        ];
    }

}
