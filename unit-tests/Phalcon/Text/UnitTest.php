<?php
/**
 * UnitTest.php
 * \Phalcon\Text\UnitTest
 *
 * Tests the \Phalcon\Text component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use Phalcon\Text as Txt;

class Text_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests the camelize function
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-17
     */
    public function testCamelizeString()
    {
        $camelizeTests = array (
            'camelize'        => 'Camelize',
            'CameLiZe'        => 'Camelize',
            'cAmeLize'        => 'Camelize',
            '_camelize'       => 'Camelize',
            '123camelize'     => '123camelize',
            'c_a_m_e_l_i_z_e' => 'CAMELIZE',
            'Camelize'        => 'Camelize',
            'camel_ize'       => 'CamelIze',
            'CameLize'        => 'Camelize',
        );

        $template = "Text::camelize did not convert the string '%s' correctly";

        foreach ($camelizeTests as $input => $camelized) {
            $expected = $camelized;
            $actual   = Txt::camelize($input);
            $this->assertEquals(
                $expected,
                $actual,
                sprintf($template, $input)
            );
        }
    }

    /**
     * Tests the uncamelize function
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-17
     */
    public function testUncamelizeString()
    {

        $uncamelizeTests = array (
            'camelize'        => 'camelize',
            'CameLiZe'        => 'came_li_ze',
            'cAmeLize'        => 'c_ame_lize',
            '_camelize'       => '_camelize',
            '123camelize'     => '123camelize',
            'c_a_m_e_l_i_z_e' => 'c_a_m_e_l_i_z_e',
            'Camelize'        => 'camelize',
            'camel_ize'       => 'camel_ize',
            'CameLize'        => 'came_lize',
        );

        $template = "Text::uncamelize did not convert the string '%s' correctly";

        foreach ($uncamelizeTests as $input => $uncamelized) {
            $expected = $uncamelized;
            $actual   = Txt::uncamelize($input);
            $this->assertEquals(
                $expected,
                $actual,
                sprintf($template, $input)
            );
        }
    }
}