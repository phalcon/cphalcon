<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

class TextUncamelizeCest
{
    /**
     * Tests the uncamelize function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextUncamelizeString(UnitTester $I)
    {
        $examples = [
            ['camelize',        'camelize',        null],
            ['CameLiZe',        'came_li_ze',      null],
            ['cAmeLize',        'c_ame_lize',      null],
            ['_camelize',       '_camelize',       null],
            ['123camelize',     '123camelize',     null],
            ['c_a_m_e_l_i_z_e', 'c_a_m_e_l_i_z_e', null],
            ['Camelize',        'camelize',        null],
            ['camel_ize',       'camel_ize',       null],
            ['CameLize',        'came_lize',       null],
            ["Camelize",        'camelize',        null],
            ["=Camelize",       '=_camelize',      "_" ],
            ["Camelize",        'camelize',        "_" ],
            ["CameLiZe",        'came_li_ze',      "_" ],
            ["CameLiZe",        'came#li#ze',      "#" ],
            ["CameLiZe",        'came li ze',      " " ],
            ["CameLiZe",        'came.li.ze',      "." ],
            ["CameLiZe",        'came-li-ze',      "-" ],
            ["CAMELIZE",        'c/a/m/e/l/i/z/e', "/" ],
        ];

        foreach ($examples as $item) {
            $value     = $item[0];
            $expected  = $item[1];
            $delimiter = $item[2];
            $actual    = Text::uncamelize($value, $delimiter);
            $I->assertEquals($expected, $actual);
        }
    }
}
