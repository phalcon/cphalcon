<?php
/**
 * UnitTest.php
 * Config_Adapter_Ini_UnitTest
 *
 * Tests the \Phalcon\Config\Adapter\Ini component
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
use \Phalcon\Config\Adapter\Ini as PhConfigIni;

class Config_Adapter_Ini_UnitTest extends Config_Helper_Unit
{
    public function testIni()
    {
        $config = new PhConfigIni(PATH_CONFIG . 'config.ini');
        $this->compareConfig($this->_myConfig, $config);
    }
}