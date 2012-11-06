<?php
/**
 * Unit.php
 * Config_Helper_Unit.php
 *
 * Helper for the \Phalcon\Config components
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

class Config_Helper_Unit extends Phalcon_Test_UnitTestCase
{
    /**
     * Array used for comparisons
     *
     * @var array
     */
    protected $_myConfig = array(
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

    protected function compareConfig($source, $target)
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