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

namespace Phalcon\Test\Unit\Storage\Serializer\Base64;

use InvalidArgumentException;
use Phalcon\Storage\Serializer\Base64;
use UnitTester;

/**
 * Class UnserializeCest
 */
class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: unserialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-30
     */
    public function storageSerializerBase64Unserialize(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - unserialize()');
        $data       = 'Phalcon Framework';
        $serializer = new Base64($data);
        $serialized = base64_encode($data);
        $serializer->unserialize($serialized);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: serialize() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-30
     */
    public function storageSerializerBase64SerializeException(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - unserialize() - exception');
        $I->expectThrowable(
            new InvalidArgumentException('Data for the unserializer must of type string'),
            function () {
                $serializer = new Base64();
                $serializer->unserialize(1234);
            }
        );
    }
}
