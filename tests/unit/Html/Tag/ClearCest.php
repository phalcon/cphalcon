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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use UnitTester;

class ClearCest
{
    /**
     * Tests Phalcon\Html\Tag :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function htmlTagClear(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - clear()');

        $tag = new Tag();

        $tag->setAttribute('name', 'Phalcon');

        $I->assertTrue(
            $tag->hasValue('name')
        );

        $tag->clear();

        $I->assertFalse(
            $tag->hasValue('name')
        );
    }
}
