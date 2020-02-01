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

namespace Phalcon\Test\Integration\Storage\Serializer\Base64;

use InvalidArgumentException;
use Phalcon\Storage\Serializer\Base64;
use UnitTester;

class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: unserialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerBase64Unserialize(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - unserialize()');

        $data       = 'Phalcon Framework';
        $serializer = new Base64($data);
        $serialized = base64_encode($data);
        $serializer->unserialize($serialized);

        $I->assertEquals(
            $data,
            $serializer->getData()
        );
    }

    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: serialize() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerBase64SerializeException(UnitTester $I)
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
}
