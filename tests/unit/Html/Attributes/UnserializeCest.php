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

namespace Phalcon\Test\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class UnserializeCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: unserialize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesUnserialize(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - unserialize()');

        $attributes = new Attributes(
            [
                'class' => 'form-control',
                'name'  => 'q',
                'value' => '',
            ]
        );

        $expected = 'a:3:{s:5:"class";s:12:"form-control";s:4:"name";s:1:"q";s:5:"value";s:0:"";}';

        $attributes->unserialize($expected);

        $actual = $attributes->serialize();

        $I->assertSame($expected, $actual);
    }
}
