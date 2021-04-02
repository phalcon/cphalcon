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

namespace Phalcon\Test\Unit\Collection\ReadOnly;

use Phalcon\Collection\ReadOnly;
use UnitTester;

class JsonSerializeCest
{
    /**
     * Tests Phalcon\Collection\ReadOnly :: jsonSerialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionJsonSerialize(UnitTester $I)
    {
        $I->wantToTest('ReadOnly - jsonSerialize()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnly($data);

        $I->assertEquals(
            $data,
            $collection->jsonSerialize()
        );
    }
}
