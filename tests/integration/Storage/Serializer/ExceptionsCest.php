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

namespace Phalcon\Tests\Integration\Storage\Serializer;

use Codeception\Stub;
use IntegrationTester;
use InvalidArgumentException;
use Phalcon\Storage\Serializer\Base64;
use Phalcon\Storage\Serializer\Igbinary;
use Phalcon\Storage\Serializer\Json;
use Phalcon\Storage\Serializer\Msgpack;
use Phalcon\Storage\Serializer\Php;
use Phalcon\Support\Collection;
use stdClass;

use function json_encode;
use function trigger_error;

use const E_WARNING;

class ExceptionsCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: serialize() - exception
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerBase64SerializeException(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - serialize() - exception');
        $I->expectThrowable(
            new InvalidArgumentException(
                'Data for the serializer must of type string'
            ),
            function () {
                $serializer = new Base64(1234);
                $serializer->serialize();
            }
        );
    }

    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: unserialize() - exception
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerBase64UnserializeException(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - unserialize() - exception');
        $I->expectThrowable(
            new InvalidArgumentException(
                'Data for the unserializer must of type string'
            ),
            function () {
                $serializer = new Base64();
                $serializer->unserialize(1234);
            }
        );
    }

    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: unserialize() - fail empty
     * string
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-24
     */
    public function storageSerializerBase64UnserializeFailReturnsEmptyString(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - unserialize() - fail returns empty string');

        $serializer = Stub::make(
            Base64::class,
            [
                'phpBase64Decode' => false,
            ]
        );

        $actual = $serializer->unserialize("Phalcon Framework");
        $I->assertEmpty($actual);

        $actual = $serializer->isSuccess();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: serialize() - fail empty
     * string
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-24
     */
    public function storageSerializerIgbinarySerializeFailReturnsEmptyString(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - serialize() - fail returns empty string');

        $serializer = Stub::make(
            Igbinary::class,
            [
                'phpIgbinarySerialize' => null,
            ]
        );

        $serializer->setData('Phalcon Framework');
        $actual = $serializer->serialize();
        $I->assertEmpty($actual);

        $actual = $serializer->isSuccess();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: unserialize() - fail empty
     * string
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-24
     */
    public function storageSerializerIgbinaryUnserializeFailReturnsEmptyString(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - unserialize() - fail returns empty string');

        $serializer = Stub::make(
            Igbinary::class,
            [
                'phpIgbinaryUnserialize' => false,
            ]
        );

        $actual = $serializer->unserialize("Phalcon Framework");
        $I->assertEmpty($actual);

        $actual = $serializer->isSuccess();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: unserialize() - fail warning
     * string
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-24
     */
    public function storageSerializerIgbinaryUnserializeFailWarning(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - unserialize() - fail warning');

        $serializer = Stub::make(
            Igbinary::class,
            [
                'phpIgbinaryUnserialize' => function () {
                    trigger_error('Unserialize Error', E_WARNING);
                },
            ]
        );

        $actual = $serializer->unserialize("Phalcon Framework");
        $I->assertEmpty($actual);

        $actual = $serializer->isSuccess();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Json :: serialize() - object
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerJsonSerializeObject(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Json - serialize() - object');

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
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Json :: serialize() - error
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerJsonSerializeError(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Json - serialize() - error');

        $I->expectThrowable(
            new InvalidArgumentException(
                "Data for the JSON serializer cannot be of type 'object' " .
                "without implementing 'JsonSerializable'"
            ),
            function () {
                $example      = new stdClass();
                $example->one = 'two';

                $serializer = new Json($example);
                $serializer->serialize();
            }
        );
    }

    /**
     * Tests Phalcon\Storage\Serializer\Msgpack :: unserialize() - error
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerMsgpackUnserializeError(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Msgpack - unserialize() - error');
        $serializer = new Msgpack();

        $serialized = '??hello?messagepack"';
        $serializer->unserialize($serialized);

        $I->assertEmpty($serializer->getData());
    }

    /**
     * Tests Phalcon\Storage\Serializer\Php :: unserialize() - error not string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerPhpUnserializeErrorNotString(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - unserialize() - error not string');
        $I->expectThrowable(
            new InvalidArgumentException(
                'Data for the unserializer must of type string'
            ),
            function () {
                $serializer = new Php();

                $serialized = new stdClass();
                $serializer->unserialize($serialized);
            }
        );
    }

    /**
     * Tests Phalcon\Storage\Serializer\Php :: unserialize() - error
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerPhpUnserializeError(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - unserialize() - error');
        $serializer = new Php();

        $serialized = '{??hello?unserialize"';
        $serializer->unserialize($serialized);

        $I->assertEmpty($serializer->getData());
    }
}
