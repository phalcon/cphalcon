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

namespace Phalcon\Tests\Integration\Storage\SerializerFactory;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Storage\Exception;
use Phalcon\Storage\Serializer\Base64;
use Phalcon\Storage\Serializer\Igbinary;
use Phalcon\Storage\Serializer\Json;
use Phalcon\Storage\Serializer\MemcachedIgbinary;
use Phalcon\Storage\Serializer\MemcachedJson;
use Phalcon\Storage\Serializer\MemcachedPhp;
use Phalcon\Storage\Serializer\Msgpack;
use Phalcon\Storage\Serializer\None;
use Phalcon\Storage\Serializer\Php;
use Phalcon\Storage\Serializer\RedisIgbinary;
use Phalcon\Storage\Serializer\RedisJson;
use Phalcon\Storage\Serializer\RedisMsgpack;
use Phalcon\Storage\Serializer\RedisNone;
use Phalcon\Storage\Serializer\RedisPhp;
use Phalcon\Storage\SerializerFactory;

use function uniqid;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageSerializerFactoryNewInstance(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - ' . $example[0]);

        $factory = new SerializerFactory();
        $service = $factory->newInstance($example[0]);

        $expected = $example[1];
        $I->assertInstanceOf($expected, $service);
    }

    /**
     * Tests Phalcon\Storage\SerializerFactory :: newInstance() - exception
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerFactoryNewInstanceException(IntegrationTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - newInstance() - exception');

        $name = uniqid();
        $I->expectThrowable(
            new Exception('Service ' . $name . ' is not registered'),
            function () use ($name) {
                $factory = new SerializerFactory();
                $service = $factory->newInstance($name);
            }
        );
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
            ['base64', Base64::class],
            ['igbinary', Igbinary::class],
            ['json', Json::class],
            ['memcached_igbinary', MemcachedIgbinary::class],
            ['memcached_json', MemcachedJson::class],
            ['memcached_php', MemcachedPhp::class],
            ['msgpack', Msgpack::class],
            ['none', None::class],
            ['php', Php::class],
            ['redis_igbinary', RedisIgbinary::class],
            ['redis_json', RedisJson::class],
            ['redis_msgpack', RedisMsgpack::class],
            ['redis_none', RedisNone::class],
            ['redis_php', RedisPhp::class],
        ];
    }
}
