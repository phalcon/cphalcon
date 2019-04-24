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

namespace Phalcon\Test\Unit\Storage\Serializer\Php;

use Phalcon\Storage\Serializer\Php;
use UnitTester;

/**
 * Class SerializeCest
 */
class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Php :: serialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-12
     */
    public function storageSerializerPhpSerialize(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - serialize()');
        $data       = ["Phalcon Framework"];
        $serializer = new Php($data);

        $expected = serialize($data);
        $actual   = $serializer->serialize();
        $I->assertEquals($expected, $actual);
    }
}
