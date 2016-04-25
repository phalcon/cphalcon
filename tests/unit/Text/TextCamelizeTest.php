<?php

namespace Phalcon\Test\Unit\Text;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Text;

/**
 * \Phalcon\Test\Unit\Text\TextConcatTest
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
            "camelize conversions do not return the correct string",
            function () {

                $camelizeTests = [
                    'camelize'        => 'Camelize',
                    'CameLiZe'        => 'Camelize',
                    'cAmeLize'        => 'Camelize',
                    '123camelize'     => '123camelize',
                    'c_a_m_e_l_i_z_e' => 'CAMELIZE',
                    'Camelize'        => 'Camelize',
                    'camel_ize'       => 'CamelIze',
                    'CameLize'        => 'Camelize',
                ];

                foreach ($camelizeTests as $input => $camelized) {
                    expect(Text::camelize($input))->equals($camelized);
                }
            }
        );
    }
}
