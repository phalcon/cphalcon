<?php
/**
 * ModelTest.php
 * \Phalcon\Tag\ModelTest
 *
 * Tests the \Phalcon\Tag component
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

use \Phalcon\Tag as Tg;

class Tag_ModelTest extends \PhalconModelTestCase
{
    private $message = "%s does not return proper html element";

    // -------------------------------------------------------------------------
    // select
    // -------------------------------------------------------------------------
    /**
     * Tests an image tag with a bare minimum of information passed
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-09
     */
    public function testSelectBasic()
    {
        $robots = Robots::find();

        $params = array(
            'some_name',
            $robots,
            'using' => array('id', 'name')
        );

        $expected = '<select name="some_name" id="some_name">' . PHP_EOL
                  . chr(9) . '<option value="1">Robotina</option>' . PHP_EOL
                  . chr(9) . '<option value="2">Astro Boy</option>' . PHP_EOL
                  . chr(9) . '<option value="3">Terminator</option>' . PHP_EOL
                  . '</select>';
        $actual   = Tg::select($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'select basic')
        );
    }

}