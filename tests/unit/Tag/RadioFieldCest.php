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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Helpers\TagSetup;
use UnitTester;

class RadioFieldCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: radioField()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testRadioField(UnitTester $I)
    {
        $I->wantToTest('Tag - radioField()');

        $options = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="radio" id="x_id" name="x_name" '
            . 'class="x_class" size="10">';
        $actual   = Tag::radioField($options);
        $I->assertEquals($expected, $actual);
    }
}
