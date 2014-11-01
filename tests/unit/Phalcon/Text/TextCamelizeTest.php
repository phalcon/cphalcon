<?php
/**
 * TextCamelizeTest.php
 * \Phalcon\Text\TextCamelizeTest
 *
 * Tests the Phalcon\Text component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Text;

use \PhalconTest\Text as PhTText;

class TextCamelizeTest extends Helper\TextBase
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
            "camelize conversions do not return the correct string",
            function () {

                $camelizeTests = [
                    'camelize'        => 'Camelize',
                    'CameLiZe'        => 'Camelize',
                    'cAmeLize'        => 'Camelize',
                    '_camelize'       => 'Camelize',
                    '123camelize'     => '123camelize',
                    'c_a_m_e_l_i_z_e' => 'CAMELIZE',
                    'Camelize'        => 'Camelize',
                    'camel_ize'       => 'CamelIze',
                    'CameLize'        => 'Camelize',
                ];

                foreach ($camelizeTests as $input => $camelized) {

                    $expected = $camelized;
                    $actual   = PhTText::camelize($input);
                    expect($actual)->equals($expected);
                }
            }
        );
    }
}
