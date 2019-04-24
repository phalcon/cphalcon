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

namespace Phalcon\Test\Unit\Storage\Serializer\Igbinary;

use Phalcon\Storage\Serializer\Igbinary;
use UnitTester;

/**
 * Class SerializeCest
 */
class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: serialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-30
     */
    public function storageSerializerIgbinarySerialize(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - serialize()');
        $data       = ["Phalcon Framework"];
        $serializer = new Igbinary($data);

        $expected = igbinary_serialize($data);
        $actual   = $serializer->serialize();
        $I->assertEquals($expected, $actual);
    }
}
