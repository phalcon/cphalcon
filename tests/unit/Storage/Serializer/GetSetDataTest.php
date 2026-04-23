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

final class GetSetDataTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                Base64::class,
            ],
            [
                Igbinary::class,
            ],
            [
                Json::class,
            ],
            [
                MemcachedIgbinary::class,
            ],
            [
                MemcachedJson::class,
            ],
            [
                MemcachedPhp::class,
            ],
            [
                Msgpack::class,
            ],
            [
                None::class,
            ],
            [
                Php::class,
            ],
            [
                RedisIgbinary::class,
            ],
            [
                RedisJson::class,
            ],
            [
                RedisMsgpack::class,
            ],
            [
                RedisNone::class,
            ],
            [
                RedisPhp::class,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2022-02-24
     */
    public function testStorageSerializerGetSetData(
        string $class
    ) {
        $data       = ['Phalcon Framework'];
        $serializer = new $class();

        $actual = $serializer->getData();
        $this->assertNull($actual);

        $serializer->setData($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $this->assertSame($expected, $actual);
    }
}
