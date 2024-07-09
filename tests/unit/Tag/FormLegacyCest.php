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

class FormLegacyCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: form()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-22
     */
    public function tagForm(UnitTester $I)
    {
        $I->wantToTest('Tag - form()');

        $options = [
            'x_name',
            'class' => 'x_class',
        ];

        $expected = '<form action="/x_name" class="x_class" method="post">';
        $actual   = Tag::formLegacy($options);
        $I->assertSame($expected, $actual);
    }
}
