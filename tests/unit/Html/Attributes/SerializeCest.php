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

class SerializeCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: serialize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesSerialize(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - serialize()');

        $attributes = new Attributes(
            [
                'class' => 'form-control',
                'name'  => 'q',
                'value' => '',
            ]
        );

        $actual   = $attributes->serialize();
        $expected = 'a:3:{s:5:"class";s:12:"form-control";s:4:"name";s:1:"q";s:5:"value";s:0:"";}';

        $I->assertSame($expected, $actual);
    }
}
