<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextUncamelizeTest
 * Tests the \Phalcon\Text component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TextUncamelizeTest extends UnitTest
{
    /**
     * Tests the uncamelize function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextUncamelizeString()
    {
        $this->specify(
            'Text::uncamelize conversions do not return the correct string',
            function ($actual, $expected, $delimiter) {
                expect(Text::uncamelize($actual, $delimiter))->equals($expected);
            },
            [
                'examples' => [
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
                ]
            ]
        );
    }
}
