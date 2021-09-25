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

namespace Phalcon\Tests\Integration\Storage\Serializer\Base64;

use InvalidArgumentException;
use Phalcon\Storage\Serializer\Base64;
use IntegrationTester;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: serialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerBase64Serialize(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - serialize()');

        $data       = 'Phalcon Framework';
        $serializer = new Base64($data);

        $I->assertEquals(
            base64_encode($data),
            $serializer->serialize()
        );
    }

    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: serialize() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
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
}
