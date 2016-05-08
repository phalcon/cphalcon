<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Text;

/**
 * \Phalcon\Test\Unit\Text\TextUncamelizeTest
 * Tests the \Phalcon\Text component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
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
            "uncamelize conversions do not return the correct string",
            function () {

                $uncamelizeTests = [
                    'camelize'        => 'camelize',
                    'CameLiZe'        => 'came_li_ze',
                    'cAmeLize'        => 'c_ame_lize',
                    '_camelize'       => '_camelize',
                    '123camelize'     => '123camelize',
                    'c_a_m_e_l_i_z_e' => 'c_a_m_e_l_i_z_e',
                    'Camelize'        => 'camelize',
                    'camel_ize'       => 'camel_ize',
                    'CameLize'        => 'came_lize',
                ];

                foreach ($uncamelizeTests as $input => $uncamelized) {
                    expect(Text::uncamelize($input))->equals($uncamelized);
                }
            }
        );
    }
}
