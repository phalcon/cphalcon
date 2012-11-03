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

class Config_Adapter_Ini_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Array used for comparisons
     *
     * @var array
     */
    private $_myConfig = array(
                            "phalcon"  => array("baseuri" => "/phalcon/"),
                            "models"   => array("metadata" => "memory"),
                            "database" => array(
                                "adapter"  => "mysql",
                                "host"     => "localhost",
                                "username" => "user",
                                "password" => "passwd",
                                "name"     => "demo"
                            ),
                            "test"     => array(
                                "parent" => array("property" => 1),
                                "parent" => array("property2" => "yeah")
                            )
                        );

    /**
     * Tests the loaded array config
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-04
     */
    public function testArray()
    {
        $config = new PhConfig($this->_myConfig);
        $this->_compareConfig($this->_myConfig, $config);
    }

    public function testIni()
    {
        $config = new PhConfigIni(ROOT_PATH . '/tests/app/var/config/config.ini');
        $this->_compareConfig($this->_myConfig, $config);
    }

    private function _compareConfig($source, $target)
    {
        foreach ($source as $sourceKey => $sourceValue)
        {
            $this->assertTrue(
                isset($target->$sourceKey),
                $sourceKey . ' is not set in the target'
            );

            if (is_array($sourceValue))
            {
                if (isset($target->$sourceKey))
                {
                    foreach ($sourceValue as $sourceKeyTwo => $sourceValueTwo)
                    {
                        $this->assertTrue(
                            isset($target->$sourceKey->$sourceKeyTwo),
                            $sourceKeyTwo . ' is not set in the target'
                        );

                        if (isset($target->$sourceKey->$sourceKeyTwo))
                        {
                            if (is_array($sourceValueTwo))
                            {
                                foreach ($sourceValueTwo as $sourceKeyThree => $sourceValueThree)
                                {
                                    if (isset($target->$sourceKey->$sourceKeyTwo->$sourceKeyThree))
                                    {
                                        $this->assertTrue(
                                            isset($target->$sourceKey->$sourceKeyTwo->$sourceKeyThree),
                                            $target->$sourceKey->$sourceKeyTwo->$sourceKeyThree .
                                            ' is not set in the target'
                                        );

                                        $this->assertEquals(
                                            $sourceValueThree,
                                            $target->$sourceKey->$sourceKeyTwo->$sourceKeyThree,
                                            $sourceValueThree .
                                            ' is not equal to the target'
                                        );
                                    }
                                }
                            }
                            else
                            {
                                $this->assertEquals(
                                    $sourceValueTwo,
                                    $target->$sourceKey->$sourceKeyTwo,
                                    $sourceValueTwo .
                                        ' is not equal to the target'
                                );
                            }
                        }
                    }
                }
            }
        }
    }
}