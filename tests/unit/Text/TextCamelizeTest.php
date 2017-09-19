<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Text\TextConcatTest
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
class TextCamelizeTest extends UnitTest
{
    /**
     * Tests the camelize function
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-29
     */
    public function testTextCamelizeString()
    {
        $this->specify(
            'Text::camelize conversions do not return the correct string',
            function ($actual, $expected, $delimiter) {
                expect(Text::camelize($actual, $delimiter))->equals($expected);
            },
            [
                'examples' => [
                    ['camelize',        'Camelize',    null],
                    ['CameLiZe',        'Camelize',    null],
                    ['cAmeLize',        'Camelize',    null],
                    ['123camelize',     '123camelize', null],
                    ['c_a_m_e_l_i_z_e', 'CAMELIZE',    null],
                    ['Camelize',        'Camelize',    null],
                    ['camel_ize',       'CamelIze',    null],
                    ['CameLize',        'Camelize',    null],
                    ["c_a-m_e-l_i-z_e", 'CAMELIZE',    null],
                    ["came_li_ze",      'CameLiZe',    null],
                    ["=_camelize",      '=Camelize',   "_" ],
                    ["camelize",        'Camelize',    "_" ],
                    ["came_li_ze",      'CameLiZe',    "_" ],
                    ["came#li#ze",      'CameLiZe',    "#" ],
                    ["came li ze",      'CameLiZe',    " " ],
                    ["came.li^ze",      'CameLiZe',    ".^"],
                    ["c_a-m_e-l_i-z_e", 'CAMELIZE',    "-_"],
                    ["came.li.ze",      'CameLiZe',    "." ],
                    ["came-li-ze",      'CameLiZe',    "-" ],
                    ["c+a+m+e+l+i+z+e", 'CAMELIZE',    "+" ],
                ]
            ]
        );
    }
}
