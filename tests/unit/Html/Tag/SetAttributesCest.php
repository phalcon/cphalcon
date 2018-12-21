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
 * Class SetAttributesCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class SetAttributesCest
{
    /**
     * Tests Phalcon\Html\Tag :: setAttributes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagSetAttributes(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - setAttributes()');
        $tag = new Tag();

        $tag->setAttributes(
            [
                'name' => 'Phalcon',
                'cols' => 100,
            ]
        );
        $expected = 'Phalcon';
        $actual   = $tag->getValue('name');
        $I->assertEquals($expected, $actual);

        $expected = 100;
        $actual   = $tag->getValue('cols');
        $I->assertEquals($expected, $actual);
    }
}
