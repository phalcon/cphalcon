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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use UnitTester;

/**
 * Class ClearCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class ClearCest
{
    /**
     * Tests Phalcon\Html\Tag :: clear()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagClear(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - clear()');
        $tag = new Tag();

        $tag->setAttribute('name', 'Phalcon');
        $actual = $tag->hasValue('name');
        $I->assertTrue($actual);

        $tag->clear();

        $actual = $tag->hasValue('name');
        $I->assertFalse($actual);
    }
}
