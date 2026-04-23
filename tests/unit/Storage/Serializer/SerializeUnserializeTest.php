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

namespace Phalcon\Tests\Unit\Storage\Serializer;

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
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

use function igbinary_serialize;
use function json_encode;
use function serialize;

final class SerializeUnserializeTest extends AbstractUnitTestCase
{
    private const TEXT = 'Phalcon Framework';

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        $stdClass = new stdClass();

        return [
            [
                Base64::class,
                self::TEXT,
                base64_encode(self::TEXT),
            ],
            [
                Igbinary::class,
                null,
                null,
            ],
            [
                Igbinary::class,
                true,
                true,
            ],
            [
                Igbinary::class,
                false,
                false,
            ],
            [
                Igbinary::class,
                1234,
                1234,
            ],
            [
                Igbinary::class,
                1.234,
                1.234,
            ],
            [
                Igbinary::class,
                self::TEXT,
                igbinary_serialize(self::TEXT),
            ],
            [
                Igbinary::class,
                [self::TEXT],
                igbinary_serialize([self::TEXT]),
            ],
            [
                Igbinary::class,
                $stdClass,
                igbinary_serialize($stdClass),
            ],
            [
                Json::class,
                null,
                null,
            ],
            [
                Json::class,
                true,
                true,
            ],
            [
                Json::class,
                false,
                false,
            ],
            [
                Json::class,
                1234,
                1234,
            ],
            [
                Json::class,
                1.234,
                1.234,
            ],
            [
                Json::class,
                self::TEXT,
                json_encode(self::TEXT),
            ],
            [
                Json::class,
                [self::TEXT],
                json_encode([self::TEXT]),
            ],
            [
                MemcachedIgbinary::class,
                null,
                null,
            ],
            [
                MemcachedJson::class,
                null,
                null,
            ],
            [
                MemcachedPhp::class,
                null,
                null,
            ],
            [
                Msgpack::class,
                null,
                null,
            ],
            [
                Msgpack::class,
                true,
                true,
            ],
            [
                Msgpack::class,
                false,
                false,
            ],
            [
                Msgpack::class,
                1234,
                1234,
            ],
            [
                Msgpack::class,
                1.234,
                1.234,
            ],
            [
                Msgpack::class,
                self::TEXT,
                msgpack_pack(self::TEXT),
            ],
            [
                Msgpack::class,
                [self::TEXT],
                msgpack_pack([self::TEXT]),
            ],
            [
                Msgpack::class,
                $stdClass,
                msgpack_pack($stdClass),
            ],
            [
                None::class,
                null,
                null,
            ],
            [
                None::class,
                true,
                true,
            ],
            [
                None::class,
                false,
                false,
            ],
            [
                None::class,
                1234,
                1234,
            ],
            [
                None::class,
                1.234,
                1.234,
            ],
            [
                None::class,
                self::TEXT,
                self::TEXT,
            ],
            [
                None::class,
                [self::TEXT],
                [self::TEXT],
            ],
            [
                None::class,
                $stdClass,
                $stdClass,
            ],
            [
                Php::class,
                null,
                null,
            ],
            [
                Php::class,
                true,
                true,
            ],
            [
                Php::class,
                false,
                false,
            ],
            [
                Php::class,
                1234,
                1234,
            ],
            [
                Php::class,
                1.234,
                1.234,
            ],
            [
                Php::class,
                self::TEXT,
                serialize(self::TEXT),
            ],
            [
                Php::class,
                [self::TEXT],
                serialize([self::TEXT]),
            ],
            [
                Php::class,
                $stdClass,
                serialize($stdClass),
            ],
            [
                RedisIgbinary::class,
                null,
                null,
            ],
            [
                RedisJson::class,
                null,
                null,
            ],
            [
                RedisMsgpack::class,
                null,
                null,
            ],
            [
                RedisNone::class,
                null,
                null,
            ],
            [
                RedisPhp::class,
                null,
                null,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-02-24
     */
    public function testStorageSerializerSerializeUnserialize(
        string $class,
        mixed $data,
        mixed $expected
    ): void {
        $serializer = new $class($data);
        $serialized = $serializer->serialize();

        $actual = $serialized;
        $this->assertSame($expected, $actual);

        $serializer = new $class();
        $serializer->unserialize($serialized);

        /**
         * assertEquals here because stdClass will not refer to the same
         * object when unserialized
         */
        $expected = $data;
        $actual   = $serializer->getData();
        $this->assertEquals($expected, $actual);
        $this->assertTrue($serializer->isSuccess());
    }
}
