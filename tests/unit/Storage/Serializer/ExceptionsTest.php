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

use Exception;
use InvalidArgumentException;
use Phalcon\Storage\Serializer\Base64;
use Phalcon\Storage\Serializer\Json;
use Phalcon\Storage\Serializer\Msgpack;
use Phalcon\Storage\Serializer\None;
use Phalcon\Storage\Serializer\Php;
use Phalcon\Support\Collection;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Storage\Fake\FakeBase64Decode;
use Phalcon\Tests\Unit\Storage\Fake\FakeIgbinarySerialize;
use Phalcon\Tests\Unit\Storage\Fake\FakeIgbinaryUnserialize;
use Phalcon\Tests\Unit\Storage\Fake\FakeIgbinaryUnserializeWarning;
use stdClass;

use function json_encode;
use function serialize;
use function unserialize;

final class ExceptionsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerAbstractSerializerSerializeWithArray(): void
    {
        $data       = ['Phalcon', 'Framework'];
        $serializer = new None($data);

        $expected = $data;
        $actual   = $serializer->__serialize();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerAbstractSerializerSerializeWithNonArray(): void
    {
        $serializer = new None('Phalcon Framework');

        $expected = [];
        $actual   = $serializer->__serialize();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerAbstractSerializerUnserialize(): void
    {
        $data       = ['Phalcon', 'Framework'];
        $serializer = new None();
        $serializer->__unserialize($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerBase64SerializeException(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage(
            'Data for the serializer must of type string'
        );

        $serializer = new Base64(1234);
        $serializer->serialize();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerBase64UnserializeException(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage(
            'Data for the unserializer must of type string'
        );

        $serializer = new Base64();
        $serializer->unserialize(1234);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-24
     */
    public function testStorageSerializerBase64UnserializeFailReturnsEmptyString(): void
    {
        $serializer = new FakeBase64Decode();

        $serializer->unserialize("Phalcon Framework");
        $actual = $serializer->getData();
        $this->assertEmpty($actual);

        $actual = $serializer->isSuccess();
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-24
     */
    public function testStorageSerializerIgbinarySerializeFailReturnsEmptyString(): void
    {
        $serializer = new FakeIgbinarySerialize();

        $serializer->setData('Phalcon Framework');
        $actual = $serializer->serialize();
        $this->assertEmpty($actual);

        $actual = $serializer->isSuccess();
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-24
     */
    public function testStorageSerializerIgbinaryUnserializeFailReturnsEmptyString(): void
    {
        $serializer = new FakeIgbinaryUnserialize();

        $serializer->unserialize("Phalcon Framework");
        $actual = $serializer->getData();
        $this->assertEmpty($actual);

        $actual = $serializer->isSuccess();
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-24
     */
    public function testStorageSerializerIgbinaryUnserializeFailWarning(): void
    {
        $serializer = new FakeIgbinaryUnserializeWarning();

        $serializer->unserialize("Phalcon Framework");
        $actual = $serializer->getData();
        $this->assertEmpty($actual);

        $actual = $serializer->isSuccess();
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerJsonSerializeError(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage(
            "Data for the JSON serializer cannot be of type 'object' " .
            "without implementing 'JsonSerializable'"
        );

        $example      = new stdClass();
        $example->one = 'two';

        $serializer = new Json($example);
        $serializer->serialize();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerJsonSerializeObject(): void
    {
        $collection1 = new Collection();
        $collection1->set('one', 'two');
        $collection2 = new Collection();
        $collection2->set('three', 'four');
        $collection2->set('object', $collection1);

        $serializer = new Json($collection2);

        $data     = [
            'three'  => 'four',
            'object' => [
                'one' => 'two',
            ],
        ];
        $expected = json_encode($data);
        $actual   = $serializer->serialize();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerMsgpackUnserializeError(): void
    {
        $serializer = new Msgpack();

        $serialized = '??hello?messagepack"';
        $serializer->unserialize($serialized);

        $this->assertEmpty($serializer->getData());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerPhpUnserializeError(): void
    {
        $serializer = new Php();

        $serialized = '{??hello?unserialize"';
        $serializer->unserialize($serialized);

        $this->assertEmpty($serializer->getData());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testStorageSerializerPhpUnserializeErrorNotString(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage(
            'Data for the unserializer must of type string'
        );

        $serializer = new Php();

        $serialized = new stdClass();
        $serializer->unserialize($serialized);
    }
}
