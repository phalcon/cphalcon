<?php
/**
 * EmptyCSSTest.php
 * Flash_Direct_EmptyCSSTest
 *
 * Tests the \Phalcon\Flash\Direct component with empty CSS
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

class Flash_Direct_EmptyCSSTest extends Flash_Direct_Helper_Unit
{
    public function setUp()
    {
        parent::setUp();

        $classes = array();

        $this->setClasses($classes);
    }
}
