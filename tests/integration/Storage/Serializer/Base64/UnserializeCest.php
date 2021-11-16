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

use IntegrationTester;
use InvalidArgumentException;
use Phalcon\Storage\Serializer\Base64;

class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: unserialize()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerBase64Unserialize(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerBase64SerializeException(IntegrationTester $I)
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
