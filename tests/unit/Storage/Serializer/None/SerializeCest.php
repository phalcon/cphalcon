<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Storage\Serializer\None;

use Phalcon\Storage\Serializer\None;
use UnitTester;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\None :: serialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerNoneSerialize(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\None - serialize()');
        $data       = ['Phalcon Framework'];
        $serializer = new None($data);

        $expected = $data;
        $actual   = $serializer->serialize();
        $I->assertEquals($expected, $actual);
    }
}
