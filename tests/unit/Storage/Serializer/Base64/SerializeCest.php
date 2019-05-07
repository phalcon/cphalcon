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
 * Class SerializeCest
 */
class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: serialize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-30
     */
    public function storageSerializerBase64Serialize(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - serialize()');
        $data       = "Phalcon Framework";
        $serializer = new Base64($data);

        $expected = base64_encode($data);
        $actual   = $serializer->serialize();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: serialize() - exception
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-30
     */
    public function storageSerializerBase64SerializeException(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - serialize() - exception');
        $I->expectThrowable(
            new InvalidArgumentException('Data for the serializer must of type string'),
            function () {
                $serializer = new Base64(1234);
                $serializer->serialize();
            }
        );
    }
}
