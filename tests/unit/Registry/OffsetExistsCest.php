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

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class OffsetExistsCest
{
    /**
     * Unit Tests Phalcon\Registry :: offsetExists()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function registryOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Registry - offsetExists()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertTrue(
            isset($registry['three'])
        );

        $I->assertFalse(
            isset($registry['unknown'])
        );

        $I->assertTrue(
            $registry->offsetExists('three')
        );

        $I->assertFalse(
            $registry->offsetExists('unknown')
        );
    }
}
