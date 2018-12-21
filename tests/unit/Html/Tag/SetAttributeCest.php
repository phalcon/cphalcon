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
 * Class SetAttributeCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class SetAttributeCest
{
    /**
     * Tests Phalcon\Html\Tag :: setAttribute()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagSetAttribute(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - setAttribute()');
        $tag = new Tag();

        $tag->setAttribute('name', 'Phalcon');
        $expected = 'Phalcon';
        $actual   = $tag->getValue('name');
        $I->assertEquals($expected, $actual);
    }
}
