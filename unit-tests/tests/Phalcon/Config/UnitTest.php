<?php
/**
 * UnitTest.php
 * Config_UnitTest
 *
 * Tests the \Phalcon\Config component
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

use \Phalcon\Config as PhConfig;

class Config_UnitTest extends Config_Helper_Unit
{
    /**
     * Tests the loaded array config
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-04
     */
    public function testArray()
    {
        $config = new PhConfig($this->_myConfig);
        $this->compareConfig($this->_myConfig, $config);
    }
}