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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Escaper;
use UnitTester;

class OffsetExistsCest
{
    /**
     * Tests Phalcon\Di :: offsetExists()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function diOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Di - offsetExists()');

        $di = new Di();

        $I->assertFalse(
            isset($di['escaper'])
        );

        $di->set('escaper', Escaper::class);

        $I->assertTrue(
            isset($di['escaper'])
        );
    }
}
